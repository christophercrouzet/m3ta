.. _examples:

Examples
========


.. _functioncallatcompiletime:

Function Call at Compile Time
-----------------------------

Let’s consider the case of 2D texture tiles to be used in the context of
tile-based texture mapping within graphic renderers such as OpenGL. Such tiles
must be square and it is often recommended for hardware optimisations and/or
limitations to set their size to a power of two.

.. code-block:: cpp
   
   template<int T_size>
   class TextureTile2D
   {};


Defining the size as a template parameter force the user to provide it at
compile time, allowing some possible further optimisations.

As it stands with this class definition, a 2D texture tile could be initialized
by passing any value—power of two, or not.

.. code-block:: cpp
   
   TextureTile2D<256> powerOfTwoTexture;
   TextureTile2D<123> nonPowerOfTwoTexture;


To avoid the risk of passing non power of two values by mistake, one could
decide to use a power function such as the stardard ``std::pow()``.

.. code-block:: cpp
   
   TextureTile2D<std::pow(2, 8)> powerOfTwoTexture;


Expect that this won’t compile because the template parameter ``T_size`` needs
to be set at compile time while the ``std::pow()`` function can only be ran at
runtime. That’s where the :ref:`m3ta::power() <function_power>` function comes
into play.

.. code-block:: cpp
   
   TextureTile2D<m3ta::power(2, 8)> powerOfTwoTexture;


This works because the :ref:`m3ta::power() <function_power>` function—like all
the other functions from this library—is defined with the ``constexpr``
qualifier introduced in C++11, allowing it to run either at runtime or
at compile time, depending on the context. The context here being a template
parameter, the function runs at compile time.


.. _tagdispatching:

Tag Dispatching
---------------

Building on the previous example, let’s assume that ``TextureTile2D`` has
a method that does something where the computations involved could be highly
optimized if the size passed as argument was a power of two less than 1024.

.. code-block:: cpp
   
   constexpr bool isPowerOfTwo(int value) { ... }
   
   template<int T_size>
   class TextureTile2D
   {
   public:
       void doSomething()
       {
           if (isPowerOfTwo(T_size) && T_size < 1024) {
               // Run optimized code.
           }
           else {
               // Run unoptimized code.
           }
       }
   };


This runs fine but the conditional check is done here at runtime even though
the value ``T_size`` is known at compile time and that the function
``isPowerOfTwo`` can also run at compile time. If the check was expensive, it
could be worthwhile to compute it once for all at compile time.

.. code-block:: cpp
   
   constexpr bool isPowerOfTwo(int value) { ... }
   
   template<int T_size>
   class TextureTile2D
   {
   public:
       void
       doSomething()
       {
           doSomething_impl(m3ta::All<bool, isPowerOfTwo(T_size), T_size < 1024>());
       }
   
   private:
       void
       doSomething_impl(std::true_type)
       {
           // Run optimized code.
       }
       
       void
       doSomething_impl(std::false_type)
       {
           // Run unoptimized code.
       }
   };


Here the trait :ref:`m3ta::All <trait_all>` inherits from ``std::true_type``
(an alias of ``std::integral_type<bool, true>``) if all the conditions passed
to :ref:`m3ta::All <trait_all>` evaluate to `true`, and from ``std::false_type``
otherwise.

This is called the tag dispatching technique—it allows to pick either one of
the implementations at compile time.


.. _overloadresolutionusingsfinae:

Overload Resolution Using SFINAE
--------------------------------

.. code-block:: cpp
   
   template<typename T1, typename T2, typename = void>
   struct AreComparableForEquality
   {
       static constexpr bool value = false;
   };
   
   template<typename T1, typename T2>
   struct AreComparableForEquality<
       T1,
       T2,
       typename std::enable_if<
           true,
           m3ta::PassT<void, decltype(std::declval<T1>() == std::declval<T2>())>
       >::type
   >
   {
       static constexpr bool value = true;
   };


This ``AreComparableForEquality`` trait defined here allows to check if
two types can be compared for equality using the operator ``==``. For example
``AreComparableForEquality<int, float>::value`` returns ``true`` while
``AreComparableForEquality<std::string, float>::value`` returns ``false``.

This works by using the SFINAE technique over template parameters—if the code 
``std::declval<T1>() == std::declval<T2>()`` is not a valid expression (no
equality operator is defined between he types ``T1`` and ``T2``), then the default
overload holding the value ``false`` is picked, otherwise the second one is
chosen at one condition: the specialization of the third parameter must return
``void`` as per the default template parameter from the first overload.

:ref:`m3ta::PassT <alias_passt>` is a used here to conveniently test the SFINAE
expression while always returning the required type.


.. _staticassert:

Static Assert
-------------

Let’s assume a ``Divide`` struct that would operate divisions between two
integers at compile time. To disallow divisions by 0, a possibility could be to
define a template specialization for the divisor value that would trigger
an informative error message at compile time using ``static_assert``.

.. code-block:: cpp
   
   template<int T_dividend, int T_divisor>
   struct Divide
   {
       static constexpr int value = T_dividend / T_divisor;
   };
   
   template<int T_dividend>
   struct Divide<T_dividend, 0>
   {
       static_assert(false, "Division by 0 not allowed.");
   };


This code won’t work because the ``static_assert`` will always be evaluated to
`false` during the compilation—and hence will trigger a compilation error—even
when no code path would lead to instantiate the version with that template
specialization.

To get it to work, the evaluation of the ``static_assert`` needs to be slightly
deferred by making it dependent on a type—any type really, including empty
parameter packs—with the help of the
:ref:`m3ta::dependenBool() <function_dependentbool>` function.

.. code-block:: cpp
   
   template<int T_dividend, int T_divisor, typename ... T_Dummies>
   struct Base
   {
      static constexpr int value = T_dividend / T_divisor;
   };
   
   template<int T_dividend, typename ... T_Dummies>
   struct Base<T_dividend, 0, T_Dummies ...>
   {
       static_assert(
           m3ta::dependentBool<T_Dummies ...>(false),
           "Division by 0 not allowed."
       );
   };
   
   template<int T_dividend, int T_divisor>
   struct Divide
       : public Base<T_dividend, T_divisor>
   {};



.. _thenestedinitializerstrickformultidimensionalarrays:

The Nested Initializers Trick for Multidimensional Arrays
---------------------------------------------------------

The built-in C/C++ arrays come with a convenient syntax to initialize them: the
curly braces.

.. code-block:: cpp
   
   int array[2][3] = {
       0, 1, 2,
       3, 4, 5
   };


The definition of ``array`` produces a multidimensional array that represents
2 arrays of 3 elements each.

The same array could have been written with an extra pair of brace for each
inner dimension.

.. code-block:: cpp
   
   int array[2][3] = {
       {0, 1, 2},
       {3, 4, 5}
   };


With the introduction of the initializer lists in C++11, this syntax is now
usable within custom types. Reproducing the first syntax requires a
constructor to accept a single ``std::initializer_list`` argument, while the
nested braces syntax requires a parameter to be defined as nested initializer
lists.

.. code-block:: cpp
   
   template<typename T, std::size_t ... T_dimensions>
   class MultidimensionalArray
   {
   protected:
       using NestedInitializerLists =
           m3ta::NestedInitializerListsT<T, sizeof ... (T_dimensions)>;
       
   public:
       static constexpr std::size_t
       size()
       {
           return m3ta::product(T_dimensions ...);
       }
       
       MultidimensionalArray(NestedInitializerLists lists)
       { ... }
       
   private:
       std::array<T, size()> _data;
   };


The :ref:`m3ta::NestedInitializerLists <trait_nestedinitializerlists>` traits
allows to quickly define a new type with a specified number of
``std::initializer_list`` nested within each other, while the
:ref:`m3ta::product() <function_product>` function returns the total size of
the multidimensional array.

From there, iterating through each element is not as simple as iterating over
a linear container. Indeed, iterating through the ``std::initializer_list``\s at
the top level with the function ``begin()`` returns pointers to the deeper
levels. As such, the elements initialized with the nested braces syntax can
only be iterated through a recursive approach.

.. code-block:: cpp
   
   template<typename T, std::size_t ... T_shape>
   struct NestedInitializerListsProcessor;
   
   template<typename T, std::size_t T_first, std::size_t ... T_others>
   struct NestedInitializerListsProcessor<T, T_first, T_others ...>
   {
       using NestedInitializerLists =
           m3ta::NestedInitializerListsT<T, 1 + sizeof ... (T_others)>;
       
       template<typename T_Function>
       static void
       process(NestedInitializerLists lists, T_Function function)
       {
           if (lists.size() > T_first) {
               throw std::invalid_argument(
                   "Elements in excess within the initilizer list."
               );
           }
           
           for (auto nested : lists) {
               NestedInitializerListsProcessor<T, T_others ...>::
                   process(nested, function);
           }
           
           if (T_first != lists.size()) {
               std::size_t count =
                   m3ta::product(T_others ...) * (T_first - lists.size());
               
               for (; count > 0; --count) {
                   function(static_cast<T>(0));
               }
           }
       }
   };
   
   template<typename T, std::size_t T_last>
   struct NestedInitializerListsProcessor<T, T_last>
   {
       using InitializerList = m3ta::NestedInitializerListsT<T, 1>;
       
       template<typename T_Function>
       static void
       process(InitializerList list, T_Function function)
       {
           if (list.size() > T_last) {
               throw std::invalid_argument(
                   "Elements in excess within the initilizer list."
               );
           }
           
           std::for_each(list.begin(), list.end(), function);
           
           if (T_last != list.size()) {
               std::size_t count = T_last - list.size();
               for (; count > 0; --count) {
                   function(static_cast<T>(0));
               }
           }
       }
   };


The ``NestedInitializerListsProcessor`` helper can iterate through nested
``std::initializer_list``\s while allowing a custom function to be applied
on each element.

With this in hands, it is now possible to fully implement the constructor for
the nested braces syntax.

.. code-block:: cpp
   
   template<typename T, std::size_t ... T_dimensions>
   class MultidimensionalArray
   {
   protected:
       using NestedInitializerLists =
           m3ta::NestedInitializerListsT<T, sizeof ... (T_dimensions)>;
       
   public:
       static constexpr std::size_t
       size()
       {
           return m3ta::product(T_dimensions ...);
       }
       
       MultidimensionalArray(NestedInitializerLists lists)
       {
           auto iterator = _data.begin();
           NestedInitializerListsProcessor<T, T_dimensions ...>::
               process(
                   lists,
                   [&iterator](T value) { *(iterator++) = value; }
               );
       }
       
   private:
       std::array<T, size()> _data;
   };

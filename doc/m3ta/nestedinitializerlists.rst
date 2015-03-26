.. _reference_nestedinitializerlists:

Nested Initializer Lists
========================

.. code-block:: cpp
    
   #include <m3ta/nestedinitializerlists>


A given type wrapped within a number of nested ``std::initializer_list``.

In other words, ``m3ta::NestedInitializerListsT<int, 2>`` is the same as
``std::initializer_list<std::initializer_list<int>>``.

.. rst-class:: seealso
.. admonition:: See Also
   
   :ref:`thenestedinitializerstrickformultidimensionalarrays`.


Traits
------

.. _trait_nestedinitializerlists:

.. describe:: m3ta::NestedInitializerLists
   
   .. code-block:: cpp
      
      template<typename T, std::size_t T_levels>
      struct NestedInitializerLists
   
   
   :Template Parameters:
      - **T** – Inner type.
      - **T_levels** – Number of ``std::initializer_list`` wrapping the type
        ``T``.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type of the outer ``std::initializer_list``. Returns ``T`` if
      `T_levels` is 0.


Aliases
-------

.. _alias_nestedinitializerlistst:

.. describe:: m3ta::NestedInitializerListsT
   
   .. code-block:: cpp
      
      template<typename T, std::size_t T_levels>
      using NestedInitializerListsT =
          typename NestedInitializerLists<T, T_levels>::type;


Usage Examples
--------------

.. _usageexamples_nestedinitializerlists:

.. code-block:: cpp
   
   using Type1 = m3ta::NestedInitializerListsT<int, 0>; // int
   using Type2 = m3ta::NestedInitializerListsT<int, 1>; // std::initializer_list<int>
   using Type3 = m3ta::NestedInitializerListsT<int, 2>; // std::initializer_list<std::initializer_list<int>>

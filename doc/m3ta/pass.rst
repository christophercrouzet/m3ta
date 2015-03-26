.. _reference_pass:

Pass
====

.. code-block:: cpp
    
   #include <m3ta/pass>


Does nothing but passing the given template argument while taking an optional
parameter pack.

This is a convenient way to test a SFINAE expression while always returning
the required type.

.. rst-class:: seealso
.. admonition:: See Also
   
   :ref:`overloadresolutionusingsfinae`.


Traits
------

.. _trait_pass:

.. describe:: m3ta::Pass
   
   .. code-block:: cpp
      
      template<typename T, typename ... T_Dummies>
      struct Pass
   
   
   :Template Parameters:
      - **T** – Type to pass.
      - **T_Dummies** – Allows for some expressions to be ran through.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type ``T``.


Aliases
-------

.. _alias_passt:

.. describe:: m3ta::PassT
   
   .. code-block:: cpp
      
      template<typename T, typename ... T_Dummies>
      using PassT = typename Pass<T, T_Dummies ...>::type;


Usage Examples
--------------

.. _usageexamples_pass:

.. code-block:: cpp
   
   using Type1 = m3ta::PassT<void, int, float>; // void
   using Type2 = m3ta::PassT<short, int, float>; // short

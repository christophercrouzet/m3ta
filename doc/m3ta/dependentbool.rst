.. _reference_dependentbool:

Dependent Bool
==============

.. code-block:: cpp
    
   #include <m3ta/dependentbool>


Creates a dependency to some dummy types and returns a `bool` value.

.. rst-class:: seealso
.. admonition:: See Also
   
   :ref:`staticassert`.


Functions
---------

.. _function_dependentbool:

.. describe:: m3ta::dependentBool
   
   .. code-block:: cpp
      
      template<typename ... T_Dummies>
      constexpr bool
      dependentBool(bool value) noexcept
   
   
   :Template Parameters:
      - **T_Dummies** — Types to trigger the dependency.
   
   :Function Parameters:
      - **value** – `bool` value to return.
   
   
   .. rubric:: Returns
   
   The `bool` value passed as argument.


Usage Examples
--------------

.. _usageexamples_dependentbool:

.. code-block:: cpp
   
   bool value1 = m3ta::dependentBool<int, float>(true); // true
   bool value2 = m3ta::dependentBool<int, float>(false); // false
   

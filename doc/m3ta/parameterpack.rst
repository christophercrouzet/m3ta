.. _reference_parameterpack:

Parameter Pack
==============

.. code-block:: cpp
    
   #include <m3ta/parameterpack>


Pack of parameters.


Traits
------

.. _trait_parameterpack:

.. describe:: m3ta::ParameterPack
   
   .. code-block:: cpp
      
      template<typename ... T>
      struct ParameterPack
   
   
   :Template Parameters:
      - **T** – Types to pack.
   
   
   .. rubric:: Member Functions
   
   .. describe:: std::size_t size() noexcept
      
      Number of parameters.

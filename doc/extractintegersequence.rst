.. _reference_extractintegersequence:

Extract Integer Sequence
========================

.. code-block:: cpp
    
   #include <m3ta/extractintegersequence>


Extracts the integer sequence as an object instance, such as a `std::array`.


Traits
------

.. _trait_extractintegersequence:

.. describe:: m3ta::ExtractIntegerSequence
   
   .. code-block:: cpp
      
      template<typename T_Sequence>
      struct ExtractIntegerSequence
   
   
   :Template Parameters:
      - **T_Sequence** – Integer sequence.
   
   
   .. rubric:: Member Functions
   
   .. describe:: std::array<T, sizeof ... (T_values)> asArray()
      
      The integer sequence as a ``std::array``.


Usage Examples
--------------

.. _usageexamples_extractintegersequence:

.. code-block:: cpp
   
   auto array = m3ta::ExtractIntegerSequence<
       m3ta::IndexSequence<0, 1, 2, 4>
   >::asArray(); // std::array<std::size_t, 4>

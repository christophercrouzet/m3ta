.. _reference_removequalifiers:

Remove Qualifiers
=================

.. code-block:: cpp
   
   #include <m3ta/removequalifiers>


Removes any qualifiers from a given type.

Any ``const``, ``volatile`` and reference qualifiers are removed. As such,
the types ``T``, ``T &&``, ``const T &``, and so on, will all resolve to ``T``.

Arrays and pointers are preserved.
   


Traits
------

.. _trait_removequalifiers:

.. describe:: m3ta::RemoveQualifiers
   
   .. code-block:: cpp
      
      template<typename T>
      struct RemoveQualifiers
   
   
   :Template Parameters:
      - **T** – Type to remove the qualifiers from.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The type ``T`` without any qualifier.


Aliases
-------

.. _alias_removequalifierst:

.. describe:: m3ta::RemoveQualifiersT
   
   .. code-block:: cpp
      
      template<typename T>
      using RemoveQualifiersT = typename RemoveQualifiers<T>::type;


Usage Examples
--------------

.. _usageexamples_removequalifiers:

.. code-block:: cpp
   
   using Type1 = m3ta::RemoveQualifiersT<int>; // int
   using Type2 = m3ta::RemoveQualifiersT<const volatile int &>; // int
   using Type3 = m3ta::RemoveQualifiersT<int &&>; // int
   using Type4 = m3ta::RemoveQualifiersT<int *&>; // int *
   using Type5 = m3ta::RemoveQualifiersT<int[32]>; // int[32]

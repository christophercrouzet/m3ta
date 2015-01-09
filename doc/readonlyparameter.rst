.. _reference_readonlyparameter:

Read-Only Parameter
===================

.. code-block:: cpp
   
   #include <m3ta/readonlyparameter>


Resolves the most optimal read-only parameter signature for a given type.

In other words, it returns either ``T`` or ``const T&`` depending on the size
of a type ``T``.

.. note::
   
   Any ``const``, ``volatile`` and reference qualifiers are ignored during the
   resolution. As such, the types ``T``, ``T &&``, ``const T &``, and so on,
   will all resolve to the same type.
   


Traits
------

.. _trait_readonlyparameter:

.. describe:: m3ta::ReadOnlyParameter
   
   .. code-block:: cpp
      
      template<typename T>
      struct ReadOnlyParameter
   
   
   :Template Parameters:
      - **T** – Type to resolve.
   
   
   .. rubric:: Member Types
   
   .. describe:: type
      
      The most optimal read-only parameter signature for the type ``T``.


Aliases
-------

.. _alias_readonlyparametert:

.. describe:: m3ta::ReadOnlyParameterT
   
   .. code-block:: cpp
      
      template<typename T>
      using ReadOnlyParameterT = typename ReadOnlyParameter<T>::type;


Usage Examples
--------------

.. _usageexamples_readonlyparameter:

.. code-block:: cpp
   
   using Type1 = m3ta::ReadOnlyParameterT<char>; // char
   using Type2 = m3ta::ReadOnlyParameterT<std::complex<double>>; // const std::complex<double> &
   using Type3 = m3ta::ReadOnlyParameterT<double *>; // double*
   using Type4 = m3ta::ReadOnlyParameterT<double[32]>; // double[32]
   using Type5 = m3ta::ReadOnlyParameterT<const volatile char &>; // char
   using Type6 = m3ta::ReadOnlyParameterT<char &&>; // char

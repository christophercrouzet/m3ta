.. _faq:

FAQ
===

Why providing constexpr functions when traits would be enough?
--------------------------------------------------------------

Functions have a friendlier syntax and can be more flexible to use. Indeed,
variadic functions accept a variable number of heterogeneous arguments
while their trait counterpart only accept the values passed to the variadic
non-type template parameters that can be implicitely converted to a same type.
Furthermore, the non-type template parameters allowed are restricted to
a smaller subset which do not include floating-points or custom types.

.. code-block:: cpp
   
   m3ta::all(true, 2, 4.0f); //< Valid.
   m3ta::AllT<bool, true, 2, 4>::value; //< Valid, implicit conversions of int to bool.
   m3ta::AllT<bool, true, 2, 4.0f>::value; //< Invalid due to the use of a float.


Why also providing traits on top of existing functions then?
------------------------------------------------------------

Because functions can only return values, not types. Retrieving a constant value
might be enough in most cases but not when used with the tag dispatching
technique or in some SFINAE contexts where a type is expected to resolve which
overload to use. Hence why each existing function is being wrapped into a trait
inheriting from ``std::integral_constant``.

.. rst-class:: seealso
.. admonition:: See Also
   
   :ref:`tagdispatching`.

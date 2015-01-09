#ifndef M3TA_READONLYPARAMETER_H
#define M3TA_READONLYPARAMETER_H

#include <type_traits>

#include "removequalifiers.h"


namespace m3ta
{
namespace _readonlyparameter
{

template<typename T, bool T_optimize>
struct Base
{
    using type = RemoveQualifiersT<T>;
};

template<typename T>
struct Base<T, true>
{
    using type = typename std::conditional<
        sizeof(T) <= sizeof(void *),
        RemoveQualifiersT<T>,
        const RemoveQualifiersT<T> &
    >::type;
};

} // namespace _readonlyparameter.


//- Traits.

template<typename T>
struct ReadOnlyParameter
    : public _readonlyparameter::Base<
          T,
          (
              std::is_object<RemoveQualifiersT<T>>::value
              &&
              !std::is_array<RemoveQualifiersT<T>>::value
          )
      >
{};


//- Aliases.

template<typename T>
using ReadOnlyParameterT = typename ReadOnlyParameter<T>::type;

} // namespace m3ta.

#endif // M3TA_READONLYPARAMETER_H

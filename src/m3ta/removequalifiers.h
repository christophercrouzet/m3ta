#ifndef M3TA_REMOVEQUALIFIERS_H
#define M3TA_REMOVEQUALIFIERS_H

#include <cstddef>
#include <type_traits>


namespace m3ta
{

//- Traits.

template<typename T>
struct RemoveQualifiers
{
    using type =
        typename std::remove_cv<T>::type;
};

template<typename T>
struct RemoveQualifiers<T *>
{
    using type =
        typename std::add_pointer<typename RemoveQualifiers<T>::type>::type;
};

template<typename T, std::size_t T_size>
struct RemoveQualifiers<T[T_size]>
{
    using type =
        typename RemoveQualifiers<T>::type[T_size];
};

template<typename T>
struct RemoveQualifiers<T &>
    : public RemoveQualifiers<T>
{};

template<typename T>
struct RemoveQualifiers<T &&>
    : public RemoveQualifiers<T>
{};


//- Aliases.

template<typename T>
using RemoveQualifiersT = typename RemoveQualifiers<T>::type;

} // namespace m3ta.

#endif // M3TA_REMOVEQUALIFIERS_H

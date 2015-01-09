#ifndef M3TA_PASS_H
#define M3TA_PASS_H


namespace m3ta
{

//- Traits.

template<typename T, typename ...>
struct Pass
{
    using type = T;
};


//- Aliases.

template<typename T, typename ... T_Dummies>
using PassT = typename Pass<T, T_Dummies ...>::type;

} // namespace m3ta.

#endif // M3TA_PASS_H

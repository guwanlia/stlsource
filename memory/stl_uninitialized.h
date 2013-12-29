#ifndef _STL_UNINITIALIZED_H_
#define _STL_UNINITIALIZED_H_

#include "type_traits.h"

// fill n
template <typename FwdItor, typename Size, typename T>
inline FwdItor UninitFillN(FwdItor first, Size size, const T& value)
{
    return __UninitFillN(first, size, value, valueType(first));
}

template <typename FwdItor, typename Size, typename T, typename T1>
inline FwdItor __UninitFillN(FwdItor first, Size size, const T& value, T1*)
{
    typedef typename typeTraits<T1>::isPodType isPod;
    return __UninitFillNAux(first, size, value, isPod());
}

template <typename FwdItor, typename Size, typename T>
inline FwdItor __UninitFillNAux(FwdItor first, Size size, const T& value, trueType)
{
    return FillN(first, size, value);
}

template <typename FwdItor, typename Size, typename T>
inline FwdItor __UninitFillNAux(FwdItor first, Size size, const T& value, falseType)
{
    FwdItor cur = first;
    // exception missed
    for ( ; size > 0; --size, ++cur)
    {
	Construct(&*cur, value);
    }
    return cur;
}

// copy
template <typename InItor, typename FwdItor>
FwdItor uninitCopy(InItor first, InItor last, FwdItor result)

#endif /* _STL_UNINITIALIZED_H_ */

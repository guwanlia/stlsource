#ifndef _STL_UNINITIALIZED_H_
#define _STL_UNINITIALIZED_H_

#include "../type_traits.h"
#include "../stl_iterator.h"

//****fill n****
template <typename FwdItor, typename Size, typename T>
inline FwdItor UninitFillN(FwdItor first, Size size, const T& value)
{
    return __UninitFillN(first, size, value, ValueType(first));
}

template <typename FwdItor, typename Size, typename T, typename T1>
inline FwdItor __UninitFillN(FwdItor first, Size size, const T& value, T1*)
{
    typedef typename TypeTraits<T1>::isPodType isPod;
    return __UninitFillNAux(first, size, value, isPod());
}

template <typename FwdItor, typename Size, typename T>
inline FwdItor __UninitFillNAux(FwdItor first, Size size, const T& value, TrueType)
{
    return FillN(first, size, value);
}

template <typename FwdItor, typename Size, typename T>
FwdItor __UninitFillNAux(FwdItor first, Size size, const T& value, FalseType)
{
    FwdItor cur = first;
    // ignore exception
    for ( ; size > 0; --size, ++cur)
    {
	Construct(&*cur, value);
    }
    return cur;
}


//****copy****
template <typename InItor, typename FwdItor>
inline FwdItor UninitCopy(InItor first, InItor last, FwdItor result)
{
    return __UninitCopy(first, last, result, ValueType(result));
}

template <typename InItor, typename FwdItor, typename T>
inline FwdItor __UninitCopy(InItor first, InItor last, FwdItor result, T*)
{
    typedef typename TypeTraits<T>::isPodType isPod;
    return __UninitCopyAux(first, last, result, isPod());
}

template <typename InItor, typename FwdItor>
inline FwdItor __UninitCopyAux(InItor first, InItor last, FwdItor result, TrueType)
{
    return Copy(first, last, result);
}

template <typename InItor, typename FwdItor>
FwdItor __UninitCopyAux(InItor first, InItor last, FwdItor result, FalseType)
{
    FwdItor cur = result;
    // ignore exception
    for ( ; first != last; ++first, ++cur)
    {
	Construct(&*cur, *first);
    }
    return cur;
}



#endif /* _STL_UNINITIALIZED_H_ */

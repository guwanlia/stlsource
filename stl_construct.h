#ifndef _STL_CONSTRUCT_H_
#define _STL_CONSTRUCT_H_

#include "../stl_iterator.h"
#include "../type_traits.h"

//****constructor****
template <typename T1, typename T2>
inline void Construct(T1* ptr, const T2& value)
{
    new (ptr) T1(value);
}

//****destructor****
template <typename T>
inline void Destroy(T* ptr)
{
    ptr->~T();
}

template <typename FwdItor>
inline void Destroy(FwdItor first, FwdItor last)
{
    __Destroy(first, last, ValueType(first));
}

template <typename FwdItor, typename T>
inline void __Destroy(FwdItor first, FwdItor last, T*)
{
    typedef typename TypeTraits<T>::hasTrivDesor trivDesor;
    __DestroyAux(first, last, trivDesor());
}

template <typename FwdItor>
void __DestroyAux(FwdItor first, FwdItor last, FalseType)
{
    for ( ; first < last; ++first)
    {
	Destroy(&*first);
    }
}

template <typename FwdItor>
inline void __DestroyAux(FwdItor, FwdItor, TrueType) {}

//specialization
template <> 
inline void Destroy(char*, char*) {}

template <>
inline void Destroy(wchar_t*, wchar_t*) {} 

#endif /* _STL_CONSTRUCT_H_ */

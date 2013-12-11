#include <cstddef>

struct InItorTag {};
struct OutItorTag {};
struct FwdItorTag : public InItorTag {};
struct BiItorTag : public FwdItorTag {};
struct RndAccessItorTag : public BiItorTag {};

template <typename Category, typename T, typename Distance = ptrdiff_t,
	  typename Pointer = T*, typename Reference = T&>
struct Iterator
{
    typedef Category itorCategory;
    typedef T valueType;
    typedef Distance diffType;
    typedef Pointer ptr;
    typedef Reference ref;
};

template <typename T>
struct ItorTraits
{
    typedef typename T::itorCategory itorCategory;
    typedef typename T::valueType valueType;
    typedef typename T::diffType diffType;
    typedef typename T::ptr ptr;
    typedef typename T::ref ref;
};

template <typename T>
struct ItorTraits<T*>
{
    typedef RndAccessItorTag itorCategory;
    typedef T valueType;
    typedef ptrdiff_t diffType;
    typedef T* ptr;
    typedef T& ref;
};

template <typename T>
struct ItorTraits<const T*>
{
    typedef RndAccessItorTag itorCategory;
    typedef T valueType;
    typedef ptrdiff_t diffType;
    typedef const T* ptr;
    typedef const T& ref;
};

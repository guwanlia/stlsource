#ifndef _TYPE_TRAITS_H_
#define _TYPE_TRAITS_H_

struct TrueType{};
struct FalseType{};

template <typename type>
struct TypeTraits
{
    typedef TrueType thisDummyMemberMustBeFirst;
    typedef FalseType hasTrivDflContor;
    typedef FalseType hasTrivCopyContor;
    typedef FalseType hasTrivAsgnOpt;
    typedef FalseType hasTrivDesor;
    typedef FalseType isPodType;
};

template <>
struct TypeTraits<char>
{
    typedef TrueType hasTrivDflContor;
    typedef TrueType hasTrivCopyContor;
    typedef TrueType hasTrivAsgnOpt;
    typedef TrueType hasTrivDesor;
    typedef TrueType isPodType;
};

template <>
struct TypeTraits<signed char>
{
    typedef TrueType hasTrivDflContor;
    typedef TrueType hasTrivCopyContor;
    typedef TrueType hasTrivAsgnOpt;
    typedef TrueType hasTrivDesor;
    typedef TrueType isPodType;
};

template <>
struct TypeTraits<unsigned char>
{
    typedef TrueType hasTrivDflContor;
    typedef TrueType hasTrivCopyContor;
    typedef TrueType hasTrivAsgnOpt;
    typedef TrueType hasTrivDesor;
    typedef TrueType isPodType;
};

template <>
struct TypeTraits<short>
{
    typedef TrueType hasTrivDflContor;
    typedef TrueType hasTrivCopyContor;
    typedef TrueType hasTrivAsgnOpt;
    typedef TrueType hasTrivDesor;
    typedef TrueType isPodType;
};

template <>
struct TypeTraits<unsigned short>
{
    typedef TrueType hasTrivDflContor;
    typedef TrueType hasTrivCopyContor;
    typedef TrueType hasTrivAsgnOpt;
    typedef TrueType hasTrivDesor;
    typedef TrueType isPodType;
};

template <>
struct TypeTraits<int>
{
    typedef TrueType hasTrivDflContor;
    typedef TrueType hasTrivCopyContor;
    typedef TrueType hasTrivAsgnOpt;
    typedef TrueType hasTrivDesor;
    typedef TrueType isPodType;
};

template <>
struct TypeTraits<unsigned int>
{
    typedef TrueType hasTrivDflContor;
    typedef TrueType hasTrivCopyContor;
    typedef TrueType hasTrivAsgnOpt;
    typedef TrueType hasTrivDesor;
    typedef TrueType isPodType;
};

template <>
struct TypeTraits<long>
{
    typedef TrueType hasTrivDflContor;
    typedef TrueType hasTrivCopyContor;
    typedef TrueType hasTrivAsgnOpt;
    typedef TrueType hasTrivDesor;
    typedef TrueType isPodType;
};

template <>
struct TypeTraits<unsigned long>
{
    typedef TrueType hasTrivDflContor;
    typedef TrueType hasTrivCopyContor;
    typedef TrueType hasTrivAsgnOpt;
    typedef TrueType hasTrivDesor;
    typedef TrueType isPodType;
};

template <>
struct TypeTraits<float>
{
    typedef TrueType hasTrivDflContor;
    typedef TrueType hasTrivCopyContor;
    typedef TrueType hasTrivAsgnOpt;
    typedef TrueType hasTrivDesor;
    typedef TrueType isPodType;
};

template <>
struct TypeTraits<double>
{
    typedef TrueType hasTrivDflContor;
    typedef TrueType hasTrivCopyContor;
    typedef TrueType hasTrivAsgnOpt;
    typedef TrueType hasTrivDesor;
    typedef TrueType isPodType;
};

template <>
struct TypeTraits<long double>
{
    typedef TrueType hasTrivDflContor;
    typedef TrueType hasTrivCopyContor;
    typedef TrueType hasTrivAsgnOpt;
    typedef TrueType hasTrivDesor;
    typedef TrueType isPodType;
};

template <typename T>
struct TypeTraits<T*>
{
    typedef TrueType hasTrivDflContor;
    typedef TrueType hasTrivCopyContor;
    typedef TrueType hasTrivAsgnOpt;
    typedef TrueType hasTrivDesor;
    typedef TrueType isPodType;
};

#endif /* _TYPE_TRAITS_H_ */

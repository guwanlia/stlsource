#ifndef _TYPE_TRAITS_H_
#define _TYPE_TRAITS_H_

struct trueType{};
struct falseType{};

template <typename type>
struct typeTraits
{
    typedef trueType thisDummyMemberMustBeFirst;
    typedef falseType hasTrivDflContor;
    typedef falseType hasTrivCopyContor;
    typedef falseType hasTrivAsgnOpt;
    typedef falseType hasTrivDesor;
    typedef falseType isPodType;
};

template <>
struct typeTraits<char>
{
    typedef trueType hasTrivDflContor;
    typedef trueType hasTrivCopyContor;
    typedef trueType hasTrivAsgnOpt;
    typedef trueType hasTrivDesor;
    typedef trueType isPodType;
};

template <>
struct typeTraits<signed char>
{
    typedef trueType hasTrivDflContor;
    typedef trueType hasTrivCopyContor;
    typedef trueType hasTrivAsgnOpt;
    typedef trueType hasTrivDesor;
    typedef trueType isPodType;
};

template <>
struct typeTraits<unsigned char>
{
    typedef trueType hasTrivDflContor;
    typedef trueType hasTrivCopyContor;
    typedef trueType hasTrivAsgnOpt;
    typedef trueType hasTrivDesor;
    typedef trueType isPodType;
};

template <>
struct typeTraits<short>
{
    typedef trueType hasTrivDflContor;
    typedef trueType hasTrivCopyContor;
    typedef trueType hasTrivAsgnOpt;
    typedef trueType hasTrivDesor;
    typedef trueType isPodType;
};

template <>
struct typeTraits<unsigned short>
{
    typedef trueType hasTrivDflContor;
    typedef trueType hasTrivCopyContor;
    typedef trueType hasTrivAsgnOpt;
    typedef trueType hasTrivDesor;
    typedef trueType isPodType;
};

template <>
struct typeTraits<int>
{
    typedef trueType hasTrivDflContor;
    typedef trueType hasTrivCopyContor;
    typedef trueType hasTrivAsgnOpt;
    typedef trueType hasTrivDesor;
    typedef trueType isPodType;
};

template <>
struct typeTraits<unsigned int>
{
    typedef trueType hasTrivDflContor;
    typedef trueType hasTrivCopyContor;
    typedef trueType hasTrivAsgnOpt;
    typedef trueType hasTrivDesor;
    typedef trueType isPodType;
};

template <>
struct typeTraits<long>
{
    typedef trueType hasTrivDflContor;
    typedef trueType hasTrivCopyContor;
    typedef trueType hasTrivAsgnOpt;
    typedef trueType hasTrivDesor;
    typedef trueType isPodType;
};

template <>
struct typeTraits<unsigned long>
{
    typedef trueType hasTrivDflContor;
    typedef trueType hasTrivCopyContor;
    typedef trueType hasTrivAsgnOpt;
    typedef trueType hasTrivDesor;
    typedef trueType isPodType;
};

template <>
struct typeTraits<float>
{
    typedef trueType hasTrivDflContor;
    typedef trueType hasTrivCopyContor;
    typedef trueType hasTrivAsgnOpt;
    typedef trueType hasTrivDesor;
    typedef trueType isPodType;
};

template <>
struct typeTraits<double>
{
    typedef trueType hasTrivDflContor;
    typedef trueType hasTrivCopyContor;
    typedef trueType hasTrivAsgnOpt;
    typedef trueType hasTrivDesor;
    typedef trueType isPodType;
};

template <>
struct typeTraits<long double>
{
    typedef trueType hasTrivDflContor;
    typedef trueType hasTrivCopyContor;
    typedef trueType hasTrivAsgnOpt;
    typedef trueType hasTrivDesor;
    typedef trueType isPodType;
};

template <typename T>
struct typeTraits<T*>
{
    typedef trueType hasTrivDflContor;
    typedef trueType hasTrivCopyContor;
    typedef trueType hasTrivAsgnOpt;
    typedef trueType hasTrivDesor;
    typedef trueType isPodType;
};

#endif /* _TYPE_TRAITS_H_ */

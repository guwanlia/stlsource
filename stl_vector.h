#ifndef _STL_VECTOR_H_
#define _STL_VECTOR_H_

#include <cstddef>
#include "memory/stl_alloc.h"

template <typename T, typename Alloc = MyAlloc>
class Vector
{
public:
    typedef T valueType;
    typedef valueType* ptr;
    typedef valueType* itor;
    typedef valueType& ref;
    typedef size_t sizeType;
    typedef ptrdiff_t diffType;

protected:
    typedef SimpleAlloc<valueType, Alloc> dataAlloc;
    itor start;
    itor finish;
    itor endOfStore;

    void insertAux(itor, const T&);
    void deallocate(){
	if (start)
	{
	    dataAlloc::deallocate(start, end-start);
	}
    }

    itor allocAndFill(sizeType size, const T& value){
	itor result = dataAlloc::allocate(size);
	uninitFillN(result, size, value);
	return result;
    }
    void fillInit(sizeType size, const T& value){
	start = allocAndFill(size, value);
	finish = start + size;
	end = finish;
    }

public:
    itor getBegin() { return start; }
    itor getEnd() { return finish; }
    sizeType size() const { return sizeType(finish-start); }
    sizeType capacity() const { return sizeType(endOfStore-start); }
    bool empty() const { return start==finish; }
    ref operator[](sizeType size) { return *(start + n); }

    Vector() : start(0), finish(0), endOfStore(0) {}
    Vector(sizeType size, const T& value) { fillInit(size, value); }
    explicit Vector(sizeType size) { fillInit(size, T()); }

    ~Vector() {
	destroy(start, finish);
	deallocate();
    }
    ref front() { return *start; }
    ref back() { return *(finish-1); }

    void pushBack(const T& value) {
	if (finish != endOfStore)
	{
	    construct(finish, value);
	    ++finish;
	}
	else
	{
	    insertAux(finish, value);
	}
    }

    void popBack() {
	--finish;
	destroy(finish);
    }

    itor erase(itor pos) {
	if (pos+1 != finish)
	{
	    copy(pos+1, finish, pos);
	}
	--finish;
	destroy(finish);
	return pos;
    }
    void resize(sizeType newSize, const T& value) {
	if (newSize < size())
	{
	    erase(start, newSize, finish);
	}
	else
	{
	    insert(finish, newSize, value);
	}
    }
    void resize(sizeType newSize) { resize(newSize, T()); }
    void clear() { erase(start, finish); }
};

#endif /* _STL_VECTOR_H_ */

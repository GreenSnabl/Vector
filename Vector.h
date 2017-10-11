#ifndef VECTOR_H
#define VECTOR_H
#include <initializer_list>
#include <algorithm>
#include <iostream>

//          template for a vector container 
//
// Stroustrup - Programming Principles and Practice
//
//


template<typename T> 
class Vector {
public:
    Vector<T>()                                              // default constructor
        : sz{0}, elem{nullptr}, space{0}
        {
        }
    
    explicit Vector<T>(int s)                 // constructor with given number of
        : sz{s}, elem{new T[s]}, space{s}     // elements initialized to 0
        {
            for (int i = 0; i < sz; ++i)
            elem[i] = 0;    
        }
    
    Vector<T>(std::initializer_list<T> lst)                  // list constructor
        : sz{lst.size()}, elem{new T[sz]}, space{sz}
        {
            std::copy(lst.begin(), lst.end(), elem);            
        } 
    
    Vector<T>(const Vector& arg)                             // copy constructor
        : sz{arg.sz}, elem{new T[arg.sz]}, space{arg.sz}
        {
            for(int i = 0; i < arg.sz; ++i) elem[i] = arg.elem[i];
        }
    
    Vector<T>& operator=(const Vector<T>&);                  // copy assignment

    
    Vector<T>(Vector<T>&& arg)                               // move constructor
        : sz{arg.sz}, elem{new T[arg.sz]}, space{arg.sz}
        {
            arg.space = 0;
            arg.sz = 0;
            arg.elem = nullptr;
        }
        
    Vector<T>& operator=(Vector<T>&&);                        // move assignment

    
    
    T& operator[](int n) {return elem[n];}                   // get elements through braces 
    T operator[](int n) const {return elem[n];}              // const version / no write access
   
    ~Vector<T>() {delete[] elem;}                            // destructor


    void reserve(int);
    void resize(int);
    void push_back(const T&);
    
    int size() const {return sz;}   
    int capacity() const { return space;}
        
    
private:    
    int sz;
    T* elem;
    int space;
};



template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& arg)            // copy operator &
{                                       
    if(this == &arg) return *this;
    
    if(arg.sz <= space)
    {
        for(int i = 0; i < arg.sz; ++i) elem[i] = arg.elem[i];
        sz = arg.sz;
        return *this;
    
    }
    T *p = new T[arg.sz];
    for(int i = 0; i < arg.sz; ++i) p[i] = arg.elem[i];
    delete[] elem;
    space = sz = arg.sz;
    elem = p;
    return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& arg)                 // move operator &&
{
    delete[] elem;
    elem = arg.elem;
    sz = arg.sz;
    space = arg.space;
    arg.elem = nullptr;
    arg.sz = 0;
    arg.space = 0;
    return *this;

}
template <typename T>
void Vector<T>::reserve(int newalloc)
{
    if(newalloc <= space) return;
    T *p = new T[newalloc];
    for(int i = 0; i < sz; ++i) p[i] = elem[i];
    delete[] elem;
    elem = p;
    space = newalloc;
}
template <typename T>
void Vector<T>::resize(int newsize)
{
    reserve(newsize);
    for(int i = sz; i < newsize; ++i) elem[i] = 0;
    sz = newsize;
}
template <typename T>
void Vector<T>::push_back(const T& d)
{
    if(space == 0)
        reserve(8);
    else if(sz==space)
        reserve(2*space);
    elem[sz] = d;
    ++sz;
}

template <typename T>
void printer(const Vector<T>& v)
{
    for(int i = 0; i < v.size(); ++i)
        std::cout << v[i] << "\t";
    std::cout << "\n";
}

#endif 


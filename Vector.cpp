#include "Vector.h"


Vector& Vector::operator=(const Vector& arg)            // copy operator &
{                                       
    if(this == &arg) return *this;
    
    if(arg.sz <= space)
    {
        for(int i = 0; i < arg.sz; ++i) elem[i] = arg.elem[i];
        sz = arg.sz;
        return *this;
    
    }
    double *p = new double[arg.sz];
    for(int i = 0; i < arg.sz; ++i) p[i] = arg.elem[i];
    delete[] elem;
    space = sz = arg.sz;
    elem = p;
    return *this;
}

Vector& Vector::operator=(Vector&& arg)                 // move operator &&
{
    delete[] elem;
    elem = arg.elem;
    sz = arg.sz;
    arg.elem = nullptr;
    arg.sz = 0;
    return *this;

}

void Vector::reserve(int newalloc)
{
    if(newalloc <= space) return;
    double *p = new double[newalloc];
    for(int i = 0; i < sz; ++i) p[i] = elem[i];
    delete[] elem;
    elem = p;
    space = newalloc;
}

void Vector::resize(int newsize)
{
    reserve(newsize);
    for(int i = sz; i < newsize; ++i) elem[i] = 0;
    sz = newsize;
}

void Vector::push_back(double d)
{
    if(space == 0)
        reserve(8);
    else if(sz==space)
        reserve(2*space);
    elem[sz] = d;
    ++sz;
}

void printer(Vector& v)
{
   for(int i = 0; i < v.size(); ++i)
       std::cout << v[i] << "\t";
   std::cout << "\n";
}
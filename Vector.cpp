#include "Vector.h"


Vector& Vector::operator=(const Vector& arg)            // copy operator &
{                                                       
    double *p = new double[arg.sz];
    std::copy(arg.elem, arg.elem + arg.sz, p);
    delete[] elem;
    elem = p;
    sz = arg.sz;
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
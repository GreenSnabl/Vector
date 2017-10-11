#ifndef VECTOR_H
#define VECTOR_H
#include <initializer_list>
#include <algorithm>
#include <iostream>

class Vector {
public:
    Vector()                                            // default constructor
        : sz{0}, elem{nullptr}, space{0}
        {
        }
    
    Vector(int s)                                       // constructor with
        : sz{s}, elem{new double[s]}, space{s}          // set size
        {
            for (int i = 0; i < sz; ++i)
            elem[i] = 0;    
        }
    
    Vector(std::initializer_list<double> lst)           // list constructor
        : sz{lst.size()}, elem{new double[sz]}, space{sz}
        {
            std::copy(lst.begin(), lst.end(), elem);            
        } 
    
    Vector(const Vector& arg)                           // copy constructor
        : sz{arg.sz}, elem{new double[arg.sz]}, space{arg.sz}
        {
            for(int i = 0; i < arg.sz; ++i) elem[i] = arg.elem[i];
        }
    
    Vector& operator=(const Vector&);                   // copy assignment
    
    Vector(Vector&& arg)                                // move constructor
        : sz{arg.sz}, elem{new double[arg.sz]}, space{arg.sz}
        {
            arg.space = 0;
            arg.sz = 0;
            arg.elem = nullptr;
        }
        
    Vector& operator=(Vector&&);                        // move assignment
    
    double& operator[](int n) {return elem[n];}         // get elements through braces 
    double operator[](int n) const {return elem[n];}    // const version / no write access
   
    ~Vector() {delete[] elem;}                          // destructor

    void push_back(double);
    int size() const {return sz;}   
    int capacity() const { return space;}
    
private:    
    
    void resize(int);
    void reserve(int);
    int sz;
    double* elem;
    int space;
    
};

void printer(Vector&);                                  // helper function

#endif 


#ifndef VECTOR_H
#define VECTOR_H

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
        : sz{lst.size()}, elem{new double[sz]}
        {
            std::copy{lst.begin(), lst.end(), elem};            
        }
    
    Vector(const Vector& arg)                           // copy constructor
        : sz{arg.sz}, elem{new double[arg.sz]}
        {
            std::copy{arg.elem, arg.elem+sz, elem};        
        }
    
    Vector& operator=(const Vector&);                   // copy assignment
    
    Vector(Vector&& arg)                                // move constructor
        : sz{arg.sz}, elem{new double[arg.sz]}
        {
            arg.sz = 0;
            arg.elem = nullptr;
        }
    Vector& operator=(Vector&&);                        // move assignment
    
    double& operator[](int n) {return elem[n];}         // 
    double operator[](int n) const {return elem[n];}
    
    
    
    
    ~Vector() {delete[] elem;}                          // destructor

    void resize();
    void reserve();
    
    int size() const {return sz;}   
    
private:    
    int sz;
    double* elem;
    int space;
    
};

#endif 


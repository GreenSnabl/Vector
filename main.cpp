#include "Vector.h"


int main() {
   
    Vector<int> vi{1,2,3,4,5};
    Vector<int> vi2(5);
    Vector<double> vd{1.1,2.2,3.3,4.4,5.5};
    Vector<double> vd2(5);
    Vector<char> vc{'a', 'b', 'c', 'd', 'e'};
    Vector<char> vc2(5);
   
    vi.push_back(6);
    vi2.push_back(7);
    vd.push_back(6.6);
    vd2.push_back(7.7);
    vc.push_back('f');
    vc2.push_back('g');
    
    printer(vi);
    printer(vi2);
    printer(vd);
    printer(vd2);
    printer(vc);
    printer(vc2);
    
    std::cout << "vc.size(): " << vc.size() << "\t" << "vc.capacity: " << vc.capacity() << "\n";
    std::cout << "vi.size(): " << vi.size() << "\t" << "vi.capacity: " << vi.capacity() << "\n"; 
    
    vi.resize(4);
    vc.resize(17);
    
    std::cout << "resized vc.size(): " << vc.size() << "\t" << "vc.capacity: " << vc.capacity() << "\n";
    std::cout << "resized vi.size(): " << vi.size() << "\t" << "vi.capacity: " << vi.capacity() << "\n"; 
        
    return 0;
}


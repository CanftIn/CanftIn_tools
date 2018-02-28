#include <iostream>

#include "../Ref_ptr.h"

using namespace std;
using namespace CAN;

class Case
{
public:
    Case(){}
};


int main()
{
    int b = 10;
    int *a = &b;

    RefPtr<int> m_ref_ptr(a);
    RefPtr<int> other_ref(m_ref_ptr);
    
    return 0;
}
class A {};

class B {
public:
    B() = default;                      // constructor
    B &operator= (const B &) = default; // assignment operator
    B(const B &) = default;             // copy constructor
    ~B() = default;                     // destructor

    // C++11:
    B(B && b);                          // move constructor
    B & operator = (B && b);            // move assignment operator
};

int main()
{
    {
        A a1;
        A a2(a1);
        A a3 = a2;
        a2 = a3;
    }

    {
        B b1;
        B b2(b1);
        B b3 = b2;
        b2 = b3;
    }
}

// A, B entirely equivalent: C++ compiler always creates
// 	default constructor;
//  default destructor;
//	default assignment operator;
//	default copy constructor
//
// C++11: C++ compiler creates
//  move constructor
//  move assignment operator
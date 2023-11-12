class A {};

class B {
public:
    B() = default;                      // constructor
    B& operator= (const B&) = default; // assignment operator
    B(const B&) = default;             // copy constructor
    ~B() = default;                     // destructor
};

int main()
{
    {
        A a1;       // default ctor
        A a2(a1);   // copy ctor
        A a3 = a2;  // assignment operator
        a2 = a3;    // ditto
        // destructor - as it goes out of scope.
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
// class A: this is plain vanilla C++; nothing new here.
// class B: we get the 'default' keywords...and we get 'delete'
//          keywords too.
// I have done this a lot in the past for small classes that should not be copy
// constructed or assigned.

class A
{
public:

    A() : _anInt(0)
    {
        // other things here in the constructor
    }

private:

    int _anInt;

    // disable the assignment operator (=) and copy constructor by making private.
    A &operator= (const A &) {}
    A (const A &) {};
};

class B
{
public:
    B() : _anInt(0) {};
    // C++11:
    B &operator= (const B &) = delete;
    B (const B &) = delete;

private:
    int _anInt;
};

int main()
{
    A a;
    // A a2(a); // copy constructor
    // A a3 = a;   // assignment operator

    B b;
    // B b2(b);
    // B b3 = b;
}

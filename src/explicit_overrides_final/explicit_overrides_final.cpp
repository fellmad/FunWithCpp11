struct Base {
    virtual void some_func(float);
};

struct Derived : Base {
    virtual void some_func(int);
};

// line 6: OUCH. compiler lets you override function with different signature.

struct A {
    virtual void some_func(float);
};

struct B : A {
    virtual void some_func(int) override; // ill-formed - doesn't override a base class method
};

// line 16: OK: get compile-time error

class D {
public:
    virtual void foo() final;
    void bar() final;
};

class E final : public D {
    void foo();
};

class F : public E {};

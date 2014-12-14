class A
{
public:
    virtual void foo() final;
    void bar() final;
};

class B final : public A
{
    void foo();
};

class C : public B
{
};
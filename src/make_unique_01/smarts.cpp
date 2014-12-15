#include <memory>
#include <iostream>
#include <string>

class Big {
    unsigned char data[10000];
    std::string name;

public:
    Big(const std::string& name) : name(name)
    {}

    void Greet()
    {
        std::cout << "hi from " << name << std::endl;
    }
    ~Big()
    {
        std::cout << name << " destructor" << std::endl;
    }
};

int main()
{
    {
        std::unique_ptr <Big> pointer_to_big(new Big("one"));
        pointer_to_big->Greet();
    }

    Big* pbig2 = new Big("two");
    {
        std::unique_ptr <Big> smart_big2_pointer(pbig2);
        pbig2->Greet();
        smart_big2_pointer->Greet();

        // i LOVE the FACT that the destructor is called here!!!
    }

    pbig2->Greet(); // crash! that's good, actually.

    return 0;
}

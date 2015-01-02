#include <memory>
#include <iostream>
#include <string>

class Big {

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

private:

    unsigned char data[10000];
    std::string name;
};

int main()
{
    {
        std::unique_ptr <Big> pointer_to_big(new Big("one"));
        pointer_to_big->Greet();
    }

    Big* big_DUMB_pointer = new Big("two");
    {
        // all your pointer now belong to me:
        std::unique_ptr <Big> big_Smart_Pointer(big_DUMB_pointer);

        big_DUMB_pointer->Greet();
        big_Smart_Pointer->Greet();

        // i LOVE the FACT that the destructor is called here - leaving scope.
    }

    // pbig2->Greet(); // crash! that's good, actually.
}
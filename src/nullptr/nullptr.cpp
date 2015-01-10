// http://en.cppreference.com/w/cpp/types/nullptr_t

#include <cstddef>	// #define's NULL
#include <iostream>
#include <string>
#include <memory>

void f(void*) {
    std::cout << "Pointer to void overload\n";
}

void f(int*) {
   std::cout << "Pointer to integer overload\n";
}
 
void f(double*) {
   std::cout << "Pointer to double overload\n";
}
 
void f(std::nullptr_t) {
   std::cout << "null pointer overload\n";
}
 
int main() {
    int* intPointer(nullptr);
    double* doublePointer{nullptr};
 
    f(intPointer);
    f(doublePointer);
    f(nullptr);  // would be ambiguous without void f(nullptr_t)
    f("");

    // fun: uncomment the next line...
    // f(NULL);

    class Robot
    {
    public:

        Robot(const std::string& name, const int& height_in_micrometers) :
            _name(name), _height_in_micrometers(height_in_micrometers)
        {}

        void Speak() {std::cout << "my name is " << _name << std::endl;}

        ~Robot() {std::cout << "deleting " << _name << std::endl;}

    private:
        std::string _name;
        int _height_in_micrometers;
    };

    auto robot1 = new Robot("robby one", 1002);  // OLD. Don't DO THIS anymore. see below.
    robot1->Speak();
    robot1 = nullptr;   // legal, but stupid: should have paired with delete
    delete robot1;      // delete of nullptr is always safe
    // but now we have a leak. UGH.

    {
        std::unique_ptr <Robot> robot2 {new Robot {"robby 2", 1234}};
        robot2->Speak();
        robot2 = nullptr;
        // no NEED to DELETE robot2!
    }

    std::cout << typeid(nullptr).name() << std::endl;
    std::cout << "sizeof nullptr: " << sizeof nullptr << std::endl << std::endl;
}
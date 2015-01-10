// munged from: http://www.reddit.com/r/cpp/comments/2l202i/iterate_over_a_list_of_types/

#include <iostream>
#include <string>
#include <memory>
#include <vector>

// abstract base class ("interface" in any other language...):
class IF {
public:
    virtual std::string str() = 0;
};

class A : public IF {
public:
    std::string str() {
        return "A";
    }
};

class B : public IF {
public:
    std::string str() {
        return "B";
    }
};

int main() {

    // create a list of interface pointers:

    std::vector<std::shared_ptr<IF>> pointer_list {
        std::make_shared<A>(),
        std::make_shared<B>(),
        std::make_shared<A>(),
        std::make_shared<A>()
    };

    for (const auto& pointer : pointer_list) {
        std::cout << pointer->str() << std::endl;

        const auto& another_instance {pointer};
    }
}

// line 42: can't do that with unique_ptr
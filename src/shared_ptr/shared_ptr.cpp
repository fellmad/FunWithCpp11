// stolen from: http://www.reddit.com/r/cpp/comments/2l202i/iterate_over_a_list_of_types/

#include <iostream>
#include <string>
#include <memory>
#include <vector>

class IF
{
public:
    virtual std::string str() = 0;
};

class A : public IF
{
public:
    std::string str() {
        return "A";
    }
};

class B : public IF
{
public:
    std::string str() {
        return "B";
    }
};

int main()
{
    std::vector<std::shared_ptr<IF>> list {
        std::make_shared<A>(),
        std::make_shared<B>(),
        std::make_shared<A>(),
        std::make_shared<A>()
    };

    for (auto l : list)
        std::cout << l->str() << std::endl;
}
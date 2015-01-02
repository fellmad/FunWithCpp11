#include <string>

class Robot {
public:
    Robot() : Robot(2, 1.0, "robbie")
    {}

    Robot(const int& arms, const double& age, const std::string& name)
        : arm_count(arms)
        , age(age)
        , name(name)
    {}

    Robot(const std::string& name) : Robot(3, 4.567, name)
    {}

private:
    int arm_count;
    double age;
    std::string name;
};

int main()
{
    Robot robot1;
    Robot robot2(3, 2.1, "bob");
    Robot robot3("fred");
}

// see: http://en.cppreference.com/w/cpp/language/initializer_list
// fails to build with vs2012 and earlier
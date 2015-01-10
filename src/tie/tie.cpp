#include <iostream> 
#include <tuple>

using Mytuple = std::tuple < int, double, int, double > ; // FUN: no ugly #define!

Mytuple multTuple(Mytuple const incoming, const short multiplier) {
    const Mytuple outgoing {
        std::get<0>(incoming) * multiplier,
        std::get<1>(incoming) * multiplier,
        std::get<2>(incoming) * multiplier,
        std::get<3>(incoming) * multiplier
    };
    return outgoing;
}

int main()
{
    const Mytuple tuple1 {0, 1.1, 2, 3.3};

    // unpack the tuple into individual variables via get():
    auto val0 = std::get<0>(tuple1);
    auto val1 = std::get<1>(tuple1);
    auto val2 = std::get<2>(tuple1);
    auto val3 = std::get<3>(tuple1);

    std::cout << " " << val0;
    std::cout << " " << val1;
    std::cout << " " << val2;
    std::cout << " " << val3 << std::endl;

    const Mytuple tuple2 {4, 5.5, 6, 7.7};
    int     val4 {};
    double  val5 {};
    int     val6 {};
    double  val7 {};

    // unpack the tuple into individual variables via get():
    std::tie(val4, val5, val6, val7) = tuple2;

    // not 'bound' to tuple2:
    val5 = 1234.123515;

    std::cout << " " << std::get<0>(tuple2);
    std::cout << " " << std::get<1>(tuple2);
    std::cout << " " << std::get<2>(tuple2);
    std::cout << " " << std::get<3>(tuple2) << std::endl;

    const auto tuple3 = multTuple(tuple2, 3);
    std::cout << " " << std::get<0>(tuple3);
    std::cout << " " << std::get<1>(tuple3);
    std::cout << " " << std::get<2>(tuple3);
    std::cout << " " << std::get<3>(tuple3) << std::endl;

    return (0);
}
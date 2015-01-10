#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>

// from: C++ standard: 5.1.2 Lambda expressions
void abssort(float* x, const unsigned N) {
    std::sort(
        x,
        x + N,
        [] (float a, float b) {return std::abs(a) < std::abs(b); }
    );
}

int main() {
    float naked_floats[] {
            24.5f,
             6.7f,
             0.0f,
         12345.56f,
         -4321.45f
    };

    abssort(naked_floats, _countof(naked_floats));

    std::cout << "absolute-value sorted floats:" << std::endl;
    for (const auto& floater : naked_floats) {
        std::cout << floater << std::endl;
    }
}

// line 2: C++ namespaced math.h
// line 24: _countof() is great.

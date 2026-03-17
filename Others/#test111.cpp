#include <iostream>
#include <version>

int main()
{
#if defined(__cpp_lib_ranges)
    std::cout << "__cpp_lib_ranges is defined, C++20 range supported.\n";
#else
    std::cout << "__cpp_lib_ranges not defined, C++20 range may not be supported.\n";
#endif
    return 0;
}
#include <iostream>

namespace my_traits {
    template <typename T>
    struct is_integral : std::false_type {};
    template <>
    struct is_integral<int> : std::true_type {};
    template <>
    struct is_integral<const int> : std::true_type {};
    template <>
    struct is_integral<bool> : std::true_type {};
    template <>
    struct is_integral<const bool> : std::true_type {};
    template <>
    struct is_integral<char> : std::true_type {};
    template <>
    struct is_integral<const char> : std::true_type {};

    template <typename T>
    struct is_floatin_poin : std::false_type {};
    template <>
    struct is_integral<float> : std::true_type {};
    template <>
    struct is_integral<const float> : std::true_type {};
    template <>
    struct is_integral<double> : std::true_type {};
    template <>
    struct is_integral<const double> : std::true_type {};
    template <>
    struct is_integral<long double> : std::true_type {};
    template <>
    struct is_integral<const long double> : std::true_type {};

    template <typename T>
    struct is_pointer : std::false_type {};
    template <typename T>
    struct is_pointer<T*> : std::false_type {};
    template <typename T>
    struct is_pointer<const T*> : std::false_type {};

    template <typename T>
    struct remove_const { using value = T; };
    
}

int main() {
    std::cout << my_traits::is_integral<float>::value;
}
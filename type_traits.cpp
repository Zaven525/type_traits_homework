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
    struct remove_const { using type = T; };
    template <typename T>
    struct remove_const<const T> { using type = T; };

    template <typename T>
    struct add_const { using type = const T; };
    
    template <typename T, typename U>
    struct is_same : std::false_type {};
    template <typename T>
    struct is_same<T, T> : std::true_type {};

    template <bool B, typename T, typename F>
    struct Conditional { using type = T; };
    template <typename T, typename F>
    struct Conditional<false, T, F> { using type = F; };

    
}

int main() {
    std::cout << my_traits::is_integral<float>::value;
}
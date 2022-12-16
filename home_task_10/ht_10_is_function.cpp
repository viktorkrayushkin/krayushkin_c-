#include <iostream>

template <typename T>
struct is_function {
    static const bool value = false;
};

template <typename F, typename... Args>
struct is_function<F(Args ...)> {
    static const bool value = true;
};

template <typename F, typename... Args>
struct is_function<F(Args ..., ...)> {
    static const bool value = true;
};

const int Func(...) { return 1; };

int main() {
    std::cout << is_function<decltype(Func)>::value << std::endl;
    std::cout << is_function<decltype(main)>::value << std::endl;
}
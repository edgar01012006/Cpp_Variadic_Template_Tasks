#include <iostream>

// option 1
// auto sum() {
//     return 0;
// }

// template<typename... Types>
// auto sum(const Types&... args) {
//     return (... + args);
// }

// option 2
template<typename... Types>
auto sum(const Types&... args) {
    if constexpr(sizeof...(args) > 0) {
        return (... + args);
    }
    return 0;
}


int main() {
    std::cout << "sum = " << sum(1, 2, 3, 4, 5) << std::endl;
    std::cout << "sum = " << sum() << std::endl;
}
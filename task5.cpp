#include <iostream>

// option 1
// bool anyTrue() {
//     return false;
// }

// template<typename... Types>
// bool anyTrue(const Types&... args) {
//     return (... || (args ? true : false));
// }

// option 2
template<typename... Types>
bool anyTrue(const Types&... args) {
    if constexpr (sizeof...(args) > 0) {
        return (... || (args ? true : false));
    }
    return false;
}

int main() {
    std::cout << "anyTrue = " << anyTrue(1, 2, 0, 3, 4, 5) << std::endl;
    std::cout << "anyTrue = " << anyTrue() << std::endl;
}
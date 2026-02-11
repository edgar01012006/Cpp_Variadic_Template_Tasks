#include <iostream>

// option 1
// bool allTrue() {
//     return true;
// }

// template<typename T, typename... Types>
// bool allTrue(const T& item, const Types&... args) {
//     return (item ? true : false) && allTrue(args...);

// }

// option 2
template<typename... Types>
bool allTrue(const Types&... args) {
    if constexpr(sizeof...(args) > 0) {
        return (... && (args ? true : false));
    }
    return true;
}

int main() {
    std::cout << "allTrue = " << allTrue(1, 2, 0, 3, 4, 5) << std::endl;
    std::cout << "allTrue = " << allTrue() << std::endl;
}
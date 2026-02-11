#include <iostream>

// option 1
// size_t countArgs() {
//     return 0;
// }

// template<typename T, typename... Types>
// size_t countArgs(T item, Types... args) {
//     return 1 + countArgs(args...);
// }

// option 2
template<typename... Types>
size_t countArgs(Types... args) {
    return sizeof...(args);
}

int main() {
    std::cout << "countArgs = " << countArgs(1, 2, 3, 4, 5) << std::endl;
    std::cout << "countArgs = " << countArgs() << std::endl;
}
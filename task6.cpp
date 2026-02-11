#include <iostream>

// option 1
// template<typename T1, typename T2>
// auto minValue(const T1& item1, const T2& item2) {
//     return (item1 < item2 ? item1 : item2);
// }

// template<typename T1, typename T2, typename... Types>
// auto minValue(const T1& item1, const T2& item2, const Types&... args) {
//     return (item1 < item2 ? minValue(item1, args...) : minValue(item2, args...));
// }

// option 2
template<typename T1, typename T2, typename... Types>
auto minValue(const T1& item1, const T2& item2, const Types&... args) {
    if constexpr(sizeof...(args) > 0) {
        return (item1 < item2 ? minValue(item1, args...) : minValue(item2, args...));
    }
    return (item1 < item2 ? item1 : item2); 
}

int main() {
    std::cout << "minValue = " << minValue(1, 2, 45, -30, 3) << std::endl;
}

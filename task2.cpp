#include <iostream>

// option 1
// void printAll() {
//     // empty    
// }

// template<typename T, typename... Types>
// void printAll(const T& item, const Types&... args) {
//     std::cout << item << std::endl;
//     printAll(args...);
// }

// option 2
template<typename T>
class AddNewLine {
    private:
        const T& m_item;
    public:
        AddNewLine(const T& item) : m_item { item } {}
        friend std::ostream& operator<<(std::ostream& ostr, const AddNewLine& out) {
            ostr << out.m_item << std::endl;
            return ostr;
        }
};

template <typename... Types>
void printAll(const Types&... args) {
    if constexpr (sizeof...(args) > 0) {
        (std::cout << ... << AddNewLine(args));
    }
}

int main() {
    printAll(1, 2, 3, 4, 5);
    printAll();
}
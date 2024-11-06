#include <iostream>

static int hello(int x) {  // Определение функции hello с модификатором static
    return x + 1;
}

int main() {
    int result = hello(5);  // Вызов функции hello
    std::cout << "Result: " << result << std::endl;
    return 0;
}
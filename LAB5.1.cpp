#include <iostream>
#include <string_view>
#include <cassert>

int countOnes(std::string_view str) {
    int count = 0;
    for (char ch : str) {
        if (ch == '1') {
            ++count;
        }
    }
    return count;
}

void runTests() {
    assert(countOnes("000000") == 0);
    assert(countOnes("") == 0);

    assert(countOnes("001100") == 2);
    assert(countOnes("1010101") == 4);

    assert(countOnes("111111") == 6);
    assert(countOnes("1") == 1);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    runTests();
    return 0;
}
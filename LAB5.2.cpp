#include <iostream>
#include <string_view>
#include <cassert>

std::string_view secondWord(std::string_view str) {
    size_t firstSpace = str.find(' ');
    if (firstSpace == std::string_view::npos) {
        return "";
    }

    size_t start = str.find_first_not_of(' ', firstSpace + 1);
    if (start == std::string_view::npos) {
        return "";
    }

    size_t end = str.find(' ', start);
    return str.substr(start, end - start);
}

void runTests() {
    assert(secondWord("Hello world") == "world");
    assert(secondWord("Hello my dear") == "my");
    assert(secondWord("") == "");
    assert(secondWord(" ") == "");
    assert(secondWord(" a ") == "a");
    assert(secondWord("a  ") == "");
    assert(secondWord("a  b") == "");
    assert(secondWord("hello     world    dear") == "");

    assert(secondWord("first second") == "second");
    assert(secondWord("first    second    third") == "second");
    assert(secondWord("   leadspace") == "");
    assert(secondWord("leadspace     second") == "second");
    assert(secondWord("word") == "");

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    runTests();
    return 0;
}
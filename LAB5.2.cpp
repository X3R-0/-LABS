#include <iostream>
#include <string_view>
#include <cassert>

size_t findSpace(std::string_view string)
{
    for (size_t i = 0; i < string.length(); i++)
    {
        if (string[i] == ' ')
        {
            return i;
        }
    }
    return size_t(-1);
}

std::string_view secondWord(std::string_view str)
{
    {
        size_t index = findSpace(str);
        if (index == size_t(-1))
            return "";
        str = str.substr(index + 1);
    }

    {
        size_t index = findSpace(str);
        if (index == size_t(-1))
            return str;
        str = { &str[0], index };
    }

    return str;
}

void runTests() 
{
    assert(secondWord("Hello world") == "world");
	assert(secondWord("Hello my dear") == "my");
	assert(secondWord("") == "");
	assert(secondWord(" ") == "");
	assert(secondWord(" a ") == "a");
	assert(secondWord("a  ") == "");
	assert(secondWord("a  b") == "");
	assert(secondWord("hello     world    dear") == "");
    std::cout << "All tests passed successfully!" << std::endl;
}

int main()
{
    runTests();
    return 0;
}
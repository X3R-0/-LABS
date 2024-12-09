#include <iostream>

struct FruitCounts {
    int apples;
    int pears;
    int oranges;
};

int main() {
    FruitCounts fruits;

    std::cout << "Apples: ";
    std::cin >> fruits.apples;

    std::cout << "Pears: ";
    std::cin >> fruits.pears;

    std::cout << "Oranges: ";
    std::cin >> fruits.oranges;

    bool finalCondition = false;

    {
        bool applesCondition = fruits.apples > 5;
        bool pearsCondition = fruits.pears < 8;
        bool orangesCondition = fruits.oranges == 2 * fruits.apples;

        finalCondition = applesCondition && pearsCondition && orangesCondition;
    }

    if (finalCondition) {
        std::cout << "Hello" << std::endl;
    }

    return 0;
}
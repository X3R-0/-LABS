#include <iostream>
#include <span>
#include <cassert>

void productWithInfiniteLoop(std::span<int> inputOutput, std::span<int> coefficients) {
    // Убедимся, что длины массивов одинаковы
    assert(inputOutput.size() == coefficients.size());

    int index = 0;
    while (true) {
        if (index >= inputOutput.size()) {
            break; // Завершение бесконечного цикла вручную
        }
        inputOutput[index] *= coefficients[index];
        ++index;
    }
}

void productWithWhileLoop(std::span<int> inputOutput, std::span<int> coefficients) {
    // Убедимся, что длины массивов одинаковы
    assert(inputOutput.size() == coefficients.size());

    int index = 0;
    while (index < inputOutput.size()) {
        inputOutput[index] *= coefficients[index];
        ++index;
    }
}

void productWithForLoop(std::span<int> inputOutput, std::span<int> coefficients) {
    // Убедимся, что длины массивов одинаковы
    assert(inputOutput.size() == coefficients.size());

    for (size_t index = 0; index < inputOutput.size(); ++index) {
        inputOutput[index] *= coefficients[index];
    }
}

int main() {
    int inputOutputArr[] = {1, 2, 3, 4};
    int coefficientsArr[] = {2, 4, 6, 8};

    std::span<int> inputOutput = inputOutputArr;
    std::span<int> coefficients = coefficientsArr;

    productWithInfiniteLoop(inputOutput, coefficients);
    for (int num : inputOutput) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int inputOutputArr2[] = {1, 2, 3, 4};
    inputOutput = inputOutputArr2;
    productWithWhileLoop(inputOutput, coefficients);
    for (int num : inputOutput) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int inputOutputArr3[] = {1, 2, 3, 4};
    inputOutput = inputOutputArr3;
    productWithForLoop(inputOutput, coefficients);
    for (int num : inputOutput) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
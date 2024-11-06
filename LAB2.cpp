#include <string.h>
#include <iostream>

struct TwoInts
{
    int a;
    int b;
};

struct StructWithArray
{
    int arr[4];
    int* someNumber;
};

int main()
{
    // Создаем экземпляр структуры TwoInts и инициализируем его значениями 5 и 7
    TwoInts i2 = { };
    i2.a = 5;
    i2.b = 7;

    // Выводим значения a и b структуры i2
    std::cout << i2.a << std::endl; // Вывод: 5
    std::cout << i2.b << std::endl; // Вывод: 7
    
    // Создаем две структуры StructWithArray и инициализируем первую ячейку массива arr
    StructWithArray s = { };
    s.arr[0] = 10;

    StructWithArray s1 = { };
    s1.arr[0] = 15;

    // Указатель на структуру s
    StructWithArray* sPointer = &s;
    sPointer->arr[0] = 20; // Изменяем значение s.arr[0] через указатель

    // Проверяем текущее значение s.arr[0]
    std::cout << s.arr[0] << std::endl; // Вывод: 20
    s.arr[0] = 25; // Прямое изменение значения s.arr[0]
    std::cout << s.arr[0] << std::endl; // Вывод: 25
    sPointer->arr[0] = 30; // Изменение значения s.arr[0] через указатель снова
    std::cout << s.arr[0] << std::endl; // Вывод: 30

    // Переназначаем указатель sPointer на s1
    sPointer = &s1;
    sPointer->arr[0] = 35; // Изменяем значение s1.arr[0] через указатель
    std::cout << s.arr[0] << std::endl; // Вывод: 30 (значение s не изменилось, изменился s1)
    std::cout << s1.arr[0] << std::endl; // Вывод: 35

    // Создаем массив структур и присваиваем указатель на элемент arr[3] структуры structArray[0]
    StructWithArray structArray[2] = { };
    structArray[0].arr[3] = 77;
    structArray[1].someNumber = &structArray[0].arr[3]; // someNumber в structArray[1] указывает на structArray[0].arr[3]

    // Переназначаем указатель sPointer на s
    sPointer = &s;
    int* pointer = &sPointer->arr[3]; // pointer указывает на s.arr[3]
    s.arr[3] = 72; // Изменяем значение s.arr[3]
    std::cout << *pointer; // Вывод: 72 (значение по адресу s.arr[3])

    // Создаем экземпляр структуры memory и заполняем его нулями с помощью memset
    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray));

    return 0;
}
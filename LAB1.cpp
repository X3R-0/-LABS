#include <iostream>

int main() {
    int i=69;
    int number=72;
    i=i+number;

    int array [3]={0};

    int *iPointer=&i;
    number=*iPointer;

    *iPointer=15;

    iPointer=&array[0];
    iPointer+=2;
    
    array[0]=5;
    *iPointer=6;

    std::cout << "i="<< i <<std::endl;
    std::cout << "number="<< number <<std::endl;
    std::cout << "array=" << array[0] << " " << array[1] << " " << array[2];

}
	
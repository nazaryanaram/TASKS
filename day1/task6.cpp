/*
	
Create a program that declares an integer variable, a pointer variable, and a reference variable. Assign the address of the integer to the pointer and manipulate the data using both the pointer and the reference. Output the results to ensure an understanding of how pointers and references are used to access and modify data. | 

*/

#include <iostream>

int main()
{
	int num = 7;
	int* ptr = &num;
	
	std::cout << "Addres num: " << ptr << std::endl;
	// adding num with pointer
	std::cout << *ptr + 3 << std::endl;
	
}

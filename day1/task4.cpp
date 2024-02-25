/*
	
Write a program that contains functions for basic arithmetic operations (add, subtract, multiply, divide). Each function should accept two parameters and return the result of the operation. Test these functions by invoking them from the main function. This task introduces the concept of functions, parameter passing, and return types
*/

#include <iostream>

int add(int arg1, int arg2);
int sub(int arg1, int arg2);
float Div(float arg1, float arg2);
int mul(int arg1, int arg2);

int main()
{
	float num1 = 0;
	float num2 = 0;
	// input numbers from user
	std::cout << "Enter num1: ";
	std::cin >> num1;
	std::cout << "Enter num2: ";
	std::cin >> num2;

	// result add, sub, div and mul functions
	std::cout << "Add -> " << add(num1, num2) << std::endl;
	std::cout << "Sub -> " << sub(num1, num2) << std::endl;
	std::cout << "Div -> " << Div(num1, num2) << std::endl;
	std::cout << "Mul -> " << mul(num1, num2) << std::endl;
	return 0;
}

int add(int arg1, int arg2)
{
	return arg1 + arg2;
}

int sub(int arg1, int arg2)
{
	return arg1 - arg2;
}

float Div(float arg1, float arg2)
{
	if (arg2 == 0)
	{
		std::cout << "invalid combination!" << std::endl;
		return 0;
	}

	return arg1 / arg2;
}

int mul (int arg1, int arg2)
{
	return arg1 * arg2;
}

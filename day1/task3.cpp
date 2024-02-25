/*
	Develop a program that asks the user for a number and then, using if-else statements, checks whether the number is positive, negative, or zero. Extend the program with a switch-case to assign a grade (A, B, C, D, F) based on a number range (e.g., 90-100 for A). Lastly, implement a loop that prints numbers from 1 to 10. This task teaches the fundamental control structures for program flow.
*/

#include <iostream>

int main()
{
	int num = 0;
	// user input
	std::cout << "Please enter number: ";
	std::cin >> num;

	// number negative pozitive or zero
	if (num < 0)
	{
		std::cout << "number is negative" << std::endl;
	} else if (num > 0)
	{
		std::cout << "number is pozitive" << std::endl;
	} else {
		std::cout << "number is zero" << std::endl;
	}
	
	// state number
	switch(num)
	{
		case 90:
			std::cout << 'A' << std::endl;
			break;
		case 80:
			std::cout << 'B' << std::endl;
			break;
		case 70:
			std::cout << 'C' << std::endl;
			break;
		case 60:
			std::cout << 'D' << std::endl;
			break;
		default:
			std::cout << 'F' << std::endl;
			break;
	}
	
	// printing numbers 1-10
	for (int i = 1; i <= 10; ++i)
	{
		std::cout << i << std::endl;
	}
	return 0;
}

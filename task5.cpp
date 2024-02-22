/*
	Implement a program where you define an array of integers and populate it with some values. Write functions to find the maximum, minimum, and average values in the array. Additionally, create a string variable and demonstrate basic string operations like concatenation and length calculation. This task focuses on data collection management using arrays and strings.

*/

#include <iostream>

int max_element(int* arr, int size);
int min_element(int* arr, int size);
int average_element(int* arr, int size);

int main()
{
	const int size = 5;
	int arr[size];

	// input array elements
	for (int i = 0; i < size; ++i)
	{
		scanf("%d", &arr[i]);
	}

	// min, max and average elements of array
	std::cout << "Max element -> " << max_element(arr, size) << std::endl;
	std::cout << "Min element -> " << min_element(arr, size) << std::endl;
	std::cout << "Average element -> " << average_element(arr, size) << std::endl;


	// manipulation with strings
	std::string num1 = "Hello ";
	std::string num2 = "World ";
	
	std::cout << num1 + num2;
	std::cout << num2.length();
}

int max_element(int* arr, int size)
{
	int max = arr[0];
	for (int i = 1; i < size; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}

int min_element(int* arr, int size)
{
	int min = arr[0];
	for (int i = 1; i < size; ++i)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	return min;
}

int average_element(int* arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		sum += arr[i];
	}
	return sum / size;
}

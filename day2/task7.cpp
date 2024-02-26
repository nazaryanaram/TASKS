// okay a

#include <iostream>

void insertionSort(int* arr, int size);
void bubbleSort(int* arr, int size);
void selectionSort(int* arr, int size);
void sort_array (int* arr, int size, void (*foo) (int*, int));

int main()
{
    int size = 0;
    int select = 0;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    int* arr = new int[size];

    std::cout << "Enter elements of array: ";
    // initalization array
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }
    
    std::cout << "(1 for bubble sort, 2 for selection sort, 3 for insertion sort)" << std::endl;
    std::cin >> select;

    switch(select)
    {
        case 1:
            sort_array(arr, size, bubbleSort);
            break;
        case 2:
            sort_array(arr, size, selectionSort);
            break;
        case 3:
            sort_array(arr, size, insertionSort);
            break;
        default:
            std::cout << "Invalid sorting index!\a" << std::endl;
            return 0;
    }

    std::cout << "Sorting array: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}

void bubbleSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(int* arr, int size)
{
    int min_index;
    for (int i = 0; i < size - 1; ++i) {
        min_index = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        std::swap(arr[i], arr[min_index]);
    }
}

void insertionSort(int* arr, int size) {
    int  key, j;
    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void sort_array (int* arr, int size, void (*foo) (int*, int))
{
    foo(arr, size);
}


#include <iostream>

void insertionSort(int* arr, int size);
void bubbleSort(int* arr, int size);
void selectionSort(int* arr, int size);
void printOptionsStrategy();

typedef enum {
    BUBBLE_SORT,
    SELECTION_SORT,
    INSERTION_SORT
} SortingStrategy;

// typedef function pointer for sorting function
typedef void (*SortingFunction)(int* array, int size);

typedef struct {
    SortingStrategy value;
    SortingFunction sortFunc;
} SortingOption;

SortingOption sorting_options[] = {
    {BUBBLE_SORT, bubbleSort},
    {SELECTION_SORT, selectionSort},
    {INSERTION_SORT, insertionSort}
};

int main()
{
    // enter size of array from user
    int size = 0;
    do {
        std::cout << "Enter size of array: ";
        std::cin >> size;
        if (size <= 0) {
            std::cout << "Invalid input" << std::endl;
        }
    } while (size <= 0);

    int* array = new int(size);

    // input elements from user
    std::cout << "Enter elements of array: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    // print options and select sort function from user
    int select = 0;
    std::cout << "\t\tSelect Sorting Strategy" << std::endl;
    printOptionsStrategy();
    std::cout << "Input Index -> ";
    std::cin >> select;
    
    // Select option 
     SortingOption option;
    switch(select) {
        case 1:
            option = sorting_options[BUBBLE_SORT];
            break;
        case 2:
            option = sorting_options[SELECTION_SORT];
            break;
        case 3:
            option = sorting_options[INSERTION_SORT];
            break;
        default:
            std::cout << "Sorting Strategy not found!" << std::endl;
            return 0;
    }

    option.sortFunc(array, size);

    // print sorted array
    std::cout << "Sorted Array -> ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
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

void printOptionsStrategy()
{
    std::cout << "\tIndex 1 for Bubble Sort" << std::endl;
    std::cout << "\tIndex 2 for Selection Sort" << std::endl;
    std::cout << "\tIndex 3 for Insertion Sort" << std::endl;
}
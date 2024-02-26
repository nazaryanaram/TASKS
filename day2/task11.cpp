#include <iostream>
#include <fstream>
#include <string>

#define MAX_SIZE 1000

void insertionSort(int* arr, int size);
void bubbleSort(int* arr, int size);
void selectionSort(int* arr, int size);
void printOptionsStrategy();
int* readArrayOfIntegersFromFile(const std::string fileName, int& size);
void saveSortedArrayInFile(const std::string fileName, int* array, int size);

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
    const std::string fileName = "text.txt";
    int size = 0;
    int* array = readArrayOfIntegersFromFile(fileName, size);

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

    // mov sorted array in file
    saveSortedArrayInFile("text.txt", array, size);
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

int* readArrayOfIntegersFromFile(const std::string fileName, int& size)
{
    int* array = new int[MAX_SIZE];

    std::ifstream inFile(fileName);
    if(!inFile) {
        std::cout << "Fail not found" << std::endl;
        return nullptr;
    }

    int num;
    while (inFile >> num && size < MAX_SIZE) {
        array[size] = num;
        ++size;
    }

    inFile.close();
    return array;
}

void saveSortedArrayInFile(const std::string fileName, int* array, int size)
{
    std::ofstream outFile(fileName);
    if (!outFile) {
        std::cout << "File not found" << std::endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        outFile << array[i] << std::endl;
    }

    outFile.close();
}
#include <iostream>
using namespace std;

// Function prototypes
void printArray(int arr[], int size);
int binarySearch(int arr[], int left, int right, int target, int &comparisons);
int linearSearch(int arr[], int size, int target, int &comparisons);
void sortArray(int arr[], int size);

int main() {
    const int SIZE = 20;
    int arr[SIZE] = {5, 12, 23, 34, 45, 56, 67, 78, 89, 90, 
                     11, 22, 33, 44, 55, 66, 77, 88, 99, 100};

    // Display the original array
    cout << "Original Array:" << endl;
    printArray(arr, SIZE);

    // Sort the array for binary search
    sortArray(arr, SIZE);
    cout << "\nSorted Array:" << endl;
    printArray(arr, SIZE);

    // Prompt the user for a target value
    int target;
    cout << "\nEnter a value to search for: ";
    cin >> target;
    cout << "\nSearching for value: " << target << endl;

    // Perform Linear Search
    int linearComparisons = 0;
    int linearResult = linearSearch(arr, SIZE, target, linearComparisons);

    // Perform Binary Search
    int binaryComparisons = 0;
    int binaryResult = binarySearch(arr, 0, SIZE - 1, target, binaryComparisons);

    // Display the results
    cout << "\nResults:" << endl;
    if (linearResult != -1)
        cout << "Linear Search: Found at index " << linearResult 
             << " with " << linearComparisons << " comparisons.\n";
    else
        cout << "Linear Search: Value not found after " << linearComparisons << " comparisons.\n";

    if (binaryResult != -1)
        cout << "Binary Search: Found at index " << binaryResult 
             << " with " << binaryComparisons << " comparisons.\n";
    else
        cout << "Binary Search: Value not found after " << binaryComparisons << " comparisons.\n";

    return 0;
}

// Function for Linear Search
int linearSearch(int arr[], int size, int target, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == target)
            return i; // Return index if found
    }
    return -1; // Not found
}

// Function for Binary Search (iterative)
int binarySearch(int arr[], int left, int right, int target, int &comparisons) {
    comparisons = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (arr[mid] == target)
            return mid; // Found the target
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Not found
}

// Function to print the array elements
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Simple Selection Sort to sort the array in ascending order
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

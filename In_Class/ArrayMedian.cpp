#include <iostream>
using namespace std;

// Function prototypes
double median(int*, int);
void displayArray(int*, int);

int main()
{
    // An array with an odd number of elements
    int odd[] = { 1, 2, 3, 4, 5, 6, 7 };

    // An array with an even number of elements
    int even[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    // Display the odd array.
    cout << "The odd-numbered set of values is:";
    displayArray(odd, 7);

    // Display the odd array's median value.
    cout << "The median is: " << median(odd, 7) << endl << endl;

    // Display the even array.
    cout << "The even-numbered set of values is:";
    displayArray(even, 8);

    // Display the even array's median value.
    cout << "The median is: " << median(even, 8) << endl << endl;

    return 0;
}

// Function median 
// This function calculates and returns the median value of a sorted array.
// It accepts a pointer to the first element of the array and the number of elements in the array.
double median(int* arr, int num)
{
    double med; // Variable to store the median value

    // Check if the number of elements is even
    if (num % 2 == 0)
    {
        // For even number of elements:
        // - Calculate the indices of the two middle elements.
        //   mid1 is the higher middle index, and mid2 is the lower middle index.
        int mid1 = num / 2;
        int mid2 = (num / 2) - 1;
        
        // Retrieve the two middle values using pointer arithmetic.
        // Add the two values together and divide by 2.0 to obtain the average.
        med = ((*(arr + mid1) + *(arr + mid2)) / 2.0);
    }
    else
    {
        // For odd number of elements:
        // - The median is the element located at the center of the array.
        //   Since the array is already sorted, simply return the element at index num/2.
        med = *(arr + (num / 2));
    }

    // Return the computed median.
    return med;
}

// Function displayArray 
// This function prints the contents of an integer array.
// It accepts a pointer to the first element of the array and the number of elements in the array.
void displayArray(int* arr, int size)
{
    cout << endl;
    for (int k = 0; k < size; k++)
    {
        cout << arr[k] << "  ";
    }
    cout << endl;
}

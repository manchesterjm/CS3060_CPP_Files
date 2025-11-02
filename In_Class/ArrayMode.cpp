#include <iostream> // Enables input/output stream operations (e.g., cout, cin)

using namespace std; // Allows using names from the std namespace without the std:: prefix

// Function prototype: getMode
// Purpose: Find the mode (most frequent element) in an array.
// Parameters:
//   - int* array: Pointer to the first element of the array (using the memory address)
//   - int size: Number of elements in the array
int getMode(int*, int);

// Function prototype: makeArray
// Purpose: Dynamically allocate an array of a given size on the heap.
// Returns: A pointer to the first element of the newly allocated array.
int* makeArray(int);

int main() 
{
    // Define a constant integer SIZE representing the number of elements in the test array.
    const int SIZE = 11;

    // Define an array 'test' with SIZE elements.
    // Note: When 'test' is passed to a function, it decays into a pointer, i.e., using the memory address of test[0].
    int test[SIZE] = { 0, 12, 54, 62, 234, 62, 25, 16, 27, 66, 92 };

    // Variable to store the mode of the test array.
    int mode;
    
    // Call getMode passing the array 'test' (as a pointer) and its size.
    mode = getMode(test, SIZE);

    // Check if the mode is -1, which indicates that no mode was found.
    if (mode == -1)
    {
        cout << "The test set has no mode.\n";
    }
    else
    {
        // If a mode was found, output it.
        cout << "\nThe mode of the test set is: " << mode << endl;
    }

    // Return 0 to indicate the program executed successfully.
    return 0;
}

// Function: makeArray
// Purpose: Dynamically allocate an array of integers on the heap and return a pointer to it.
// Parameter: int size - number of elements to allocate.
// Returns: A pointer to the first element of the allocated array.
int* makeArray(int size)
{
    // 'new int[size]' allocates memory for an array of 'size' integers on the heap.
    // It returns the memory address of the first element, which is stored in the pointer 'ptr'.
    int* ptr = new int[size];

    // Return the pointer so that the caller can use the allocated memory.
    return ptr;
}

// Function: getMode
// Purpose: Determine the mode (most frequent element) in the array.
// Parameters:
//   - int* array: Pointer to the first element of the array (using the memory address)
//   - int size: Number of elements in the array.
int getMode(int* array, int size)
{
    // Declare a pointer 'freq' to store the frequency counts, initializing it to nullptr.
    int* freq = nullptr;

    int mode = -1;      // Variable to store the mode; remains -1 if no mode exists.
    int highest = 0;    // Variable to track the highest frequency count.
    int element = 0;    // Index of the element with the highest frequency.
    int count = 0;      // Loop counter variable.

    // Allocate memory for the frequency array using makeArray.
    // 'freq' now holds the memory address of the dynamically allocated frequency array.
    freq = makeArray(size);

    // Initialize the frequency array by setting each memory location (dereferenced via the pointer) to 0.
    for (count = 0; count < size; count++)
    {
        // Using array indexing here, which internally uses the memory address.
        freq[count] = 0; // Alternatively: *(freq + count) = 0;
    }

    // Calculate the frequency of each element in the input array.
    // The outer loop picks an element; the inner loop counts its occurrences.
    for (int count1 = 0; count1 < size; count1++)
    {
        for (int count2 = 0; count2 < size; count2++)
        {
            // Compare the two elements by dereferencing the pointer with pointer arithmetic.
            // If elements match, increment the frequency counter.
            if (*(array + count2) == *(array + count1)) {
                // Dereferences the pointer 'freq' (using the memory address of freq[count1]) and increments its value.
                (*(freq + count1))++;
            }
        }
    }

    // Identify the element with the highest frequency.
    highest = *freq; // Dereferences 'freq' to read the first frequency value.
    element = 0;     // Assume initially that the first element has the highest frequency.

    // Loop through the frequency array (accessing via their memory addresses) to find the highest frequency.
    for (count = 1; count < size; count++)
    {
        if (*(freq + count) > highest)
        {
            highest = *(freq + count); // Update the highest frequency by dereferencing the pointer at the current index.
            element = count;           // Update the index of the element with the highest frequency.
        }
    }

    // Warning: The dynamically allocated memory for 'freq' is not freed.
    // Setting freq to nullptr does not deallocate the memory, causing a memory leak.
    delete[] freq; // Deallocate the memory previously allocated for the freq array
	freq = nullptr; // Set pointer to nullptr to avoid dangling references

    // If the highest frequency is greater than 1, a mode exists.
    if (highest > 1)
    {
        // Retrieve the mode from the original array by dereferencing the pointer at the index 'element'.
        mode = *(array + element);
    }
    // Return the mode (or -1 if no mode was found).
    return mode;
}

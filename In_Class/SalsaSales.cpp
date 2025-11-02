#include <iostream> // allows communications to the console
#include <string> // allows you to use strings
#include <iomanip> // allows use to manipulate our output to look nice
#include <array> // allows the use of arrays
#include <vector> // dynamic lists

using namespace std; // allows us to avoid having to do std::cin and std::cout

int getTotal(int[], int); // function to get the total number of jars
int posOfLargest(int[], int); // function to get the largest amount of salsa sold
int posOfSmallest(int[], int); // function to get the least amount of salsa sold
int getAvg(int[], int); // function to find the av

const int SALSA_TYPE = 5; // constant number of salsas

int main()
{
	//array<string,SALSA_TYPE> salsa_names; // array for salsa types
	string types[SALSA_TYPE] = {"mild", "medium", "sweet", "hot", "zesty"}; // initialize the salsa array
	int sales[SALSA_TYPE] = {0}; // array for sales of salsa, initialize everything to 0
	int total_sold = 0; // var to store total salsas sold
	int most_sold; // var to store the position in the array of the salsa that was most sold
	int least_sold; // var to store the position in the array of the salsa that was least sold
	int avg_sold; // var to store the average sales

	for (int count = 0; count < SALSA_TYPE; count++)
		{
			cout << "Please enter the amount sold for " << types[count] << " : "; // ask for input
			cin >> sales[count]; // get input and store
			while (sales[count] < 0) // check input is 0 or more
			{
				cout << "Jars sold must be 0 or more" << "Please re-enter: "; // no input or negative input
				cin >> sales[count]; // store input
			}
		}

	total_sold = getTotal(sales, SALSA_TYPE); // find total sales
	most_sold = posOfLargest(sales, SALSA_TYPE); // find most sold
	least_sold = posOfSmallest(sales, SALSA_TYPE); // find least sold
	avg_sold = getAvg(sales, SALSA_TYPE);  // find the avg sold

	cout << endl << endl; // make the output look good
	cout << "Salsa sales report\n\n";
	cout << "Name     Jars Sold\n";
	cout << "------------------\n";

	for (int type = 0; type < SALSA_TYPE; type++) // loop through the array
		{
			cout << left << setw(6) << types[type] << ": " << right << setw(9) << sales[type] << endl; // print each type of salsa
		}

	cout << "\nTotal Sales: " << right << setw(4) << total_sold << " jars" << endl;
	cout << "Highest Sold: " << right << setw(3) << sales[most_sold] << " of the " << types[most_sold] << endl;
	cout << "Least Sold: " << right << setw(5) << sales[least_sold] << " of the " << types[least_sold] << endl;
	cout << "Avg Sold: " << right << setw(7) << avg_sold << " jars" << endl;
	return 0;
}

// function to find the total amount of sales
int getTotal (int arr[], int count)
	{
		int total = 0;
		for (int pos = 0; pos < count; pos++) // loop through array
			{
				total = total + arr[pos]; // tally up sales, could use += but I like this
			}
		return total; // returned the total tally
	}

// function to find the largest amount of salsa sold
int posOfLargest (int arr[], int count)
	{
		int largest = -1;
		int position = 0;
		for (int pos = 0; pos < count; pos++) // loop through arrary
			{
				if (largest <= arr[pos]) // compare the current largest value with the current value in the array
					{
						largest = arr[pos]; // if the largest is smaller than the current value, set largest to the current value in the array
						position = pos; // sae the position of that value
					}
			}
		return position; // reutrn the position in the array of the largest value
	}

// function to find the smallest amount of salsa sold
// same as largest, but we are looking for the smallest
int posOfSmallest (int arr[], int count)
	{
		int smallest = arr[0];
		int position = 0;
		for (int pos = 0; pos < count; pos++)
			{
				if (smallest >= arr[pos]) // the only difference between the two functions, if the smallest is larger, then
					{
						smallest = arr[pos]; // set smallest to the current value in the array
						position = pos; // save that position
					}
			}
		return position; // return the postion in the array the smallest was found
	}

// function to get the average sales of all salsa
int getAvg (int arr[], int count)
	{
		int total = 0;
		for (int pos = 0; pos < count; pos++) // loop through array
			{
				total = total + arr[pos]; // tally up sales
			}
		return (total / count); // return average
	}
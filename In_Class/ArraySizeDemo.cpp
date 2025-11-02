#include <iostream>
#include <string>
#include <iomanip>
#include <array>
using namespace std;

int main()
{
	array<int,5> myints;
	cout << "sizeof myints: " << myints.size() << endl;
	cout << "sizeof(myints): " << sizeof(myints) << endl;
	return 0;
}
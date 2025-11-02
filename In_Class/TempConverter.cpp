// in class work 29 Jan 2025
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	double c_temp, f_temp;
	cout << "Enter temp in Celcius: ";
	cin >> c_temp;
	f_temp = (c_temp * 1.8) + 32;;
	cout << fixed << showpoint << setprecision(1) << "Temp in F: " << f_temp << endl;
	return 0;
}

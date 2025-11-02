#include <iostream>
#include <string>
#include <iomanip>
#include <array>
using namespace std;

class ComplexNumber
{
    private:
        float realPart;
        float complexPart;

    public:
        ComplexNumber() // constructor that has no argument.  It instantiates, or makes an instance of. The compiler needs this no arg constructor to compile this class.
        {
            cout << "No arg-constructor called" << endl;
        }
        void setMemeberVariables(double r, double c)
        {
            realPart = r;
            complexPart = c;
        }
        float getRealPart()
        {
            return realPart;
        }
        float getComplexPart()
        {
            return complexPart;
        }
        void print()
        {
            cout << "real = " << realPart << " complex = " << complexPart << endl;
        }
};
#include <iostream>
#include <string>
using namespace std;

// Template for the minimum function
// TODO: Write template <class T> T minimum(T a, T b);

// Template for the maximum function
// TODO: Write a temple <class T> T maximum(T a, T b);

// tmeplate for minimum function
template <class T>
T minimum(T number1, T number2){
    return (number1 < number2) ? number1 : number2; // ternary operator
}
    
// template for the maximum function
template <class T>
T maximum(T number1, T number2){
    return (number1 > number2) ? number1 : number2;
}

// example of some other code you can do with this
 /*template <typename T>
    void swap (T & t1, T & t2){
    T temp = t1;
    t1 = t2;
    t2 = temp;
    return;
 }*/


// the main function
int main() {
    // test with the in arguments
    int num1 = 5;
    int num2 = 3;
    cout << "minimum of 5 and 3 is: " << endl;
    cout << minimum(num1, num2) << endl;
    cout << "maximum of 5 and 3 is: " << endl;
    cout << maximum(num1, num2) << endl;
    // test with double args
    double num3 = 5.5;
    double num4 = 3.5;
    cout << "minimum of 5.5 and 3.5 is: " << endl;
    cout << minimum(num3, num4) << endl;
    cout << "maximum of 5.5 and 3.5 is: " << endl;
    cout << maximum(num3, num4) << endl;
    // test with string args
    string str1 = "This is a string";
    string str2 = "This is another string";
    cout << "minimum of str1 and str2 is: " << endl;
    cout << minimum(str1, str2) << endl;
    cout << "maximum of str1 and str2 is: " << endl;
    cout << maximum(str1, str2) << endl;


    return 0;
}
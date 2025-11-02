/*
I asked for guidance on this from the TA and never got a response
so I am assuming that this homework is the checkpoint problem
on page 641 in the book:

11.13 Write a function that returns a Rectangle structure. The function
should store the user’s input in the members of the structure before returning it.

11.14 Write the definition of a pointer to a Rectangle structure.
*/

#include <iostream>
using namespace std;

// STRUCTS
struct Rectangle // the given struct for the problem
{
    int length;
    int width;
};

// PROTOTYPES
Rectangle getRectangle();

// MAIN
int main()
{
    Rectangle* rptr = nullptr; // 11.14 define a pointer to a new Rectangle
    rptr = new Rectangle;      // assign the pointer rptr to an allocation of a new struct of type Rectangle
    *rptr = getRectangle();    // use the function from 11.13 to fill the new Rectangle
                               /* it copies the values returned from the temp struct made in the
                                  function to the struct we just defined.  the *rptr dereferences
                                  our new struct that rptr points to so we can set (copy) its
                                  values to the ones returned from the function */

    /* display the results by using the arrow operator
       because we are accessing the struct through the pointer rptr.
       The arrow operator dereferences rptr and accesses the member
       variable in the struct so we can display its value */
    cout << "Rectangle length = " << rptr->length << endl;
    cout << "Rectangle width  = " << rptr->width << endl;
    delete rptr; // clean up what we allocated
    rptr = nullptr;
    return 0;
}

// FUNCTIONS
Rectangle getRectangle() // function of type Rectangle for 11.13
{
    Rectangle temp; // the temporary struct to store user info in
    
    /* we can use the dot operator here since we are accessing the struct
       directly because we are not accessing it through a pointer */
    cout << "Enter length: "; // get user info
    cin >> temp.length; // store it in length in the struct temp
    cout << "Enter width: ";
    cin >> temp.width;
    return temp; // return the struct values so they can be copied
                 // to the struct we allocated in main()
}
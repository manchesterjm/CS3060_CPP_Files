#include <iostream>
#include <string>
using namespace std;

// Shape Class: A base class that represents a generic shape.
class Shape
{
private:
    string shapeType;  // A string to store the type or description of the shape.
public:
    // Default constructor: called when a Shape object is created without any parameters.
    // no argument constructor
    Shape()
    {
        cout << "SHAPE: Inside the default constructor" << endl;
    }

    // Parameterized constructor: initializes the shapeType using the passed string 's'.
    Shape(string s) : shapeType(s)
    {
        cout << "SHAPE: Inside the 1-argument constructor " << shapeType << endl;
    }

    // Copy constructor: creates a new Shape object as a copy of an existing one.
    // 'rhs' stands for "right-hand side" and represents the source object to copy from.
    // copy by value
    Shape(const Shape& rhs)
    {
        shapeType = rhs.shapeType;
        cout << "SHAPE: Inside the copy constructor " << shapeType << endl;
    }

    // Destructor: called when a Shape object is destroyed or the program finishes
    // releases the resources taken up by the objects that have been created
    ~Shape()
    {
        cout << "SHAPE: Inside the destructor " << shapeType << endl;
    }

    // Assignment operator overload: allows one Shape object to be assigned to another.
    // 'rhs' is the source object from which data will be copied.
    Shape& operator=(const Shape &rhs)
    {
        cout << "SHAPE: Inside the assignment operator " << shapeType << endl;
        // Check for self-assignment to avoid copying an object into itself.
        if (this != &rhs)
        {
            shapeType = rhs.shapeType;  // Copy the shapeType from rhs.
        }
        // Return the current object to allow chaining of assignments.
        return *this;
    }
};

// Circle Class: Derived from Shape, adds a radius attribute.
class Circle : public Shape
{
private:
    float radius;  // Additional member variable to store the radius of the circle.
public:
    // Default constructor: initializes radius to 0.0.
    Circle() : radius(0.0)
    {
        cout << "CIRCLE: Inside the default constructor" << endl;
    }

    // Parameterized constructor: 
    // Calls the base class (Shape) constructor with string 's' and initializes radius.
    // explicitly initializing data memebers
    // from base class chape
    Circle(string s, float r) : Shape(s), radius(r)
    {
        cout << "CIRCLE: Inside the 1-argument constructor " << s << endl;
    }

    // Copy constructor: creates a new Circle object as a copy of an existing one.
    // 'rhs' is the source Circle object.
    // (Note: the base class part is copied using the default process if not explicitly called.)
    Circle(const Circle& rhs)
    {
        radius = rhs.radius;  // Copy the radius from rhs.
        cout << "CIRCLE: Inside the copy constructor raidus " << radius << endl;
    }

    // Destructor: called when a Circle object is destroyed.
    ~Circle()
    {
        cout << "CIRCLE: Inside the destructor " << radius << endl;
    }

    // Assignment operator overload for Circle objects.
    // 'rhs' is the source Circle object whose data will be assigned.
    // explicitly calling base class
    Circle& operator=(const Circle &rhs)
    {
        cout << "CIRCLE: Inside the assignment operator" << endl;
        
        // Check that the current object is not the same as the source (self-assignment check)
        if (this != &rhs)
        {
            // Call the assignment operator of the base class (Shape)
            // This copies the base part (like shapeType) from rhs (c2) to the current object (c1)
            Shape::operator=(rhs); // overloaded operator= basically hijacking it
            
            // Copy the radius from the source object to the current object
            radius = rhs.radius;
        }
        
        // Return the current object to allow for assignment chaining
        return *this;
    }
};

int main()
{
    // Uncommenting the next line would create a Shape object.
    // Shape s("Some shape");

    cout << "Start of program" << endl;
    
    cout << "Instantiate object c1" << endl;
    // Instantiates a Circle object 'c1' with "Some shape" as the shape description and 3.5 as the radius.
    Circle c1("Some shape", 3.5);
    
    cout << "Instantiate object c2" << endl;
    // Instantiates a Circle object 'c2' with "Some other shape" as the description and 10.2 as the radius.
    Circle c2("Some other shape" , 10.2);
    
    cout << "Assign c1 = c2" << endl;
    // Assigns c2 to c1 which invokes the assignment operator for Circle.
    c1 = c2;
    
    cout << "Instantiate object c3 (copy constructor)" << endl;
    // Creates a new Circle 'c3' as a copy of c1 using the copy constructor.
    Circle c3 = c1;
    
    cout << "End of program" << endl;
}

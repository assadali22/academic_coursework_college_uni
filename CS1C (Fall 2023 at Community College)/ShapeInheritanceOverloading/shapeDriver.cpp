#include "shapeType.h"
#include "circleType.h"
#include "rectangleType.h"
#include "squareType.h"
#include "triangleType.h"

int main()
{
    shapeType shapes[10];
    circleType circle1;
    circleType circle2(10.00);
    circleType circle3(5.0);

    circle1.setRadius(5.0);
    circle1.setColor("Orange");
    circle3.setColor("Orange");

    //Data for circle1
    cout << "Printing circles with print function in circleType: " << endl;
    //printCircle function
    circle1.printCircle();
    circle2.printCircle();
    cout << "Printing circle3" << endl;
    circle3.printCircle();


    cout << endl;
    cout << "Adding circles to array of shapes" << endl;
    shapes[0] = circle1;
    shapes[1] = circle2;
    shapes[2] = circle3;

    //try == operator
    if (shapes[0] == shapes[1]) //circle1 == circle2
    {
        cout << "shapes[0] == shapes[1] is true. (circle1 == circle2)" << endl;
    }
    else
    {
        cout << "shapes[0] is not the same as shapes[1]. (circle1 doesn't equal circle 2)" << endl;
    }


    if (shapes[0] == shapes[2]) //circle1 == circle3
    {
        cout << "shapes[0] == shapes[2] is true. (circle1 == circle3)" << endl;
    }
    else
    {
        cout << "shapes[0] is not the same as shapes[2]. (circle1 is not the same as circle3)" << endl;
    }

    cout << endl;
    //Test rectangleType
    rectangleType rect1;
    rectangleType rect2(10, 5.50);
    rectangleType rect3(10, 5.50);

    rect1.setWidth(8);
    rect1.setLength(4);

    cout << "Rectangle 1" << endl;
    rect1.printRect();
    cout << "Rectangle 2" << endl;
    rect2.printRect();
    cout << "Rectangle 3" << endl;
    rect3.printRect();

    cout << "Adding rectangles to shape array" << endl;
    shapes[3] = rect1;
    shapes[4] = rect2;
    shapes[5] = rect3;

    if (shapes[3] != shapes[4])
    {
        cout << "shapes[3] != shapes[4] (rect1 != rect2) is true, the shapes are not equal" << endl;
    }
    else
    {
        cout << "shapes[3] != shapes[4] (rect1 != rect2) is false, the shapes ARE EQUAL" << endl;
    }

    if (shapes[4] != shapes[5])
    {
        cout << "shapes[4] != shapes[5] (rect2 != rect3) is true, the shapes are not equal" << endl;
    }
    else
    {
       cout << "shapes[4] != shapes[5] (rect2 != rect3) is false, the shapes ARE EQUAL" << endl;
    }

    cout << endl;
    //test squareType
    squareType square1;
    squareType square2(7.50);

    square1.setSide(7.50);
    square1.setColor("Blue");
    square2.setColor("Blue");

    square1.printSquare();
    square2.printSquare();

    cout << "Adding squares to shape array" << endl;
    shapes[6] = square1;
    shapes[7] = square2;

    if (shapes[6] == shapes[7])
    {
        cout << "shapes[6] == shapes[7] (square1 == square2) is true, they are equal" << endl;
    }
    else
    {
        cout << "square1 does not equal square2. (shapes[6] == shapes[7])" << endl;
    }

    cout << endl;
    //test right triangle
    triangleType t1;
    triangleType t2;

    cout << "After declaring two triangles: " << endl;
    t1.printTriangle();
    t2.printTriangle();

    if (t1 != t2)
    {
        cout << "triangle1 != triangle2 is true, both triangles are not same." << endl;
    }
    else
    {
        cout << "triangle1 != triangle2 is false, they are EQUAL." << endl;
    }

    t1.setBase(10.00);
    t1.setHeight(6.00);

    t2.setBase(10.00);
    t2.setHeight(6.00);

    t1.setColor("Red");
    t2.setColor("Green");


    cout << "After adding data to triangles: " << endl;
    t1.printTriangle();
    t2.printTriangle();

    if (t1 != t2)
    {
        cout << "triangle1 != triangle2 is true, both triangles are not the same." << endl;
    }
    else
    {
        cout << "triangle1 != triangle2 is false, they are EQUAL." << endl;
    }

    cout << "Adding triangles to shape array" << endl;
    shapes[8] = t1;
    shapes[9] = t2;


    cout << "-----------------------------------------------------------------" << endl << endl;
    cout << "Now testing overloaded cout, printing shapes in the shape array:" << endl;

    int i;
    for (i = 0; i < 10; i++)
    {
        cout << "Shape #" << i + 1 << endl;
        cout << shapes[i];
        cout << endl;
    }

    return 0;
}


//Output Sample Run
/*
Printing circles with print function in circleType:
----------------------------------------------
Printing circle:
Radius: 5
Area: 78.5
Circumference: 31.4
Color: Orange
----------------------------------------------
End of printCircle function.


----------------------------------------------
Printing circle:
Radius: 10
Area: 314
Circumference: 62.8
Color: Clear
----------------------------------------------
End of printCircle function.


Printing circle3
----------------------------------------------
Printing circle:
Radius: 5
Area: 78.5
Circumference: 31.4
Color: Orange
----------------------------------------------
End of printCircle function.



Adding circles to array of shapes
shapes[0] is not the same as shapes[1]. (circle1 doesn't equal circle 2)
shapes[0] == shapes[2] is true. (circle1 == circle3)

Rectangle 1
----------------------------------------------
Printing rectangle:
Rectangle length: 4
Rectangle width: 8
Rectangle area: 32
Rectangle perimeter: 24
Rectangle color: Clear
----------------------------------------------
End of printRect function.


Rectangle 2
----------------------------------------------
Printing rectangle:
Rectangle length: 10
Rectangle width: 5.5
Rectangle area: 55
Rectangle perimeter: 31
Rectangle color: Clear
----------------------------------------------
End of printRect function.


Rectangle 3
----------------------------------------------
Printing rectangle:
Rectangle length: 10
Rectangle width: 5.5
Rectangle area: 55
Rectangle perimeter: 31
Rectangle color: Clear
----------------------------------------------
End of printRect function.


Adding rectangles to shape array
shapes[3] != shapes[4] (rect1 != rect2) is true, the shapes are not equal
shapes[4] != shapes[5] (rect2 != rect3) is false, the shapes ARE EQUAL

----------------------------------------------
Printing square:
Square side length: 7.5
Square area: 56.25
Square perimeter: 30
Square color: Blue
----------------------------------------------
End of printSquare function.


----------------------------------------------
Printing square:
Square side length: 7.5
Square area: 56.25
Square perimeter: 30
Square color: Blue
----------------------------------------------
End of printSquare function.


Adding squares to shape array
shapes[6] == shapes[7] (square1 == square2) is true, they are equal

After declaring two triangles:
----------------------------------------------
Printing triangle:
Base: 0
Height: 0
Triangle area: 0
Triangle perimeter: 0
Triangle color: Clear
----------------------------------------------
End of printTriangle function.


----------------------------------------------
Printing triangle:
Base: 0
Height: 0
Triangle area: 0
Triangle perimeter: 0
Triangle color: Clear
----------------------------------------------
End of printTriangle function.


triangle1 != triangle2 is false, they are EQUAL.
After adding data to triangles:
----------------------------------------------
Printing triangle:
Base: 10
Height: 6
Triangle area: 30
Triangle perimeter: 27.6619
Triangle color: Red
----------------------------------------------
End of printTriangle function.


----------------------------------------------
Printing triangle:
Base: 10
Height: 6
Triangle area: 30
Triangle perimeter: 27.6619
Triangle color: Green
----------------------------------------------
End of printTriangle function.


triangle1 != triangle2 is true, both triangles are not the same.
Adding triangles to shape array
-----------------------------------------------------------------

Now testing overloaded cout, printing shapes in the shape array:
Shape #1
Using overloaded cout:
----------------------------------------------
Shape Type: Circle
Area: 78.5
Perimeter: 31.4
Color: Orange
----------------------------------------------


Shape #2
Using overloaded cout:
----------------------------------------------
Shape Type: Circle
Area: 314
Perimeter: 62.8
Color: Clear
----------------------------------------------


Shape #3
Using overloaded cout:
----------------------------------------------
Shape Type: Circle
Area: 78.5
Perimeter: 31.4
Color: Orange
----------------------------------------------


Shape #4
Using overloaded cout:
----------------------------------------------
Shape Type: Rectangle
Area: 32
Perimeter: 24
Color: Clear
----------------------------------------------


Shape #5
Using overloaded cout:
----------------------------------------------
Shape Type: Rectangle
Area: 55
Perimeter: 31
Color: Clear
----------------------------------------------


Shape #6
Using overloaded cout:
----------------------------------------------
Shape Type: Rectangle
Area: 55
Perimeter: 31
Color: Clear
----------------------------------------------


Shape #7
Using overloaded cout:
----------------------------------------------
Shape Type: Square
Area: 56.25
Perimeter: 30
Color: Blue
----------------------------------------------


Shape #8
Using overloaded cout:
----------------------------------------------
Shape Type: Square
Area: 56.25
Perimeter: 30
Color: Blue
----------------------------------------------


Shape #9
Using overloaded cout:
----------------------------------------------
Shape Type: Triangle
Area: 30
Perimeter: 27.6619
Color: Red
----------------------------------------------


Shape #10
Using overloaded cout:
----------------------------------------------
Shape Type: Triangle
Area: 30
Perimeter: 27.6619
Color: Green
----------------------------------------------



*/

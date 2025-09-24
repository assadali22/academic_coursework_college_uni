/*
(The Rectangle class)
Following the example of the Circle class in Section 9.2, design a class named Rectangle to represent a rectangle.
The class contains:
- Two double data fields named width and height that specify the width and height of the rectangle.
The default values are 1 for both width and height.
- A no-arg constructor that creates a default rectangle.
- A constructor that creates a rectangle with the specified width and height.
- A method named getArea() that returns the area of this rectangle.
- A method named getPerimeter() that returns the perimeter.

Write a test program that creates two Rectangle objects—one with
width 4 and height 40 and the other with width 3.5 and height 35.9.
Display the width, height, area, and perimeter of each rectangle in this order.

*/

public class Exercise09_01
{
    public static void main(String[] args)
    {
        Rectangle r1 = new Rectangle(4, 40);
        Rectangle r2 = new Rectangle(3.5, 35.9);

        //Rectangle 1
        System.out.println("The area of a rectangle with width " + r1.getWidth() + " and height " + r1.getHeight() + " is " + r1.getArea());
        System.out.println("The perimeter of a rectangle is " + r1.getPerimeter());

        //Rectangle 2
        System.out.println("The area of a rectangle with width " + r2.getWidth() + " and height " + r2.getHeight() + " is " + r2.getArea());
        System.out.println("The perimeter of a rectangle is " + r2.getPerimeter());
    }
}



class Rectangle
{
    //public:
    //Constructors
    public Rectangle()
    {

    }
    public Rectangle(double w, double h)
    {
        width = w;
        height = h;
    }

    //Getters
    public double getArea()
    {
        return height * width;
    }

    public double getPerimeter()
    {
        return height + height + width + width;
    }

    public double getWidth()
    {
        return width;
    }

    public double getHeight()
    {
        return height;
    }

    //private:
    private double width = 0.0;
    private double height = 0.0;
}

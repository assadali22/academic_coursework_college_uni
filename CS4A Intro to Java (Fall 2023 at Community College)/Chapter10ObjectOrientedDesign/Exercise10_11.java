/*
(Geometry: the Circle2D class)
Define the Circle2D class that contains:
-Two double data fields named x and y that specify the center of the circle
with getter methods.
-A data field radius with a getter method.
-A no-arg constructor that creates a default circle with (0, 0) for (x, y)
and 1 for radius.
-A constructor that creates a circle with the specified x, y, and radius.
-A method getArea() that returns the area of the circle.
-A method getPerimeter() that returns the perimeter of the circle.


-A method contains(double x, double y) that returns true if the specified point (x, y) is inside this circle (see Figure 10.21a).
-A method contains(Circle2D circle) that returns true if the specified circle is inside this circle (see Figure 10.21b).
-A method overlaps(Circle2D circle) that returns true if the specified circle overlaps with this circle (see Figure 10.21c).


Write a test program that creates a Circle2D object c1
(new Circle2D(2, 2, 5.5)), displays its area and perimeter,
and displays the result of c1.contains(3, 3), c1.contains(new Circle2D(4, 5, 10.5)),
and c1.overlaps(new Circle2D(3, 5, 2.3)).
*/


public class Exercise10_11
{
    public static void main(String[] args)
    {
        Circle2D c1 = new Circle2D(2, 2, 5.5);
        System.out.println("Area = " + c1.getArea() + " Circumference = " + c1.getPerimeter());
        System.out.println(c1.contains(3, 3));
        System.out.println(c1.contains(new Circle2D(4, 5, 10.5)));
        System.out.println(c1.overlaps(new Circle2D(3, 5, 2.3)));
    }
}


class Circle2D
{
    //private:
    private double x;
    private double y;
    private double radius;


    //public:
    public Circle2D()
    {
        x = 0.0;
        y = 0.0;
        radius = 1;
    }

    public Circle2D(double newX, double newY, double r)
    {
        x = newX;
        y = newY;
        radius = r;
    }

    //check if a points lies in the circle
    public boolean contains(double x1, double y1)
    {
        double d = 0;

        d = Math.sqrt(Math.pow(x1 - x , 2) + Math.pow(y1 - y, 2));

        if (d <= radius)
        {
            return true;
        }

        return false;
    }

    //check if a circle overlaps another circle
    public boolean overlaps(Circle2D c)
    {
        double d = 0;

        d = Math.sqrt(Math.pow(c.getX() - x , 2) + Math.pow(c.getY() - y, 2));

        if (d >= 2 * radius)
        {
            return false;
        }

        return true;

    }

    //check if one circle is inside another
    public boolean contains(Circle2D c)
    {
        double d = 0;

        d = Math.sqrt(Math.pow(c.getX() - x , 2) + Math.pow(c.getY() - y, 2));

        if (d + c.getRadius() <= radius)
        {
            return true;
        }

        return false;
    }

    public double getPerimeter()
    {
        return 2 * radius * Math.PI;
    }

    public double getArea()
    {
        return radius * radius * Math.PI;
    }

    public double getX()
    {
        return x;
    }

    public double getY()
    {
        return y;
    }

    public double getRadius()
    {
        return radius;
    }
}

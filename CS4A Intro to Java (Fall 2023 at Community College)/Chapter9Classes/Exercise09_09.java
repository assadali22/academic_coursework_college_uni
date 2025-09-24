/*
(Geometry: n-sided regular polygon)
In an n-sided regular polygon, all sides have the same length and all angles
have the same degree (i.e., the polygon is both equilateral and equiangular).

Design a class named RegularPolygon that contains:
- A private int data field named n that defines the number of sides in the polygon with default value 3.
- A private double data field named side that stores the length of the side with default value 1.
- A private double data field named x that defines the x-coordinate of the polygon’s center with default value 0.
- A private double data field named y that defines the y-coordinate of the polygon’s center with default value 0.
- A no-arg constructor that creates a regular polygon with default values.
- A constructor that creates a regular polygon with the specified number of sides and length of side, centered at (0, 0).
- A constructor that creates a regular polygon with the specified number of sides, length of side, and x- and y-coordinates.
- The accessor and mutator methods for all data fields.
- The method getPerimeter()that returns the perimeter of the polygon.
- The method getArea()that returns the area of the polygon.

The formula for computing the area of a regular polygon is:
Area = n * s^2 / (4 * tan(pi / n))



Write a test program that creates three RegularPolygon objects,
created using the no-arg constructor, using RegularPolygon(6, 4),
and using RegularPolygon(10, 4, 5.6, 7.8).
For each object, display its perimeter and area.

Sample Run
Polygon 1 perimeter: 3.0
Polygon 1 area: 0.43301270189221946
Polygon 2 perimeter: 24.0
Polygon 2 area: 41.569219381653056
Polygon 3 perimeter: 40.0
Polygon 3 area: 123.10734148701015
*/

public class Exercise09_09
{
    public static void main(String[] args)
    {
        RegularPolygon p1 = new RegularPolygon();
        RegularPolygon p2 = new RegularPolygon(6, 4);
        RegularPolygon p3 = new RegularPolygon(10, 4, 5.6, 7.8);

        //Polygon 1
        System.out.println("Polygon 1 perimeter: " + p1.getPerimeter());
        System.out.println("Polygon 1 area: " + p1.getArea());

        //Polygon 2
        System.out.println("Polygon 2 perimeter: " + p2.getPerimeter());
        System.out.println("Polygon 2 area: " + p2.getArea());

        //Polygon 3
        System.out.println("Polygon 3 perimeter: " + p3.getPerimeter());
        System.out.println("Polygon 3 area: " + p3.getArea());
    }
}




class RegularPolygon
{
    //public:

    public RegularPolygon()
    {

    }
    public RegularPolygon(int nSide, double l)
    {
        n = nSide;
        side = l;
    }
    public RegularPolygon(int nSide, double l, double newX, double newY)
    {
        n = nSide;
        side = l;
        x = newX;
        y = newY;
    }
    //Setters
    public void setN(int newN)
    {
        n = newN;
    }

    public void setLength(double L)
    {
        side = L;
    }

    public void setX(double newX)
    {
        x = newX;
    }

    public void setY(double newY)
    {
        y = newY;
    }

    //Getters
    public int getNumSides()
    {
        return n;
    }

    public double getLength()
    {
        return side;
    }

    public double getX()
    {
        return x;
    }

    public double getY()
    {
        return y;
    }

    public double getPerimeter()
    {
        return (side * n);
    }

    public double getArea()
    {
        double top;
        double bottom;
        double result;

        top = n * (Math.pow(side, 2));
        bottom = 4 * Math.tan(Math.PI / n);

        result = top / bottom;
        return result;
    }


    //private:
    private int n = 3; //number of sides
    private double side = 1; //length
    private double x = 0;
    private double y = 0;
}

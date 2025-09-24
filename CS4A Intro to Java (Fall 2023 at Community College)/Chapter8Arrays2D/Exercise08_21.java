/*
(Central city)
Given a set of cities, the central city is the city that has
the shortest total distance to all other cities.
Write a program that prompts the user to enter the number of the
cities and the locations of the cities (coordinates), and finds the
central city and its total distance to all other cities.


Sample Run
Enter the number of cities: 5
Enter the coordinates of the cities:  2.5 5  5.1 3  1 9  5.4 54  5.5 2.1
The central city is at (2.5, 5.0)
The total distance to all other cities is 60.81
*/

import java.util.Scanner;
public class Exercise08_21
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int numCities;
        int i;
        int j;
        double numInput;
        double minTotalDist = 0;
        int minIndex = 0;


        //Input number of cities
        System.out.print("Enter the number of cities: ");
        numCities = input.nextInt();


        //Make the array and prompt input
        double[][] coordinates = new double[numCities][2];
        System.out.print("Enter the coordinates of the cities: ");
        for (i = 0; i < coordinates.length; i++)
        {
            for (j = 0; j < coordinates[i].length; j++)
            {
                numInput = input.nextDouble();
                coordinates[i][j] = numInput;
            }
        }

        //First assume first city is central city
        minTotalDist = totalDistance(coordinates, minIndex);
        double dist;
        for (i = 1; i < coordinates.length; i++)
        {
            dist = totalDistance(coordinates, i);

            if (dist < minTotalDist)
            {
                minTotalDist = dist;
                minIndex = i;
            }
        }


        //Output
        System.out.println("The central city is at (" + coordinates[minIndex][0] + ", " + coordinates[minIndex][1] + ")");
        System.out.println("The total distance to all other cities is " + minTotalDist);

    }

    public static double distance(double[] c1, double[] c2)
    {
        //Implement distance formula
        double result;

        result = Math.sqrt(Math.pow(c2[0] - c1[0], 2) + Math.pow(c2[1] - c1[1], 2));

        return result;
    }


    public static double totalDistance(double[][] cities, int i)
    {
        double totalDist = 0;
        int k;
        for (k = 0; k < cities.length; k++)
        {
            totalDist += distance(cities[i], cities[k]);
        }
        return totalDist;
    }
}

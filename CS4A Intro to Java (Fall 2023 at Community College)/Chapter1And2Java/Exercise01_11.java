/*
The U.S. Census Bureau projects population based on the following assumptions:
- One birth every 7 seconds
- One death every 13 seconds
- One new immigrant every 45 seconds
Write a program to display the population for each of the next five years.
Assume the current population is 312,032,486 and one year has 365 days.

Hint: In Java, if two integers perform division, the result is an integer.
The fractional part is truncated. For example, 5 / 4 is 1 (not 1.25) and
10 / 4 is 2 (not 2.5). To get an accurate result with the fractional part,
one of the values involved in the division must be a number with a decimal point.
For example, 5.0 / 4 is 1.25 and 10 / 4.0 is 2.5.
*/

public class Exercise01_11
{
    public static void main(String[] args)
    {
        //Variables
       double currentPopulation = 312032486;
       double secondToYears = 60 * 60 * 24 * 365; //1 year into seconds
       double birthsPerYear;
       double immigrantsPerYear;
       double deathsPerYear;
       double popGainPerYear;

       //Calculation
       birthsPerYear = secondToYears / 7.0;
       immigrantsPerYear = secondToYears / 45.0;
       deathsPerYear = secondToYears / 13.0;

       popGainPerYear = (birthsPerYear + immigrantsPerYear) - deathsPerYear;

       //Print population after 1-5 years
       currentPopulation = currentPopulation + popGainPerYear;
       System.out.println("Population after 1 year: " + currentPopulation);

       currentPopulation = currentPopulation + popGainPerYear;
       System.out.println("Population after 2 years: " + currentPopulation);

       currentPopulation = currentPopulation + popGainPerYear;
       System.out.println("Population after 3 years: " + currentPopulation);

       currentPopulation = currentPopulation + popGainPerYear;
       System.out.println("Population after 4 years: " + currentPopulation);

       currentPopulation = currentPopulation + popGainPerYear;
       System.out.println("Population after 5 years: " + currentPopulation);
    }
}

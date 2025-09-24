/*
(Assign grades)
Write a program that reads student scores, gets the best score,
and then assigns grades based on the following scheme:
Grade is A if score is >= best - 10
Grade is B if score is >= best - 20
Grade is C if score is >= best - 30
Grade is D if score is >= best - 40
Grade is F otherwise.

The program prompts the user to enter the total number of students,
then prompts the user to enter all of the scores, and
concludes by displaying the grades.


Sample Run
Enter the number of students: 4
Enter 4 scores: 40 55 70 58
Student 0 score is 40 and grade is C
Student 1 score is 55 and grade is B
Student 2 score is 70 and grade is A
Student 3 score is 58 and grade is B
*/

import java.util.Scanner;
public class Exercise07_01
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int size;
        int best;

        //Read the number of students
        System.out.print("Enter the number of students: ");
        size = input.nextInt();

        int[] grades = fillArray(size, input); //pass in the Scanner object
        best = findBest(grades);
        showGrade(grades, best);
    }

    public static int[] fillArray(int s, Scanner input)
    {
        int[] grades = new int[s];
        int i = 0;
        int score;

        //Fill the array
        System.out.print("Enter " + s + " scores: ");
        for (i = 0; i < s; i++)
        {
            score = input.nextInt();
            grades[i] = score;
        }

        return grades;

    }

    public static int findBest(int[] grades)
    {
        int max;
        max = grades[0];
        int k = 0;

        //Find highest score
        for (k = 1; k < grades.length; k++)
        {
            if (grades[k] > max)
            {
                max = grades[k];
            }
        }

        return max;
    }

    public static void showGrade(int[] grades, int best)
    {
        int i = 0;
        for (i = 0; i < grades.length; i++)
        {
            if (grades[i] >= best - 10)
            {
                System.out.println("Student " + i + " score is " + grades[i] + "and grade is A");
            }
            else if (grades[i] >= best - 20)
            {
                System.out.println("Student " + i + " score is " + grades[i] + "and grade is B");
            }
            else if (grades[i] >= best - 30)
            {
                System.out.println("Student " + i + " score is " + grades[i] + "and grade is C");
            }
            else if (grades[i] >= best - 40)
            {
                System.out.println("Student " + i + " score is " + grades[i] + "and grade is D");
            }
            else
            {
                System.out.println("Student " + i + " score is " + grades[i] + "and grade is F");
            }
        }
    }
}

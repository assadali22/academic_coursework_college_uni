/*
(Find the two highest scores)
Write a program that prompts the user to enter the number of students and each student’s name and score,
and finally displays the student with the highest score and the student with the second-highest score.
Use the next() method in the Scanner class to read a name rather than using the nextLine() method.
Assume that the number of students is at least 2.
Sample Run
Enter the number of students: 5
Enter a student name: Smith
Enter a student score: 60
Enter a student name: Jones
Enter a student score: 96
Enter a student name: Peterson
Enter a student score: 85
Enter a student name: Greenlaw
Enter a student score: 98
Enter a student name: Zhang
Enter a student score: 95
Top two students:
Greenlaw's score is 98.0
Jones's score is 96.0
*/

import java.util.Scanner;
public class Exercise05_09
{
    public static void main(String[] args)
    {
        //Variables
        Scanner input = new Scanner(System.in);
        double highScore = 0; //score1
        double secondHighest = 0; //score2
        String topStudent; //student1
        String secondHighestStudent; //student2

        int totalStudents;
        String tempName;
        double temp;

        //Input
        System.out.println("Enter the number of students: ");
        totalStudents = input.nextInt();

        System.out.println("Enter a student name: ");
        topStudent = input.next();

        System.out.println("Enter a student score: ");
        highScore = input.nextDouble();

        System.out.println("Enter a student name: ");
        secondHighestStudent = input.next();

        System.out.println("Enter a student score: ");
        secondHighest = input.nextDouble();

        if (highScore < secondHighest)
        {
            temp = highScore;
            highScore = secondHighest;
            secondHighest = temp;

            tempName = topStudent;
            topStudent = secondHighestStudent;
            secondHighestStudent = tempName;
        }

        //Calculation and Output
        int i;
        double numInput; //score
        String name; //student
        for (i = 0; i < totalStudents - 2; i++)
        {
            System.out.println("Enter a student name: ");
            name = input.next();

            System.out.println("Enter a student score: ");
            numInput = input.nextDouble();

            if (numInput > highScore)
            {
                secondHighest = highScore;
                highScore = numInput;
                secondHighestStudent = topStudent;
                topStudent = name;
            }
            else if (numInput > secondHighest)
            {
                secondHighest = numInput;
                secondHighestStudent = name;
            }

        }

        System.out.println("Top two students:");
        System.out.println(topStudent + "'s score is " + highScore);
        System.out.println(secondHighestStudent + "'s score is " + secondHighest);
    }
}

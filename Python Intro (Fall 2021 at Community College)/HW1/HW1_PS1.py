#Homework 1 Program Set 1
#This program computes the monthly and total payment given the annual interest rate, number of years, and loan amount specified by the user.

#Input
#Let the user define the annual interest rate, number of years, and loan amount.
annual_interest_rate = float(input("Enter the annual interest rate:"))
numberOfYears = int(input("Enter the number of years as an integer:"))
loanAmount = float(input("Enter the loan amount:"))


#Processing/Calculation
#Calculate the monthly interest rate, monthly payment, and total payment.
monthlyInterestRate = annual_interest_rate / 1200
monthlyPayment = loanAmount * monthlyInterestRate / (1 - 1/(1 + monthlyInterestRate)**(numberOfYears * 12))
totalPayment = monthlyPayment * numberOfYears * 12

#Output
#Define the monthly and total payment.
print("The monthly payment is", format(monthlyPayment, ',.2f'))
print("The total payment is", format(totalPayment, ',.2f'))


##Test Run 1 for Program Set 1
##Enter the annual interest rate:4.5
##Enter the number of years as an integer:30
##Enter the loan amount:350000.50
##The monthly payment is 1,773.40
##The total payment is 638,424.40

##Test Run 2 for Program Set 1
##Enter the annual interest rate:5.5
##Enter the number of years as an integer:20
##Enter the loan amount:200000
##The monthly payment is 1,375.77
##The total payment is 330,185.91

##Test Run 3 for Program Set 1
##Enter the annual interest rate:6
##Enter the number of years as an integer:35
##Enter the loan amount:250000
##The monthly payment is 1,425.47
##The total payment is 598,699.19

##Test Run 4 for Program Set 1
##Enter the annual interest rate:2
##Enter the number of years as an integer:10
##Enter the loan amount:100000
##The monthly payment is 920.13
##The total payment is 110,416.14

##Test Run 5 for Program Set 1
##Enter the annual interest rate:6.5
##Enter the number of years as an integer:15
##Enter the loan amount:325000
##The monthly payment is 2,831.10
##The total payment is 509,597.81


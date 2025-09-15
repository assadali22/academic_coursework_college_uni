#Homework 2 Program Set 1
#this program generates a random 2 digit number and the user inputs a number to try and match the digits for a prize.

#Input
import random
user_num = int(input("Enter your lottery pick (2 digits) or -999 to quit: "))

#Processing/Output
while user_num != -999:
    lott_num = random.randint(0, 99)
    lott_digit1 = lott_num // 10
    lott_digit2 = lott_num % 10
    user_digit1 = user_num // 10
    user_digit2 = user_num % 10

    if lott_digit1 == user_digit1 and lott_digit2 == user_digit2:
        print("Exact match: You win $10,000!")

    elif lott_digit1 == user_digit2 and lott_digit2 == user_digit1:
        print("Match all digits: You win $3,000")

    elif lott_digit1 == user_digit1 or lott_digit1 == user_digit2 or lott_digit2 == user_digit1 or lott_digit2 == user_digit2:
        print("Match one digit: You win $1,000")

    else:
        print("Sorry no match")

    print()
    user_num = int(input("Enter your lottery pick (2 digits) or -999 to quit: "))
    


#Test Run 1 for Program Set 1
##>>>
##Enter your lottery pick (2 digits) or -999 to quit: 44
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 23
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 68
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 12
##Match one digit: You win $1,000
##
##Enter your lottery pick (2 digits) or -999 to quit: 45
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: -999
##>>>



#Test Run 2 for Program Set 1
##>>>
##Enter your lottery pick (2 digits) or -999 to quit: 14
##Match all digits: You win $3,000
##
##Enter your lottery pick (2 digits) or -999 to quit: 16
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 18
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 42
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 69
##Match one digit: You win $1,000
##
##Enter your lottery pick (2 digits) or -999 to quit: 77
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 45
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 19
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 83
##Match one digit: You win $1,000
##
##Enter your lottery pick (2 digits) or -999 to quit: -999
##>>> 



#Test Run 3 for Program Set 1
##>>>
##Enter your lottery pick (2 digits) or -999 to quit: 67
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 98
##Match one digit: You win $1,000
##
##Enter your lottery pick (2 digits) or -999 to quit: 95
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 44
##Match one digit: You win $1,000
##
##Enter your lottery pick (2 digits) or -999 to quit: 58
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 13
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 34
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 54
##Match one digit: You win $1,000
##
##Enter your lottery pick (2 digits) or -999 to quit: 87
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 75
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 71
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 16
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 27
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: -999
##>>> 



#Test Run 4 for Program Set 1
##>>>
##Enter your lottery pick (2 digits) or -999 to quit: 65
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 87
##Match one digit: You win $1,000
##
##Enter your lottery pick (2 digits) or -999 to quit: 23
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 54
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 68
##Match one digit: You win $1,000
##
##Enter your lottery pick (2 digits) or -999 to quit: 21
##Match one digit: You win $1,000
##
##Enter your lottery pick (2 digits) or -999 to quit: 43
##Match one digit: You win $1,000
##
##Enter your lottery pick (2 digits) or -999 to quit: 64
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: -999
##>>> 



#Test Run 5 for Program Set 1
##>>>
##Enter your lottery pick (2 digits) or -999 to quit: 13
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 43
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 98
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 26
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 43
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 48
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 23
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 43
##Match one digit: You win $1,000
##
##Enter your lottery pick (2 digits) or -999 to quit: 87
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 73
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 72
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 61
##Sorry no match
##
##Enter your lottery pick (2 digits) or -999 to quit: 22
##Match one digit: You win $1,000
##
##Enter your lottery pick (2 digits) or -999 to quit: -999
##>>> 

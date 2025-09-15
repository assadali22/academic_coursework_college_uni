#Lab 2 Question 1
#This program determines whether someone is eligible to vote or not, and how many years left to be eligible.

#Input
age = int(input("Enter the age:"))

#Processing/Output
if age < 18:
    print("You have to wait another", 18 - age, "years to cast your vote")
else:
    print("You are eligible to cast your vote")


##Test Run 1 for Q1
##Enter the age:10
##You have to wait another 8 years to cast your vote
    
##Test Run 2 for Q1
##Enter the age:25
##You are eligible to cast your vote

##Test Run 3 for Q1
##Enter the age:16
##You have to wait another 2 years to cast your vote
##>>> 


#Lab 2 Question 2
#this program determines whether a number is even or odd entered by the user

#input
num = int(input("Enter any number:"))

#processing/output
if num % 2 == 0:
    print(num, "is even")

else:
    print(num, "is odd")


#Test Run 1 for Q2
##Enter any number:125
##125 is odd

#Test Run 2 for Q2
##Enter any number:12
##12 is even

#Test Run 3 for Q2
##Enter any number:6515
##6515 is odd


#Lab 2 Question 3
#this program finds whether a letter is a vowel or not

#Input
letter = input("Enter any character: ")
vowel1 = 'a'
vowel2 = 'e'
vowel3 = 'i'
vowel4 = 'o'
vowel5 = 'u'

#processing/output
if letter == vowel1:
    print(letter, "is a vowel")
elif letter == vowel2:
    print(letter, "is a vowel")
elif letter == vowel3:
    print(letter, "is a vowel")
elif letter == vowel4:
    print(letter, "is a vowel")
elif letter == vowel5:
    print(letter, "is a vowel")

else:
    print(letter, "is not a vowel")
    

##Test Run 1 for Q3
##Enter any character: h
##h is not a vowel

##Test Run 2 for Q3
##Enter any character: e
##e is a vowel
    
##Test Run 3 for Q3
##Enter any character: u
##u is a vowel



#Lab 2 Question 4
#this program checks if a charcter entered by a user is upper/lowercase or a number.

#Input
character = input("Enter any character: ")


#Processing/Output

if "A" <= character <= "Z":
    print("Uppercase character was entered")

elif 'a' <= character <= 'z':
    print("Lowercase character was entered")

else:
    print("A number was entered")
    

#Test Run 1 for Q4
##Enter any character: C
##Uppercase character was entered
##>>>

#Test Run 2 for Q4
##Enter any character: b
##Lowercase character was entered
##>>>

#Test Run 3 for Q4
##Enter any character: 2
##A number was entered
##>>>


#Lab 2 Question 5
#this program prints horizontal stars with a while loop

#Input
x=0
stars = int(input("How many stars you want? "))

#Processing/Output
while x < stars:
    print('*', end = ' ')
    x = x + 1



#Test Run 1 for Q5
##How many stars you want? 20
##* * * * * * * * * * * * * * * * * * * *
##>>>

#Test Run 2 for Q5
##How many stars you want? 12
##* * * * * * * * * * * *
##>>>

#Test Run 3 for Q5
##How many stars you want? 17
##* * * * * * * * * * * * * * * * * 
##>>> 

    
#Lab 2 Question 6
#This program finds property tax given a lot number and property value unless user wants to quit


#input
print("Enter the property lot number or enter -999 to end")
lot_num = int(input("Enter the lot number: "))

#processing/output
tax_factor = .0065
while lot_num != -999:
    property_value = float(input("Enter property value: "))
    property_tax = property_value * tax_factor
    print("Property tax: $",format(property_tax, '.2f'),sep = '')
    print()
    print("Enter the property lot number or enter -999 to end")
    lot_num = int(input("Enter the lot number: "))
    


#Test Run 1 for Q6
##Enter the lot number: 100
##Enter property value: 100000.00
##Property tax: $650.00
##
##Enter the property lot number or enter -999 to end
##Enter the lot number: 200
##Enter property value: 5000.00
##Property tax: $32.50
##
##Enter the property lot number or enter -999 to end
##Enter the lot number: -999

    
#Test Run 2 for Q6
#Enter the lot number: -999
#>>>


#Test Run 3 for Q6
##Enter the property lot number or enter -999 to end
##Enter the lot number: 153
##Enter property value: 5000
##Property tax: $32.50
##
##Enter the property lot number or enter -999 to end
##Enter the lot number: 657
##Enter property value: 1400
##Property tax: $9.10
##
##Enter the property lot number or enter -999 to end
##Enter the lot number: 14
##Enter property value: 6250
##Property tax: $40.62
##
##Enter the property lot number or enter -999 to end
##Enter the lot number: -999



#Lab 2 Question 7
#this program calculates retail prices

#Input/Processing/Output
wholesale_cost = float(input("Enter the item's wholesale cost: "))

if wholesale_cost < 0:
    print("ERROR: the cost cannot be negative")
    wholesale_cost = float(input("Enter the correct wholesale cost: "))
    markup = wholesale_cost * 2.5
    print("Retail price is $", format(markup, '.2f'), sep = '')

else:
    markup = wholesale_cost * 2.5
    print("Retail price is $", format(markup, '.2f'), sep = '')

confirm = input("Do you have another item? (Enter y for yes): ")

while confirm == 'Y' or confirm == 'y':
    wholesale_cost = float(input("Enter the item's wholesale cost: "))
    if wholesale_cost < 0:
        print("ERROR: the cost cannot be negative")
        wholesale_cost = float(input("Enter the correct wholesale cost: "))
        markup = wholesale_cost * 2.5
        print("Retail price is $", format(markup, '.2f'), sep = '')
        
    else:
        markup = wholesale_cost * 2.5
        print("Retail price is $", format(markup, '.2f'), sep = '')

    confirm = input("Do you have another item? (Enter y for yes): ")

#Test Run 1 for Q7
##Enter the item's wholesale cost: -.5
##ERROR: the cost cannot be negative
##Enter the correct wholesale cost: .5
##Retail price is $1.25

#Test Run 2 for Q7
##Enter the item's wholesale cost: .75
##Retail price is $1.88
##Do you have another item? (Enter y for yes): Y
##Enter the item's wholesale cost: .50
##Retail price is $1.25
##Do you have another item? (Enter y for yes): n

#Test Run 3 for Q7
##Enter the item's wholesale cost: 7.50
##Retail price is $18.75
##Do you have another item? (Enter y for yes): y
##Enter the item's wholesale cost: 2.65
##Retail price is $6.62
##Do you have another item? (Enter y for yes): Y
##Enter the item's wholesale cost: 13.25
##Retail price is $33.12
##Do you have another item? (Enter y for yes): n


#Lab 2 Question 8
#this program prints Barzinger 5 times

#Input/Processing/Output
for x in range(5):
    print('Barzinger', end = '')

print()
#Test Run 1 for Q8
##BarzingerBarzingerBarzingerBarzingerBarzinger
##>>>

#Lab 2 Question 9
#this program calculates the sum of numbers. user specifies how many numbers to add.

#Input
amount_of_numbers = int(input("How many numbers do you want to add? "))
total = 0


#Processing/Output
for num in range(amount_of_numbers):
    print("Enter number", num + 1, end='')
    nums = float(input(': '))
    total = total + nums

print("The total is:", total)

#Test Run 1 for Q9
##How many numbers do you want to add? 3
##Enter number 1: 25
##Enter number 2: 34
##Enter number 3: 33
##The total is: 92.0
##>>> 

#Test Run 2 for Q9
##Enter number 1: 31
##Enter number 2: 534
##Enter number 3: 12
##Enter number 4: 14
##Enter number 5: 54
##The total is: 645.0

#Test Run 3 for Q9
##How many numbers do you want to add? 6
##Enter number 1: 12.4
##Enter number 2: 13
##Enter number 3: 25
##Enter number 4: 22.2
##Enter number 5: 55
##Enter number 6: 69
##The total is: 196.6
##>>> 

#Lab 2 Question 10
#this program converts speeds from 60 KPH to 130 KPH into MPH

#Input
start = 60
end = 130
conversion_factor = .6214

#Processing/Output
print()
print('KPH\tMPH')
print('-' * 36)

for kph in range(start, end + 1, 10):
    mph = kph * conversion_factor
    print(kph, "\t", format(mph, '.1f'))


#Test Run 1 for Q10
##KPH	MPH
##------------------------------------
##60 	 37.3
##70 	 43.5
##80 	 49.7
##90 	 55.9
##100 	 62.1
##110 	 68.4
##120 	 74.6
##130 	 80.8
##>>> 


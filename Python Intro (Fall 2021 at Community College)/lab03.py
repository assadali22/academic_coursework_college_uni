#Lab 3 Question 1
#this program prints the amount of birds in Texas and California with functions

def texas():
    '''Prints the amount of birds in Texas'''
    birds = 5000
    print("Texas has", birds, "birds")


def California():
    '''Prints the amount of bird in California'''
    birds = 8000
    print("California has", birds, "birds")
    

def main():
    texas()
    California()

    

if __name__ == "__main__":
    main()

#Test Run 1 for Q1
##>>>
##Texas has 5000 birds
##California has 8000 birds
##>>> 

#Test Run 2 for Q1
##>>>
##Texas has 5000 birds
##California has 8000 birds
##>>> 

#Test Run 3 for Q1
##>>>
##Texas has 5000 birds
##California has 8000 birds
##>>>


#Lab 3 Question 2
#this program states the simple interest with the use of functions

def show_interest(rate = .01, period = 10, principal = 10000.00):
    '''Calculate interest and print the result.'''
    interest = principal * rate * period
    print("The simple interest will be $", format(interest, ',.2f'), sep = '')

    

def main():
    show_interest()

    

if __name__ == "__main__":
    main()


#Test Run 1 for Q2
##>>> 
##The simple interest will be $1,000.00
##>>> 


#Test Run 2 for Q2
##>>> 
##The simple interest will be $1,000.00
##>>> 


#Test Run 3 for Q2
##>>> 
##The simple interest will be $1,000.00
##>>>


#Lab 3 Question 3
#this program calculates area of a right triangle using functions

def getData() -> (int, int):
    '''Obtain base and height from user input.'''
    base = int(input("Enter the base of your triangle: "))
    height = int(input("Enter the height of your triangle: "))

    return base, height



def trigArea(base : int, height : int) -> (int):
    '''Calculate the area of the triangle'''
    area = base * height * .5

    return area



def displayData(base : int, height : int, area : float):
    '''Print the base, height, and area.'''
    print("The base, height, and area are", \
    format(base, '.2f'),',', format(height, '.2f'),',', format(area, '.2f'))



def main():
    base, height = getData()
    area = trigArea(base, height)
    displayData(base, height, area)

if __name__ == "__main__":
    main()



#Test Run 1 for Q3
##Enter the base of your triangle: 10
##Enter the height of your triangle: 5
##The base, height, and area are 10.00 , 5.00 , 25.00
##>>> 


#Test Run 2 for Q3
##The simple interest will be $1,000.00
##Enter the base of your triangle: 2
##Enter the height of your triangle: 3
##The base, height, and area are 2.00 , 3.00 , 3.00
##>>>

#Test Run 3 for Q3
##Enter the base of your triangle: 15
##Enter the height of your triangle: 22
##The base, height, and area are 15.00 , 22.00 , 165.00
##>>> 


#Lab 3 Question 4
#this program calculates pay given user input of monthly sales and advanced pay with functions

def get_sales(float):
    '''Get sales from user as a float.'''
    sales = float(input("Enter the monthly sales: "))

    return sales


def get_advanced_pay(float):
    '''Get advanced pay as a float from user.'''
    advanced_pay = float(input("Enter the amount of advanced pay, or \nenter 0 if no advanced pay was given.\nAdvanced pay: "))

    return advanced_pay



def determine_comm_rate(sales):
    '''Determine rate using if-elif statements.'''
    if sales < 10000:
        comm_rate = .10
    elif 10000 <= sales <= 14999.99:
        comm_rate = .12
    elif 15000 <= sales <= 17999.99:
        comm_rate = .14
    elif 18000 <= sales <= 21999.99:
        comm_rate = .16
    elif sales > 21999.99:
        comm_rate = .18

    return comm_rate





def main():
    # Get the amount of sales from user
    sales = get_sales(float)
    
    # Get the amount of advanced pay from user.
    advanced_pay = get_advanced_pay(float)
    
    # Determine the commission rate.
    comm_rate = determine_comm_rate(sales)
    
    # Calculate the pay.
    pay = sales * comm_rate - advanced_pay
    
    # Display the amount of pay.
    print('The pay is $', format(pay, ',.2f'), sep='')
    
    # Determine whether the pay is negative.
    if pay < 0:
        print('The salesperson must reimburse')
        print('the company.')



#calls main
if __name__ == "__main__":
    main()


#Test Run 1 for Q4
##Enter the monthly sales: 14550.00
##Enter the amount of advanced pay, or 
##enter 0 if no advanced pay was given.
##Advanced pay: 1000.00
##The pay is $746.00
##>>>

#Test Run 2 for Q4
##Enter the monthly sales: 9500
##Enter the amount of advanced pay, or 
##enter 0 if no advanced pay was given.
##Advanced pay: 0
##The pay is $950.00
##>>>

#Test Run 3 for Q4
##Enter the monthly sales: 12000.00
##Enter the amount of advanced pay, or 
##enter 0 if no advanced pay was given.
##Advanced pay: 2000.00
##The pay is $-560.00
##The salesperson must reimburse
##the company.
##>>>


#Lab 3 Question 5
#this program find the sum of the single digit numbers, number inputted as a string


def string_total(number_string):
    '''Find the total of the digit numbers in the string'''
    i = 0
    total = 0
    for i in range(len(number_string)):
        total = total + int(number_string[i])
        i = i + 1

    return total




def main():
    #Get a string of numbers as input from the user.
    number_string = input('Enter a sequence of digits with nothing separating them:')
    
    # Call string_total function, and store the total.
    total = string_total(number_string)
    
    # Display the total.
    print('The total of the digits in the string you entered is', total)

    
#calls main
if __name__ == "__main__":
    main()    


#Test Run 1 for Q5
##Enter a sequence of digits with nothing separating them:4563
##The total of the digits in the string you entered is 18
##>>>

#Test Run 2 for Q5
##Enter a sequence of digits with nothing separating them:653214
##The total of the digits in the string you entered is 21
##>>>

#Test Run 3 for Q5
##Enter a sequence of digits with nothing separating them:123475123
##The total of the digits in the string you entered is 28


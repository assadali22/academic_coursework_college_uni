#Lab 1 Question 4
#This program find the area and volume of a cylinder

#Input
radius = float(input('Enter the radius of a cylinder: '))
length = float(input('Enter the length of a cylinder: '))



#Calculation/Processing
area = radius * radius * 3.141
volume = area * length



#Output
print("The area is", area)
print("The volume is", volume)

##Test Run 1 for Q4
##Enter the radius of a cylinder: 5.5
##Enter the length of a cylinder: 12
##The area is 95.01525
##The volume is 1140.183

##Test Run 2 for Q4
##Enter the radius of a cylinder: 5
##Enter the length of a cylinder: 8
##The area is 78.525
##The volume is 628.2
 
##Test Run 3 for Q4
##Enter the radius of a cylinder: 22
##Enter the length of a cylinder: 16
##The area is 1520.244
##The volume is 24323.904


#Lab 1 Question 5
#This program find the profit given a projected amount of sales.


#Input
total_sales = float(input("Enter the projected total sales: "))
profit_margin = .24


#Calculation/Processing
profit = total_sales * profit_margin



#Output
print("The profit made from this amount:", profit)


##Test Run 1 for Q5
##Enter the projected total sales: 1250
##The profit made from this amount: 300.0

##Test Run 2 for Q5
##Enter the projected total sales: 2000
##The profit made from this amount: 480.0

##Test Run 3 for Q5
##Enter the projected total sales: 1725
##The profit made from this amount: 414.0


#Lab 1 Question 6
#This program defines how much butter, sugar, and flour someone needs given how many cookies they want to make.


#Input
cookies = float(input("Enter the number of cookies:"))
unit_sugar = 1.5
unit_butter = 1
unit_flour = 2.75


#Processing/Calculation
ratio = cookies/48
sugar = unit_sugar * ratio
butter = unit_butter * ratio
flour = unit_flour * ratio


#Output
print("To make", cookies, "cookies, you will need:\n", format(sugar, '.2f'), "cups of sugar\n", format(butter, '.2f'), "cups of butter\n", format(flour, '.2f'), "cups of flour")


##Test Run 1 for Q6
##Enter the number of cookies:56
##To make 56.0 cookies, you will need:
## 1.75 cups of sugar
## 1.17 cups of butter
## 3.21 cups of flour

##Test Run 2 for Q6
##Enter the number of cookies:120
##To make 120.0 cookies, you will need:
## 3.75 cups of sugar
## 2.50 cups of butter
## 6.88 cups of flour

##Test Run 3 for Q6
##Enter the number of cookies:175
##To make 175.0 cookies, you will need:
## 5.47 cups of sugar
## 3.65 cups of butter
## 10.03 cups of flour


#Lab 1 Question 7
#This program displays a 4 digit number in reverse order.

#Input
integer = float(input("Enter a 4 digit integer:"))


#Processing/Calculation
first_num = integer // 1000
remainder = integer % 1000
second_num = remainder // 100
remainder2 = remainder % 100
third_num = remainder2 // 10
fourth_num = remainder2 % 10


#Output
print(int(fourth_num))
print(int(third_num))
print(int(second_num))
print(int(first_num))

#Test Run 1 for Q7
##Enter a 4 digit integer:3125
##5
##2
##1
##3

##Test Run 2 for Q7
##Enter a 4 digit integer:6147
##7
##4
##1
##6

##Test Run 3 for Q7
##Enter a 4 digit integer:6951
##1
##5
##9
##6


#Lab 1 Question 8
#This programs calculates the gravitational force and accleration due to gravity exerted to a person of m kg.

#Input
mass = float(input("Enter a mass in kg:"))


#Processing/Calculation
G = 6.67300 * 10**-11
r = 6378 * 10**3
earth_mass = 5.9742 * 10**24
g = ((G * earth_mass * mass)/r**2)/mass


#Output
print("The gravitational force is", format(g, ".4f"))


#Test Run 1 for Q8
##Enter a mass in kg:30
##The gravitational force is 9.8001


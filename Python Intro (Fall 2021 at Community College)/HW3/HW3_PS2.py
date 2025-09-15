#Homework 3 Program Set 2
#this program checks to see if credit card numbers are valid or invalid using functions


def isValid(number : str) -> bool:
     valid = True
     length = len(number)
     if length < 13 or length > 16:
          valid = False

          return valid

     elif number.startswith('4') or number.startswith('5') or number.startswith('6') or number.startswith('37'):
          total_sum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)
          if total_sum % 10 == 0:
               return valid
          else:
               valid = False
               
               return valid
           

 
def sumOfDoubleEvenPlace(cardNumber : str) -> int:
     # Get the result from Step 2
     total = 0
     for i in range(len(cardNumber) - 2, -1, -2):
          total = total + getDigit(int(cardNumber[i]) * 2)
     return total
     



def getDigit(number : int) -> int:
     #return this number if it is single digit, otherwise, return
     #sum of 2 digits
     if 0 <= number <= 9:
          return number
     
     else:
          divide = number // 10
          remainder = number % 10
          number = divide + remainder

          return number




def sumOfOddPlace(cardNumber : str) -> int:
     #return sum of odd place digits in number
     oddTotal = 0
     for y in range(len(cardNumber) - 1, -1, -2):
          oddTotal = oddTotal + int(cardNumber[y])

     return oddTotal
          



def main():
     confirm = int(input("How many credit card numbers do you want to check? "))
     for x in range(confirm):
          cardNumber = input("Enter a credit card number: ")
          validCard = isValid(cardNumber)
          if validCard:
               print(cardNumber, 'is valid')
               print()
          else:
               print(cardNumber, 'is invalid')
               print()
 


if __name__ == "__main__":
     main()


#Test Run 1 for PS2
##>>>
##How many credit card numbers do you want to check? 2
##Enter a credit card number: 4388576018402626
##4388576018402626 is invalid
##
##Enter a credit card number: 4388576018410707
##4388576018410707 is valid


#Test Run 2 for PS2
##How many credit card numbers do you want to check? 0
##>>>


#Test Run 3 for PS2
##How many credit card numbers do you want to check? 3
##Enter a credit card number: 12345678
##12345678 is invalid
##
##Enter a credit card number: 5169769005222217
##5169769005222217 is valid
##
##Enter a credit card number: 6011655276746808
##6011655276746808 is invalid


#Test Run 4 for PS2
##>>>
##How many credit card numbers do you want to check? 5
##Enter a credit card number: 5471841491481471
##5471841491481471 is invalid
##
##Enter a credit card number: 5617418491851851
##5617418491851851 is valid
##
##Enter a credit card number: 37124568957836
##37124568957836 is valid
##
##Enter a credit card number: 37147184364141
##37147184364141 is invalid
##
##Enter a credit card number: 641841658174714
##641841658174714 is invalid


#Test Run 5 for PS2
##>>>
##How many credit card numbers do you want to check? 5
##Enter a credit card number: 681748174817411
##681748174817411 is valid
##
##Enter a credit card number: 569367140945671
##569367140945671 is invalid
##
##Enter a credit card number: 569367140945672
##569367140945672 is valid
##
##Enter a credit card number: 6514817491478
##6514817491478 is invalid
##
##Enter a credit card number: 6524817491478
##6524817491478 is valid

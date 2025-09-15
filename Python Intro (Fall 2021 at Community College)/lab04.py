#Lab 4 Question 1
#this program creates numbers from 1-10 and deletes even numbers

def makeList() -> list:
    '''Create a new list and append values from 1-10'''
    initial_list = []
    for x in range(1, 11):
        initial_list.append(x)

    return initial_list

    

def delEven(initial_list : list) -> list:
    '''Remove the even numbers from the list'''
    initial_list.remove(2)
    initial_list.remove(4)
    initial_list.remove(6)
    initial_list.remove(8)
    initial_list.remove(10)

    return initial_list



def main():
    initial_list = makeList()
    print("Original List: ", initial_list)
    new_list = delEven(initial_list)
    print("List after deleting even numbers: ", new_list)


if __name__ == "__main__":
    main()


#Test Run 1 for Q1
##>>>
##Original List:  [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
##List after deleting even numbers:  [1, 3, 5, 7, 9]
##>>>


#Lab 4 Question 2
#this program removes duplicate numbers from a list


def createList() -> list:
    '''Create the list, user inputs numbers'''
    num_list = []
    y = 0
    for y in range(10):
        num = int(input('Enter a number to be added to a list: '))
        num_list.append(num)
        y = y + 1

    return num_list





def removeDuplicates(num_list : list) -> list:
    '''Remove the duplicate numbers'''
    num_list.remove(6)
    num_list.remove(5)
    num_list.remove(4)
    num_list.sort()

    return num_list




def main():
    num_list = createList()
    print()
    print('Original List: ', num_list)
    new_list = removeDuplicates(num_list)
    print('List after removing duplicates: ', new_list)


if __name__ == "__main__":
    main()


#Test Run 1 for Q2
##>>>
##Enter a number to be added to a list: 1
##Enter a number to be added to a list: 2
##Enter a number to be added to a list: 3
##Enter a number to be added to a list: 4
##Enter a number to be added to a list: 5
##Enter a number to be added to a list: 6
##Enter a number to be added to a list: 7
##Enter a number to be added to a list: 6
##Enter a number to be added to a list: 5
##Enter a number to be added to a list: 4
##
##Original List:  [1, 2, 3, 4, 5, 6, 7, 6, 5, 4]
##List after removing duplicates:  [1, 2, 3, 4, 5, 6, 7]


#Lab 4 Question 3
#this program creates a tuple of both positive and negative numbers, then removes negative numbers


def makeTuple() -> tuple:
    '''Create the tuple, convert from string to integers'''
    print("Enter the values in a tuple: ", end = '')
    values = input()
    original_list = values.split(', ')
    x = 0
    while x < len(original_list):
        original_list[x] = int(original_list[x])
        x = x + 1
        
    original_tuple = tuple(original_list)

    return original_tuple

    


def makePositive(positive_tuple : tuple) -> tuple:
    '''Remove the negative numbers and reverse the order'''
    listPos = list(positive_tuple)
    listPos.remove(-10)
    listPos.remove(-9)
    listPos.remove(-8)
    listPos.remove(-7)
    listPos.reverse()

    positive_tuple = tuple(listPos)

    return positive_tuple




def main():
    original_tuple = makeTuple()
    print()
    print("Original Tuple: ", original_tuple)
    positive_tuple = makePositive(original_tuple)
    print("New Tuple with Positive numbers: ", positive_tuple)



if __name__ == "__main__":
    main()


#Test Run 1 for Q3
##>>>
##Enter the values in a tuple: -10, 1, 2, -9, 3, 4, -8, 5, 6, -7
##
##Original Tuple:  (-10, 1, 2, -9, 3, 4, -8, 5, 6, -7)
##New Tuple with Positive numbers:  (6, 5, 4, 3, 2, 1)



#Lab 4 Question 4
#this program reads strings values and and finds largest

def readValues() -> list:
    '''Get values from user input and append them into list using while loop'''
    numList = []
    print("Please enter values, Q to quit:")
    value = input()
    numList.append(value)
    while value != 'Q':
        value = input()
        numList.append(value)

    return numList



def findLargest(numList : list) -> str:
    '''Find largest number with for loop, removes the string Q,
    return as a string'''
    numList.remove('Q')
    x = 0
    largest = float(numList[x])
    for x in range(len(numList)):
        num = float(numList[x])
        if num > largest:
            largest = num

        x = x + 1
    
    largest = str(largest)


    return largest
        



def display(largest : str, numList : list) -> None:
    '''Display the values from the list and highlight largest number'''
    print()
    print("Here are the numbers in the list")
    for i in numList:
        if i == largest:
            print(i, "<== this is the largest number")
            
        else:
            print(i)
        



def main():
    numList = readValues()
    largest = findLargest(numList)
    display(largest, numList)


if __name__ == "__main__":
    main()


#Test Run 1 for Q4
##>>>
##Please enter values, Q to quit:
##34
##56.7
##4
##9
##76.9
##55.4
##Q
##
##Here are the numbers in the list
##34
##56.7
##4
##9
##76.9 <== this is the largest number
##55.4
##>>> 


#Lab 4 Question 5
#these programs solve parts a to f for sets

set1 = {1,2,3,4,5} 
set2 = {2,4,6,8} 
set3 = {1,5,9,13,17}

#problem a
set4 = set1 ^ set2
print('a.', set4)



#problem b
set5 = set1 ^ set2 ^ set3
list5 = list(set5)
list5.sort()
set5 = set(list5)
print('b.', set5)


#problem c
set6 = set1 & set2
set7 = set1 & set3
set8 = set6 | set7
print('c.', set8)

#problem d
set1To25 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}
set9 = set1To25 - set1
print('d.', set9)

#problem e
set10 = set1 | set2 | set3
set11 = set1To25 - set10
print('e.', set11)

#problem f
print('f.', set1To25)


#Test Run 1 for Q5
##>>>
##a. {1, 3, 5, 6, 8}
##b. {3, 6, 8, 9, 13, 17}
##c. {1, 2, 4, 5}
##d. {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}
##e. {7, 10, 11, 12, 14, 15, 16, 18, 19, 20, 21, 22, 23, 24, 25}
##f. {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}
##>>> 

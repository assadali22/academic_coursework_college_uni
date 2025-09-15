#Homework 4 Program Set 1
#this program tests different tasks for a list of integers such as
#shifting elements, replacing elements, and more

#ONE_TEN = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
#ONE_TEN =  [12, 20, 10, 14, 54, 16, 75, 38, 79, 103] #this is test run 2  
ONE_TEN = [1, 25, 25, 4, 5, 4, 7, 60, 9, 10] #test run 3


def swapFirstLast(data : list) -> list:
    '''Swap the first and last element in the list.'''
    temp = data[0]
    data[0] = data[9]
    data[9] = temp

    return data



def shiftRight(data : list) -> list:
    '''Shift the elements of the list to the right.'''
    temp = data[9]
    for i in range(9, 0, -1):
        data[i] = data[i - 1]

    data[0] = temp

    return data



def replaceEven(data : list) -> list:
    '''Replace even numbers with zeros.'''
    for num in data:
        if num % 2 == 0:
            index = data.index(num)
            data[index] = 0


    return data



def replaceNeighbors(data : list) -> list:
    '''Replace the values except the first and last number with
    the larger of their neighbors.'''
    for x in range (1, 9):
        if data[x - 1] > data[x + 1]:
            data[x] = data[x - 1]
        else:
            data[x] = data[x + 1]
        
        x = x + 1

    return data



def removeMiddle(data : list) -> list:
    '''Remove the middle elements in the list.'''
    data.pop(4)
    data.pop(4)

    return data



def evenToFront(data : list) -> list:
    '''Bring the even elements to the front of the list.'''
    oddList = []
    for num in data:
        if num % 2 != 0:
            oddList.append(num)
    
    
    for num in oddList:
        data.remove(num)
        data.append(num)
        
    return data
    


def secondLargest(ONE_TEN : list) -> int:
    '''Find the second largest number and return it as an integer.'''
    data = list(ONE_TEN)
    data.sort()
    secondLargest = data[8]
    
    return secondLargest



def isIncreasing(ONE_TEN : list) -> bool:
    '''Determine if the list is in increasing order.'''
    z = 0
    while z < len(ONE_TEN) - 1:
        if ONE_TEN[z + 1] > ONE_TEN[z]:
            isIncreasing = True
        else:
            isIncreasing = False
            z = 9
        
        z = z + 1
    
    return isIncreasing



def hasAdjacentDuplicate(ONE_TEN : list) -> bool:
    '''Determine if the list has duplicates right next to each other.'''
    hasAdjacentDuplicate = False
    j = 0
    while j < len(ONE_TEN) - 1:
        if ONE_TEN[j] == ONE_TEN[j + 1]:
            hasAdjacentDuplicate = True
            j = 9
        else:
            j = j + 1
            
    
    return hasAdjacentDuplicate



def hasDuplicate(ONE_TEN : list) -> bool:
    '''Determine if the list has any duplicates.'''
    hasDuplicate = False
    data = list(ONE_TEN)
    data.sort()
    w = 0
    while w < len(ONE_TEN) - 1:
        if data[w] == data[w + 1]:
            hasDuplicate = True
            w = 9
        else:
            w = w + 1
    
    
    return hasDuplicate



def main():
    print("The original data for all functions is: ", ONE_TEN) 

    #a. Demonstrate swapping the first and last element. 
    data = list(ONE_TEN) 
    swapFirstLast(data)
    print("After swapping first and last: ", data) 

    #b. Demonstrate shifting to the right. 
    data = list(ONE_TEN) 
    shiftRight(data)
    print("After shifting right: ", data) 

    #c. Demonstrate replacing even elements with zero. 
    data = list(ONE_TEN)
    replaceEven(data)
    print("After replacing even elements: ", data) 

    #d. Demonstrate replacing values with the larger of their neighbors. 
    data = list(ONE_TEN) 
    replaceNeighbors(data)
    print("After replacing with neighbors: ", data) 

    #e. Demonstrate removing the middle element. 
    data = list(ONE_TEN) 
    removeMiddle(data)
    print("After removing the middle element(s): ", data) 

    #f. Demonstrate moving even elements to the front of the list. 
    data = list(ONE_TEN) 
    evenToFront(data)
    print("After moving even elements: ", data) 

    #g. Demonstrate finding the second largest value. 
    print("The second largest value is: ", secondLargest(ONE_TEN)) 

    #h. Demonstrate testing if the list is in increasing order. 
    print("The list is in increasing order: ", isIncreasing(ONE_TEN)) 

    #i. Demonstrate testing if the list contains adjacent duplicates. 
    print("The list has adjacent duplicates: ", hasAdjacentDuplicate(ONE_TEN)) 

    #j. Demonstrate testing if the list contains duplicates. 
    print("The list has duplicates: ", hasDuplicate(ONE_TEN)) 



if __name__ == "__main__":
    main()


#Test Run 1 for PS1
##>>>
##The original data for all functions is:  [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
##After swapping first and last:  [10, 2, 3, 4, 5, 6, 7, 8, 9, 1]
##After shifting right:  [10, 1, 2, 3, 4, 5, 6, 7, 8, 9]
##After replacing even elements:  [1, 0, 3, 0, 5, 0, 7, 0, 9, 0]
##After replacing with neighbors:  [1, 3, 4, 5, 6, 7, 8, 9, 10, 10]
##After removing the middle element(s):  [1, 2, 3, 4, 7, 8, 9, 10]
##After moving even elements:  [2, 4, 6, 8, 10, 1, 3, 5, 7, 9]
##The second largest value is:  9
##The list is in increasing order:  True
##The list has adjacent duplicates:  False
##The list has duplicates:  False
##>>>


#Test Run 2 for PS1
##>>>
##The original data for all functions is:  [12, 20, 10, 14, 54, 16, 75, 38, 79, 103]
##After swapping first and last:  [103, 20, 10, 14, 54, 16, 75, 38, 79, 12]
##After shifting right:  [103, 12, 20, 10, 14, 54, 16, 75, 38, 79]
##After replacing even elements:  [0, 0, 0, 0, 0, 0, 75, 0, 79, 103]
##After replacing with neighbors:  [12, 12, 14, 54, 54, 75, 75, 79, 103, 103]
##After removing the middle element(s):  [12, 20, 10, 14, 75, 38, 79, 103]
##After moving even elements:  [12, 20, 10, 14, 54, 16, 38, 75, 79, 103]
##The second largest value is:  79
##The list is in increasing order:  False
##The list has adjacent duplicates:  False
##The list has duplicates:  False
##>>>


#Test Run 3 for PS1
##>>>
##The original data for all functions is:  [1, 25, 25, 4, 5, 4, 7, 60, 9, 10]
##After swapping first and last:  [10, 25, 25, 4, 5, 4, 7, 60, 9, 1]
##After shifting right:  [10, 1, 25, 25, 4, 5, 4, 7, 60, 9]
##After replacing even elements:  [1, 25, 25, 0, 5, 0, 7, 0, 9, 0]
##After replacing with neighbors:  [1, 25, 25, 25, 25, 25, 60, 60, 60, 10]
##After removing the middle element(s):  [1, 25, 25, 4, 7, 60, 9, 10]
##After moving even elements:  [4, 4, 60, 10, 1, 25, 25, 5, 7, 9]
##The second largest value is:  25
##The list is in increasing order:  False
##The list has adjacent duplicates:  True
##The list has duplicates:  True
##>>>


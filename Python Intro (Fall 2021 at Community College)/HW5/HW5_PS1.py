#Homework 5 Program Set 1
#this program calculate and displays the loan for buy a car using classes and objects

class Loan:
    def __init__(self, annualInterestRate = 2.5,  
                 numberOfYears = 1, loanAmount = 1000, borrower = " "):
        '''Initializer or constructor for the class with private data fields.'''
        self.__annualInterestRate = annualInterestRate
        self.__numberOfYears = numberOfYears
        self.__loanAmount = loanAmount
        self.__borrower = borrower



    def getMonthlyPayment(self): 
        '''Get the monthly payment and return it as a float.'''
        monthlyInterestRate = self.__annualInterestRate / 1200
        monthlyPayment = self.__loanAmount * monthlyInterestRate / (1 - (1 / (1 + monthlyInterestRate) ** (self.__numberOfYears * 12)))
        
        return monthlyPayment


    def getTotalPayment(self):
        '''Get the total payment and return it as a float.'''
        totalPayment = self.getMonthlyPayment()  *  self.__numberOfYears * 12
        
        return totalPayment
    

    def getAnnualRate(self):
        '''Obtain the annual interest rate.'''
        return self.__annualInterestRate
    


    def getYears(self):
        '''Obtain the number of years.'''
        return self.__numberOfYears
    
    

    def getLoanAmount(self):
        '''Obtain the loan amount'''
        return self.__loanAmount
    
    

    def getBorrower(self):
        '''Obtain the borrower's name'''
        return self.__borrower
    

    def setAnnualRate(self, annualInterestRate):
        '''Change the annual interest rate.'''
        self.__annualInterestRate = annualInterestRate


    def setYears(self, numberOfYears):
        '''Change the number of years.'''
        self.__numberOfYears = numberOfYears


    def setLoanAmount(self, loanAmount):
        '''Change the loan amount.'''
        self.__loanAmount = loanAmount


    def setBorrower(self, borrower):
        '''Change the borrower's name.'''
        self.__borrower = borrower

        

def main():
    annualInterestRate = float(input("Enter yearly interest rate: "))
    numberOfYears = float(input("Enter number of years as an integer: "))
    loanAmount = float(input("Enter loan amount: "))
    borrower = input("Enter a borrower's name: ")
    loan1 = Loan(annualInterestRate, numberOfYears, loanAmount, borrower)
    print('The loan is for', loan1.getBorrower())
    print('The monthly payment is', format(loan1.getMonthlyPayment(), ',.2f'))
    print('The total payment is', format(loan1.getTotalPayment(), ',.2f'))
    print()
    change = input('Do you want to change the loan amount? Y for yes or enter to quit ')
    while change.lower() == 'y':
        loanAmount = float(input("Enter new loan amount "))
        loan1.setLoanAmount(loanAmount)
        print('The loan is for', loan1.getBorrower())
        print('The monthly payment is', format(loan1.getMonthlyPayment(), ',.2f'))
        print('The total payment is', format(loan1.getTotalPayment(), ',.2f'))
        print()
        change = input('Do you want to change the loan amount? Y for yes or enter to quit ')
        

if __name__ == "__main__":
    main()


#Test Run 1 for PS1
##Enter yearly interest rate: 2.5
##Enter number of years as an integer: 5
##Enter loan amount: 1000.00
##Enter a borrower's name: John Jones
##The loan is for John Jones
##The monthly payment is 17.75
##The total payment is 1,064.84
##
##Do you want to change the loan amount? Y for yes or enter to quit y
##Enter new loan amount 5000
##The loan is for John Jones
##The monthly payment is 88.74
##The total payment is 5,324.21
##
##Do you want to change the loan amount? Y for yes or enter to quit
##>>>  
    

#Test Run 2 for PS1
##Enter yearly interest rate: 5.3
##Enter number of years as an integer: 4
##Enter loan amount: 3000.00
##Enter a borrower's name: Angel
##The loan is for Angel
##The monthly payment is 69.50
##The total payment is 3,335.82
##
##Do you want to change the loan amount? Y for yes or enter to quit Y
##Enter new loan amount 1060
##The loan is for Angel
##The monthly payment is 24.56
##The total payment is 1,178.66
##
##Do you want to change the loan amount? Y for yes or enter to quit Y
##Enter new loan amount 900
##The loan is for Angel
##The monthly payment is 20.85
##The total payment is 1,000.75
##
##Do you want to change the loan amount? Y for yes or enter to quit
##>>>


#Test Run 3 for PS1
##Enter yearly interest rate: 4.8
##Enter number of years as an integer: 8
##Enter loan amount: 7800.50
##Enter a borrower's name: Ryan
##The loan is for Ryan
##The monthly payment is 98.01
##The total payment is 9,409.21
##
##Do you want to change the loan amount? Y for yes or enter to quit Y
##Enter new loan amount 8000.25
##The loan is for Ryan
##The monthly payment is 100.52
##The total payment is 9,650.16
##
##Do you want to change the loan amount? Y for yes or enter to quit y
##Enter new loan amount 1320
##The loan is for Ryan
##The monthly payment is 16.59
##The total payment is 1,592.23
##
##Do you want to change the loan amount? Y for yes or enter to quit Y
##Enter new loan amount 2240
##The loan is for Ryan
##The monthly payment is 28.15
##The total payment is 2,701.96
##
##Do you want to change the loan amount? Y for yes or enter to quit
#>>>


#Test Run 4 for PS1
##Enter yearly interest rate: 6.5
##Enter number of years as an integer: 10
##Enter loan amount: 5000.00
##Enter a borrower's name: Lisbeth
##The loan is for Lisbeth
##The monthly payment is 56.77
##The total payment is 6,812.88
##
##Do you want to change the loan amount? Y for yes or enter to quit y
##Enter new loan amount 9400
##The loan is for Lisbeth
##The monthly payment is 106.74
##The total payment is 12,808.21
##
##Do you want to change the loan amount? Y for yes or enter to quit Y
##Enter new loan amount 6255
##The loan is for Lisbeth
##The monthly payment is 71.02
##The total payment is 8,522.91
##
##Do you want to change the loan amount? Y for yes or enter to quit y
##Enter new loan amount 2350.75
##The loan is for Lisbeth
##The monthly payment is 26.69
##The total payment is 3,203.07
##
##Do you want to change the loan amount? Y for yes or enter to quit y
##Enter new loan amount 1875.25
##The loan is for Lisbeth
##The monthly payment is 21.29
##The total payment is 2,555.17
##
##Do you want to change the loan amount? Y for yes or enter to quit
##>>>


#Test Run 5 for PS1
##Enter yearly interest rate: 14.4
##Enter number of years as an integer: 12
##Enter loan amount: 14500
##Enter a borrower's name: Bill Nye
##The loan is for Bill Nye
##The monthly payment is 212.06
##The total payment is 30,536.58
##
##Do you want to change the loan amount? Y for yes or enter to quit Y
##Enter new loan amount 16100.60
##The loan is for Bill Nye
##The monthly payment is 235.47
##The total payment is 33,907.40
##
##Do you want to change the loan amount? Y for yes or enter to quit y
##Enter new loan amount 20340
##The loan is for Bill Nye
##The monthly payment is 297.47
##The total payment is 42,835.45
##
##Do you want to change the loan amount? Y for yes or enter to quit Y
##Enter new loan amount 28545.50
##The loan is for Bill Nye
##The monthly payment is 417.47
##The total payment is 60,116.00
##
##Do you want to change the loan amount? Y for yes or enter to quit y
##Enter new loan amount 17700.30
##The loan is for Bill Nye
##The monthly payment is 258.86
##The total payment is 37,276.32
##
##Do you want to change the loan amount? Y for yes or enter to quit y
##Enter new loan amount 19980
##The loan is for Bill Nye
##The monthly payment is 292.20
##The total payment is 42,077.30
##
##Do you want to change the loan amount? Y for yes or enter to quit 
##>>>
    


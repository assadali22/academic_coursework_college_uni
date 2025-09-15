#Homework 3 Program Set 1
#This program calculates profit, stock purchase and selling price and shares using functions

    

def get_stock_name() -> str:
    '''Get stock name from the user and return it'''
    stock_name = input("Enter stock name: ")

    return stock_name



def get_shares() -> int:
    '''Get number of shares from the user and return it'''
    num_of_shares = int(input("Enter number of shares: "))

    return num_of_shares



def get_purchase() -> float:
    '''Get purchase price from the user and return it'''
    purchase_price = float(input("Enter purchase price: "))

    return purchase_price



def get_selling() -> float:
    '''Get selling price from the user and return it'''
    selling_price = float(input("Enter selling price: "))

    return selling_price




def get_comm() -> float:
    '''Get commission from the user and return it'''
    comm_rate = float(input("Enter commission: "))

    return comm_rate




def calc(num_of_shares : int, purchase_price : float, selling_price : float, comm_rate : float) -> (float, float, float, float, float):
    '''Calculate amount paid and amount sold for the stock,
    commission paid on purchase and sale, and profit. Then return these values'''
    AmountPaidStock = num_of_shares * purchase_price
    
    CommPaidPurchase = AmountPaidStock * comm_rate
    
    AmountStockSold = num_of_shares * selling_price
    
    CommPaidSale = AmountStockSold * comm_rate
    
    Profit = (AmountStockSold - CommPaidSale) - (AmountPaidStock + CommPaidPurchase)

    return AmountPaidStock, CommPaidPurchase, AmountStockSold, CommPaidSale, Profit





def output(stock_name : str, AmountPaidStock : float, CommPaidPurchase : float, AmountStockSold : float, CommPaidSale : float, Profit : float) -> None:
    '''print the amount stock was paid and sold for, and commission paid on purchase and sale, and profit.'''
    print("Stock name: ", stock_name)
    print("Amount paid for the stock:          $", format(AmountPaidStock, '13,.2f'))
    print("Commission paid on the purchase:    $", format(CommPaidPurchase, '13,.2f'))
    print("Amount the stock sold for:          $", format(AmountStockSold, '13,.2f'))
    print("Commission paid on the sale:        $", format(CommPaidSale, '13,.2f'))
    print("Profit:                             $", format(Profit, '13,.2f'))





def main():
    again = input("Enter your stock information? Type 'y' for yes, or 'n' for no: ")
    while again.lower() == 'y':
        print()
        stock_name = get_stock_name()
        num_of_shares = get_shares()
        purchase_price = get_purchase()
        selling_price = get_selling()
        comm_rate = get_comm()
        AmountPaidStock, CommPaidPurchase, AmountStockSold, CommPaidSale, Profit = calc(num_of_shares, purchase_price, selling_price, comm_rate)
        print('\n')
        output(stock_name, AmountPaidStock, CommPaidPurchase, AmountStockSold, CommPaidSale, Profit)
        print('\n')
        again = input("Enter your stock information? Type 'y' for yes, or 'n' for no: ")



if __name__ == "__main__":
    main()


#Test Run 1 for PS1
##>>>
##Enter your stock information? Type 'y' for yes, or 'n' for no: y
##
##Enter stock name: Kaplack, Inc.
##Enter number of shares: 10000
##Enter purchase price: 33.92
##Enter selling price: 35.92
##Enter commission: 0.04
##
##
##Stock name:  Kaplack, Inc.
##Amount paid for the stock:          $    339,200.00
##Commission paid on the purchase:    $     13,568.00
##Amount the stock sold for:          $    359,200.00
##Commission paid on the sale:        $     14,368.00
##Profit:                             $     -7,936.00
##
##
##Enter your stock information? Type 'y' for yes, or 'n' for no: y
##
##Enter stock name: IBM
##Enter number of shares: 15000
##Enter purchase price: 50.25
##Enter selling price: 100.20
##Enter commission: 0.02
##
##
##Stock name:  IBM
##Amount paid for the stock:          $    753,750.00
##Commission paid on the purchase:    $     15,075.00
##Amount the stock sold for:          $  1,503,000.00
##Commission paid on the sale:        $     30,060.00
##Profit:                             $    704,115.00
##
##
##Enter your stock information? Type 'y' for yes, or 'n' for no: n
##>>> 


#Test Run 2 for PS1
##>>>
##Enter your stock information? Type 'y' for yes, or 'n' for no: n
##>>>

#Test Run 3 for PS1
##>>>
##Enter your stock information? Type 'y' for yes, or 'n' for no: Y
##
##Enter stock name: Dell
##Enter number of shares: 14500
##Enter purchase price: 60
##Enter selling price: 49.95
##Enter commission: 0.12
##
##
##Stock name:  Dell
##Amount paid for the stock:          $    870,000.00
##Commission paid on the purchase:    $    104,400.00
##Amount the stock sold for:          $    724,275.00
##Commission paid on the sale:        $     86,913.00
##Profit:                             $   -337,038.00
##
##
##Enter your stock information? Type 'y' for yes, or 'n' for no: y
##
##Enter stock name: Lays
##Enter number of shares: 6000
##Enter purchase price: 123.25
##Enter selling price: 145.20
##Enter commission: 0.09
##
##
##Stock name:  Lays
##Amount paid for the stock:          $    739,500.00
##Commission paid on the purchase:    $     66,555.00
##Amount the stock sold for:          $    871,200.00
##Commission paid on the sale:        $     78,408.00
##Profit:                             $    -13,263.00
##
##
##Enter your stock information? Type 'y' for yes, or 'n' for no: Y
##
##Enter stock name: Gamestop
##Enter number of shares: 22000
##Enter purchase price: 432
##Enter selling price: 299.50
##Enter commission: 0.18
##
##
##Stock name:  Gamestop
##Amount paid for the stock:          $  9,504,000.00
##Commission paid on the purchase:    $  1,710,720.00
##Amount the stock sold for:          $  6,589,000.00
##Commission paid on the sale:        $  1,186,020.00
##Profit:                             $ -5,811,740.00
##
##
##Enter your stock information? Type 'y' for yes, or 'n' for no: n
##>>>


#Test Run 4 for PS1
##>>>
##Enter your stock information? Type 'y' for yes, or 'n' for no: y
##
##Enter stock name: Nike
##Enter number of shares: 7500
##Enter purchase price: 165.25
##Enter selling price: 137.85
##Enter commission: 0.10
##
##
##Stock name:  Nike
##Amount paid for the stock:          $  1,239,375.00
##Commission paid on the purchase:    $    123,937.50
##Amount the stock sold for:          $  1,033,875.00
##Commission paid on the sale:        $    103,387.50
##Profit:                             $   -432,825.00
##
##
##Enter your stock information? Type 'y' for yes, or 'n' for no: y
##
##Enter stock name: Vans Off the Wall
##Enter number of shares: 4400
##Enter purchase price: 77.85
##Enter selling price: 49.99
##Enter commission: 0.15
##
##
##Stock name:  Vans Off the Wall
##Amount paid for the stock:          $    342,540.00
##Commission paid on the purchase:    $     51,381.00
##Amount the stock sold for:          $    219,956.00
##Commission paid on the sale:        $     32,993.40
##Profit:                             $   -206,958.40
##
##
##Enter your stock information? Type 'y' for yes, or 'n' for no: n
##>>>


#Test Run 5 for PS1
##>>>
##Enter your stock information? Type 'y' for yes, or 'n' for no: y
##
##Enter stock name: Nintendo
##Enter number of shares: 12350
##Enter purchase price: 67.75
##Enter selling price: 89.50
##Enter commission: 0.25
##
##
##Stock name:  Nintendo
##Amount paid for the stock:          $    836,712.50
##Commission paid on the purchase:    $    209,178.12
##Amount the stock sold for:          $  1,105,325.00
##Commission paid on the sale:        $    276,331.25
##Profit:                             $   -216,896.88
##
##
##Enter your stock information? Type 'y' for yes, or 'n' for no: y
##
##Enter stock name: Costco
##Enter number of shares: 8800
##Enter purchase price: 310.50
##Enter selling price: 245.10
##Enter commission: 0.05
##
##
##Stock name:  Costco
##Amount paid for the stock:          $  2,732,400.00
##Commission paid on the purchase:    $    136,620.00
##Amount the stock sold for:          $  2,156,880.00
##Commission paid on the sale:        $    107,844.00
##Profit:                             $   -819,984.00
##
##
##Enter your stock information? Type 'y' for yes, or 'n' for no: y
##
##Enter stock name: Apple
##Enter number of shares: 9600
##Enter purchase price: 120.50
##Enter selling price: 174.25
##Enter commission: 0.30
##
##
##Stock name:  Apple
##Amount paid for the stock:          $  1,156,800.00
##Commission paid on the purchase:    $    347,040.00
##Amount the stock sold for:          $  1,672,800.00
##Commission paid on the sale:        $    501,840.00
##Profit:                             $   -332,880.00
##
##
##Enter your stock information? Type 'y' for yes, or 'n' for no: n
##>>> 


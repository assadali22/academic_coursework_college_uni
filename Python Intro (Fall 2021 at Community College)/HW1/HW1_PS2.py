#Homework 1 Program Set 2
#This program calculates the amount paid, commission, selling price, commission paid on the sale, and the profit of a stock.

#Input
#Let the user input the stock name, number of shares, purchase price, selling price, and comission
input("Enter Stock Name:")
number_of_shares = float(input("Enter Number of shares:"))
purchase_price = float(input("Enter Purchase price:"))
selling_price = float(input("Enter selling price:"))
commission = float(input("Enter Commission:"))


#Processing/Calculation
#Calculate the amount paid for the stock, commission paid on the purchase, the amount the stock sold for, commission paid on the sale, and the profit.
AmountPaidStock = number_of_shares * purchase_price
CommissionPaidPurchase = AmountPaidStock * commission
AmountStockSold = number_of_shares * selling_price
CommissionPaidSale = AmountStockSold * commission
Profit = (AmountStockSold - CommissionPaidSale) - (AmountPaidStock + CommissionPaidPurchase)



#Output
#Define the commission, amount sold and paid for the stock, and the profit.
print("Amount paid for the stock:          $", format(AmountPaidStock, '13,.2f'))
print("Commission paid on the purchase:    $", format(CommissionPaidPurchase, '13,.2f'))
print("Amount the stock sold for:          $", format(AmountStockSold, '13,.2f'))
print("Commission paid on the sale:        $", format(CommissionPaidSale, '13,.2f'))
print("Profit:                             $", format(Profit, '13,.2f'))


##Test Run 1
##Enter Stock Name:Kaplack, Inc.
##Enter Number of shares:10000
##Enter Purchase price:33.92
##Enter selling price:35.92
##Enter Commission:0.04
##Amount paid for the stock:          $    339,200.00
##Commission paid on the purchase:    $     13,568.00
##Amount the stock sold for:          $    359,200.00
##Commission paid on the sale:        $     14,368.00
##Profit:                             $     -7,936.00
##
##Test Run 2
##Enter Stock Name:IBM
##Enter Number of shares:15000
##Enter Purchase price:50.25
##Enter selling price:100.20
##Enter Commission:0.02
##Amount paid for the stock:          $    753,750.00
##Commission paid on the purchase:    $     15,075.00
##Amount the stock sold for:          $  1,503,000.00
##Commission paid on the sale:        $     30,060.00
##Profit:                             $    704,115.00
##
##Test Run 3
##Enter Stock Name:Nintendo
##Enter Number of shares:37000
##Enter Purchase price:126.50
##Enter selling price:175.25
##Enter Commission:0.07
##Amount paid for the stock:          $  4,680,500.00
##Commission paid on the purchase:    $    327,635.00
##Amount the stock sold for:          $  6,484,250.00
##Commission paid on the sale:        $    453,897.50
##Profit:                             $  1,022,217.50
##
##Test Run 4
##Enter Stock Name:Bandai Namco
##Enter Number of shares:12500
##Enter Purchase price:60
##Enter selling price:95.50
##Enter Commission:0.08
##Amount paid for the stock:          $    750,000.00
##Commission paid on the purchase:    $     60,000.00
##Amount the stock sold for:          $  1,193,750.00
##Commission paid on the sale:        $     95,500.00
##Profit:                             $    288,250.00
##
##Test Run 5
##Enter Stock Name:Walmart
##Enter Number of shares:9400
##Enter Purchase price:120
##Enter selling price:99
##Enter Commission:0.04
##Amount paid for the stock:          $  1,128,000.00
##Commission paid on the purchase:    $     45,120.00
##Amount the stock sold for:          $    930,600.00
##Commission paid on the sale:        $     37,224.00
##Profit:                             $   -279,744.00



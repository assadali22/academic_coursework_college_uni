#Homework 2 Program Set 2
#this program calculates tax in 2017 and 2018 given income input by user
#user inputs income as much as they want until they enter negative income.

#Input
income = int(input("Enter income as an integer with no commas: "))

#Processing/Output

while income >= 0:
    #compare 2017 income
    bracket1_2017 = 932.50
    bracket2_2017 = 4293.75
    bracket3_2017 = 13487.50
    bracket4_2017 = 27930
    bracket5_2017 = 74266.50
    bracket6_2017 = 595
    
    if income <= 9325:
        tax_rate_2017 = .10
        total_tax_2017 = income * tax_rate_2017
        
    elif 9326 <= income <= 37950:
        tax_rate_2017 = .15
        tax_bracket_2017 = income - 9325
        taxable_bracket_2017 = tax_bracket_2017 * tax_rate_2017
        total_tax_2017 = bracket1_2017 + taxable_bracket_2017
        
    elif 37951 <= income <= 91900:
        tax_rate_2017 = .25
        tax_bracket_2017 = income - 37950
        taxable_bracket_2017 = tax_bracket_2017 * tax_rate_2017
        total_tax_2017 = bracket1_2017 + bracket2_2017 + taxable_bracket_2017
        
    elif 91901 <= income <= 191650:
        tax_rate_2017 = .28
        tax_bracket_2017 = income - 91900
        taxable_bracket_2017 = tax_bracket_2017 * tax_rate_2017
        total_tax_2017 = bracket1_2017 + bracket2_2017 + bracket3_2017 + taxable_bracket_2017
        
    elif 191651 <= income <= 416700:
        tax_rate_2017 = .33
        tax_bracket_2017 = income - 191650
        taxable_bracket_2017 = tax_bracket_2017 * tax_rate_2017
        total_tax_2017 = bracket1_2017 + bracket2_2017 + bracket3_2017 + bracket4_2017 + taxable_bracket_2017
        
    elif 416701 <= income <= 418400:
        tax_rate_2017 = .35
        tax_bracket_2017 = income - 416700
        taxable_bracket_2017 = tax_bracket_2017 * tax_rate_2017
        total_tax_2017 = bracket1_2017 + bracket2_2017 + bracket3_2017 + bracket4_2017 + bracket5_2017 + taxable_bracket_2017
        
    elif income > 418400:
        tax_rate_2017 = .396
        tax_bracket_2017 = income - 418400
        taxable_bracket_2017 = tax_bracket_2017 * tax_rate_2017
        total_tax_2017 = bracket1_2017 + bracket2_2017 + bracket3_2017 + bracket4_2017 + bracket5_2017 + bracket6_2017 + taxable_bracket_2017

    


    #compare 2018 income
    bracket1_2018 = 952.50
    bracket2_2018 = 3501
    bracket3_2018 = 9636
    bracket4_2018 = 18000
    bracket5_2018 = 13600
    bracket6_2018 = 105000
    
    
    if income <= 9525:
        tax_rate_2018 = .10
        total_tax_2018 = income * tax_rate_2018
        
    elif 9526 <= income <= 38700:
        tax_rate_2018 = .12
        tax_bracket_2018 = income - 9525
        taxable_bracket_2018 = tax_bracket_2018 * tax_rate_2018
        total_tax_2018 = bracket1_2018 + taxable_bracket_2018
        
    elif 38701 <= income <= 82500:
        tax_rate_2018 = .22
        tax_bracket_2018 = income - 38700
        taxable_bracket_2018 = tax_bracket_2018 * tax_rate_2018
        total_tax_2018 = bracket1_2018 + bracket2_2018 + taxable_bracket_2018
        
    elif 82501 <= income <= 157500:
        tax_rate_2018 = .24
        tax_bracket_2018 = income - 82500
        taxable_bracket_2018 = tax_bracket_2018 * tax_rate_2018
        total_tax_2018 = bracket1_2018 + bracket2_2018 + bracket3_2018 + taxable_bracket_2018
        
    elif 157501 <= income <= 200000:
        tax_rate_2018 = .32
        tax_bracket_2018 = income - 157500
        taxable_bracket_2018 = tax_bracket_2018 * tax_rate_2018
        total_tax_2018 = bracket1_2018 + bracket2_2018 + bracket3_2018 + bracket4_2018 + taxable_bracket_2018
        
    elif 200001 <= income <= 500000:
        tax_rate_2018 = .35
        tax_bracket_2018 = income - 200000
        taxable_bracket_2018 = tax_bracket_2018 * tax_rate_2018
        total_tax_2018 = bracket1_2018 + bracket2_2018 + bracket3_2018 + bracket4_2018 + bracket5_2018 + taxable_bracket_2018
        
    elif income > 500000:
        tax_rate_2018 = .37
        tax_bracket_2018 = income - 500000
        taxable_bracket_2018 = tax_bracket_2018 * tax_rate_2018
        total_tax_2018 = bracket1_2018 + bracket2_2018 + bracket3_2018 + bracket4_2018 + bracket5_2018 + bracket6_2018 + taxable_bracket_2018


    

    difference = total_tax_2018 - total_tax_2017

    percent_difference = (difference/total_tax_2017) * 100
    percent_difference = percent_difference * -1



    print("Income: ", income)
    print("2017 tax: ", format(total_tax_2017, '.2f'))
    print("2018 tax: ", format(total_tax_2018, '.2f'))
    print("Difference: ", format(difference, '.2f'))
    print("Difference (percent): ", format(percent_difference, '.2f'))
    print()

    income = int(input("Enter income as an integer with no commas: "))




#Test Run 1 for Program Set 2
##>>>
##Enter income as an integer with no commas: 8000
##Income:  8000
##2017 tax:  800.00
##2018 tax:  800.00
##Difference:  0.00
##Difference (percent):  -0.00
##
##Enter income as an integer with no commas: 15000
##Income:  15000
##2017 tax:  1783.75
##2018 tax:  1609.50
##Difference:  -174.25
##Difference (percent):  9.77
##
##Enter income as an integer with no commas: 40000
##Income:  40000
##2017 tax:  5738.75
##2018 tax:  4739.50
##Difference:  -999.25
##Difference (percent):  17.41
##
##Enter income as an integer with no commas: 100000
##Income:  100000
##2017 tax:  20981.75
##2018 tax:  18289.50
##Difference:  -2692.25
##Difference (percent):  12.83
##
##Enter income as an integer with no commas: 200000
##Income:  200000
##2017 tax:  49399.25
##2018 tax:  45689.50
##Difference:  -3709.75
##Difference (percent):  7.51
##
##Enter income as an integer with no commas: 500000
##Income:  500000
##2017 tax:  153818.85
##2018 tax:  150689.50
##Difference:  -3129.35
##Difference (percent):  2.03
##
##Enter income as an integer with no commas: 1000000
##Income:  1000000
##2017 tax:  351818.85
##2018 tax:  335689.50
##Difference:  -16129.35
##Difference (percent):  4.58
##
##Enter income as an integer with no commas: 10000000
##Income:  10000000
##2017 tax:  3915818.85
##2018 tax:  3665689.50
##Difference:  -250129.35
##Difference (percent):  6.39
##
##Enter income as an integer with no commas: -1
##>>>


#Test Run 2 for Program Set 2
##>>>
##Enter income as an integer with no commas: -1
##>>> 

#Test Run 3 for Program Set 2
##>>>
##Enter income as an integer with no commas: 41650
##Income:  41650
##2017 tax:  6151.25
##2018 tax:  5102.50
##Difference:  -1048.75
##Difference (percent):  17.05
##
##Enter income as an integer with no commas: 35400
##Income:  35400
##2017 tax:  4843.75
##2018 tax:  4057.50
##Difference:  -786.25
##Difference (percent):  16.23
##
##Enter income as an integer with no commas: 56755
##Income:  56755
##2017 tax:  9927.50
##2018 tax:  8425.60
##Difference:  -1501.90
##Difference (percent):  15.13
##
##Enter income as an integer with no commas: 14845
##Income:  14845
##2017 tax:  1760.50
##2018 tax:  1590.90
##Difference:  -169.60
##Difference (percent):  9.63
##
##Enter income as an integer with no commas: -1
##>>> 

#Test Run 4 for Program Set 2
##>>>
##Enter income as an integer with no commas: 56755
##Income:  56755
##2017 tax:  9927.50
##2018 tax:  8425.60
##Difference:  -1501.90
##Difference (percent):  15.13
##
##Enter income as an integer with no commas: 54185
##Income:  54185
##2017 tax:  9285.00
##2018 tax:  7860.20
##Difference:  -1424.80
##Difference (percent):  15.35
##
##Enter income as an integer with no commas: 78980
##Income:  78980
##2017 tax:  15483.75
##2018 tax:  13315.10
##Difference:  -2168.65
##Difference (percent):  14.01
##
##Enter income as an integer with no commas: 95140
##Income:  95140
##2017 tax:  19620.95
##2018 tax:  17123.10
##Difference:  -2497.85
##Difference (percent):  12.73
##
##Enter income as an integer with no commas: 102842
##Income:  102842
##2017 tax:  21777.51
##2018 tax:  18971.58
##Difference:  -2805.93
##Difference (percent):  12.88
##
##Enter income as an integer with no commas: -1
##>>> 

#Test Run 5 for Program Set 2
##>>>
##Enter income as an integer with no commas: 240150
##Income:  240150
##2017 tax:  62648.75
##2018 tax:  59742.00
##Difference:  -2906.75
##Difference (percent):  4.64
##
##Enter income as an integer with no commas: 365169
##Income:  365169
##2017 tax:  103905.02
##2018 tax:  103498.65
##Difference:  -406.37
##Difference (percent):  0.39
##
##Enter income as an integer with no commas: 475820
##Income:  475820
##2017 tax:  144243.57
##2018 tax:  142226.50
##Difference:  -2017.07
##Difference (percent):  1.40
##
##Enter income as an integer with no commas: 587600
##Income:  587600
##2017 tax:  188508.45
##2018 tax:  183101.50
##Difference:  -5406.95
##Difference (percent):  2.87
##
##Enter income as an integer with no commas: 841430
##Income:  841430
##2017 tax:  289025.13
##2018 tax:  277018.60
##Difference:  -12006.53
##Difference (percent):  4.15
##
##Enter income as an integer with no commas: 1724920
##Income:  1724920
##2017 tax:  638887.17
##2018 tax:  603909.90
##Difference:  -34977.27
##Difference (percent):  5.47
##
##Enter income as an integer with no commas: 2918750
##Income:  2918750
##2017 tax:  1111643.85
##2018 tax:  1045627.00
##Difference:  -66016.85
##Difference (percent):  5.94
##
##Enter income as an integer with no commas: -1
##>>> 


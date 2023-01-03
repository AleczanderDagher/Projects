import constant

# Please create a Python program that calculate the take home pay for an individual. The program 
# must ask the user’s First name and for hours worked during the week, the hourly rate of pay. The 
# program must also ask for overtime hours to be calculated at 1.5 time regular pay. Calculate the 
# gross weekly pay and figure in the following taxes: 
# a. FICA = 6.2%
# b. Medicare Tax = 1.45%
# c. State Tax = 4.25%
# d. Federal Tax = 24%
# e. City Tax = 0.9%
# f. Park Tax = 0.6%
# Print out the totals at the bottom of the program along with what the total home pay would be for 
# the user. 
# Must use constants and comments within your code * 


# Enter first name, hours worked during week, and hourly pay
firstName = input("Enter your first name: ")
hoursWorked = float(input("Enter hours worked during the week: "))
hourlyPay = float(input("Enter hourly pay: "))
overtimeHours = float(input("Enter overtime hours worked: "))
overtimePay = constant.OVERTIME * hourlyPay

# Calculated percentages
salary = (hoursWorked * hourlyPay) + (overtimeHours * overtimePay)
ficaTax = constant.FICA * salary
medicareTax = constant.MEDICARE_TAX * salary
stateTax = constant.STATE_TAX * salary
federalTax = constant.CITY_TAX * salary
cityTax = constant.CITY_TAX * salary
parkTax = constant.PARK_TAX * salary

# Converted float to string and rounded answers to two decimal places

print("Taxes")
print("----------------")
print("Paid this week = $" + str(round(salary, 2)))
print("FICA tax = $" + str(round(ficaTax, 2)))
print("Medicare tax = $" + str(round(medicareTax, 2)))
print("State tax = $" + str(round(stateTax, 2)))
print("Federal tax = $" + str(round(federalTax, 2)))
print("City tax = $" + str(round(cityTax, 2)))
print("Park tax = $" + str(round(parkTax, 2)))
print("----------------")
totalHomePay = salary - ficaTax - medicareTax - stateTax - federalTax - cityTax - parkTax
print("Total home pay = $" + str(round(totalHomePay, 2)))

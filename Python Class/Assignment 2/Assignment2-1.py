import constant

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
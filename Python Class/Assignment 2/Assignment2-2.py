import constant

# Please create a python program that will ask the user for the gas mileage on a given car (i.e. 24 
# MPG) and how far they plan on traveling (i.e. 125 miles). Calculate the expenses incurred on a trip 
# with gas costing $3.49 per gallon. 
# a. Display the end result back to the user on how much the trip will cost. 

# Enter gas mileage of car and travel distance
gasMileage = float(input("Enter gas mileage of car (miles per gallon): "))
travelDistance = float(input("Enter how far you want to travel (miles): "))

# Formula for gallonsOfGas and travelCost
gallonsOfGas = travelDistance / gasMileage
travelCost = gallonsOfGas * constant.GAS

# Prints out cost of gas, amount of gallons, and cost of trip
print("Cost of gas: $" + str(constant.GAS))
print("Amount of gallons of gas:", gallonsOfGas)
print("Cost of trip: $" + str(round(travelCost, 2)))

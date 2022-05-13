import constant

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
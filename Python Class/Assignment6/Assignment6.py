from pprint import pprint

# Constants of prices of gas, diesel and electric
GAS = 4.39
DIESEL = 5.15
ELECTRIC = 0.14

class Car:
    def __init__(self, typeCar, make, model, year, cost, mpg, kwh, tankSize, city, mileage, 
    fuelCost, totalCost):
        self.typeCar = typeCar
        self.make = make
        self.model = model
        self.year = year
        self.cost = cost
        self.mpg = mpg
        self.kwh = kwh
        self.tankSize = tankSize
        self.city = city
        self.mileage = mileage
        self.fuelCost = fuelCost
        self.totalCost = totalCost

def printOut(list):
    print("{:<8} {:<15} {:<10} {:<13} {:<11} {:<14}".format('Make','Model', 'Year', 'Cost', 
    'Fuel Cost', 'Total Cost'))
    print("------------------------------------------------------------------------------")
    for obj in list:
        print("{:<8} {:<15} {:<10} ${:<13.2f} ${:<11.2f} ${:<14.2f}".format(obj.make, obj.model, 
        obj.year, obj.cost, obj.fuelCost, obj.totalCost))

def main():
    city = input("Enter location of destination: ")
    mileage = float(input("Enter round-trip mileage from Detroit: "))
    # Constants 
    F150 = Car("diesel", "Ford", "F-150", 2021, 60000.00, 10.0, 0.0, 500, city, mileage, 
    mileage/10.0 * DIESEL, 60000.00 + (mileage/10.0 * DIESEL))
    EQUINOX = Car("gas", "Chevy", "Equinox", 2020, 40000.00, 7.0, 0.0, 500, city, mileage, 
    mileage/7.0 * GAS, 40000.00 + (mileage/7.0 * GAS))
    MACHE = Car("electric", "Ford", "Mach-E", 2022, 80000.00, 0.0, 7.0, 0.0, city, 
    mileage, mileage/7.0 * ELECTRIC, 80000.00 + (mileage/7.0 * ELECTRIC))

    # Vehicles list
    vehicles = []
    
    # Appending constant variables
    vehicles.append(F150)
    vehicles.append(EQUINOX)
    vehicles.append(MACHE)

    # Additional vehicles
    i = 0
    while i < 3:
        make = input("\nEnter make of vehicle: ")
        model = input("Enter model of vehicle: ")
        year = int(input("Enter year of vehicle: "))
        cost = float(input("Enter cost of vehicle: "))
        typeCar = input("Enter the type of car (electric, diesel, or gas): ")
        if typeCar == "electric":
            kwh = float(input("Enter kilowatt-hour: "))
            fuelCost = mileage / kwh * ELECTRIC
            vehicle = Car(typeCar, make, model, year, cost, 0.0, kwh, 0.0, city, mileage, fuelCost,
            cost + fuelCost)
            vehicles.append(vehicle)
            i += 1
        elif typeCar == "gas" or typeCar == "diesel":
            mpg = float(input("Enter miles per gallon of vehicle: "))
            tankSize = input("Enter tank size of vehicle: ")
            if typeCar == "gas":
                fuelCost = mileage / mpg * GAS
                vehicle = Car(typeCar, make, model, year, cost, mpg, 0.0, tankSize, city, mileage, 
                fuelCost, cost + fuelCost)
                vehicles.append(vehicle)
            elif typeCar == "diesel":
                fuelCost = mileage / mpg * DIESEL
                vehicle = Car(typeCar, make, model, year, cost, mpg, 0.0, tankSize, city, mileage, 
                fuelCost, cost + fuelCost)
                vehicles.append(vehicle)
            i += 1
        else:
            print("Typed in the wrong thing.")
    print('\n')
    # Sort list by fuel cost
    ordered = sorted(vehicles, reverse=True, key=lambda x: x.totalCost)
    printOut(ordered)
    
if __name__ == "__main__": main()



        
PAY_PER_VIEW = 9.99
BASIC_SERVICE_TAX = 6.50
PREMIUM_SERVICE_TAX = 9.25
BASIC = 50
PREMIUM = 90  

firstName = input("Enter subscriber's first name: ")
lastName = input("Enter subscriber's last name: ")

def getPastBalance(answer):
    if answer == "yes":
        owed = float(input("How much does the subscriber owe? $"))
        return round(owed * 1.1, 2)
    else:
        return 0

def getBill(firstName, lastName, pastBalance, newBalance):
    print("------------Bill--------------")
    print("Name..............." + lastName + ", " + firstName)
    print("Past balance.......$" + "%.2f" % pastBalance)
    print("New balance........$" + "%.2f" % newBalance)

service = input("Does the subscriber have basic or premium? (type exit if you want to end program) ")

while service != "exit":
    if service == "premium":
        channels = int(input("How many pay-per-view channels? "))
        costOfPPV = channels * PAY_PER_VIEW
        answer = input("Does the subscriber have a past balance? (yes or no): ")
        pastBalance = getPastBalance(answer)
        newBalance = PREMIUM + PREMIUM_SERVICE_TAX + costOfPPV + pastBalance
        getBill(firstName, lastName, pastBalance, newBalance)
        break
    elif service == "basic":
        answer = input("Do you have a past balance? (yes or no): ")
        pastBalance = getPastBalance(answer)
        newBalance = BASIC + BASIC_SERVICE_TAX + pastBalance
        getBill(firstName, lastName, pastBalance, newBalance)
        break
    else:
        print(service + " is not an option.")

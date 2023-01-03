# Please create a Python program that prints out a bill for a cable TV subscriber. The clerk will 
# input the following: (20 points)
# a. First and last name
# b. type of service (basic $50 or premium $90).
# c. If premium, how many pay-per-view channels ($9.99 for each).
# d. taxes on basic service = $6.50 and $9.25 on premium. (only on part a (one time 
# charge))
# e. Is there a past balance? If so, how much do they owe and add 10% on the balance 
# owed.
# f. Print out totals that the owner must pay at the bottom. Use your discretion what a 
# bill would look like. 
# Output examples: (please use print out the bill in a professional format) 
# Output:  
#    basic = $50.00 + $6.25 = $56.25
#   premium + one extra channel = $90 + 9.99  + 9.25 (taxes) + 100 (existing balance + 10 = 
# $110)  = $214.24 total balance due

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

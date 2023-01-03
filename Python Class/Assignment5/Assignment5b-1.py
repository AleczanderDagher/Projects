# Please create a Python currency conversation program using breezyPythonGui or 
# tkinter. The program will allow the user to select from a list of 5 separate international 
# currencies and have the output converted to dollars. You will also need a textbox that 
# allows the user to input an amount and have the program return the exact amount 
# (including cents i.e. $59.62). 
# The program will also need to allow the user to have the output go to a file called 
# currencyConversion.txt. 
# Note: no json or requests modules are allowed
# Possible currencies: (you can figure out the actual exchange rate)
# Egyptian - Pound
# Europe - Euro 
# South Korean - Won
# Russian - Ruble
# India – Rupee
# (or a denomination of your choice)


import math
from tkinter import *

file = open('currencyConversion.txt','a+', encoding="utf-8")

# Converts Egyptian pound to US dollar
def EgyptConversion() :
    amt = float(amount.get())
    egypt = amt * 0.055
    conversion = Label(main, text = '$ %.2f' % egypt).grid(row = 3, column = 1, padx = 0, pady = 10)
    file.write("E" + u"\xA3" + "%.2f" % amt + " to US Dollar is: $" + "%.2f" % egypt + '\n')
    return
# Converts Euro to US dollar
def Euro():
   amt = float(amount.get())
   euro = amt * 1.09
   conversion = Label(main, text = '$ %.2f' % euro).grid(row = 3, column = 1, padx = 0, pady = 10)
   file.write(u"\u20AC" + "%.2f" % amt + " to US Dollar is: $" + "%.2f" % euro + '\n')
   return
# Converts Won to US dollar
def Won():
   amt = float(amount.get())
   won = amt * 0.00082
   conversion = Label(main, text = '$ %.2f' % won).grid(row = 3, column = 1, padx = 0, pady = 10)
   file.write(u"\uFFE6" + "%.2f" % amt + " to US Dollar is: $" + "%.2f" % won + '\n')
   return
# Converts Ruble to US dollar
def Ruble():
   amt = float(amount.get())
   ruble = amt * 0.012
   conversion = Label(main, text = '$ %.2f' % ruble).grid(row = 3, column = 1, padx = 0, pady = 10)
   file.write(u"\u20BD" + "%.2f" % amt + " to US Dollar is: $" + "%.2f" % ruble + '\n')
   return
# Converts Rupee to US dollar
def Rupee():
   amt = float(amount.get())
   rupee = amt * 0.013
   conversion = Label(main, text = '$ %.2f' % rupee).grid(row = 3, column = 1, padx = 0, pady = 10)
   file.write(u"\u20B9" + "%.2f" % amt + " to US Dollar is: $" + "%.2f" % rupee + '\n')
   return

main = Tk()
main.title("Convert to US Dollars")
main.geometry('300x300')

amount = StringVar()

lblAmount = Label(main, text = 'Amount:').grid(row = 0, column = 0, padx = 0, pady = 10)
entAmount = Entry(main, textvariable = amount).grid(row = 0, column = 1)
egyptButton = Button(main, text = 'Convert Egyptian pound to US Dollars', command = EgyptConversion).grid(row = 5, column = 1)
euroButton = Button(main, text = 'Convert Euro to US Dollars', command = Euro).grid(row = 6, column = 1)
wonButton = Button(main, text = 'Convert Won to US Dollars', command = Won).grid(row = 7, column = 1)
rubleButton = Button(main, text = 'Convert Ruble to US Dollars', command = Ruble).grid(row = 8, column = 1)
rupeeButton = Button(main, text = 'Convert Rupee to US Dollars', command = Rupee).grid(row = 9, column = 1)
conversion = Label(main, text = 'US Dollars:').grid(row = 3, column = 0, padx = 0, pady = 10)

main.mainloop()

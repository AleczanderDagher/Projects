# Please create a python program that will modify one of our previous assignments into a 
# gui-based program using either tkinter or breezypythongui. Please create a Python 
# program that loop through from 147 to 62 by -3 during each iteration. Also, print out the total 
# number of times that the program looped along with the ending number. 
# a. Differences:
# i. Allow user to enter starting number between 200 and 135.
# ii. Allow user to enter ending number between 95 and 62
# iii. Allow user to enter increment value between 2 and 5.


import math
import time
from tkinter import *
# Loop function
def loopNumbers():
    # Converts string to int
    startNumber = int(start.get())
    endNumber = int(end.get())
    dec = int(decrement.get())
    decre = dec * -1
    # Prints out loop on listbox if it follows the if statement
    x = 0
    if startNumber >= 135 and startNumber <= 200 and endNumber >= 62 and endNumber <= 95 and dec >=2 and dec <= 5:
        for i in range(startNumber, endNumber - 1, decre):
            output = "Loop" , x, ":", i
            x+=1
            listbox.insert(END, output)
    else:
        listbox.insert(END, 'Wrong')


main = Tk()
main.title("Loop")
main.geometry('700x300')

# Adds listbox and scrollbar to list box
listbox = Listbox(main)
listbox.grid(row = 3, column = 1)
scrollbar = Scrollbar(main)
scrollbar.grid(row = 3, column = 2)
listbox.config(yscrollcommand = scrollbar.set)
scrollbar.config(command = listbox.yview)

start = StringVar()
end = StringVar()
decrement = StringVar()

lblStartNumber = Label(main, text = 'Enter starting number btwn 135 & 200:').grid(row = 0, column = 0, padx = 0, pady = 10)
entStartNumber = Entry(main, textvariable = start).grid(row = 0, column = 1)
lblEndNumber = Label(main, text = 'Enter ending number btwn 62 & 95:').grid(row = 1, column = 0, padx = 0, pady = 10)
entEndNumber = Entry(main, textvariable = end).grid(row = 1, column = 1)
lblDecrementNumber = Label(main, text = 'Enter decrement number btwn 2 & 5:').grid(row = 2, column = 0, padx = 0, pady = 10)
entDecrementNumber = Entry(main, textvariable = decrement).grid(row = 2, column = 1)
printButton = Button(main, text = 'Print', command = loopNumbers).grid(row = 3, column = 0)


main.mainloop()

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

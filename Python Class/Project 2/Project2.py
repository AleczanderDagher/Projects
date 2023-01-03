# Please create a Python program based on the game of WAR. The rules of the game are 
# as follows:
# The game of WAR is rather simple as it requires  only the ability to recognize 
# which of two cards has a higher value.
# In this game the value of cards from lowest to highest is:
# 2,3,4,5,6,7,8,9,10,J,Q,K,A
# No suit has a higher value than another.
# Both players take the top card off of their pile (stack) and place it face up in the 
# playing area. The player that played the higher card wins the round and takes 
# both cards. 
# If there is a tie, then both players place the next card down and the 3rd  card up. 
# The winner of the 3rd card wins the round. If the 3rd cards tie, then both players 
# repeat the process until a player has won the hand. 
# When the player runs out of cards, then the player will shuffle the cards from the 
# winning pile (stack). The game will continue until one play player is completely 
# out cards.
# This program must be in a graphical format. 


from random import shuffle
from distutils import config
from http.cookiejar import DefaultCookiePolicy
import random
from tkinter import *
from turtle import left, right
from urllib.request import ProxyHandler
from PIL import Image, ImageTk


# Class cards
class Cards:
    def __init__(self):
        values = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]
        suites = ["diamonds", "spades", "hearts", "clubs"]
        self.deck = [f'{j}_of_{i}' for j in values for i in suites]

    def shuffle(self):
        shuffle(self.deck)
    # Deal cards to n players
    def deal(self, n_players):
        self.hands = [self.deck[i::n_players] for i in range(0, n_players)]

# Resize Cards
def resize_cards(card):
	# Open the image
	our_card_img = Image.open(card)

	# Resize The Image
	our_card_resize_image = our_card_img.resize((150, 218))
	
	# output the card
	global our_card_image
	our_card_image = ImageTk.PhotoImage(our_card_resize_image)

	# Return that card
	return our_card_image

def shuffling():
    # Global player1 and player2 cards
    global player1, player2
    player1 = []
    player2 = []

    c = Cards()
    c.shuffle()
    c.deal(2)
    # Player 1 and Player 2 cards
    player1 = c.hands[0]
    player2 = c.hands[1]
    # Pop Player 1 card from player1 stack
    player1_card = player1.pop()

    global player1_image
    player1_image = resize_cards(f'cards\{player1_card}.png')
    player1_label.config(image = player1_image)

    # Pop player 2 card from player2 stack
    player2_card = player2.pop()

    global player2_image
    player2_image = resize_cards(f'cards\{player2_card}.png')
    player2_label.config(image = player2_image)
    
    # Display who won round and how many cards each player has
    score(player1_card, player2_card)
    main.title(f'Player 1: {len(player1)} | ' f'Player 2: {len(player2)}')

def getCards():
    try:
        # Pop Player 1 card from player1 stack
        player1_card = player1.pop()
        global player1_image
        player1_image = resize_cards(f'cards\{player1_card}.png')
        player1_label.config(image = player1_image)
       

        # Pop Player 2 card from player2 stack
        player2_card = player2.pop()
        global player2_image
        player2_image = resize_cards(f'cards\{player2_card}.png')
        player2_label.config(image = player2_image)

        # Display who won round and how many cards each player has
        score(player1_card, player2_card)
        main.title(f'Player 1: {len(player1)} | ' f'Player 2: {len(player2)}')
    except:
        # If player reaches 52 cards, they win
        if len(player1) == 52 or len(player2) == 0:
            main.title(f'Player 1 wins the game!')
        elif len(player2) == 52 or len(player1) == 0:
            main.title(f'Player 2 wins the game!')
        else:
            main.title(f'No one wins...')
    
def score(player1_card, player2_card):
    p1card = int(player1_card.split("_", 1)[0])
    p2card = int(player2_card.split("_", 1)[0])
    # Compare higher card
    if p1card > p2card:
        score_label.config(text = "Player 1 wins!")
        player1.insert(0, player2_card)
        player1.insert(1, player1_card)
    elif p1card < p2card:
        score_label.config(text = "Player 2 wins!")
        player2.insert(0, player1_card)
        player2.insert(1, player2_card)
    else:
        score_label.config(text = "It's a tie! Play a game of War!")
        # Make getCards button disappear and make warButton appear
        getCardsButton.pack_forget()
        global warButton
        warButton = Button(main, text = 'Play War', command = war)
        warButton.pack(pady = 15)
    
def war():
    # Pop 3 cards from each player
    p1cards = [player1.pop() for _ in range(3)]
    p2cards = [player2.pop() for _ in range(3)]

    # Pop final card from each player and compare them. If player wins, they take all the cards
    p1FinalCard = player1.pop()
    p2FinalCard = player2.pop()
    player1_label.config(text = p1FinalCard)
    player2_label.config(text = p2FinalCard)
    p1F = int(p1FinalCard.split("_", 1)[0])
    p2F = int(p2FinalCard.split("_", 1)[0])
    if p1F > p2F:
        score_label.config(text = "Player 1 wins!")
        player1.insert(0, p2FinalCard)
        player1.insert(1, p2FinalCard)
        player1.insert(2, p2FinalCard)
        player1.insert(3, p2FinalCard)
        player1.insert(4, p2FinalCard)
        player1.insert(5, p1FinalCard)
        player1.insert(6, p1FinalCard)
        player1.insert(7, p1FinalCard)
        player1.insert(8, p1FinalCard)
        player1.insert(9, p1FinalCard)
        warButton.pack_forget()
        getCardsButton.pack(pady=20)
    elif p1F < p2F:
        score_label.config(text = "Player 2 wins!")
        player2.insert(0, p1FinalCard)
        player2.insert(1, p1FinalCard)
        player2.insert(2, p1FinalCard)
        player2.insert(3, p1FinalCard)
        player2.insert(4, p1FinalCard)
        player2.insert(5, p2FinalCard)
        player2.insert(6, p2FinalCard)
        player2.insert(7, p2FinalCard)
        player2.insert(8, p2FinalCard)
        player2.insert(9, p2FinalCard)
        warButton.pack_forget()
        getCardsButton.pack(pady=20)
    else:
        war()
    
main = Tk()
main.title("War")
main.geometry('900x550')
main.configure(background="green")

frame = Frame(main, bg="green", width = 450, height = 50)
frame.pack(pady = 20)

player1_frame = LabelFrame(frame, text="Player 1")
player1_frame.pack(side = 'left', padx = 20, pady = 20)
player2_frame = LabelFrame(frame, text="Player 2")
player2_frame.pack(side = 'right', pady = 20)

player1_label = Label(player1_frame, text = '')
player1_label.pack(side='left')

player2_label = Label(player2_frame, text = '')
player2_label.pack(side='right')

score_label = Label(main, text = "")
score_label.pack(pady = 15)

getCardsButton = Button(main, text = 'Get Cards', command = getCards)
getCardsButton.pack(pady=20)

# Shuffles automatically when loaded in
shuffling()
main.mainloop()

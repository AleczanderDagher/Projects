file = open("Project1a.txt", "r")
list_of_lists = [(line.strip()).split(':') for line in file]
file.close()

# Unzip list
date, wsu, wsuScore, opponents, opponentScore = zip(*list_of_lists)

win = loss = 0
for i in range(len(wsuScore)):
    if(wsuScore[i] > opponentScore[i]):
        win += 1
    else:
        loss += 1

print("-----Wayne State Warriors Stats-----")
# Wayne State record
print("Record:", win, "-", loss)

# Convert wsuScore and opponentScore to int list
wsuScore = list(map(int, wsuScore))
opponentScore = list(map(int, opponentScore))

# Average scores for WSU and opponents
averageWSUscore = sum(wsuScore)/len(wsuScore)
averageOpponentScore = sum(opponentScore)/len(opponentScore)
print("Points average:", "%.2f" % averageWSUscore)
print("Opponents points average:", "%.2f" % averageOpponentScore)

wsuWinMargins = []
wsuLossMargins = []
allMargins = []
for i in range(len(wsuScore)):
    margins = wsuScore[i] - opponentScore[i]
    allMargins.append(margins)
    if(margins > 0):
        wsuWinMargins.append(margins)
    else:
        wsuLossMargins.append(margins)

averageWinMargin = sum(wsuWinMargins)/len(wsuWinMargins)
averageLossMargin = sum(wsuLossMargins)/len(wsuLossMargins)
print("Average win margin:", "%.2f" % averageWinMargin)
print("Average loss margin:", "%.2f" % averageLossMargin)

# Zip and sort allMargins and opponents list
sortedMargins = sorted(zip(allMargins, opponents, date), reverse = False)
# Unzip lists
allMargins, opponents, date = zip(*sortedMargins)
print("Biggest win: " + opponents[len(opponents) - 1] + " (" + date[len(opponents) - 1] + ")")
print("Worst loss: " + opponents[0] + " (" + date[0] + ")")
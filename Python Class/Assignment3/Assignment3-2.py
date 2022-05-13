# List of scores for each round
teamScoresR1 = []
teamScoresR2 = []
teamScoresR3 = []

# List of all bowlers and their averages
allAverages = []
allBowlers = ["Smith, Steve (USA)", "Smith, Ryan (USA)", "Smith, Bubby (USA)", "Sterling, Scott (USA)",
"James, Don (USA)", "Perry, Josh (India)", "Ali, Steven (India)", "Bhatta, Brian (India)", 
"Ghandi, Lewis (India)", "Chopra, James (India)", "Long, Ryan (Canada)", "Jackson, Boe (Canada)", 
"Douglas, Ty (Canada)", "Benoit, Peter (Canada)", "Roy, Brian (Canada)"]

# Input players and scores for team USA
i = 0
print("ALL BOWLERS")
while i < len(allBowlers):
    print(allBowlers[i])
    bowlerScore1 = int(input("Enter score for R1 (0-300): "))
    bowlerScore2 = int(input("Enter score for R2 (0-300): "))
    bowlerScore3 = int(input("Enter score for R3 (0-300): "))
    bowlerAverage = (bowlerScore1 + bowlerScore2 + bowlerScore3) / 3
        # If scores are greater than or equal to 0 and less than or equal to 300, the loop will 
        # continue until it inputs all scores for bowlers
    if bowlerScore1 >= 0 and bowlerScore1 <= 300 and bowlerScore2 >= 0 and bowlerScore2 <= 300 and bowlerScore3 >= 0 and bowlerScore3 <= 300:
        teamScoresR1.append(bowlerScore1)
        teamScoresR2.append(bowlerScore2)
        teamScoresR3.append(bowlerScore3)
        allAverages.append(bowlerAverage)
        print("")
        i += 1 
    else:
        print("Please enter correct score(s) for bowler.")
     
print("Scores for Round 1")
totalScoreUSA1 = teamScoresR1[0] + teamScoresR1[1] + teamScoresR1[2] + teamScoresR1[3] + teamScoresR1[4]
totalIndiaScore1 = teamScoresR1[5] + teamScoresR1[6] + teamScoresR1[7] + teamScoresR1[8] + teamScoresR1[9]
totalCanadaScore1 = teamScoresR1[10] + teamScoresR1[11] + teamScoresR1[12] + teamScoresR1[13] + teamScoresR1[14]
print("USA:", totalScoreUSA1)
print("India:", totalIndiaScore1)
print("Canada:", totalCanadaScore1)
if totalScoreUSA1 > totalIndiaScore1 and totalCanadaScore1:
    print("USA wins Round 1!")
elif totalIndiaScore1 > totalCanadaScore1 and totalScoreUSA1:
    print("India wins Round 1!")
elif totalCanadaScore1 > totalIndiaScore1 and totalScoreUSA1:
    print("Canada wins Round 1!")
print("")


print("Scores for Round 2")
totalScoreUSA2 = teamScoresR2[0] + teamScoresR2[1] + teamScoresR2[2] + teamScoresR2[3] + teamScoresR2[4]
totalIndiaScore2 = teamScoresR2[5] + teamScoresR2[6] + teamScoresR2[7] + teamScoresR2[8] + teamScoresR2[9]
totalCanadaScore2 = teamScoresR2[10] + teamScoresR2[11] + teamScoresR2[12] + teamScoresR2[13] + teamScoresR2[14]
print("USA:", totalScoreUSA2)
print("India:", totalIndiaScore2)
print("Canada:", totalCanadaScore2)
if totalScoreUSA2 > totalIndiaScore2 and totalCanadaScore2:
    print("USA wins Round 2!")
elif totalIndiaScore2 > totalCanadaScore2 and totalScoreUSA2:
    print("India wins Round 2!")
elif totalCanadaScore2 > totalIndiaScore2 and totalScoreUSA2:
    print("Canada wins Round 2!")
print("")

print("Scores for Round 3")
totalScoreUSA3 = teamScoresR3[0] + teamScoresR3[1] + teamScoresR3[2] + teamScoresR3[3] + teamScoresR3[4]
totalIndiaScore3 = teamScoresR3[5] + teamScoresR3[6] + teamScoresR3[7] + teamScoresR3[8] + teamScoresR3[9]
totalCanadaScore3 = teamScoresR3[10] + teamScoresR3[11] + teamScoresR3[12] + teamScoresR3[13] + teamScoresR3[14]
print("USA:", totalScoreUSA3)
print("India:", totalIndiaScore3)
print("Canada:", totalCanadaScore3)
if totalScoreUSA3 > totalIndiaScore3 and totalCanadaScore3:
    print("USA wins Round 3!")
elif totalIndiaScore3 > totalCanadaScore3 and totalScoreUSA3:
    print("India wins Round 3!")
elif totalCanadaScore3 > totalIndiaScore3 and totalScoreUSA3:
    print("Canada wins Round 3!")
print("")

totalScoreUSA = totalScoreUSA1 + totalScoreUSA2 + totalScoreUSA3
totalIndiaScore = totalIndiaScore1 + totalIndiaScore2 + totalIndiaScore3
totalCanadaScore = totalCanadaScore1 + totalCanadaScore2 + totalCanadaScore3
print("Total score for USA:", totalScoreUSA)
print("Total score for India:", totalIndiaScore)
print("Total score for Canada:", totalCanadaScore)
if totalScoreUSA > totalIndiaScore and totalCanadaScore:
    print("USA wins the match!")
elif totalIndiaScore > totalCanadaScore and totalScoreUSA:
    print("India wins the match!")
elif totalCanadaScore > totalIndiaScore and totalScoreUSA:
    print("Canada wins the match!")
print("")
print("USA scores")
for i in range(5):
    print(allBowlers[i], '\t\t', teamScoresR1[i], '\t\t', teamScoresR2[i], '\t\t', 
    teamScoresR3[i], '\t\t', allAverages[i])
print("")

print("India scores")
for i in range(5, 10):
    print(allBowlers[i], '\t\t', teamScoresR1[i], '\t\t', teamScoresR2[i], '\t\t', 
    teamScoresR3[i], '\t\t', allAverages[i])
print("")

print("Canada scores")
for i in range(10, 15):
    print(allBowlers[i], '\t\t', teamScoresR1[i], '\t\t', teamScoresR2[i], '\t\t', 
    teamScoresR3[i], '\t\t', allAverages[i])
print("")
print("All bowlers and their averages")
for i in range(len(allBowlers)):
    print(allBowlers[i], '\t\t', allAverages[i])
print("")
# Zip lists
results = sorted(zip(allAverages, allBowlers), reverse = True)
# Unzip list
averages, bowlers = zip(*results)
print("Gold:", bowlers[0])
print("Silver:", bowlers[1])
print("Bronze:", bowlers[2])
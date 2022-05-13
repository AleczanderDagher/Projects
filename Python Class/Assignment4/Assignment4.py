import random
file2 = open("Scoreboard.txt", "w")
def printAllScores(bowlers, R1Scores, R2Scores, R3Scores, averages):
    file2.write("%-30s %-15s %-15s %-15s %-15s" % ("Bowlers (country)", "Round 1", "Round 2",
    "Round 3", "Averages"))
    file2.write("\n---------------------------------------------------------------------------------------")
    for i in range(len(bowlers)):
        file2.write("\n%-30s %-15s %-15s %-15s %-15.2f" % (bowlers[i], R1Scores[i], R2Scores[i], 
        R3Scores[i], averages[i]))
    file2.write("\n")
   

def whoWon(scoresUSA, scoresIndia, scoresCanada):
    if scoresUSA > scoresIndia and scoresCanada:
        return "Winner: USA\n"
    elif scoresIndia > scoresCanada and scoresUSA:
        return "Winner: India\n"
    elif scoresCanada > scoresIndia and scoresUSA:
        return "Winner: Canada\n"
    

def topBowlers(allAverages, allBowlers):
    # Zip lists
    results = sorted(zip(allAverages, allBowlers), reverse = True)
    # Unzip list
    averages, bowlers = zip(*results)
    file2.write("Gold: " + str(bowlers[0]) + '\n')
    file2.write("Silver: " + str(bowlers[1]) + '\n')
    file2.write("Bronze: " + str(bowlers[2]) + '\n')
    file2.close()

def printRound(teamUSAround, teamIndiaRound, teamCanadaRound):
    file2.write("USA: " + str(teamUSAround) + '\n')
    file2.write("India: " + str(teamIndiaRound) + '\n')
    file2.write("Canada: " + str(teamCanadaRound) + '\n')
    winner = whoWon(teamUSAround, teamIndiaRound, teamCanadaRound)
    file2.write(str(winner) + '\n')

def main():
    file1 = open("Bowlers.txt", "r")
    allBowlers = [(line.strip()) for line in file1]
    file1.close()
    # List of scores for each round
    teamScoresR1 = []
    teamScoresR2 = []
    teamScoresR3 = []
    # List of all bowlers and their averages
    allAverages = []
    # Input players and scores for team USA
    i = 0
    while i < len(allBowlers):
        bowlerScore1 = random.randint(150, 300)
        bowlerScore2 = random.randint(150, 300)
        bowlerScore3 = random.randint(150, 300)
        bowlerAverage = (bowlerScore1 + bowlerScore2 + bowlerScore3) / 3
        teamScoresR1.append(bowlerScore1)
        teamScoresR2.append(bowlerScore2)
        teamScoresR3.append(bowlerScore3)
        allAverages.append(bowlerAverage)
        i += 1
    # Prints out all bowlers and their scores
    printAllScores(allBowlers, teamScoresR1, teamScoresR2, teamScoresR3, allAverages)

    # List of scores for each country for Round 1
    teamScoresUSAR1 = teamScoresR1[:5]
    teamScoresIndiaR1 = teamScoresR1[5:10]
    teamScoresCanadaR1 = teamScoresR1[10:15]
    # List of scores for each country for Round 2
    teamScoresUSAR2 = teamScoresR2[:5]
    teamScoresIndiaR2 = teamScoresR2[5:10]
    teamScoresCanadaR2 = teamScoresR2[10:15]
    # List of scores for each country for Round 3
    teamScoresUSAR3 = teamScoresR3[:5]
    teamScoresIndiaR3 = teamScoresR3[5:10]
    teamScoresCanadaR3 = teamScoresR3[10:15]
    # Prints out scores for Round 1
    file2.write("\nScores for Round 1\n")
    printRound(sum(teamScoresUSAR1), sum(teamScoresIndiaR1), sum(teamScoresCanadaR1))
    # Prints out scores for Round 2
    file2.write("Scores for Round 2\n")
    printRound(sum(teamScoresUSAR2), sum(teamScoresIndiaR2), sum(teamScoresCanadaR2))
    # Prints out scores for Round 3
    file2.write("Scores for Round 3\n")
    printRound(sum(teamScoresUSAR3), sum(teamScoresIndiaR3), sum(teamScoresCanadaR3))
    # Adds total scores for each team and prints winner of the final match
    totalUSAscore = sum(teamScoresUSAR1) + sum(teamScoresUSAR2) + sum(teamScoresUSAR3)
    totalIndiaScore = sum(teamScoresIndiaR1) + sum(teamScoresIndiaR2) + sum(teamScoresIndiaR3)
    totalCanadaScore = sum(teamScoresCanadaR1) + sum(teamScoresCanadaR2) + sum(teamScoresCanadaR3)
    file2.write("Final Scores\n")
    printRound(totalUSAscore, totalIndiaScore, totalCanadaScore)
    # Prints top 3 bowlers
    topBowlers(allAverages, allBowlers)
    
if __name__ == "__main__": 
    main()
// Problem 589.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

//class ProbabilityMap {
//private:
//    map<int, int> probabilityMap;
//    int numOfSides;
//    int numOfDice;
//public:
//    ProbabilityMap(int sides, int dice) : numOfSides(sides), numOfDice(dice) {
//
//    }
//};

// Function to generate all possible dice rolls and count sums
void generateDiceSums(int diceCount, int currentIndex, std::vector<int>& currentRolls, std::map<int, int>& sumCounts, const int& diceSides) {
    if (currentIndex == diceCount) {
        // Calculate the sum of the current roll
        int sum = 0;
        for (int roll : currentRolls) {
            sum += roll;
        }
        // Increment the count of this sum in the map
        sumCounts[sum]++;
        return;
    }

    // Roll the dice (values from 1 to 6)
    for (int i = 1; i <= diceSides; ++i) {
        currentRolls[currentIndex] = i;
        generateDiceSums(diceCount, currentIndex + 1, currentRolls, sumCounts, diceSides);
    }
}

int main() {
    int diceCount;
    int diceSides;

    // Input the number of dice
    std::cout << "Enter the number of dice: ";
    std::cin >> diceCount;

    // Input the number of dice
    std::cout << "Enter the number of sides on the dice: ";
    std::cin >> diceSides;

    // Vector to store the current rolls
    std::vector<int> currentRolls(diceCount);

    // Map to store the frequency of each possible sum
    std::map<int, int> sumCounts;

    // Generate all possible dice rolls and count sums
    generateDiceSums(diceCount, 0, currentRolls, sumCounts, diceSides);

    // Print the frequency of each possible sum
    std::cout << "Frequency of possible sums:\n";
    for (const auto& pair : sumCounts) {
        std::cout << "Sum " << pair.first << ": " << pair.second << " times\n";
    }

    return 0;
}
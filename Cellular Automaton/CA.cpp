#include <iostream>
/*
 * Author: Thu Ha.
 * Assignment: Cellular Automaton Rule Simulation
 * Description: This program simulates cellular automaton generations based on a given rule set number (0-255).
 *              The rule set is converted into an array of binary rules that dictate the state of each cell in the
 *              next generation based on its current neighborhood.
 */
void convertRuleSetNumberToRuleSetArray(int num, int array[8]);
void displayCurrentGeneration(int generatedArray[], int length);
void computeNextGeneration (int currGeneration[], int nextGeneration[], int arrayLength, int ruleSetArr[]);
int convertNeighborhoodToIndex(int left, int curr, int right);

// Converts the given rule set number (0-255) into a binary array representation.
void convertRuleSetNumberToRuleSetArray(int num, int array[8])
{
    int index = 0;
    // Initialize the rule set array with all zeros.
    for (int i = 0; i < 8; i++)
    {
        array[i] = 0;
    }

    // Convert the rule set number into its binary representation stored in ruleSetArray.
    while (num != 0)
    {
        if (num % 2 == 0)
        {
            array[index] = 0;
        } else {
            array[index] = 1;
            num--;
        }
        num /=2;
        index++;
    }
}

// Displays the current generation of cells, where 0 is represented by a space and 1 by a '#'.
void displayCurrentGeneration(int generatedArray[], int length) {
    for (int i = 0; i < length; i++)
    {
        if (generatedArray[i] == 0)
        {
            std::cout << " ";
        } else if (generatedArray[i] == 1)
        {
            std::cout << "#";
        }
    }
    std::cout << std::endl;
}

// Computes the next generation of cells based on the current generation and the rule set array.
void computeNextGeneration (int currGeneration[], int nextGeneration[], int arrayLength, int ruleSetArr[])
{
    int index;
    // Copy the first and last element of the array from the 
    // current generation to the next generation array.
    nextGeneration[0] = currGeneration[0];
    nextGeneration[arrayLength - 1] = currGeneration[arrayLength - 1];

    // Compute the next generation based on the neighborhood of each cell.
    for (int i = 1; i < arrayLength -1; i++)
    {
        int left = currGeneration[i - 1];
        int curr = currGeneration[i];
        int right = currGeneration[i + 1];

        index = convertNeighborhoodToIndex(left, curr, right);
        nextGeneration[i] = ruleSetArr[index];
    }
}

// Converts the left, current, and right cell values to an index used to access the rule set array.
int convertNeighborhoodToIndex(int left, int curr, int right)
{
    int index = (left *4) + (curr * 2)
     + (right * 1);
    return index;
}

int main() {
    int ruleNumber;
    // Prompt the user to enter a rule set number.
    std::cout << "Enter a rule set number (0-255): ";
    std::cin >> ruleNumber;

    if (std::cin.fail() || ruleNumber < 0 || ruleNumber > 255) {
        std::cout << "Invalid input. Please enter a number between 0 and 255." << std::endl;
        return 0;
    }

    int ruleSetArr[8] = {};
    convertRuleSetNumberToRuleSetArray(ruleNumber, ruleSetArr);\
    
    int currentGeneration[64] = {};
    currentGeneration[32] = 1; // Initialize the array
    displayCurrentGeneration(currentGeneration, 64);

    int nextGeneration[64] = {};
    for (int i = 0; i < 49; i++) {
        computeNextGeneration(currentGeneration, nextGeneration, 64, ruleSetArr);
        std::copy(std::begin(nextGeneration), std::end(nextGeneration), std::begin(currentGeneration));
        displayCurrentGeneration(currentGeneration, 64);
    }

    return 0;
}
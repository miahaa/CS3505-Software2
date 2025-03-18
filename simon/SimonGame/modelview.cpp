/*
 * This file implements the ModelView class, which manages the core logic
 * of the Simon Game. It handles the game’s sequence of moves, processes
 * user inputs, and updates the game state accordingly.
 *
 * Author: Thu Ha
 * Date: 28/10/2024
 * Assignment: A6 - Simon game
 */

#include "modelview.h"

ModelView::ModelView(QObject *parent) : QObject(parent), currentStep(0), speed(1000) {}

// Start the game by adding initial moves
void ModelView::startGame() {
    sequence.clear();
    currentStep = 0;

     // Add initial moves to the sequence
    for (int i = 0; i < 3; ++i) {
        addMove();
    }

    emit stateChange(0);    // Emit signal to update state
}

// Add a move to the sequence
void ModelView::addMove() {
    Color nextColor = (rand() % 2 == 0) ? Red : Blue;   // Randomly select color
    sequence.append(nextColor);
}

// Process user input
void ModelView::processInput(Color color) {
    checkInput(color);  // Check if the input matches the sequence
}

// Check the user input against the expected color
void ModelView::checkInput(Color color) {
    if (color == sequence[currentStep]) {
        currentStep++;
        emit progressUpdate((currentStep * 100) / sequence.size());

        if (currentStep == sequence.size()) {
            currentStep = 0;
            addMove();
            emit stateChange(3);    // Emit signal for successful input
        }
    } else {
        emit stateChange(4);    // Emit signal for failed input
    }
}

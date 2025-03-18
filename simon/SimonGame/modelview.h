/*
 * This header file defines the ModelView class, which is responsible
 * for managing the game logic of the Simon Game. It declares public
 * methods for starting the game, adding moves, and processing user input.
 *
 * Author: Thu Ha
 * Date: 28/10/2024
 * Assignment: A6 - Simon game
 */

#ifndef MODELVIEWH
#define MODELVIEWH

#include <QObject>
#include <QVector>

// Enum to represent the button colors
enum Color { Red, Blue };

class ModelView : public QObject {
    Q_OBJECT
public:
    explicit ModelView(QObject *parent = nullptr);

    void startGame();   // Start the game
    void addMove(); // Add a new move
    void processInput(Color color);  // Process user input

    // Getter methods for sequence data
    int getSequenceSize() const { return sequence.size(); }
    Color getSequenceAt(int index) const { return sequence[index]; }

signals:
    void stateChange(int nextState);     // Signal for state change
    void progressUpdate(int progress);  // Signal for progress update

private:
    QVector<Color> sequence;     // Sequence of moves
    int currentStep;            // Current step in the sequence
    int speed;      // Speed of the game

    void checkInput(Color color);       // Check user input
};

#endif // MODELVIEWH

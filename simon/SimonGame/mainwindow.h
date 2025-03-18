/* This header file defines the MainWindow class, which serves as the
 * graphical user interface for the Simon Game application. It includes
 * declarations of public methods, private members, and slot functions
 * that handle user interactions.
 *
 * Author: Thu Ha
 * Date: 10/28/2024
 * Assignment: A6 - Simon Game
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QProgressBar>
#include <QLabel>

#include <QTimer>               // QTimer
#include <QKeyEvent>            // QKeyEvent
#include <QMessageBox>

#include "modelview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);  // Constructor
    ~MainWindow();   // Destructor

public slots:

protected:
    void keyPressEvent(QKeyEvent *);   // Handle key press events

private:
    Ui::MainWindow *ui;        // UI pointer

    QPushButton *startButton;
    QPushButton *redButton;
    QPushButton *blueButton;
    QLabel *turnLabel;
    QLabel *scoreLabel;

    QProgressBar *progressBar;

    void connectSignalsAndSlots();      // Function to connect signals and slots
    void computerTurn();
    void playerTurn();
    void flashButton(Color color);
    void changeTheme();
    void updateTurnLabel(const QString &text);
    void updateScore();

    ModelView *gameModel;       // Game model pointer
    int currProgress = 0;
    int speed = 1000;
    int score = 0;

private slots:
    void startButtonClicked();      // Start button handler
    void redButtonClicked();        // Red button handler
    void blueButtonClicked();       // Blue button handler

    void increaseSpeed();
    void updateProgressBar(int val);     // Update progress bar
    void stateChanged(int state);       // Handle state change
};

#endif // MAINWINDOW_H

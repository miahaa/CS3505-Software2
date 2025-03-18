/*
 * This file defines the implementation of the MainWindow class, which
 * manages the primary GUI for the Simon Game. It handles the initialization
 * of the user interface, connects signals and slots, and manages user
 * interactions such as button clicks and key presses.
 *
 * Author: Thu Ha
 * Date: 10/28/2014
 * Assignment: A6 - Simon Game
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Initialize the game model
    gameModel = new ModelView(this);

    // Set up UI components
    ui->progressBar->setValue(0);
    ui->turnLabel->setText("Welcome to Simon Game!");
    ui->label->setText("Score: 0");

    // Set the background color of the main window
    this->setStyleSheet("background-color: lightgray;");

    // Style buttons
    ui->RedButton->setStyleSheet("background-color: red; color: white; border: 1px solid black;");
    ui->BlueButton->setStyleSheet("background-color: blue; color: white; border: 1px solid black;");
    ui->Start->setStyleSheet("background-color: yellow; color: black; border: 1px solid black;");

    // Connect signals and slots
    connectSignalsAndSlots();
}

MainWindow::~MainWindow() {
    delete ui;
}

// Connect all signals and slots
void MainWindow::connectSignalsAndSlots()
{
    connect(ui->Start, &QPushButton::clicked, this, &MainWindow::startButtonClicked);
    connect(ui->RedButton, &QPushButton::clicked, this, &MainWindow::redButtonClicked);
    connect(ui->BlueButton, &QPushButton::clicked, this, &MainWindow::blueButtonClicked);
    connect(gameModel, &ModelView::stateChange, this, &MainWindow::stateChanged);
    connect(gameModel, &ModelView::progressUpdate, this, &MainWindow::updateProgressBar);
}

// Handle key press events for Red and Blue keys
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Red)
    {
        redButtonClicked();
    }
    else if (event->key() == Qt::Key_Blue)
    {
        blueButtonClicked();
    }
}

// Update the state of the game based on the model's signal
void MainWindow::stateChanged(int nextState)
{
    switch (nextState) {
    case 0:  // Reset state
        ui->progressBar->setValue(0);
        break;
    case 1:  // Start state
        ui->RedButton->setStyleSheet("background-color: lightcoral;");
        QTimer::singleShot(500, this, [this]() {
            ui->RedButton->setStyleSheet("background-color: red;");
        });
        break;
    case 2:  // User's turn
        ui->BlueButton->setStyleSheet("background-color: lightblue;");
        QTimer::singleShot(500, this, [this]() {
            ui->BlueButton->setStyleSheet("background-color: blue;");
        });
        break;
    case 3:   // User succeeded
        updateScore();
        changeTheme();
        increaseSpeed();
        QTimer::singleShot(1000, this, &MainWindow::computerTurn);
        break;
    case 4:  // Game over
        QMessageBox::critical(this, "Game Over", "Game Over! You lose!!");
        ui->Start->setEnabled(true);  // Enable start button
        break;
    default:
        break;
    }
}

// Slot to handle the start button click
void MainWindow::startButtonClicked()
 {
    qDebug() << "Start button clicked";
    ui->Start->setEnabled(false);

    // Reset progress
    currProgress = 0;
    score = 0;
    ui->progressBar->setValue(0);
    ui->label->setText("Score: 0");

    updateTurnLabel("My turn :>>");
    gameModel->startGame();

    QTimer::singleShot(500, this, &MainWindow::computerTurn);
}

void MainWindow::computerTurn() {
    ui->RedButton->setEnabled(false);
    ui->BlueButton->setEnabled(false);
    updateTurnLabel("Computer's turn");

    for (int i = 0; i < gameModel->getSequenceSize(); ++i) {
        QTimer::singleShot(i * speed, this, [this, i]() {
            Color color = gameModel->getSequenceAt(i);
            flashButton(color);
        });
    }

    QTimer::singleShot(gameModel->getSequenceSize() * speed + 500, this, &MainWindow::playerTurn);
}

void MainWindow::playerTurn() {
    updateTurnLabel("Your turn");
    ui->RedButton->setEnabled(true);
    ui->BlueButton->setEnabled(true);
}

void MainWindow::updateScore() {
    score++;
    ui->label->setText(QString("Score: %1").arg(score));
}

void MainWindow::updateTurnLabel(const QString &text) {
    ui->turnLabel->setText(text);
}

void MainWindow::flashButton(Color color) {
    if (color == Red) {
        ui->RedButton->setStyleSheet("background-color: lightcoral;");
        QTimer::singleShot(500, this, [this]() {
            ui->RedButton->setStyleSheet("background-color: red;");
        });
    } else if (color == Blue) {
        ui->BlueButton->setStyleSheet("background-color: lightblue;");
        QTimer::singleShot(500, this, [this]() {
            ui->BlueButton->setStyleSheet("background-color: blue;");
        });
    }
}

// Slot to handle red button click
void MainWindow::redButtonClicked()
{
    qDebug() << "Red button clicked";
    ui->RedButton->setStyleSheet("background-color: darkred;");
    QTimer::singleShot(200, this, [this]() {
        ui->RedButton->setStyleSheet("background-color: red;");
    });
    gameModel->processInput(Red);
}

// Slot to handle blue button click
void MainWindow::blueButtonClicked() {
    qDebug() << "Blue button clicked";
    ui->BlueButton->setStyleSheet("background-color: darkblue;");
    QTimer::singleShot(200, this, [this]() {
        ui->BlueButton->setStyleSheet("background-color: blue;");
    });
    gameModel->processInput(Blue);
}

void MainWindow::increaseSpeed() {
    if (speed > 100) {
        speed -= 50;
    }
}

// Update the progress bar based on the model's progress signal
void MainWindow::updateProgressBar(int val) {
    ui->progressBar->setValue(val);
}

// Adding unique feature
void MainWindow::changeTheme() {
    // Randomly generate colors for the theme, ensuring a positive bound
    QColor bgColor = QColor::fromRgb(QRandomGenerator::global()->bounded(1, 256),
                                     QRandomGenerator::global()->bounded(1, 256),
                                     QRandomGenerator::global()->bounded(1, 256));

    QColor redButtonColor = QColor::fromRgb(QRandomGenerator::global()->bounded(1, 256),
                                            QRandomGenerator::global()->bounded(1, 50),
                                            QRandomGenerator::global()->bounded(1, 50));

    QColor blueButtonColor = QColor::fromRgb(QRandomGenerator::global()->bounded(1, 50),
                                             QRandomGenerator::global()->bounded(1, 50),
                                             QRandomGenerator::global()->bounded(1, 256));

    // Set new colors for the background and buttons
    this->setStyleSheet(QString("background-color: %1;").arg(bgColor.name()));
    ui->RedButton->setStyleSheet(QString("background-color: %1; color: white; border: 1px solid black;")
                                     .arg(redButtonColor.name()));
    ui->BlueButton->setStyleSheet(QString("background-color: %1; color: white; border: 1px solid black;")
                                      .arg(blueButtonColor.name()));

    // Set new color for the start button for a fresh look
    QColor startButtonColor = QColor::fromRgb(QRandomGenerator::global()->bounded(1, 256),
                                              QRandomGenerator::global()->bounded(1, 256),
                                              QRandomGenerator::global()->bounded(1, 256));
    ui->Start->setStyleSheet(QString("background-color: %1; color: black; border: 1px solid black;")
                                 .arg(startButtonColor.name()));
}

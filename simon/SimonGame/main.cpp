/* This file serves as the entry point for the Simon Game application.
 * It initializes the QApplication, creates the MainWindow, sets the
 * window title, and starts the event loop.
 *
 * Team Members: Thu Ha
 * Github: https://github.com/miahaa
 * Creative Element:
 * The Simon Game incorporates a creative feature where the game's theme
 * changes dynamically based on player performance. As the user progresses
 * through the game, the color scheme and speed of the game adapt, offering
 * a more engaging experience. Additionally, after each round, the score is updated.
 *
 * Author: Thu Ha
 * Date: 28/10/2024
 * Assignment: A6 - Simon game
 * Repo: https://github.com/University-of-Utah-CS3505/a6-simon-f24-miahaa.git
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Simon Game");
    w.show();

    return a.exec();
}

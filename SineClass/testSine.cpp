/*
Author: Thu Ha
Assignment 2: Making a sine class
Date: 9/3/2024
Test file for the Sine class.
*/

#include "Sine.h"
#include <iostream>

int main() {
    // Construct a Sine object with amplitude 2.0 and wavelength 360.0 degrees
    Sine curve(2.0, 360.0, 45.0);

    // Loop from 0 to 360 degrees
    for (int i = 0; i <= 8; ++i) {
        std::cout << curve << std::endl;  // Output the current state of the sine object
        ++curve;  // Increment the angle of the sine object
    }

    return 0;
}

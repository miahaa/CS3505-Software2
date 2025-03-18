/*
Author: Thu Ha
Assignment 2: Making a sine class
Date: 9/3/2024
Complie file for the Sine class.
*/
#include "Sine.h"
#include <cmath>

// Constructor
Sine::Sine(double amplitude, double wave, double increment)
    : Amplitude(amplitude), waveLength(wave), angleIncrement(increment), Angle(0) {}

// Getter for current angle
double Sine:: currentAngle() const {
    return Angle;
}

// Getter for current height (y-value)
double Sine::currentHeight() const {
    double height = Amplitude * sin(2 * M_PI * Angle / waveLength);
    return height;
}

// Pre-increment operator
Sine& Sine::operator++() {
    Angle += angleIncrement;
    return *this;
}

// Post-increment operator
Sine Sine::operator++(int) {
    Sine temp(*this);
    ++(*this);
    return temp;
}

// Overload << operator
std::ostream& operator<<(std::ostream& os, const Sine& s) {
    os << s.currentAngle() << ", " << s.currentHeight();
    return os;
}

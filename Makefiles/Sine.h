/*
Author: Thu Ha
Assignment 2: Making a sine class
Date: 9/3/2024
Header file for the Sine class.
*/
#ifndef SINE_H
#define SINE_H

#include <iostream>

class Sine {
private:
    double Amplitude;      // The height from the curve centerline to the peak (amplitude of the sine wave)
    double waveLength;     // The horizontal distance between peaks (wavelength of the sine wave)
    double angleIncrement; // The change in angle for each step (in degrees)
    double Angle;      // The current angle being used to calculate the sine wave height

public:
    // Constructor
    // Initializes the Sine object with amplitude, wavelength, and angle increment, and starts at angle 0.
    Sine(double amplitude, double wave, double increment);

    // Getters
    // Returns the current angle of the sine wave.
    double currentAngle() const;

    // Calculates and returns the current height (y-value) of the sine wave based on the current angle.
    double currentHeight() const;

    // Overloaded operators
    // Pre-increment operator (increments the current angle by the angle increment).
    Sine& operator++();  

    // Post-increment operator (increments the current angle but returns the value before the increment).
    Sine operator++(int);  

    // Overload the << operator
    friend std::ostream& operator<<(std::ostream& os, const Sine& sine);
};
#endif
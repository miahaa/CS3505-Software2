/*
 * Program: Sine Wave Text Placement in PDF
 * Author: Thu Ha
 * Date: 09/12/2024
 * Description: This program generates a PDF document where the input text is placed
 * along a sine wave using the Haru PDF library. The sine wave characteristics—amplitude,
 * wavelength, and step size—define the vertical positioning of the characters along the curve.
 */

#include "HaruPDF.h"
#include "Sine.h"
#include <iostream>
#include <cstring>

/**
 * Main function that generates a PDF with text placed along a sine wave.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The command-line arguments, where the first is the program name and the second is the text to be placed.
 * @return 0 on success.
 */
int main(int argc, char** argv)
{
    // Prepare the PDF file name by appending ".pdf" to the program name
    char pdfFileName[256];
    strcpy(pdfFileName, argv[0]);
    strcat(pdfFileName, ".pdf");

    // Extract the text input from the command-line argument
    std::string textInput = argv[1];

    // Initialize the HaruPDF object with the specified file name
    HaruPDF pdfGenerator(pdfFileName);

    // Sine wave parameters for text placement
    double waveAmplitude = 40.0;    // Amplitude of the sine wave (vertical range)
    double waveWavelength = 180.0;  // Wavelength of the sine wave (horizontal length)
    double waveStep = 20.0;         // Step size to increment along the sine wave

    // Create a sine wave object for positioning text along the curve
    Sine sineCurve(waveAmplitude, waveWavelength, waveStep);

    // Starting coordinates for the sine wave text placement
    float xStartCoord = 10.0;      // Starting x-coordinate for the first character
    float yCenterCoord = 400.0;    // y-coordinate for the center baseline of the sine wave

    // Iterate through each character in the input text and place it along the sine curve
    for (size_t charIndex = 0; charIndex < textInput.length(); ++charIndex)
    {
        // Calculate the x and y coordinates for each character based on its index
        float xPos = xStartCoord + (charIndex * 20);      // Horizontal spacing between characters (20 units)
        float yPos = yCenterCoord + sineCurve.currentHeight(); // Vertical position based on the sine wave

        // Convert the current character to a string for placement
        std::string charToRender(1, textInput[charIndex]);

        // Place the character at the calculated position on the PDF
        pdfGenerator.placeText(xPos, yPos, charToRender);

        // Move to the next point on the sine curve for subsequent characters
        ++sineCurve;
    }

    // Save the generated PDF file
    pdfGenerator.save();

    return 0;
}

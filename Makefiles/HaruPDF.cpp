/*
 * Name: Thu Ha
 * Course: CS3505
 * Assignment: Facades and Makefiles
 * Description: This file implements the HaruPDF class, which uses the Haru PDF library 
 * to create and manipulate a PDF document. The class provides methods to add pages, 
 * place text along a sine curve, and save the PDF to a file.
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include "hpdf.h"
#include "HaruPDF.h"

/**
 * Constructor for HaruPDF class.
 * Initializes a new Haru PDF document and creates the first page.
 * 
 * @param filename The name of the file where the PDF will be saved.
 */
HaruPDF::HaruPDF(const std::string &filename) : filename(filename)
{
    // Initialize the Haru PDF document object
    pdf = HPDF_New(NULL, NULL);

    // Add an initial page to the PDF document
    addPage();
}

/**
 * Destructor for HaruPDF class.
 * Releases all resources allocated by the Haru PDF library.
 */
HaruPDF::~HaruPDF()
{
    HPDF_Free(pdf);
}

/**
 * Adds a new page to the PDF document.
 * Sets the page size to A4 with a portrait orientation.
 */
void HaruPDF::addPage()
{
    // Create and add a new page object to the PDF
    page = HPDF_AddPage(pdf);

    // Set the page size to A4 and orientation to portrait
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);
}

/**
 * Places text at a specified position (x, y) on the current page.
 * 
 * @param x        The x-coordinate where the text should be placed.
 * @param y        The y-coordinate where the text should be placed.
 * @param text     The content to be displayed as text.
 * @param fontSize The size of the font for the text (default: 24.0).
 */
void HaruPDF::placeText(float x, float y, const std::string& text, float fontSize)
{
    // Begin a new text object on the current page
    HPDF_Page_BeginText(page);

    // Set the font to "Courier-Bold" and specify the font size
    HPDF_Font font = HPDF_GetFont(pdf, "Courier-Bold", nullptr);
    HPDF_Page_SetFontAndSize(page, font, fontSize);

    // Position the text at the given (x, y) coordinates
    HPDF_Page_SetTextMatrix(page, 1.0, 0.0, 0.0, 1.0, x, y);

    // Show the text at the specified position
    HPDF_Page_ShowText(page, text.c_str());

    // End the current text object
    HPDF_Page_EndText(page);
}

/**
 * Saves the current PDF document to the file.
 * Writes the content of the PDF document to the specified filename.
 */
void HaruPDF::save() {
    HPDF_SaveToFile(pdf, filename.c_str());
}

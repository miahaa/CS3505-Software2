/*
 * Program: HaruPDF Class Definition
 * Author: Thu Ha
 * Date: 09/12/2024
 * Description: This header file defines the HaruPDF class, which serves as a wrapper 
 * for creating and manipulating PDF documents using the Haru PDF library. It includes 
 * methods for adding pages, placing text at specific coordinates, and saving the document to a file.
 */

#ifndef HARUPDF_H
#define HARUPDF_H

#include <string>
#include "hpdf.h" // Include Haru PDF library for PDF document handling.

/**
 * The HaruPDF class encapsulates functionality for creating and managing PDF documents.
 * It provides methods to add pages, position text, and save the PDF to a file.
 */
class HaruPDF
{
private:
    HPDF_Doc pdf;         // The PDF document object.
    HPDF_Page page;       // The current page of the PDF document.
    std::string filename; // Filename for saving the PDF document.
    HPDF_Font font;       // Font used for rendering text in the PDF.

public:
    /**
     * Constructor for the HaruPDF class.
     * Initializes a new PDF document and assigns a filename for saving.
     * 
     * @param filename The name of the file where the PDF will be saved.
     */
    explicit HaruPDF(const std::string& filename);

    /**
     * Destructor for the HaruPDF class.
     * Releases all resources allocated by the Haru PDF library.
     */
    ~HaruPDF();

    /**
     * Adds a new page to the PDF document.
     * The page size is set to A4 with portrait orientation.
     */
    void addPage();
    
    /// @brief Place text at the given coordinates
    /// @param x
    /// @param y
    /// @param text
    /// @param fontSize
    void placeText(float x, float y, const std::string& text, float fontSize = 24.0);

    void save();
};

#endif // HARUPDF_H

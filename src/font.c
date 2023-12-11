// #include <raylib.h>
// #include <stdlib.h>
// #include "gods.h"

// void font()
// {

//     Font font = {0};                                         // Declare empty font
//     font.texture = LoadTexture("assets/img/bitmapFont.png"); // Load your font image
//     font.baseSize = 35;                                      // Define your font characters height
//     font.glyphCount = 41;                                    // Define how many characters contains the font

//     // Fill the information for every individual character
//     font.glyphs = (GlyphInfo *)malloc(font.glyphCount * sizeof(GlyphInfo)); // Allocate some memory first
//     font.recs = (Rectangle *)malloc(font.glyphCount * sizeof(Rectangle));   // Allocate some memory first

//     for (int i = 0; i < font.glyphCount; i++)
//     {
//         font.glyphs[i].value = 32; // Character value (Unicode), for example 32 is SPACE

//         // Character rectangle in sprite font (x, y, width, heigh)
//         font.recs[i] = (Rectangle){20, 0, 34, 34};

//         // Just leave the following values as 0
//         font.glyphs[i].offsetX = 0;  // Character offset X when drawing
//         font.glyphs[i].offsetY = 0;  // Character offset Y when drawing
//         font.glyphs[i].advanceX = 0; // Character advance position X
//         //font.glyphs[i].image = NULL; // Character pixel data (grayscale)
//     }

//     // Use your font as usual
// }
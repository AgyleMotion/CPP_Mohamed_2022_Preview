#pragma once

#include <vector>
#include <string>
#include "font.hh"

/**
 * Represent a family of fonts of different sizes
 * THe size is the vertical height of the font
*/
typedef struct FT_LibraryRec_  *FT_Library;
typedef struct FT_FaceRec_*  FT_Face;

class font_face {
private:
  std::vector<font> fonts;
  std:: string filename; 
  static FT_Library ft_lib; 

public:
  font_face(const char filename[]);
  const font* get(const char faceName[], uint32_t size)const ;
};

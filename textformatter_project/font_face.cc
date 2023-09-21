#include <ft2build.h>
#include FT_FREETYPE_H
#include "font_face.hh"
#include <string>
#include <iostream>
#include <vector> 
#include <string>
#include "font.hh"
#include <fstream>
using namespace std; 


FT_Library font_face::ft_lib; 


font_face::font_face(const char filename[]) : filename(filename){
    std::string fontPath = "fonts/fonts.conf";
    std::cout << "FONT PATH = " << fontPath << endl;
  string font_name;
  uint32_t min_font_size, max_font_size, step_size;
 
  ifstream fontConf("fonts.conf");
  fontConf >> font_name >> min_font_size >> step_size >> max_font_size;
  //for each size font 
  // add each font to your vector
  //    font(ftLib, faceName, fontBase + facePath, minFontSize, inc,
  //                 maxFontSize, bitmap, sizeX, sizeY, currX, currY, rowSize);
  //  }
  //TODO: close FT_FONt_library....
}

// return the nearest size font you have
const font* font_face::get(const char faceName[],uint32_t size) const  {
  return nullptr; // TODO: fix this!
}

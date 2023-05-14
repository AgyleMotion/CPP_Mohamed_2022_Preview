#include<iostream>
#include<fstream>
#include<string>
#include<cstdint>
#include "bitmap.hh"
#include "color.hh"
#include "font_face.hh"
#include "font.hh"
#include "glyph.hh"
#include "bound_box.hh"
#include <webp/encode.h>
#include <webp/decode.h>
using namespace std;
/*
Mohamed Eraky
*/

bitmap::bitmap(uint32_t w, uint32_t h)
 : w(w), h(h), pixels(new color[w*h]){
//TODO: let's check out the random noise....
 }

bitmap::~bitmap(){
     delete [] pixels;  
}
/*
// we won't support copying bitmaps yet
bitmap(const bitmap& orig) = delete;
bitmap& operator =(const bitmap& orig) = delete;
*/
// read/write a single pixel
color& bitmap::operator ()(uint32_t x, uint32_t y) {
     return pixels[y * w + x];
}
// readonly lookup a single pixel
color bitmap::operator ()(uint32_t x, uint32_t y) const {
     return pixels[y * w + x];
}
//


// draw horizontal line from (x1,y) to (x2,y)
// note this can be significantly faster than arbitrary diagonals
void bitmap::horiz_line(uint32_t x1, uint32_t x2, uint32_t y, color c){
     for (uint32_t i=x1; i<=x2;i++){
          pixels[y*w+i] = c; 
     }
}
    
// draw vertical line from (x,y1) to (x,y2)
// note this can be significantly faster than arbitrary diagonals
void bitmap::vert_line(uint32_t x, uint32_t y1, uint32_t y2, color c){
     for (uint32_t i=y1; i<=y2;i++){
          pixels[i*w+x] = c; 
     }
}

void bitmap::rect(uint32_t x1, uint32_t y1, uint32_t w, uint32_t h, color c){
     horiz_line(x1, x1+w, y1, c);
     horiz_line(x1, x1+w, y1+h, c);
     vert_line(x1, y1, y1+h, c);
     vert_line(x1 + w, y1, y1+h, c);
     
}

void bitmap::fill_rect(uint32_t x1, uint32_t y1, uint32_t w, uint32_t h, color c){
     for (uint32_t i=y1; i<=y1+h;i++)
          horiz_line(x1, x1+w, i, c);
}

void bitmap::line(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, color c){
     double k = (double)(y2 - y1) / (x2 - x1);
     double y = y1;

     for (uint32_t i = x1; i <=x2; i++) {          
          pixels[(int)y*w+i] = c;
          y = y+k;
          
     }
}



void bitmap::circle(uint32_t xc, uint32_t yc, uint32_t r, color c){

}
void bitmap::fill_circle(uint32_t xc, uint32_t yc, uint32_t r, color c){

}

void bitmap::ellipse(uint32_t xc, uint32_t yc, uint32_t r, color c){

}
void bitmap::fill_ellipse(uint32_t xc, uint32_t yc, uint32_t rx, uint32_t ry, color c){

}
void bitmap::grid(uint32_t x, uint32_t y, uint32_t dx, uint32_t dy, uint32_t num_rows,  uint32_t num_cols){
     
}
void bitmap::gouraud(uint32_t x1, uint32_t y1, color c1, uint32_t x2, uint32_t y2, color c2, uint32_t x3, uint32_t y3, color c3){

}
void bitmap::triangle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, color c){

}
void bitmap::quad(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, uint32_t x4, uint32_t y4, color c){

}
void bitmap::fill_quad(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t x3, uint32_t y3, uint32_t x4, uint32_t y4, color c){

}
void bitmap::fill_quad(uint32_t x1, uint32_t y1, color c1, uint32_t x2, uint32_t y2, color c2, uint32_t x3, uint32_t y3, color c3, uint32_t x4, uint32_t y4, color c4){

}
void bitmap::fill_grid(uint32_t x[], uint32_t xlen, uint32_t y[], uint32_t ylen,  float data[]){

}
// draw a cubic bezier curve
//TODO: specify the resolution of the line segments?
void bitmap::bezier(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, color c){

}
// draw a sequence of connected cubic beziers where
// the first point of each is the last of the previous
void bitmap::bezier(float pts[], uint32_t len, color c){

}

// piecewise cubic hermite interpolation
// see: https://www.mathworks.com/help/matlab/ref/pchip.html
void bitmap::pchip(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, color c){

}
void bitmap::lagrange(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, color c){

}


void bitmap::natural_spline(float pts[], uint32_t len, color c){

}

void bitmap::text(uint32_t x, uint32_t y, const font* f, const char text[], uint32_t len){

}

// inline convenience function for nul-terminated strings
void bitmap::text(uint32_t x, uint32_t y, const font* f, const char text[]) {//text(x, y, f, text, strlen(text))

}
void bitmap::text(uint32_t x, uint32_t y, const font* f, uint32_t val){

}
void bitmap::text(uint32_t x, uint32_t y, const font* f, uint64_t val){

}
void bitmap::text(uint32_t x, uint32_t y, const font* f, double val){

}

// draw text with a fixed pixel limit. Return the number of characters drawn
uint32_t bitmap::text(uint32_t x, uint32_t y, const font* f, const char text[], uint32_t len, uint32_t max_width){
return x; // to be updated 
}

// draw text centered within a box of size width
void bitmap::centered_text(uint32_t x, uint32_t y, uint32_t width, const font* f, const char text[], uint32_t len){

}

// draw text centered within a rectangle whose top-left corner is x,y
// and that is width x height
void bitmap::xycentered_text(uint32_t x, uint32_t y, uint32_t width, uint32_t height, const font* f, const char text[], uint32_t len){

}

// right justified
void bitmap::right_text(uint32_t x, uint32_t y, uint32_t width, const font* f, const char text[], uint32_t len){

}

void bitmap::save(const char filename[]) {
  uint8_t* out;
  //size_t WebPEncodeRGB(const uint8_t* rgb, int width, int height, int stride, float quality_factor, uint8_t** output);
 // size_t = WebPEncodeRGB(uint8_t* rgb, w, h, 4*w, 100, & out);

     uint8_t* buf = new uint8_t[w*h*3];
     for (auto i = 0; i < h; i++) {
          for (auto j = 0; j < w; j++) {
               color c = pixels[(i * w + j)];
               buf[(i * w + j) * 3 + 0] = ((c.val >> 16) & 0xFF);  // Extract the RR byte
               buf[(i * w + j) * 3 + 1] = ((c.val >> 8) & 0xFF);   // Extract the GG byte
               buf[(i * w + j) * 3 + 2] = ((c.val) & 0xFF);        // Extract the BB byte
          }
      }

  size_t s = WebPEncodeRGB(buf, w, h, 3 * w, 100, &out);
  ofstream f(filename, ios::binary);
  f.write((char*)out, s);
  WebPFree(out);
}
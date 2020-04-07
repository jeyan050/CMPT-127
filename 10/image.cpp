#include <stdint.h> // for uint8_t
#include <stdio.h>
#include "image.hpp"
#include <stdlib.h>

/* 
class Image {
private:
  unsigned int cols;
  unsigned int rows;
  uint8_t* pixels;

public:
  Image();
  ~Image();
  int resize( unsigned int width,  unsigned int height, uint8_t fillcolour );
  int set_pixel( unsigned int x, unsigned int y, uint8_t colour );
  int get_pixel( unsigned int x, unsigned int y, uint8_t* colourp );
};
*/

Image::Image()
  : cols(0),
	rows(0),
	pixels(NULL)
{}

Image::~Image(){
	if(pixels != NULL){
		delete[] pixels;	
	}
}
/* Changes the size of an image, allocating memory as necessary, and
     setting all pixels to fillcolour. Returns 0 on success, or a non-zero error code.*/ 
 int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolour ){
	// Delete Pixels
	delete[] pixels;

	// Replace Pixels with new colour
	rows = height; //Can put this-> in front too
	cols = width;
	pixels = new uint8_t[rows*cols];
	// OR uint8_t pixels[rows* cols] (then using pixels later on)

	if(pixels == NULL){
		return 1;	
	}
	for (int i = 0; i < rows*cols; i++){
		pixels[i] = fillcolour;	
	}
	return 0;
}
  
  /* Sets the colour of the pixel at (x,y) to colour. Returns 0 on success, else a non-zero 
     error code. If (x,y) is not a valid pixel, the call fails and the image does not change.*/
int Image::set_pixel( unsigned int x, unsigned int y, uint8_t colour ){
	if (x >= cols || y >= rows){
		return 1;	
	}
	pixels[y*cols + x] = colour;
	return 0;
}
  
  /* Gets the colour of the pixel at (x,y) and stores at the address pointed to 
     by colourp. Returns 0 on success, else a non-zero error code. */
int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colourp ){
	if (x >= cols || y >= rows){
		return 1;	
	}
	*colourp = pixels[y*cols+x];
	return 0;
}




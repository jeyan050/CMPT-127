#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "image2.hpp"

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
	for (unsigned int i = 0; i < rows*cols; i++){
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
	pixels[y*rows + x] = colour;
	return 0;
}
  
  /* Gets the colour of the pixel at (x,y) and stores at the address pointed to 
     by colourp. Returns 0 on success, else a non-zero error code. */
int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colourp ){
	if (x >= cols || y >= rows || colourp == NULL){
		return 1;	
	}
	*colourp = pixels[y*cols+x];
	return 0;
}

  /* Saves the image in the file filename. In a format that can be
     loaded by load(). Returns 0 on success, else a non-zero error
     code. */
int Image::save( const char* filename ){
	if (filename == NULL || pixels == NULL){
		return 1;	
	}
	FILE *f = fopen(filename, "w");
	
	// Write into f
	fwrite(&cols, sizeof(int), 1, f);
	fwrite(&rows, sizeof(int), 1, f);
	fwrite(pixels, sizeof(uint8_t), 1, f);
	fclose(f);
	return 0;		
}

  /* Load the an image from the file filename, replacing the current
     image size and data. The file is in a format that was saved by
     save(). Returns 0 success, else a non-zero error code . */
int Image::load( const char* filename ){
	if (filename == NULL){
		return 1;	
	}

    unsigned int colsrows[2];
    FILE* f = fopen(filename, "r");
    if (fread(colsrows, sizeof(unsigned int), 2, f) != 2) {
      cols = 0;
      rows = 0;
      pixels = NULL;
      return 0;
    }
    cols = colsrows[0];
    rows = colsrows[1];
    pixels = new uint8_t[cols*rows];
    if (fread(pixels, sizeof(uint8_t), cols*rows, f) != cols*rows) {
      return 1;
    }
    fclose(f);
    return 0;
}



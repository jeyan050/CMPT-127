#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "image3.hpp"

Image::Image()
  : cols(0),
	rows(0),
	pixels(NULL)
{{}{}}

Image::~Image(){
	if(pixels != NULL){
		for (int x = 0; x < rows; x++){
			delete [] pixels[x];
		}	
		delete [] pixels;
	}
}
/* Changes the size of an image, allocating memory as necessary, and
     setting all pixels to fillcolour. Returns 0 on success, or a non-zero error code.*/ 
 int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolour ){
	// Delete Pixels
	for(int x = 0; x < rows; x++){
		delete[] pixels[x];	
	}
	delete[] pixels;

	// Replace Pixels with new colour
	rows = height; //Can put this-> in front too
	cols = width;
	pixels = new uint8_t*[cols];
	for (int x = 0; x < width; x++){
		pixels[x] = new uint8_t[width];
	}
	// OR uint8_t pixels[rows* cols] (then using pixels later on)

	if(pixels == NULL){
		return 1;	
	}
	for (int i = 0; i < rows; i++){
		for (int y = 0; y < cols; y++){
			pixels[i][y] = fillcolour;	
		}	
	}
	return 0;
}
  
  /* Sets the colour of the pixel at (x,y) to colour. Returns 0 on success, else a non-zero 
     error code. If (x,y) is not a valid pixel, the call fails and the image does not change.*/
int Image::set_pixel( unsigned int x, unsigned int y, uint8_t colour ){
	if (x >= cols || y >= rows){
		return 1;	
	}
	pixels[y][x] = colour;
	return 0;
}
  
  /* Gets the colour of the pixel at (x,y) and stores at the address pointed to 
     by colourp. Returns 0 on success, else a non-zero error code. */
int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colourp ){
	if (x >= cols || y >= rows || colourp == NULL){
		return 1;	
	}
	*colourp = pixels[y][x];
	return 0;
}

  /* Saves the image in the file filename. In a format that can be
     loaded by load(). Returns 0 on success, else a non-zero error
     code. */
int Image::save( const char* filename ){
	if (filename == NULL) {
      return 1;
    }
	FILE* f = fopen(filename, "w");
    if (f == NULL) {
      return 1;
    }
	if(pixels == NULL){
	  fclose(f);
	  return 0;	
	}

    int len = (cols * rows);
    fwrite(&len, sizeof(int), 1, f);
    fwrite(&(rows), sizeof(int), 1, f);
    fwrite(&(cols), sizeof(int), 1 , f);

    for (int x = 0; x < rows; x++){
		for (int y = 0; y < cols; y++){
			fwrite(&(pixels[x][y]), sizeof(uint8_t), 1, f);	
		}
    }	
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
	FILE *f = fopen(filename, "r");
	
	int len;
	// Check if its empty
	if (fread(&len, sizeof(int), 1, f) == 0){
		cols = 0;
		rows = 0;
		pixels = NULL;
		fclose(f);
		return 0;
	}

	// Stores Rols and Cols
	int lenRows;
	int lenCols;
	fread(&lenRows, sizeof(int), 1, f);
	fread(&lenCols, sizeof(int), 1, f);
	
	// Using Previous Functions to size up the image
	resize(lenCols, lenRows, 0);
	
	for (int y = 0; y < rows; y++){
		for (int x = 0; x < cols; x++){
			fread(&pixels[y][x], sizeof(uint8_t), 1, f);	
		}	
	}
	if (pixels == NULL){
		return 1;	
	}
	fclose(f);
	return 0;
}


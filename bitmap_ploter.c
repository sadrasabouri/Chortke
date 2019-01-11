#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bitmap_ploter.h"

void write_bitmap(char *plot, int width, int height, int axis_color, const char *filename) {
  FILE *f;
  unsigned char *img = NULL;
  int filesize = 54 + 3 * width * height;
  int axis_colors[0];
  axis_colors[2] = axis_color % 0x100;
  axis_color /= 0x100;
  axis_colors[1] = axis_color % 0x100;
  axis_color /= 0x100;
  axis_colors[0] = axis_color % 0x100; 
  
  img = (unsigned char *) malloc(3 * width * height);//Reserve 3*width*height bytes from memory.
  memset(img, 0, 3 * width * height);//set all reserved memory with 0.
	
  for(int i = 0; i < width; i++) {
    for(int j = 0; j < height; j++) {
      int x = i, y = j;
      int r = plot[i * width + j] * 0xFF;
	  // simply plot[i][j]*255 | if r is plot[i][j] = 0 r is zero else if plot[i][j] = 1 r is 255.
      int g = r;
      int b = r;
      if (x == height / 2 || y == width / 2){//axis lines
		r = axis_colors[0];
		b = axis_colors[1];
		g = axis_colors[2];
	  }
      if (r > 255) r = 255;
      if (g > 255) g = 255;
      if (b > 255) b = 255;
      img[(x + y * width) * 3 + 2] = (unsigned char)(r);
      img[(x + y * width) * 3 + 1] = (unsigned char)(g);
      img[(x + y * width) * 3 + 0] = (unsigned char)(b);
    }
  }

  unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
  unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
  unsigned char bmppad[3] = {0,0,0};

  bmpfileheader[ 2] = (unsigned char)(filesize    );
  bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
  bmpfileheader[ 4] = (unsigned char)(filesize>>16);
  bmpfileheader[ 5] = (unsigned char)(filesize>>24);

  bmpinfoheader[ 4] = (unsigned char)(    width    );
  bmpinfoheader[ 5] = (unsigned char)(    width>> 8);
  bmpinfoheader[ 6] = (unsigned char)(    width>>16);
  bmpinfoheader[ 7] = (unsigned char)(    width>>24);
  bmpinfoheader[ 8] = (unsigned char)(   height    );
  bmpinfoheader[ 9] = (unsigned char)(   height>> 8);
  bmpinfoheader[10] = (unsigned char)(   height>>16);
  bmpinfoheader[11] = (unsigned char)(   height>>24);

  f = fopen(filename, "wb");
  fwrite(bmpfileheader, 1, 14, f);
  fwrite(bmpinfoheader, 1, 40, f);
  for(int i = 0; i < height; i++) {
    fwrite(img + (width * i * 3), 3, width, f);
    fwrite(bmppad, 1, (4 - (width * 3) % 4) % 4, f);
  }

  free(img);
  fclose(f);

}

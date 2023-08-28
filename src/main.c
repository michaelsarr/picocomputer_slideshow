
#include <fcntl.h>
#include "rp6502.h"



#define WIDTH 320
#define HEIGHT 240

static void vmode(uint16_t data)
{
    xreg(data, 0, 1);
}

int load_image(const char * filename)
{
int fd;
fd = open(filename,O_RDONLY);
if ( fd < 0) 
      return fd;

readx(0x0000, 0x4b00, fd);
readx(0x4B00, 0x4B00, fd);
close(fd);
return fd;
}


void pause(int val)
{
while (val) 
  {
  int16_t counter;
  for (counter =0;counter < 30000;)
     counter++;
  val--;
  }
}


void main()
{
    int8_t cnt=1;
    int status;
    char filename[15];
    vmode(1);  // 320x240 4 bit color


    while (1) 
    {
    // for now name your files ss_img1.bin, ss_img2.bin ...    
    status = load_image(filename);
    if( status < 0) // file didnt load
      cnt=1;
    pause(20);
    }
}
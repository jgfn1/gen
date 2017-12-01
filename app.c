/*
This game was made to be played on a Altera Ciclone IV E GX board.
*/

#include <unistd.h>
#include <fcntl.h>
#include "stdlib.h"
#include "stdio.h"

unsigned char hexdigit[] = {0x3F, 0x06, 0x5B, 0x4F,
                            0x66, 0x6D, 0x7D, 0x07, 
                            0x7F, 0x6F, 0x77, 0x7C,
			                      0x39, 0x5E, 0x79, 0x71};

int main() {
  int i, j, k;

  int dev = open("/dev/de2i150_altera", O_RDWR);
  printf("Welcome to Hex-Bin!\n");
  printf("Your job is to input a binary number displayed in hexadecimal on the BCD using the switches from 0 to 15.\n");
  printf("Enter the maximum number you want to convert: ");
  int max_number;
  scanf("%d", &max_number);                                                              

  for (i =0 ; i > -1; i++) {
    read(dev, &j, 4);

    srand(time(NULL));
    j = (rand() + i) % max_number + 1;
    
    j = j + 65536;
    k = hexdigit[j & 0xF]
      | (hexdigit[(j >>  4) & 0xF] << 8)
      | (hexdigit[(j >>  8) & 0xF] << 16)
      | (hexdigit[(j >> 12) & 0xF] << 24);
    k = ~k;

    write(dev, &k, 4);

    int answer = 0;
    j = j % 65536;
    do{
        read(dev, &answer, 4);
        answer = answer % 65536;
    }while((j != answer));
  }

  close(dev);
  return 0;
}
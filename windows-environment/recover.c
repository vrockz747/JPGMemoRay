#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
    FILE *card = fopen(argv[1] , "rb" );
    if (card == NULL)
    {
      printf("Error, cannot read card\n");
      return -1;
    }
    if (argc != 2)
    {
      printf("Wrong usage of program, please read READ_ME.txt\n");
      return -1;
    }

    typedef uint8_t BYTE;
    BYTE *copy = malloc(512);
    int jpegcounter = 0;
    int number = 1;

    //Repeat untill the end of card
    FILE *img = NULL;
    char *filename = malloc(sizeof(int));

    for(int i = 1; number == 1; i++)
    {
        //READ 512 BYTES INTO A BUFFER
        number = fread(copy, 512, 1,card);
        sprintf(filename,"%03i.jpg",jpegcounter);

        //IF START OF A NEW JPG
        if ( copy[0] == 0xff &&
             copy[1] == 0xd8 &&
             copy[2] == 0xff &&
             (copy[3] & 0xf0 ) == 0xe0)

            {
		
              jpegcounter++;
              //IF FIRST JPEG open
                if (jpegcounter == 1)
                {
                img = fopen(filename, "wb");
                fwrite(copy,512,1,img);


                }
                //ELSE close before
                else
                {
                  fclose(img);
                  img = fopen(filename, "wb");
                  sprintf(filename,"%03i.jpg",jpegcounter-1);

                  fwrite(copy,512,1,img);

                }

            }

          //ELSE CONTINUE WRITING
          else if (jpegcounter > 0)
          {
            //IF ALREADY FOUND JPEG
            fwrite(copy,512,1,img);


          }

      }
  //close all files and malloc
  free(copy);
  free(filename);
  fclose(card);
  fclose(img);

}


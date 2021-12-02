#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 6

char* myGetLine(FILE*);

int main()
{
    FILE *fp;
    FILE *fp2;
    char *ptr1;
    char *ptr2;
    char *ptr3;

    int counter = 0;
    int ii;
    int diff;

    fp = fopen("input.txt", "r");
    fp2 = fopen("test.txt", "w");

    if (fp != NULL)
    {
        ptr2 = myGetLine(fp);
        do
        {
            //get line from file
            ptr1 = myGetLine(fp);

            //compare with previous ptr
            diff = atoi(ptr2) - atoi(ptr1);
            if (diff < 0)
            {
                counter++;
            }

            //copy ptr1 to ptr2, move old value to ptr3
            ptr3 = ptr2;
            ptr2 = ptr1;

            //free ptr3 after comparison
            free(ptr3);
        } 
        while (!feof(fp));
        
        printf("\nNumber of differences > 0 found: %d\n", counter);

        // Safely release file pointer
        if (fclose(fp))
        {
            printf("Something went wrong!\n");
        }
    }
    
    return 0;
}

//Reads until it finds a return char
char* myGetLine(FILE *fp)
{
    int ii = 0, size;
    char test;
    char *out, temp[BUF];


    while (ii < BUF && temp[ii-1] != 13)
    {
        temp[ii] = fgetc(fp);
        ii++;
    };

    out = (char*) malloc(ii * sizeof(char));
    size = ii-1;

    for (ii = 0; ii < size; ii++)
    {
        out[ii] = temp[ii];
    }
    
    return out;
}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 6

char* myGetLine(FILE*);
int compareTwo(FILE *fp);
int slidingWindowCompare(FILE *fp);

int main()
{
    FILE *fp;
    FILE *fp2;

    int diff;

    fp = fopen("input.txt", "r");
    fp2 = fopen("test.txt", "w");

    if (fp != NULL)
    {
        diff = slidingWindowCompare(fp);
        printf("\nNumber of differences > 0 found: %d\n", diff);

        // Safely release file pointer
        if (fclose(fp))
        {
            printf("Something went wrong!\n");
        }
    }
    
    return 0;
}

int slidingWindowCompare(FILE *fp)
{
    int ii = 0, counter = 0;
    char* ptr1, *ptr2, *ptr3;
    int a, b, c, sum, sum2, sum3, diff;

    ptr1 = myGetLine(fp);
    ptr2 = myGetLine(fp);
    ptr3 = myGetLine(fp);

    a = atoi(ptr1);
    b = atoi(ptr2);
    c = atoi(ptr3);

    sum = a + b + c;

    while (!feof(fp))
    {
        free(ptr1);

        ptr1 = ptr2;
        ptr2 = ptr3;

        a = b;
        b = c;

        ptr3 = myGetLine(fp);
        c = atoi(ptr3);
        
        sum2 = a + b + c;

        printf("%d + %d + %d = %d\n", a, b, c, sum2);

        if (sum2 - sum > 0)
        {
            counter++;
        }

        sum = sum2;

    }

    return counter;

}

//Reads until it finds a newline char
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




#include <stdio.h>
#pragma warning(disable : 4996)
FILE* myFile;



int AmountOfLines() {
    int count_lines = 0;
    char chr;
    myFile = fopen("test.txt", "r");
    //extract character from file and store in chr
    chr = getc(myFile);
    while (chr != EOF)
    {
        //Count whenever new line is encountered
        if (chr == '\n')
        {
            count_lines = count_lines + 1;
        }
        //take next character from file.
        chr = getc(myFile);
    }
    fclose(myFile); //close file.

    return count_lines;
}






int main()
{
    int LengthFile = AmountOfLines();

    myFile = fopen("test.txt", "r");

    //read file into array
    int numberArray[1000];
    int i;

    for (i = 0; i < LengthFile; i++)
    {
        fscanf(myFile, "%d", &numberArray[i]);
    }
    for (i = 0; i < LengthFile; i++)
    {
        for (int j = 0; j < LengthFile; j++) 
        {
            if (numberArray[i] + numberArray[j] == 2020) 
            {
                printf("%d\n", numberArray[i] * numberArray[j]);
                return 0;
            }
        }
    }
    return 0;
}
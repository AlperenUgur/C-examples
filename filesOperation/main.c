#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Input
{
    char *inputArray;
    int size;
    int capacity;
}Input_t;

typedef struct InputLine
{
    Input_t* inp;
    int Lsize;
    int Lcapacity;
}InputLine_t;

void inputRead(InputLine_t* inputL);

int main()
{    
    InputLine_t inputL;
    inputL.Lsize=0;
    inputL.Lcapacity=10;
    inputL.inp=(Input_t*)malloc(inputL.Lcapacity*sizeof(Input_t));
    inputRead(&inputL);
    for (int i = 0; i < inputL.Lsize; i++)
    {
        free(inputL.inp[i].inputArray);
    }
    free(inputL.inp);
    return 0;
}

void inputRead(InputLine_t* inputL)
{
    char character;
    FILE *fptr;
    fptr=fopen("tryFile2.txt","r");
    character=fgetc(fptr);

    inputL->inp[inputL->Lsize].size = 0;
    inputL->inp[inputL->Lsize].capacity = 10;
    inputL->inp[inputL->Lsize].inputArray = (char*)malloc(inputL->inp[inputL->Lsize].capacity * sizeof(char));

    while(character!=EOF)
    {
        if(character == '\n') 
        {
            inputL->Lsize++;
            if (inputL->Lsize == inputL->Lcapacity) 
            {
                inputL->Lcapacity = inputL->Lcapacity * 2;
                inputL->inp=(Input_t*)realloc(inputL->inp, inputL->Lcapacity*sizeof(Input_t));
            }
            inputL->inp[inputL->Lsize].size = 0;
            inputL->inp[inputL->Lsize].capacity = 10;
            inputL->inp[inputL->Lsize].inputArray = (char*)malloc(inputL->inp[inputL->Lsize].capacity * sizeof(char));
        } 
        else 
        {
            Input_t* linePtr = &inputL->inp[inputL->Lsize];
            if (linePtr->size + 1  == linePtr->capacity) 
            {
                linePtr->capacity = linePtr->capacity * 2;
                linePtr->inputArray = (char*)realloc(linePtr->inputArray, linePtr->capacity*sizeof(char));
            }
            linePtr->inputArray[linePtr->size] = character;
            linePtr->size++;
        }
        character=fgetc(fptr); 
    }

    for(int i = 0; i < inputL->Lsize; i++)
    {
        printf("%d. line: ", (i+1));
        Input_t* linePtr = &inputL->inp[i];
        for (int j = 0; j < linePtr->size; j++) {
            printf("%c|",linePtr->inputArray[j]);
        }
        printf("\n");
    }
    fclose(fptr);
}

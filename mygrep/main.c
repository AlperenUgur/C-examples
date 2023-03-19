#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Input
{
   char* inputArray;
   int size;
   int capacity;
}Input_t;
typedef struct InputLine
{
   Input_t* input;
   int size;
   int capacity;
}InputLine_t;

void reader(InputLine_t* inputLine);
int founder(Input_t* input,char *word);

int main() {
   char word[10];
   printf("enter what do you want to search:");
   gets(word);
   
   InputLine_t inputLine;

   inputLine.size=0;
   inputLine.capacity=10;
   inputLine.input=(Input_t*)malloc(inputLine.capacity*(sizeof(Input_t)));
   reader(&inputLine);

   
   
   for(int i = 0; i < inputLine.size;i++)
   {
      int result = founder(&inputLine.input[i],word);
      printf("%d. line result is :%d\n" ,(i+1),result);
      printf("%d. line: ",(i+1));
      Input_t* linePtr =&inputLine.input[i];
      for(int j = 0;j<linePtr->size;j++)
      {
         printf("%c",linePtr->inputArray[j]);
      }
      

      printf("\n");
   }

      
   for(int i = 0;i<inputLine.size;i++)
   {
      free(inputLine.input[i].inputArray);
   }
   free(inputLine.input);
   return 0;
}
void reader(InputLine_t* inputLine){
   char character;
   FILE *fptr;
   fptr=fopen("grepsFile.txt","r");
   character=fgetc(fptr);

   inputLine->input[inputLine->size].size=0;
   inputLine->input[inputLine->size].capacity=10;
   inputLine->input[inputLine->size].inputArray=(char*)malloc(inputLine->input[inputLine->size].capacity*(sizeof(char)));
   
   
   while(character!=EOF )
   {
      if(character=='\n')
      {
         inputLine->size++;
         if(inputLine->size==inputLine->capacity)
         {
            inputLine->capacity=inputLine->capacity*2;
            inputLine->input=(Input_t*)realloc(inputLine->input,inputLine->capacity*sizeof(Input_t));
         }
         inputLine->input[inputLine->size].size=0;
         inputLine->input[inputLine->size].capacity=10;
         inputLine->input[inputLine->size].inputArray=(char*)malloc(inputLine->input[inputLine->size].capacity*(sizeof(char)));
      }
      else
      {  
         Input_t* linePtr =&inputLine->input[inputLine->size];
         if(linePtr->size + 1 == linePtr->capacity)
         {
            linePtr->capacity=linePtr->capacity*2;
            linePtr->inputArray=(char*)realloc(linePtr->inputArray,linePtr->capacity*(sizeof(char)));
         }
         
         linePtr->inputArray[linePtr->size] = character;
         linePtr->size++;
      }
      character=fgetc(fptr);
   }
   
   
   
   fclose(fptr);
}

int founder(Input_t* input,char *word)
{
   int i;
   int lengthWord=strlen(word);
   int flg=0;
   for(i = 0;i<input->size;i++)
   {
      if(input->inputArray[i]==word[0])
      {
         for(int j = 0;j<lengthWord;j++)
         if(word[j]==input->inputArray[i+j])
         {
            flg=1;
            return flg;
         }
      }
   }
return flg;
}
   
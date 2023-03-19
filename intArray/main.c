#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NumberList
{
    int *numberArray;
    int size;
    int capacity;
}NumberList_t;

int main(){
    NumberList_t intList;
    char nbrListString[50];
    intList.size =0;
    intList.capacity=5;
    intList.numberArray = (int*) malloc(intList.capacity * sizeof(int));
    printf("enter your string\n");
    scanf("%s",nbrListString);
    //printf("here your string:%s\n",nbrListString);
    
    const char delim[]=",";
    char *token;
   
    token = strtok(nbrListString, delim);

    while( token != NULL ) 
    {
      //printf( " %s\n", token );
      int intToken = atoi(token);
      intList.numberArray[intList.size]=intToken;
      if(intList.size+1==intList.capacity){
        intList.capacity=intList.capacity*2;
        intList.numberArray=(int*)realloc(intList.numberArray,intList.capacity*sizeof(int));
      }
      intList.size++;
      token = strtok(NULL, delim);
    }
    for(int i = 0; i < intList.size; i++) 
    {
        for(int j=0;j<(intList.size-1);j++)
        {
            if(intList.numberArray[j]>intList.numberArray[j+1])
            {
                int temp=intList.numberArray[j];
                intList.numberArray[j]=intList.numberArray[j+1];
                intList.numberArray[j+1]=temp;
            }
           
        } 
        
    }
    for(int i=0;i< intList.size; i++){
        printf("%d ",intList.numberArray[i]);

    }
    printf("\n");
    
    

    free(intList.numberArray);
    return 0;
}
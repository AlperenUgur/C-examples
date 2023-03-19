#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct NumberList
{
    int* numbers;
    int size;
    int capacity;
} NumberList_t;

int main()
{
    char str[100];
    const char delim[] = {" "};
    char* token;

    NumberList_t list;
    list.size = 0;
    list.capacity = 10;
    list.numbers = (int*) malloc(list.capacity * sizeof(int));

    printf("enter a string:"); // get a string from user and parse it with strtok
    gets(str);
    token=strtok(str,delim);
    
   
   
    while (token!=NULL)
    {   
        bool flg=false;
        for(int j=0;strlen(token);j++)
        {
            if(!(isdigit(token[j])))
            {
                break;
            }
            else
            {
                flg=true;
            }
        }
        
        if(flg==false)
        {
            token=strtok(NULL,delim);
        }
        else
        {
            int tkn=atoi(token);
            list.numbers[list.size]=tkn;
            list.size++;
        }
        
        if (list.size + 1 == list.capacity) 
        {
            list.capacity = list.capacity * 2;
            list.numbers = (int*) realloc(list.numbers, list.capacity * sizeof(int));   
        } 
        token=strtok(NULL,delim);
    }
    for(int i = 0;i<list.size;i++)
    {
        printf("numbers are:%d\n",list.numbers[i]);
    }
    free(list.numbers);
    return 0;
    
}
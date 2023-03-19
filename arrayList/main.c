#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NumberList{
    int* list;
    int listSize;
    int listCapacity;
} NumberList_t;

/**
 * @brief add numbers between startPoint and endPoint
 *        e.g. addNumbersToList(3,10); -> will add [3, 4, 5, 6, 7, 8, 9]
 * @param nbrList 
 * @param startPoint 
 * @param endPoint 
 */
void addNumbersToList(NumberList_t* nbrList, int startPoint, int endPoint);

/**
 * @brief Print number list + list size + list cap to screen
 * @param nbrList 
 */
void printNumbers(const NumberList_t* nbrList);

int main()
{
    NumberList_t nbrList;
    nbrList.listSize = 0;
    nbrList.listCapacity = 3;
    nbrList.list = (int*) malloc (nbrList.listCapacity * sizeof(int));
    addNumbersToList(&nbrList, 3, 10);
    printNumbers(&nbrList);
    addNumbersToList(&nbrList, 15, 85);
    printNumbers(&nbrList);
    free(nbrList.list);
    return 0;
}

void addNumbersToList(NumberList_t* nbrList, int startPoint, int endPoint)
{
    for(int i=startPoint;i<endPoint;i++)
    {      
        nbrList->list[nbrList->listSize]=i;
        if (nbrList->listSize + 1 == nbrList->listCapacity) 
        {
            nbrList->listCapacity = nbrList->listCapacity * 2;
            nbrList->list= (int*) realloc (nbrList->list,nbrList->listCapacity * sizeof(int));
        }
        nbrList->listSize++;
    }
}

void printNumbers(const NumberList_t* nbrList)
{
    for(int i=0;i<nbrList->listSize;i++)
    {
        printf("%d ",nbrList->list[i]);
    }
    printf("\n");
    printf("list capasity:%d list size:%d\n",nbrList->listCapacity, nbrList->listSize);
}
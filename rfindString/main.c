#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int findString(const char* sample, const char* target);

bool findStringHelper(const char* sample, const char* target);

void testInvalidTarget();

void testEmptyTarget();

void testNormalTarget();

void testifTargetBiggerThanCatchedLatter();

void testmultiTarget();




int main(){
    printf("testInvalidTarget is started\n");
    testInvalidTarget();

    printf("testEmptyTarget is started\n");
    testEmptyTarget();

    printf("testNormalTarget is started\n");
    testNormalTarget();

    printf("ifTargetBiggerThanCatchedLatter is started\n");
    testifTargetBiggerThanCatchedLatter();

    printf("multiTarget\n");
    testmultiTarget();
}

int findString(const char* sample, const char* target) 
{   
    if(strlen(target)==0){
        printf("Empty target can not be found!\n");
        return -1;
    }


    if(strlen(target)>strlen(sample))
        {
            printf("İnvalid string to be found!\n");
            return -1;
        }
    for(int i=strlen(sample)-1;i>=0;i--)
    {
        if(target[0]==sample[i])
        {
            if(findStringHelper(&sample[i],target))
            {
                return i;
            }
        }
    }
    return -1;
}

bool findStringHelper(const char* sample, const char* target){
    for(int j=0;j<strlen(target);j++){
        if(target[j]!=sample[j]){
            return false;
        }
    }
    return true; 
}
void testInvalidTarget(){
    char exStr[] = {"I want to go to abroad"};
    char target[] = {"to to to ot ot ot ot ot ot ot to"};

    int index = findString(exStr, target);
    printf("index : %d\n", index);

}
void testEmptyTarget(){
    char exStr[] = {"I want to go to abroad"};
    char target[] = {""};

    int index = findString(exStr, target);
    printf("index : %d\n", index);
}
void testNormalTarget(){
    char exStr[] = {"I want to go to abroad"};
    char target[] = {"to"};

    int index = findString(exStr, target);
    printf("index : %d\n", index);
}
void testifTargetBiggerThanCatchedLatter(){
    char exStr[] = {"I want to go to abroad"};
    char target[] = {"totototototo"};

    int index = findString(exStr, target);
    printf("index : %d\n", index);
}

void testmultiTarget(){
    char exStr[] = {"I want to go to to abroad"};
    char target[] = {"to"};

    int index = findString(exStr, target);
    printf("index : %d\n", index);
}

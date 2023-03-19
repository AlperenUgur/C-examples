#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int findString(const char* sample, const char* target);

bool findStringHelper(const char* sample, const char* target);

void testInvalidTarget();
void testIfTargetdoesNotExist();
void testNormalTarget();
void testMultiTarget();
void testEmptyTarget();
void testEmptySample();



int main(){
    printf("testInvalidTarget is started\n");
    testInvalidTarget();

    printf("testIfTargetdoesNotExist is started\n");
    testIfTargetdoesNotExist();

    printf("testNormalTarget is started\n");
    testNormalTarget();

    printf("testMultiTarget is started\n");
    testMultiTarget();

    printf("testEmptyTarget is started\n");
    testEmptyTarget();

    printf("testEmptySample is started\n");
    testEmptySample();

    return 0;
}

int findString(const char* sample, const char* target) 
{
     if(strlen(sample)==0){
        printf("Sample can not be empty!\n");
        return -1;
     }
     if(strlen(target)==0){
        printf("Empty target can not be found!\n");
        return -1;
     }
     if(strlen(target)>strlen(sample)){
         printf("İnvalid string to be found!\n");
        return -1;
     }
     
     
    int retval=-1;
    for(int i=0;i<strlen(sample);i++)
    {
        if(target[0]==sample[i])
        {
            bool found= findStringHelper(&sample[i],target);
            if(found){
                return i;
            }
        }
    }
    return retval;
}

bool findStringHelper(const char* sample, const char* target){
    bool found= true;
    
    for(int j=0;j<strlen(target);j++){
        if(target[j]!=sample[j]){
            found = false;
            break;
        }
    }
    return found; 
}
    
 void testInvalidTarget(){
     char exStr[] = {"the lazy bty went to the market boy in a car"};
    char target[] = {"boy boy boy boy boy boy boy boy boy boy boy boy boy boy"};

     int index = findString(exStr, target);
     printf("index : %d\n", index);

}

void testIfTargetdoesNotExist(){
    char exStr[] = {"the lazy bty went to the market boy in a car"};
    char target[] = {"superior"};

    int index = findString(exStr, target);
    printf("index : %d\n", index);
}

void testNormalTarget(){
    char exStr[] = {"the lazy boy went to the market boy in a car"};
    char target[] = {"boy"};

    int index = findString(exStr, target);
    printf("index : %d\n", index);
}

void testMultiTarget(){
    char exStr[] = {"the lazy boy boy went to the market boy in a car"};
    char target[] = {"boy"};

    int index = findString(exStr, target);
    printf("index : %d\n", index);
}

void testEmptyTarget(){
    char exStr[] = {"the lazy boy went to the market boy in a car"};
    char target[] = {""};

    int index = findString(exStr, target);
    printf("index : %d\n", index);
}

void testEmptySample(){
    char exStr[] = {""};
    char target[] = {"boy"};

    int index = findString(exStr, target);
    printf("index : %d\n", index);
}

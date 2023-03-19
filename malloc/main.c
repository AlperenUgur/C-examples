#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    char *word=NULL;
    word =(char*) malloc(10);
    printf("enter your word:");
    scanf("%s",word);
    word = realloc(word,15);
    strcat(word," amazing!");
    printf("new word:%s\n",word);
    free(word);
    return 0;
}


































// int main(){

//     char *name;
//     name = malloc(sizeof(*name));
//     printf("what's your name:");
//     scanf("%s",name);
//         if(name==NULL){
//             printf("çalışmadı");
//         }
//         else {
//             printf("your name is:%s\n",name);
//         }
//     free(name);
// return 0;

// }
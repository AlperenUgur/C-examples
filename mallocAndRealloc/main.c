#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[100];
    char surname[100];
} Person_t;

int main()
{
    char name[100];
    char surname[100];
    Person_t* personList;
    int personListSize = 0;
    int personListCapacity = 2;

    personList = (Person_t*) malloc (personListCapacity * sizeof(Person_t));

    while(name[0] != '!') {
        printf("Enter a name:\n");
        scanf("%s", name);
        printf("Enter a surname:\n");
        scanf("%s", surname);
        
        if (personListSize + 1 == personListCapacity) {
            personListCapacity = personListCapacity * 2;
            personList = (Person_t*) realloc (personList, personListCapacity * sizeof(Person_t));
            printf("personListCapacity : %d \n", personListCapacity);
        }
        strcpy(personList[personListSize].name, name);
        strcpy(personList[personListSize].surname, surname);

        personListSize++;
        sleep(1);
    }

    printf("Person List\n");
    printf("------------------------------\n");
    for(int i = 1; i < personListSize; i++) {
        printf("%d. person: %s %s\n", i, personList[i].name, personList[i].surname);
    }

    free(personList);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int strtoint(char* mathOperation);
void testSum();
void testSubs();

int main()
{
    testSum();
    testSubs();
    return 0;
}

/**
 * @brief This function will calculate a math operation
 *        like "13 + 17" and result should be 30 here
 * @note this function is calculating only sum and substruction
 * 
 * @param mathOperation string that keeps the math operation
 * @return int this is the result
 */
int strtoint(char* mathOperation)
{
    const char sum = '+';
    const char subs = '-';
    char delim[] = {" "};
    char* firstNumStr = strtok(mathOperation, delim);
    char* operation = strtok(NULL, delim);
    char* secondNumStr = strtok(NULL, delim);

    if (firstNumStr == NULL || operation == NULL || secondNumStr == NULL) {
        printf("The given math operation is invalid!\n");
        return -1;
    }

    int firstNum = atoi(firstNumStr);
    int secondNum = atoi(secondNumStr);

    if (operation[0] == sum) {
        return firstNum + secondNum;
    } else if (operation[0] == subs) {
        return firstNum - secondNum;
    }

    return 0;
}

void testSum()
{
    char exStr[] = {"13 + 17"};
    printf("res: %d\n", strtoint(exStr));
}

void testSubs()
{
    char exStr[] = {""};
    printf("res: %d\n", strtoint(exStr));
}
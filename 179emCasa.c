// JOÃO MARCELO BITAR DUARTE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char *largestNumber(int *nums, int numsSize);
bool comparaMenorQue(char *num1s, char *num2s);

int main()
{
    int numsSize = 5;
    int nums[] = {3, 30, 34, 5, 9};

    char *resultado = largestNumber(nums, numsSize);
    printf("%s\n", resultado);

    free(resultado);
    return 0;
}

char *largestNumber(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize - 1; j++)
        {
            char s1[100], s2[100];
            sprintf(s1, "%d", nums[j]);
            sprintf(s2, "%d", nums[j + 1]);

            if (comparaMenorQue(s1, s2))
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    if (nums[0] == 0)
    {
        char *res = malloc(2);
        strcpy(res, "0");
        return res;
    }

    char *res = (char *)malloc(1000 * sizeof(char));
    res[0] = '\0';
    for (int i = 0; i < numsSize; i++)
    {
        char temp[20];
        sprintf(temp, "%d", nums[i]);
        strcat(res, temp);
    }
    return res;
}

bool comparaMenorQue(char *num1s, char *num2s)
{
    char comb1[100], comb2[100];

    strcpy(comb1, num1s);
    strcat(comb1, num2s);
    strcpy(comb2, num2s);
    strcat(comb2, num1s);

    if (strcmp(comb1, comb2) < 0)
    {
        return true;
    }
    return false;
}

// pesquisei sobre o sprintf pq sabia que existia
// e convertia int pra string mas não lembrava como usava!!
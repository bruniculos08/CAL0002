#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

void mergeSort(int *array, int start, int end);
void merge(int *array, int left, int right, int end);

struct timeval tv_ini, tv_fim;
unsigned long time_diff, sec_diff, usec_diff, msec_diff;

void mergeSort(int *array, int start, int end)
{
    if (array == NULL || start >= end)
        return;
    mergeSort(array, start, (end + start) / 2);
    mergeSort(array, (end + start) / 2 + 1, end);
    merge(array, start, (end + start) / 2 + 1, end);
    return;
}

void merge(int *array, int left, int right, int end)
{
    if (array == NULL)
        return;
    else if (right > end || left > right)
        return;

    int *tempArray = malloc((1 + end - left) * sizeof(int));
    int l = left, r = right;
    for (int i = 0; i <= end - left; i++)
    {
        if (l > right - 1)
        {
            tempArray[i] = array[r];
            r++;
        }
        else if (r > end)
        {
            tempArray[i] = array[l];
            l++;
        }
        else if (array[l] <= array[r])
        {
            tempArray[i] = array[l];
            l++;
        }
        else
        {
            tempArray[i] = array[r];
            r++;
        }
    }
    for (int i = 0; i <= end - left; i++)
        array[i + left] = tempArray[i];
    return;
}

void printTime(FILE *filePointer)
{
    fprintf(filePointer, "%lu ", time_diff);
    time_diff = 0;
}

void testCase()
{
    FILE *filePointer;
    filePointer = fopen("PerformanceTestCase.txt", "w+");

    int n = 5000;
    for (int i = 0; i < n; i++)
    {
        int *array = malloc(sizeof(int) * i);

        printf("array %i\n", i);

        for (int j = 0; j < i; j++)
            array[j] = i - j;

        gettimeofday(&tv_ini, NULL);
        mergeSort(array, 0, i - 1);
        gettimeofday(&tv_fim, NULL);

        time_diff = (1000000L * tv_fim.tv_sec + tv_fim.tv_usec) - (1000000L * tv_ini.tv_sec + tv_ini.tv_usec);

        printTime(filePointer);
        free(array);
    }
    fprintf(filePointer, "\n");
}

int main()
{
    testCase();
}
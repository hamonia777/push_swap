#include "push_swap.h"
#include "libft/libft.h"

void run_sort(Info info)
{

}
int quick_sort(Info info,)
{
    int *arr = info.arr;
    int pivot;

    pivot = 0;
    init(arr, info.len);
}
int *init(int *arr, int len)
{
    int pivot;
    int start;
    int end;
    
    start = 1;
    end = len - 1;
    pivot = arr[0];
    while (start < end)
    {
        while (arr[start] > pivot)
            start++;
        while (arr[end] > pivot)
            end--;
        if (start < end )
        {
            swap(&arr[start], &arr[end]);
            start++;
            end--;
        }
    }
    return arr;
}
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
#include<stdio.h>
int main()
{
    int a = 3;
    int b = 10;
    printf("a= %d b= %d", a,b);
    swap(&a,&b);
    printf("a= %d b= %d", a,b);
}
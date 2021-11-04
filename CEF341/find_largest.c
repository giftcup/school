#include <stdio.h>

#define N 5

int num_of_max = 0;
int min_num;

int find_largest(int* arr, int size, int* max, int max_index);

int main(void)
{
    int arr[N], max, max_pos;
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    
    max = arr[N-1];
    min_num = arr[N-1];
    max_pos = find_largest(arr, N-2, &max, N-1);
    printf("Max number is found first at %d found at index %d. "
            "There are %d of them\n", max, max_pos, num_of_max);
    printf("The smallest number is %d\n", min_num);

    return 0;
}

int find_largest(int* arr, int size, int* max_num, int max_index)
{
    int max;

    if (size < 0)
        return max_index;

    if (*max_num < arr[size])
    {
        *max_num = arr[size];
        max_index = size;
        num_of_max = 1;
    }
    else if (*max_num == arr[size])
        num_of_max++;

    if (min_num > arr[size])
        min_num = arr[size];
    
    return find_largest(arr, --size, max_num, max_index);
}
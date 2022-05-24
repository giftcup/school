#include <stdio.h>

#define N 6

int num_of_max = 0;
int min_num;

int maximum(int *arr, int start, int end);

int main(void)
{
    int arr[N], max, max_pos;
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    
    max = arr[N-1];
    min_num = arr[N-1];

    max_pos = maximum(arr, 0, N-1);

    printf("max position %d contains %d\n", max_pos, arr[max_pos]);

    // printf("Max number is found first at %d found at index %d. "
    //         "There are %d of them\n", max, max_pos, num_of_max);
    // printf("The smallest number is %d\n", min_num);

    return 0;
}

int maximum(int *arr, int start, int end) {
    int max_pos, left = 0, right = 0;
    if (start == end) {
        return start;
    }
    else {
        max_pos = maximum(arr, start+1, end);
        if (arr[start] >= arr[max_pos]) {
            return start;
        }
        else 
            return max_pos;
    }
    
}
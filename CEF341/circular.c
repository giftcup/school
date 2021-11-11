/**
 * @brief Generates a queue implemented using circular arrays
 *        which performs the enqueue, dequeue, topOfQueue,
 *        endOfQueue and others as it's main operations.
 * @author giftcup
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Queue;
int max_size;

void greeting(void);
void instruction(void);
void create(Queue* Q);
bool queue_is_empty(int* end);
bool queue_is_full(int *head, int *end);
void enqueue(Queue* Q, int *head, int* end, int num);
int dequeue(Queue* Q, int* head, int* end);
void display(Queue* Q, int* head, int* end);
int top_of_queue(Queue* Q, int *head, int* end);
int end_of_queue(Queue* Q, int *head, int* end);
int size_of_queue(Queue* Q, int* head, int* end);

int main(void)
{
    Queue* Q;
    int option, number, size;
    int head = 0, end = -1;

    greeting();
    create(Q);

    for (;;)
    {
        instruction();
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Enter number: ");
                scanf("%d", &number);
                enqueue(Q, &head, &end, number);
                printf("%d %d\n", head, end);
                break;
            case 2:
            printf("%d\n", dequeue(Q, &head, &end));
                break;
            case 3:
                display(Q, &head, &end);
                break;
            case 4:
                size = size_of_queue(Q, &head, &end);
                size == 0 ? printf("Queue is empty\n") : printf("Size of queue: %d\n", size);
                break;
            case 5:
                printf("Top of queue: %d\n", top_of_queue(Q, &head, &end));
                break;
            case 6:
                printf("End of queue: %d\n", end_of_queue(Q, &head, &end));
                break;
            case 0:
                printf("\nBye!\n");
                return 0;
            default:
                printf("Option is invalid\n");
        }
    }

    return 0;
}

/** 
 * @brief Says hello to the user
 * @return void
 */
void greeting(void)
{ 
    printf("\nHello, welcome to the queue program!\n");
}

/**
 * @brief create: Takes a pointer to integers P
 *        Asks the user for the size of the stack.
 *        Allocates space for P in memory according to the
 *        size given.
 * @param Q a queue Q
 * @return void
 */
void create(Queue* Q)
{
    printf("\nEnter size of queue: ");
    scanf("%d", &max_size);

    Q = (int *) malloc (sizeof(int) * max_size);
}

/**
 * @brief   instruction: Displays the operations that can be performed
 *          on the queue.
 * @param void
 * @return void
*/
void instruction(void)
{
    printf("\nEnter (1) to enqueue\n"
           "Enter (2) to dequeue\n"
           "Enter (3) to display queue\n"
           "Enter (4) to check the size of queue\n"
           "Enter (5) to display topOfQueue\n"
           "Enter (6) to display the endOfQueue\n"
           "Enter (0) to quit\n");
}

/**
 * @brief checks if queue is empty
 * @param end pointer to the last element of the queue
 * @return true or false
 */ 
bool queue_is_empty(int* end)
{
    if (*end == -1)
        return true;
    return false;
}

/**
 * @brief checks if a queue is full
 * @param head pointer to the first element
 * @param end pointer to the last element
 */ 
bool queue_is_full(int *head, int *end)
{
    if ((*head == *end + 1 && *end != -1) || (*head == 0 && *end == max_size - 1))
        return true;
    return false;
}

/**
 * @brief displays the elements in a queue withou removing them
 * @param Q a queue
 * @param head pointer to first element
 * @param end pointer to last element
 * @return void
 */ 
void display(Queue* Q, int* head, int* end)
{
    int temp_head = *head, temp_end = *end;
    int data;

    if (queue_is_empty(end))
    {
        printf("Queue is empty\n");
        return;
    }

    while (!queue_is_empty(end))
    {
        data = dequeue(Q, head, end);
        printf("%d ", data);
    }
    printf("\n");
    *head = temp_head;
    *end = temp_end;
}

/**
 * @brief removes the first element from the queue
 * @return the first element of it exists, otherwise, terminates
 *         the program
 */ 
int dequeue(Queue* Q, int* head, int* end)
{
    int data;
    if (queue_is_empty(end))
    {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    data = Q[*head];
    if (*head == *end)
    {
        *head = 0;
        *end = -1;
    }
    else if(*head == max_size - 1)
        *head = 0;
    else
        *head += 1;
    return data;
}

/**
 * @brief Adds elements to the end of the queue
 * @param num number to be added at the end of the queue
 * @return void
 */ 
void enqueue(Queue* Q, int *head, int* end, int num)
{
    if (queue_is_full(head, end))
    {
        printf("Queue is full\n");
        return;
    }
    if (*end == max_size - 1 && *head != 0)
        *end = 0;
    else 
        *end += 1;
    Q[*end] = num;
}

/**
 * @brief Gets the first element without removing it
 * @return the first element in the queue
 */ 
int top_of_queue(Queue* Q, int *head, int* end)
{
    if (queue_is_empty(end))
    {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return Q[*head];
}


/**
 * @brief gets the last element in the queue without removing it
 * @return the last element in the queue
 */ 
int end_of_queue(Queue* Q, int *head, int* end)
{
    if (queue_is_empty(end))
    {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return Q[*end];
}

/**
 * @brief Calculates the number of elements in the queue
 * @return integer representing the number of elements
 */ 
int size_of_queue(Queue* Q, int* head, int* end)
{
    int temp_head = *head, temp_end = *end;
    int count = 0;

    while (!queue_is_empty(end))
    {
        dequeue(Q, head, end);
        count++;
    }
    *head = temp_head;
    *end = temp_end;

    return count;
}
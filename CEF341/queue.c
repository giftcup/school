#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Queue;

void greeting(void);
void instruction(void);
void create(Queue* Q);
bool queue_is_empty(int* head, int* end);
void enqueue(Queue* Q, int* end, int number);
int dequeue(Queue* Q, int* head, int* end);
void display(Queue* Q, int* head, int* end);
int top_of_queue(Queue* Q, int *head, int* end);
int end_of_queue(Queue* Q, int *head, int* end);
int size_of_queue(int *head, int* end);

int max_size = 0;

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
                enqueue(Q, &end, number);
                break;
            case 2:
            printf("%d\n", dequeue(Q, &head, &end));
                break;
            case 3:
                display(Q, &head, &end);
                break;
            case 4:
                size = size_of_queue(&head, &end);
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

/* greeting: Says hello to the user
** returns
*/
void greeting(void)
{ 
    printf("\nHello, welcome to the queue program!\n");
}


/* create: Takes a pointer to integers P
**         Asks the user for the size of the stack.
**         Allocates space for P in memory according to the
**         size given.
**         returns;
*/
void create(Queue* Q)
{
    printf("\nEnter size of queue: ");
    scanf("%d", &max_size);

    Q = (int *) malloc (sizeof(int) * max_size);
}

/* instruction: Displays the operations that can be performed
**              on the queue.
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

/* queue_is_empty: Takes a pointers to the head and end of a 
**                 queue as parametera. Checks if queue is empty
**                 and return true if it is and false otherwise.
*/
bool queue_is_empty(int* head, int* end)
{
    return *head > *end;
}

/* enqueue: Takes pointers to a queue and the end of queue and
**          a number to be added to the the queue.
**          If the queue is full return, else it add the element
**          to the queue then returns.
*/
void enqueue(Queue* Q, int* end, int num)
{
    if (*end > max_size -1)
    {
        printf("Queue is full\n");
        return;
    }
    *end += 1;
    Q[*end] = num;
}


/* dequeue: Takes pointers to a queue, head of the queue and end
**          of the queue. If the queue is empty, it terminates the
**          program else, returns the element at the head and
**          increments the head.
*/
int dequeue(Queue* Q, int* head, int* end)
{
    if (queue_is_empty(head, end))
    {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    *head = *head + 1;
    return Q[*head - 1];
}


/* display: Displays the list of elements in the queue if
**          its not empty and returns.
*/
void display(Queue* Q, int* head, int* end)
{
    int temp = *head;

    if (queue_is_empty(head, end))
    {
        printf("Queue is empty\n");
        return;
    }

    while (!queue_is_empty(head, end))
    {
        *head = *head + 1;
        printf("%d ", Q[*head - 1]);
    }
    printf("\n");
    *head = temp;
}

/* size_of_queue: Takes a pointer to the head and end of a queue
**                and returns the size of the queue.
*/
int size_of_queue(int *head, int* end)
{
    return *end - *head + 1;
}

/* top_of_queue: Takes pointers to a queue, head and end of the queue
**               If the queue is not empty, it returns the element at
**               the top of the queue, else just returns
*/
int top_of_queue(Queue* Q, int *head, int* end)
{
    if (queue_is_empty(head, end))
    {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return Q[*head];
}


/* end_of_queue: Takes pointers to a queue, head and end of the queue
**               If the queue is not empty, it returns the element at
**               the end of the queue, else just returns
*/
int end_of_queue(Queue* Q, int *head, int* end)
{
    if (queue_is_empty(head, end))
    {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return Q[*end];
}

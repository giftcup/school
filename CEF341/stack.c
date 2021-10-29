#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Stack;

void greeting(void);
void instruction(void);
void create(Stack* P);
bool stack_is_empty(int *top);
void push(Stack* P, int *top, int num);
int pop(Stack* P, int *top);
void display(Stack* P, int* top);
int size_of_stack(Stack* P, int* top);
int top_of_stack(Stack* P, int* top);

int main(void)
{
    Stack *P;
    int top = 0, option;
    int number;
    int size;

    greeting();
    create(P);

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
                push(P, &top, number);
                break;
            case 2:
                printf("%d\n", pop(P, &top));
                break;
            case 3:
                if (stack_is_empty(&top))
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
            case 4:
                display(P, &top);
                break;
            case 5:
                size = size_of_stack(P, &top);
                size == 0 ? printf("Stack is Empty\n") : printf("Size of stack: %d\n", size);
                break;
            case 6:
                printf("Top of stack: %d\n", top_of_stack(P, &top));
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
    printf("\nHello, welcome to the stacks program!\n");
}


/* create: Takes a pointer to integers P
**         Asks the user for the size of the stack.
**         Allocates space for P in memory according to the
**         size given.
**         returns;
*/
void create(Stack* P)
{
    int size;

    printf("\nEnter size of stack: ");
    scanf("%d", &size);

    P = (int *) malloc (sizeof(int) * size);
}

/* instruction: Displays the operations that can be performed
**              on the stack.
*/
void instruction(void)
{
    printf("\nEnter (1) to push an element\n"
           "Enter (2) to pop\n"
           "Enter (3) to check if Stack is empty\n"
           "Enter (4) to display stack\n"
           "Enter (5) to check the size of stack\n"
           "Enter (6) to display the topOfStack\n"
           "Enter (0) to quit\n");
}

/* stack_is_empty: Takes a pointer to the top of stack as
**                 parameter. Checks if stack is empty and
**                 return true if it is and false otherwise.
*/
bool stack_is_empty(int *top)
{
    return *top == 0;
}


/* push: Takes a pointer to a stack, top of stack and
**       a number to be added to stack.
**       If stack is empty, returns, else it adds the number
**       to the top of stack and increments the top of stack by
**       one then returns.
*/
void push(Stack* P, int *top, int num)
{
    if  (*top == SIZE)
    {
        printf("Stack is full!\n");
        return;
    }

    *top = *top + 1;
    P[*top - 1] = num;
}


/* pop: Returns the elements at the top of stack
**      and decrements the top of stack.
*/
int pop(Stack* P, int *top)
{
    if (stack_is_empty(top))
    {
        printf("Stack is empty!\n");
        exit(EXIT_FAILURE);
    }

    *top = *top - 1;
    return P[*top];
}

/* display: Takes in a pointer to a stack and the top of stack
**          Displays all the elements in the stack and returns.
*/
void display(Stack* P, int* top)
{
    int i = *top;
    if (stack_is_empty(top))
    {
        printf("Stack is empty!\n");
        exit(EXIT_FAILURE);
    }

    while (!stack_is_empty(top))
    {
        *top = *top - 1;
        printf ("%d ", P[*top]);
    }
    printf("\n");
    *top = i;
}


/* top_of_stack: Displays the element at the top of stack
**               without removing it then returns.
*/
int top_of_stack(Stack* P, int* top)
{
     if (stack_is_empty(top))
    {
        printf("Stack is empty!\n");
        exit(EXIT_FAILURE);
    }

    return P[*top - 1];
}


/* size_of_stack: Takes in a stack and a pointer to the 
**                top of stack and return an integer
**                representing the number of elements in the
**                stack.
*/
int size_of_stack(Stack* P, int *top)
{
    int count = 0, temp = *top;

    while (!stack_is_empty(top))
    {
        *top -= 1;
        count ++;
    }

    *top = temp;
    return count;
}

#include <stdio.h>  //I/O operations
#include <math.h>   //pow function
#include <stdlib.h> //for memory allocation

// data structure for storing a polynomial.
struct Poly_Node
{
  int coefficient;
  int degree;
  struct Poly_Node *next;
};

// function prototypes
void create_node(struct Poly_Node **P);
void make_poly(struct Poly_Node **P);
void create_poly(struct Poly_Node **);
void display_poly(struct Poly_Node *);
int degree_Poly(struct Poly_Node *P);
void add_to_poly(struct Poly_Node **P, struct Poly_Node *new_node);
void add_Poly(struct Poly_Node **R, struct Poly_Node *P, struct Poly_Node *Q);
void add_to_end(struct Poly_Node **tracker, struct Poly_Node *newNode);

// main function
int main(void)
{
  struct Poly_Node *P, *Q, *R;
  P = Q = R = NULL;
  char make_polynomial;
  int degree;

  make_poly(&P);

  printf("\n\nMake another polynomial (y | n): ");
  scanf("%c", &make_polynomial);
  fflush(stdin);
  if (make_polynomial == 'y' || make_polynomial == 'Y')
  {
    make_poly(&Q);
  }

  display_poly(P);
  degree = degree_Poly(P);
  printf("The polynomial is of degree %d\n", degree);

  if (Q != NULL)
  {
    display_poly(Q);
    degree = degree_Poly(Q);
    printf("The polynomial is of degree %d\n", degree);
    add_Poly(&R, P, Q);
    display_poly(R);
    degree = degree_Poly(R);
  }

  return 0;
}

/**
 * @brief: Creating a new node of type Poly_Node.
 */

void create_node(struct Poly_Node **P)
{
  *P = malloc(sizeof(struct Poly_Node));
  if (*P == NULL)
    printf("Memory allocation failed in create_node");
}

/**
 * @brief: condition to add node to a polynomial
 * @param P: polynomial in question.
 */

void make_poly(struct Poly_Node **P)
{
  char condition;
  printf("Add node to polynomial (y | n): ");
  scanf("%c", &condition);
  fflush(stdin);

  while (condition == 'y' || condition == 'Y')
  {
    create_poly(P);
    printf("Add node to polynomial (y | n): ");
    scanf(" %c", &condition);
    fflush(stdin);
  }
}

/**
 * @brief: Adding a new node to the polynomial
 * @param P: polynomial in question.
 * @param newNode: node to be added.
 */
void add_to_poly(struct Poly_Node **P, struct Poly_Node *newNode)
{
  struct Poly_Node *cur, *prev;

  if (*P == NULL || newNode->degree > (*P)->degree)
  {
    newNode->next = *P;
    *P = newNode;
    return;
  }

  for (cur = *P, prev = NULL;
       cur != NULL && newNode->degree < cur->degree;
       prev = cur, cur = cur->next)
    ;

  if (cur == NULL)
  {
    prev->next = newNode;
    newNode->next = NULL;
    return;
  }

  if (cur != NULL && newNode->degree > cur->degree)
  {
    prev->next = newNode;
    newNode->next = cur;
    return;
  }

  if (cur != NULL && newNode->degree == cur->degree)
  {
    cur->coefficient += newNode->coefficient;
    return;
  }

  newNode->next = cur->next;
  cur->next = newNode;
}

/**
 * @brief: creates a term of a polynomial by getting the
 * degree and coefficient and storing in a structure
 * @param P: pointer to a pointer of type struct Poly_Node;
 * @return void
 **/
void create_poly(struct Poly_Node **P)
{
  struct Poly_Node *newNode, *cur, *prev;
  create_node(&newNode);

  printf("Enter coefficient: ");
  scanf("%d", &newNode->coefficient);
  printf("Enter degree: ");
  scanf("%d", &newNode->degree);

  while (newNode->degree < 0)
  {
    printf("Degree can not be less than 0, input a correct degree: ");
    scanf("%d", &newNode->degree);
  }

  add_to_poly(P, newNode);
}

/**
 * @brief: Function to display polynomial.
 * @param P: polynomial in question.
 */

void display_poly(struct Poly_Node *P)
{
  if (P == NULL)
  {
    printf("No polynomial to be displayed.\n");
    return;
  }

  printf("%dx^%d", P->coefficient, P->degree);
  P = P->next;
  while (P != NULL)
  {
    printf(" + %dx^%d ", P->coefficient, P->degree);
    P = P->next;
  }
  printf(" = 0\n");
}

/**
 * @brief: Function to return the degree of polynomial.
 * @param P: Polynomial in question.
 */
int degree_Poly(struct Poly_Node *P)
{
  return P->degree;
}

/**
 * @brief: Add node to the end of the polynomial.
 * @param tracker: pointer used to track current end node.
 * @param newNode: a newly created node.
 */

void add_to_end(struct Poly_Node **tracker, struct Poly_Node *newNode)
{
  if (*tracker == NULL)
    *tracker = newNode;
  else
  {
    while ((*tracker)->next != NULL)
      *tracker = (*tracker)->next;
    (*tracker)->next = newNode;
    *tracker = newNode;
  }
  (*tracker)->next = NULL;
  printf("%d %d\n", (*tracker)->coefficient, (*tracker)->degree);
}

/**
 * @brief: Function to add two polynomials
 * @param R: Resulting polynomial of the addition(sum).
 * @param P and @param Q: polynomials to be added.
 */

void add_Poly(struct Poly_Node **R, struct Poly_Node *P, struct Poly_Node *Q)
{
  struct Poly_Node *newNode, *tracker;
  create_node(&newNode);

  while (Q != NULL && P != NULL)
  {
    if (Q->degree > P->degree)
    {
      newNode->degree = Q->degree;
      newNode->coefficient = Q->coefficient;
      Q = Q->next;
      printf("1.%d %d\n", newNode->degree, newNode->coefficient);
    }

    else if (P->degree > Q->degree)
    {
      newNode->degree = P->degree;
      newNode->coefficient = P->coefficient;
      P = P->next;
      printf("2.%d %d\n", newNode->degree, newNode->coefficient);
    }

    else
    {
      newNode->degree = P->degree;
      newNode->coefficient = P->coefficient + Q->coefficient;
      Q = Q->next;
      P = P->next;
      printf("3.%d %d\n", newNode->degree, newNode->coefficient);
    }
    newNode->next = NULL;

    if (*R == NULL)
    {
      add_to_end(R, newNode);
      tracker = *R;
      continue;
    }
    add_to_end(&tracker, newNode);

    printf("    %d %d\n", (*R)->degree, (*R)->coefficient);
  }

  while (Q != NULL || P != NULL)
  {
    if (Q->next)
    {
      newNode->degree = Q->degree;
      newNode->coefficient = Q->coefficient;
      Q = Q->next;
      printf("%d %d\n", newNode->degree, newNode->coefficient);
    }
    if (P->next)
    {
      newNode->degree = P->degree;
      newNode->coefficient = P->coefficient;
      P = P->next;
      printf("%d %d\n", newNode->degree, newNode->coefficient);
    }

    if (*R == NULL)
    {
      add_to_end(R, newNode);
      tracker = *R;
      continue;
    }
    add_to_end(&tracker, newNode);

    printf("    %d %d\n", (*R)->degree, (*R)->coefficient);
  }
}

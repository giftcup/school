#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Poly_Node {
  int coefficient;
  int degree;
  struct Poly_Node *next;
};

void create_node(struct Poly_Node **P);
void create_poly(struct Poly_Node **);
void display_poly(struct Poly_Node *);
int degree_Poly(struct Poly_Node *P);
void add_Poly(struct Poly_Node **R, struct Poly_Node *P, struct Poly_Node *Q);


int main(void){
  struct Poly_Node *poly1, *tracker;
  poly1 = NULL;
  char condition;
  int degree;

    printf("Add node to polynomial (y | n)?: ");
    scanf("%c", &condition);

    while(condition == 'y' || condition == 'Y'){
        create_poly(&poly1);
        printf("Add node to polynomial (y | n)?: ");
        scanf(" %c", &condition);
    }

    display_poly(poly1);
//   degree = degree_Poly(poly1);
//   printf("The polynomial is of degree %d\n", degree);

    free(poly1);
    return 0;
}

void create_node(struct Poly_Node **P) {
    *P = malloc(sizeof(struct Poly_Node));
    if (*P == NULL) printf("Memory allocation failed in create_node");
}

void create_poly(struct Poly_Node **P){
    struct Poly_Node *newNode, *temp;
    create_node(&newNode);

    printf("Enter coefficient: ");
    scanf("%d", &newNode->coefficient);
    printf("Enter degree: ");
    scanf("%d", &newNode->degree);

    while(newNode->degree < 0){
        printf("Degree can not be less than 0, input a correct degree: ");
        scanf("%d", &newNode->degree);
    }

    if (*P == NULL || newNode->degree > (*P)->degree) {
        newNode->next = *P;
        *P = newNode;
        free(newNode);
        return;
    }

    create_node(&temp);
    temp = *P;

    for(; newNode->degree < temp->degree && temp->next != NULL; temp = temp->next);

    if (newNode->degree == temp->degree) {
        temp->coefficient += newNode->coefficient;
        free(newNode);
        free(temp);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    free(newNode);
}

void display_poly(struct Poly_Node *P){
    if(P == NULL){
        printf("No polynomial to be displayed.\n");
        return;
    }

    while (P->next != NULL) {
        printf(" + %dx^%d ", P->coefficient, P->degree);
        P = P->next;
    }


  printf(" = 0\n");
}

int degree_Poly(struct Poly_Node *P) {
    int degree = P->degree;
    P = P->next;

    while (P != NULL) {
        if (P->degree > degree) 
            degree = P->degree;
        P = P->next;
    }
    return degree;
}
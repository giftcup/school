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
void add_at_end(struct Poly_Node **R,int coef,int deg);
void multiply_poly(struct Poly_Node **R,struct Poly_Node *P,struct Poly_Node *Q);
void removeDuplicates(struct Poly_Node *P);
int eval_poly(struct Poly_Node *P, int x);

// main function
int main(void)
{
  struct Poly_Node *P, *Q, *R;
  P = Q = R = NULL;
  char eval_polynomial;
  int degree;

int main(void){
    struct Poly_Node *P, *Q, *R;
    P = Q = R = NULL;
    char make_polynomial;
    int degree,value;
    make_poly(&P);

    printf("\n\nMake another polynomial (y | n): ");
    scanf("%c", &make_polynomial);
    fflush(stdin);
    if (make_polynomial == 'y' || make_polynomial == 'Y')
    {
      make_poly(&Q);
    }

    printf("\n\nMake another polynomial (y | n): ");
    scanf("%c", &make_polynomial);
    fflush(stdin);
    if (make_polynomial == 'y' || make_polynomial == 'Y') {
        make_poly(&Q);
    }
    display_poly(P);
    degree = degree_Poly(P);
    printf("The polynomial is of degree %d\n", degree);


  

    if (Q != NULL) {
        display_poly(Q);
        degree = degree_Poly(Q);
        printf("The polynomial is of degree %d\n", degree);
        
        create_node(&R);
        add_Poly(&R, P, Q);
        printf("\nSum of Polynomials is : \n");
        display_poly(R);
        degree = degree_Poly(R);
        printf("The polynomial is of degree %d\n", degree);
        
        multiply_poly(&R,P,Q);
        printf("\nThe Product of Polynomials is : \n");
        display_poly(R);
        printf("The polynomial is of degree %d\n", degree_Poly(R));
    }
    
    printf("\n\nEnter a value to evaluate Polynomial: ");
    scanf("%d", &value);
    fflush(stdin);
  
    printf("\nChoose polynomial to evaluate (P | Q): ");
    scanf("%c", &eval_polynomial);
    fflush(stdin);
  
    if (eval_polynomial == 'p' || eval_polynomial == 'P') {
        printf("\nThe result is %d\n", eval_poly(P,value));
    }
    else if (eval_polynomial == 'q' || eval_polynomial == 'Q') {
        printf("\nThe result is %d\n", eval_poly(Q,value));
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


void add_to_poly(struct Poly_Node **P, struct Poly_Node *newNode) {
    struct Poly_Node *cur, *prev;

    if (*P == NULL || newNode->degree > (*P)->degree) {
        newNode->next = *P;
        *P = newNode;
        return;
    }
=======
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
  
void add_Poly(struct Poly_Node **R, struct Poly_Node *P, struct Poly_Node *Q){
    int coef,deg;
    *R = NULL;
    
	  while (Q != NULL && P != NULL) {
      if (Q->degree > P->degree){
        deg = Q->degree;
        coef = Q->coefficient;
        Q = Q->next;
		}

		else if (P->degree > Q->degree){
			deg = P->degree;
			coef = P->coefficient;
			P = P->next;
		}
		
		else {
			deg = P->degree;
			coef = P->coefficient + Q->coefficient;
			Q = Q->next;
			P = P->next;
		}

		add_at_end(R,coef,deg);
	}
	
	while(Q != NULL || P != NULL){
		if(Q->next){
			deg = Q->degree;
			coef = Q->coefficient;
			Q = Q->next;
		}
		if(P->next){
			deg = P->degree;
			coef = P->coefficient;
			P = P->next;
		}
		
		add_at_end(R,coef,deg);

	}
	
}

/**
* @brief: adds a new term to a polynomial
* @param R: The polynomial for the terms to be added in.
* @param coef: the coefficient of the term.
* @param deg: the degree of the term..
*/
void add_at_end(struct Poly_Node **R,int coef,int deg){
	
	struct Poly_Node *last,*item;
	last = (*R);
	item = (struct Poly_Node*) malloc(sizeof(struct Poly_Node));
	
	item->coefficient = coef;
	item->degree = deg;
	item->next = NULL;
	
	if((*R)==NULL){
		(*R) = item;
		return;
	}
	
	while(last->next != NULL){
		last = last->next;
	}
	
	last->next = item;
	
	return;
}

 /**
 * @brief: Function to multiply two polynomials
 * @param R: Resulting polynomial of the addition(sum).
 * @param P and @param Q: polynomials to be added.
 */
void multiply_poly(struct Poly_Node **R,struct Poly_Node *P,struct Poly_Node *Q){
	struct Poly_Node *p1,*p2;
	int coef,deg;
	p1 = P;
	p2 = Q;
	(*R) = NULL;
	
	while(p1 != NULL){
		while(p2 != NULL){
      
			//Multiplying coefficients
			coef = p1->coefficient * p2->coefficient;
      
			//adding degrees
			deg = p1->degree + p2->degree;
			
			add_at_end(R,coef,deg);
			
			p2 = p2->next;
		}
		p2 = Q;
		p1 = p1->next;
	}
	
	//Sum coefficients with same power
	removeDuplicates((*R));
}

/**
 * @brief: Sums up terms in a polynomial of equal power
 * @param P polynomial for operation to be performed on
 */
void removeDuplicates(struct Poly_Node *P){
	struct Poly_Node *p1,*p2,*dup;
	
	p1 = P;
	
	while(p1 != NULL && p1->next != NULL){
		p2 = p1;
		
		while(p2->next != NULL){
			//if degree is the same
			if(p1->degree == p2->next->degree){
				//adding coefficients
				p1->coefficient = p1->coefficient + p2->next->coefficient;
				dup = p2->next;
				p2->next = p2->next->next;	
				
				//removing duplicate
				free(dup);
			}
			else{
				p2 = p2->next;
			}
		}
		p1 = p1->next;
	}
}

/**
 * @brief: Evaluates polynomial when x is a given value
 * @param x value to equate x to.
 * @param P polynomial to be evaluated.
 */
int eval_poly(struct Poly_Node *P, int x){
	int result = 0;
	
	while(P != NULL){
		int temp = P->coefficient * pow(x,P->degree);
		result+= temp;
		P = P->next;
	}
	
	return result;
}

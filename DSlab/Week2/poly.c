/*perform the adition of 2 polynomials stored as a sll
struct of the polynomial node:
struct poly {
int coeff;
int px;
int py;

struct node *next;
*/


 
#include<stdio.h>
#include<stdlib.h>
 
/*
 * The structure for the polynomial
 * This is a linked list with two variable
 * int coeff The Coefficient
 * int pow The power of x
 */
typedef struct link {
    int coeff;
    int px;
    int py;
    struct link * next;
} my_poly;
 
/** The prototypes */
void my_create_poly(my_poly **);
void my_show_poly(my_poly *);
void my_add_poly(my_poly **, my_poly *, my_poly *);
 
/**
 * The simple menu driven main function
 */
int main(void) {
    int ch;
    do {
        my_poly * poly1, * poly2, * poly3, *temp;
 
        printf("\nCreate 1st expression\n");
        my_create_poly(&poly1);
        printf("\nStored the 1st expression");
        my_show_poly(poly1);
 
        printf("\nCreate 2nd expression\n");
        my_create_poly(&poly2);
        printf("\nStored the 2nd expression");
        my_show_poly(poly2);
 
        my_add_poly(&poly3, poly1, poly2);
        my_show_poly(poly3);
		my_show_poly(temp);
 
        printf("\nAdd two more expressions? (Y = 1/N = 0): ");
        scanf("%d", &ch);
    } while (ch);
    return 0;
}
 
/**
 * The create polynomial function
 * @param my_poly ** node The pointer to the head of the polynomial
 * We will modify the parameter and will store the base address
 * @return void
 */
void my_create_poly(my_poly ** node) {
    int flag; //A flag to control the menu
    int coeff, px, py;
    my_poly * tmp_node; //To hold the temporary last address
    tmp_node = (my_poly *) malloc(sizeof(my_poly)); //create the first node
    *node = tmp_node; //Store the head address to the reference variable
    do {
			//Get the user data
			printf("\nEnter Coefficient:");
			scanf("%d", &coeff);
			tmp_node->coeff = coeff;
			printf("\nEnter power of x:");
			scanf("%d", &px);
			tmp_node->px = px;
			printf("\nEnter power of y:");
			scanf("%d", &py);
			tmp_node->py = py;
			//Done storing user data
	 
			//Now increase the Linked on user condition
			tmp_node->next = NULL;
	 
			//Ask user for continuation
			printf("\nContinue adding more terms to the polynomial list?(Yes = 1/No = 0): ");
			scanf("%d", &flag);
			//printf("\nFLAG: %c\n", flag);
			//Grow the linked list on condition
			if(flag) 
			{
				tmp_node->next = (my_poly *) malloc(sizeof(my_poly)); //Grow the list
				tmp_node = tmp_node->next;
				tmp_node->next = NULL;
			}
        } while (flag);
}
 
/**
 * The show polynomial function
 * Prints the Polynomial in user readable format
 * @param my_poly * node The polynomial linked list
 * @return void
 */
void my_show_poly(my_poly * node) {
    printf("\nThe polynomial expression is:\n");
    while(node != NULL) {
        printf("%dx^%dy^%d", node->coeff, node->px, node->py);
        node = node->next;
        if(node != NULL)
            printf(" + ");
    }
}
 
/*
 * The polynomial add function
 * Adds two polynomial to a given variable
 * @param my_poly ** result Stores the result
 * @param my_poly * poly1 The first polynomial expression
 * @param my_poly * poly2 The second polynomial expression
 * @return void
 */
void my_add_poly(my_poly ** result, my_poly * poly1, my_poly * poly2) 
{
    my_poly * tmp_node, *temp; //Temporary storage for the linked list
    tmp_node = (my_poly *) malloc(sizeof(my_poly));
    tmp_node->next = NULL;
    *result = tmp_node; //Copy the head address to the result linked list
 
    //Loop while both of the linked lists have value
    while(poly1 && poly2) {
        if ((poly1->px > poly2->px) && (poly1->py > poly2->py)) 
		{
            tmp_node->px = poly1->px;
            tmp_node->py = poly1->py;
            tmp_node->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if ((poly1->px < poly2->px) && (poly1->py < poly2->py)) 
		{
            tmp_node->px = poly2->px;
            tmp_node->py = poly2->py;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else if ((poly1->px == poly2->px)&& (poly1->py==poly2->py))
		{
            tmp_node->px = poly1->px;
            tmp_node->py = poly1->py;
            tmp_node->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if ((poly1->px < poly2->px) && (poly1->py > poly2->py)) 
		{
            tmp_node->px = poly1->px;
            tmp_node->py = poly1->py;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
		else if ((poly1->px > poly2->px) && (poly1->py < poly2->py)) 
		{
            tmp_node->px = poly2->px;
            tmp_node->py = poly2->py;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        //Grow the linked list on condition
        if(poly1 && poly2)
		{
            tmp_node->next = (my_poly *) malloc(sizeof(my_poly));
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    }
 
    //Loop while either of the linked lists has value
    while(poly1 || poly2) 
	{
        //We have to create the list at beginning
        //As the last while loop will not create any unnecessary node
        tmp_node->next = (my_poly *) malloc(sizeof(my_poly));
        tmp_node = tmp_node->next;
        tmp_node->next = NULL;
 
        if(poly1) 
		{
            tmp_node->px = poly1->px;
            tmp_node->py = poly1->py;
            tmp_node->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if(poly2) 
		{
            tmp_node->px = poly2->px;
            tmp_node->py = poly2->py;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
    }
 
    printf("\nPolynomial Addition Complete");
}
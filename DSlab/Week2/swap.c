#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
void swapNodes(struct Node** head_ref, int x, int y)
{	
	if (x == y)
		return;
	struct Node *prevX = NULL, *currX = *head_ref;
	while (currX && currX->data != x) {
		prevX = currX;
		currX = currX->next;
	}

	struct Node *prevY = NULL, *currY = *head_ref;
	while (currY && currY->data != y) {
		prevY = currY;
		currY = currY->next;
	}
	if (currX == NULL || currY == NULL)
		return;

	if (prevX != NULL)
		prevX->next = currY;
	else 
		*head_ref = currY;
	if (prevY != NULL)
		prevY->next = currX;
	else 
		*head_ref = currX;
	struct Node* temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node)
{
	while (node != NULL) 
	{
		printf("%d ", node->data);
		node = node->next;
	}
}
int main()
{
        int n,d;
	struct Node* start = NULL;
	printf("Enter number of nodes\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
        {
             scanf("%d",&d);   	
	     push(&start, d);
	}
	printf("Linked list before swapping:");
	printList(start);
	int x,y;
	printf("\nElements to swap\n");
	scanf("%d%d",&x,&y);
	swapNodes(&start, x, y);
	printf("Linked list after swapping:");
	printList(start);
	return 0;
}
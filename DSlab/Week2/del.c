#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
void deleteAlt(struct Node *head)
{
	if (head == NULL)
		return;
	struct Node *prev = head;
	struct Node *node = head->next;

	while (prev != NULL && node != NULL)
	{
		prev->next = node->next;
		free(node);
		prev = prev->next;
		if (prev != NULL)
			node = prev->next;
	}
}
void push(struct Node** head_ref, int new_data)
{
	
	struct Node* new_node =
		(struct Node*) malloc(sizeof(struct Node));

	
	new_node->data = new_data;

	
	new_node->next = (*head_ref);

	
	(*head_ref) = new_node;
}


void printList(struct Node *node)
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
	struct Node* head = NULL;
	printf("Enter number of nodes\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
        {
             scanf("%d",&d);   	
	     push(&head, d);
	}
	printf("List before deleting \n");
	printList(head);
	deleteAlt(head);
	printf("\nList after deleting\n");
	printList(head);
	return 0;
}
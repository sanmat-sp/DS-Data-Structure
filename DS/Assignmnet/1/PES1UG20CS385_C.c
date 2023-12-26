#include<stdio.h>
#include<stdlib.h>
#include "PES1UG20CS385_H.h"

int main()
{
  struct node* head=(struct node*)malloc(sizeof(struct node));
  head->data=0;
  head->down=head->right=NULL;
  readmatrix(&head);
  path(head);
  return 0;
}

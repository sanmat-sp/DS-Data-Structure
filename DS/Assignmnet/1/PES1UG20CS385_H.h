struct node
{
  struct node* right;
  struct node* down;
  int x, y, data;
};

void readmatrix(struct node**);
void path(struct node*);
void output(struct node**,int);

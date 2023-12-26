#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "PES1UG20CS385_H.h"




void output(struct node** res,int t);


void readmatrix(struct node** head)
{
  FILE* input_file=fopen("input.txt","r");
  if(!input_file)
  {
    printf("NO INPUT FILE");
    return;
  }
  char buff[1024];
  int row=0,col=0,row_x=-1;
  while(fgets(buff,1024,input_file))
  {
	col=0;
    row++;
    if(row==1 || row==2)
      continue;
    row_x++;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->down=temp->right=NULL;
    temp->data=row_x;
    struct node* curr=*head;
    while(curr->down!=NULL)
    {
      curr=curr->down;
    }
    curr->down=temp;
    curr=curr->down;
    char* dataue = strtok(buff," ");
    while(dataue && col<10)
    {
      struct node* curr_col=*head;
      if(row_x==0)
      {
        struct node* C_NODE=(struct node*)malloc(sizeof(struct node));
        C_NODE->right=C_NODE->down=NULL;
        C_NODE->data=col;
        while(curr_col->right!=NULL)
        {
          curr_col=curr_col->right;
        }
        curr_col->right=C_NODE;
        curr_col=C_NODE;
      }
      else
      {
        curr_col=curr_col->right;
        while(curr_col->data!=col)
        {
          curr_col=curr_col->right;
        }
      }
      struct node* temp= (struct node*)malloc(sizeof(struct node));
      temp->x=10;
      if(atoi(dataue)==0)
      {
        temp->x=row_x;
        temp->y=col;
        temp->data=atoi(dataue);
        temp->down=temp->right=NULL;
        curr->right=temp;
        curr=curr->right;
      }
      if(temp->x==row_x)
      {
        while(curr_col->down!=NULL)
        {
          curr_col=curr_col->down;
        }
        curr_col->down=temp;
      }
      dataue=strtok(NULL," ");
      col++;
    }
  }
  fclose(input_file);
}




void push(struct node* temp,struct node** stack,int* t)
{
  ++(*t);
  stack[*t]=temp;
}




struct node *pop(struct node **stack,int *t)
{
  struct node* temp;
  temp=stack[*t];
  --(*t);
  return temp;
}




void path(struct node* head)
{
  struct node* path=NULL;
  int start_x, start_y, end_x, end_y;

  
  FILE* input_file=fopen("input.txt","r");
  if(!input_file)
  {
    printf("Cannot open the file");
  }
  else
  {
    char buff[1024];
    int row=0;
    while(fgets(buff,1024,input_file))
    {
      char* dataue = strtok(buff," ");
      row++;
      if(row==1)
      {
        start_x=atoi(dataue);
        dataue=strtok(NULL," ");
        start_y=atoi(dataue);
      }
      else if(row==2)
      {
        end_x=atoi(dataue);
        dataue=strtok(NULL," ");
        end_y=atoi(dataue);
      }
      else
        break;
    }
  }
  fclose(input_file);
 
  struct node* target=NULL,*temp=NULL;
  struct node* row=head->down;
  struct node* col=head->right;

  while(row->data!=end_x)
    row=row->down;

  temp=row->right;

  while(temp->y!=end_y)
    temp=temp->right;

  target=temp;

  row=head->down;
  col=head->right;

  while(row->data!=start_x)
    row=row->down;

  temp=row->right;
 

  while(temp->y!=start_y)
    temp=temp->right;

  path=temp;
  int t=-1;
  int t1=-1;
  struct node* res[100];
  struct node* stack[100];
  struct node* curr=path;
  push(curr,res,&t1);
  while(curr!=target)
  {
    if(curr->right!=NULL && (curr->right->y==((curr->y)+1)))
    {
      if(curr->down!=NULL && curr->down->x==((curr->x)+1))
      {
        push(curr,stack,&t);
      }
      curr=curr->right;
      push(curr,res,&t1);
    }
    else if(curr->right==NULL)
    {
      if(curr->down!=NULL && curr->down->x==((curr->x)+1))
      {
        curr=curr->down;
        push(curr,res,&t1);
      }
      else
      {
        if(t>=0)
        {
          curr=pop(stack,&t);
          while((temp = pop(res,&t1))!=curr);
          push(curr,res,&t1);
          curr=curr->down;
          push(curr,res,&t1);
          
        }
        else
        {
          return;
        }
      }
    }
    else
    {
      if(curr->down!=NULL && curr->down->x==((curr->x)+1))
      {
        curr=curr->down;
        push(curr,res,&t1);
      }
      else
      {
        if(t>=0)
        {
          curr=pop(stack,&t);
          while((temp = pop(res,&t1))!=curr);
          push(curr,res,&t1);
          curr=curr->down;
          push(curr,res,&t1);
        }
        else
        {
          return;
        }
      }
    }
  }
  output(res,t1);
}





void output(struct node** res,int t)
{
  FILE* input_file=fopen("PES1UG20CS385.txt","w");
  if(!input_file)
  {
    printf("NO INPUT FILE");
    return;
  }
  int i=0;
  if(t==-1)
  {
    fprintf(input_file,"%d",-1);
  }
  else
  {
    while(i<=t)
    {
      fprintf(input_file,"%d %d\n",res[i]->x,res[i]->y);
      i++;
    }
  }
}

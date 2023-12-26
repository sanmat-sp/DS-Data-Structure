#include<stdio.h>
#include<stdlib.h>

void creat_graph();
void bfs(int v, int *n, int *f, int *r);
void qinsert(int v, int *f, int *r);
int qdelete(int *f, int *r);
int qempty(int *f);
int main()
{
	int v, n;
	int a[100][100];
	int visit[100];
	int q[100];
	int f, r;
	f=-1;
	r=-1;
	printf("Enter the number of vertices : ");
	scanf("%d", &n);
	creat_graph();
	printf("Enter source vertex : ");
	scanf("%d", &v);
	printf("Vertices reachable from source vertex using BFS are : ");
	bfs(v, &n, &f, &r);
}

void creat_graph()
{
	int a[100][100];
	int i, j;
	while(1)
	{
		printf("Enter source and destination vertices : ");
		scanf("%d%d", &i, &j);
		if(i==0 && j==0)
			break;
		a[i][j]=1;
	}
}

void bfs(int v, int *n, int *f, int *r)
{
	int w;
	int visit[100];
	int a[100][100];
	visit[v]=1;
	printf("%d", v);
	qinsert(v, f, r);
	while(!qempty(f))
	{
		v=qdelete(f, r);
		for(w=1;w<=*n;w++)
		{
			if(a[v][w]==1 && visit[w]==0)
			{
				visit[w]=1;
				printf("%d", w);
				qinsert(w, f, r);
			}
		}
	}
	
}

void qinsert(int v, int *f, int *r)
{
	int q[100];
	++(*r);
	q[*r]=v;
	if(*f==-1)
		*f=0;
}

int qdelete(int *f, int *r)
{
	int q[100];
	int w;
	w=q[*f];
	if(*f==*r)
		*f=*r=-1;
	else
		(*f)++;
	return w;
}

int qempty(int *f)
{
	if(*f==-1)
		return 1;
	return 0;
}






/*

struct node 
{
	int data;
	struct node *next;
};

void creat_graph();
void bfs(int v, int *n, int *f, int *r);
void insert(int i, int j);
void qinsert(int v, int *f, int *r);
int qdelete(int *f, int *r);
int qempty(int *f);
int main()
{
	struct node *a;
	int v, n;
	int visit[100];
	int q[100];
	int f, r;
	f=-1;
	r=-1;
	printf("Enter the number of vertices : ");
	scanf("%d", &n);
	creat_graph(&n);
	printf("Enter source vertex : ");
	scanf("%d", &v);
	printf("Vertices reachable grom source vertex using BFS is %d\n", v);
	bfs(v, &n, &f, &r);
}

void creat_graph(int *n)
{
	int a[100][100];
	int i, j;
	for(i=1;i<=*n;i++)
		a[i]=NULL;
	while(1)
	{
		printf("Enter source and destination vertices : ");
		scanf("%d%d", &i, &j);
		if(i==0 && j==0)
			break;
		a[i][j]=1;
	}
}

void bfs(int v, int *n, int *f, int *r)
{
	struct node *p; 
	int w;
	int a[100][100];
	int visit[100];
	visit[v]=1;
	printf("%d", v);
	qinsert(v, f, r);
	{
		while(!qempty(f))
		{
			v=qdelete(f, r);
			for(p=a[v];p!=NULL;p=p->next)
			{
				w=p->data;
				if(visit[w]==0)
				{
					visit[w]=1;
					printf("%d", w);
					qinsert(w, f, r);
				}
					
			}
		}
	}
}

void insert(int i, int j)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=j;
	temp->next=a[i];
	a[i]=temp;
}

void qinsert(int v, int *f, int *r)
{
	int q[100];
	(*r)++;
	q[*r]=v;
	if(*f==-1)
		*f=0;
}

int qdelete(int *f, int *r)
{
	int q[100];
	int w;
	w=q[*f];
	if(*f==*r)
		*f=*r=-1;
	else
		(*f)++;
	return w;
}

int qempty(int *f)
{
	if(*f==-1)
		return 1;
	return 0;
}
*/



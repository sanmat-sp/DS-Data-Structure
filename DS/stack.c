//conversion of infix expression to postfix expression
#include<stdio.h>
#include<stdlib.h>
void convert(char *infix, char *postfix);
int stkprec(char ch);
int ipprec(char ch);
void push(char *s, int *t, char x);
char pop(char *s, int *t);
char peak(char *s, int t);
int main()
{   
    while(1)
	{
		char infix[20], postfix[20];
		printf("Enter a valid infix expression\n");
		scanf("%s",infix);
		convert(infix, postfix);
		printf("After conversion..post expression is %s\n", postfix);
		return 0;
	}
}

void convert(char *infix, char *postfix)
{
	char ch, s[10];
	int top, i, j;
	top=1;
	i=0;
	push(s, &top, '#');
	j=0;
	for(i=0; infix[i]!='\0'; ++i)
	{
		ch=infix[i];
		while(stkprec(peak(s, top))>(ipprec(ch)))
		{
			postfix[j++]=pop(s, &top);
		}
		if(stkprec(peak(s, top))<(ipprec(ch)))
		{
			push(s, &top, ch);
		}
		else
		{
			pop(s, &top);
		}
	}
	while(peak(s, top)!='#')
	{
			postfix[j++]=pop(s, &top);
	}
	postfix[j++]='\0';
}

int stkprec(char ch)
{
	switch(ch)
	{
		case '+' :
		case '-' : return 2;
		case '*' : 
		case '/' : return 4;
		case '$' : return 5;
		case '(' : return 6;
		case '#' : return -1;
		default : return 8;
	}
}

int ipprec(char ch)
{
	switch(ch)
	{
		case '+' :
		case '-' : return 1;
		case '*' : 
		case '/' : return 3;
		case '$' : return 6;
		case '(' : return 9;
		case ')' : return 0;
		default : return 7;
	}
}

void push(char *s, int *t, char x)
{
	++*t;
	s[*t]=x;
}

char pop(char *s, int *t)
{
	char x;
	x=s[*t];
	s[*t]=0;
	--*t;
	return x;
}

char peak(char *s, int t)
{
	return s[t];
}




/*








//evaluation of postfix expression
int eval(char *eval);
void push(int *s, int *t, int x);
int pop(int *s, int *t);
int isoper(char ch);
int isempty(int t);
int main()
{
	while(1)
	{
		char postfix[20];
		int t;
		int result=eval(postfix);
		printf("After evaluation, result is %d\n", result);
	}
}

int eval(char *eval)
{
	int s[10];
	char postfix[20];
	printf("Enter the postfix expression\n");
	scanf("%s", postfix);
	int top, r, a, i=0;
	top=-1;
	while(postfix[i]!='\0')
	{
		char ch=postfix[i];
		if(isoper(ch))
		{
			int op2=pop(s, &top);
			int op1=pop(s, &top);
			switch(ch)
			{
				case '+' : r=op1+op2;
				           push(s, &top, r);
						   break;
				case '-' : r=op1-op2;
				           push(s, &top, r);
						   break;
				case '*' : r=op1*op2;
				           push(s, &top, r);
						   break;
				case '/' : r=op1/op2;
				           push(s, &top, r);
						   break;
				case '^' : r=(op1)^(op2);
				           push(s, &top, r);
						   break;			
			}
			i++;
		}
		else
		{
			printf("%c= ", ch);
			scanf("%d", &a);
			push(s, &top, a);
			i++;
		}
	}
	return pop(s, &top);
}

void push(int *s, int *t, int x)
{
	++*t;
	s[*t]=x;
}

int pop(int *s, int *t)
{
	int a;
	int x=s[*t];
	--*t;
	return x;
}

int isoper(char ch)
{
	switch(ch)
	{
		case '+' :
		case '-' :
		case '*' :
		case '/' :
		case '^' : return 1;
		default : return 0;
	}
}














//parantheses match

int match(char *expr);
int isempty(int t);
void push(char *s, int *t, char x);
char pop(char *s, int *t);
int main()
{
	char expr[20];
	printf("Enter the expression\n");
	scanf("%s", expr);
	int k=match(expr);
	if(k)
	{
		printf("Matching..\n");
	}
	else
	{
		printf("Not matching..\n");
	}
	return 0;
}

int match(char *expr)
{
	char s[10], ch, x;
	int top, i;
	top=-1;
	i=0;
	while(expr[i])
	{
		ch=expr[i];
		switch(ch)
		{
			case '(' :
			case '{' :
			case '[' : push(s, &top, ch);
				break;
			case ')' :if(!isempty(top))
			          {
						  x=pop(s, &top);
						  if(x=='(')
							  break;
						  else
						  {
							  return 0;
						  }
					  }
					  else
					  {
						  return 0;
					  }
		    case '}' :if(!isempty(top))
			          {
						  x=pop(s, &top);
						  if(x=='{')
							 break;
						  else
						  {
							  return 0;
						  }
					  }
					  else
					  {
						  return 0;
					  }
			case ']' :if(!isempty(top))
			          {
						  x=pop(s, &top);
						  if(x=='[')
							 break;
						  else
						  {
							  return 0;
						  }
					  }
					  else
					  {
						  return 0;
					  }
		}
		i++;
	}
}

int isempty(int t)
{
	if(t==-1)
		return 1;
	else
		return 0;
}

void push(char *s, int *t, char x)
{
	++*t;
	s[*t]=x;
}

char pop(char *s, int *t)
{
	char x;
	x=s[*t];
	*t--;
	return x;
}
*/


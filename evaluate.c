 // evaluate
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

double op(char symbol, double op1, double op2)
{
	switch(symbol)
	{
		case '+':
			return op1 + op2;

		case '-':
			return op1 - op2;

		case '*':
			return op1 * op2;

		case '/':
			return op1 / op2;

		
		case '^':
			return pow(op1,op2);
	}
}
int top =-1;
double s[20];
void push(double item)
{
	
	s[++top] = item;
}

double pop()
{
	double item_deleted;

	item_deleted = s[top--];
	

	return item_deleted;
}

int isDigit(char symbol)
{
	return (symbol >= '0' && symbol <= '9');
}


void main()
{
	double  res, op1, op2;
	int i;
	char postfix[20], symbol;

	printf("Enter a valid postfix expression\n");
	scanf("%s",postfix);

	top = -1;

	for(i = 0; i < strlen(postfix); i++)
	{
		symbol = postfix[i];

		if(isDigit(symbol))
			push(symbol -'0');
		else
		{
			op2 = pop();
			op1 = pop();

			res = op(symbol, op1, op2);

			push(res);
		}
	}

	res = pop();

	printf("The result of evaluated postfix expression is:\t%lf\n", res);
}

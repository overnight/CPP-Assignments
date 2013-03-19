#include <stdio.h>
#include <stdlib.h>
#define PLUS 43
#define MINUS 45
#define MULTIPLY 42
#define DIVIDE 47
#define true 1
#define false 0
typedef struct Node_
{
	int val;
	struct Node_ * next;
} Node;
typedef struct Pfix_
{
	int isOperand;
	int val;
} PfixNode;
Node* push(Node* list,int val)
{
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->val=val;
	if(list==NULL)
	{
		temp->next=NULL;
		list=temp;
		return list;
	}
	temp->next=list;
	list = temp;
	return list;
}
Node *pop(Node * list)
{
	if(list==NULL) return NULL;
	list=list->next;
	return list;
}
int  isEmpty(Node * list)
{
	if(list==NULL) return true;
	return false;
}
int isDigit(char a)
{
	if(a>47&&a<58) return true;
	return false;
}
int infixtopostfix(char* infix, PfixNode *  pfix)
{
	Node* list=NULL;
	int j=0,i;
	for(i=0; infix[i]!='\0'; i++)
	{
		int currnum=0;
		char currchar;
		currchar=infix[i];
		if(isDigit(currchar))
		{
			while(isDigit(currchar))
			{
				currnum = currnum*10 + (currchar-48);
				i++;
				currchar=infix[i];
			}
			pfix[j].isOperand=true;
			pfix[j].val=currnum;
			j++;
			i--;
		}
		else
		{
			if(currchar==MINUS)
			{
				while(list)
				{
					pfix[j].isOperand=false;
					pfix[j].val=list->val;
					j++;
					list =pop(list);
				}
				list =push(list,currchar);
			}
			else if(currchar==PLUS)
			{
				while(list)
				{
					pfix[j].isOperand=false;
					pfix[j].val=list->val;
					j++;
					list =pop(list);
				}
				list =push(list,currchar);
			}
			else if(currchar==MULTIPLY)
			{
				while(list&&(list->val==DIVIDE||list->val==MULTIPLY))
				{
					pfix[j].isOperand=false;
					pfix[j].val=list->val;
					j++;
					list =pop(list);
				}
				list =push(list,currchar);
			}
			else if(currchar==DIVIDE)
			{
				while(list&&(list->val==DIVIDE))
				{
					pfix[j].isOperand=false;
					pfix[j].val=list->val;
					j++;
					list =	pop(list);
				}
				list =push(list,currchar);
			}
			else
			{
				printf("invalid character %c\n",currchar);
				return -1;
			}
		}
		
	}
	while(list)
	{
		pfix[j].isOperand=false;
		pfix[j].val=list->val;
		j++;
		list =pop(list);
	}
	return j;
}
int evaluatepostfix(PfixNode *  pfix,int length)
{
	Node*list=NULL;
	int i;
	for(i=0; i<length; i++)
	{
		if(pfix[i].isOperand)
		{
			list=push(list,pfix[i].val);
		}
		else
		{
			if(isEmpty(list))
			{
				printf("Invalid expression, more operator than operand\n");
				return false;
			}
			int num1= list->val;
			list = pop(list);
			if(isEmpty(list))
			{
				printf("Invalid expression, more operator than operand\n");
				return false;
			}
			int num2 = list->val;
			list = pop(list);
			int ans;
			switch(pfix[i].val)
			{
				case PLUS:
					ans = num1+num2;
					break;
				case MINUS:
					ans = num2-num1;
					break;
				case MULTIPLY:
					ans = num1*num2;
					break;
				case DIVIDE:
					if(num1==0)
					{
						printf("Cannot divide by 0\n");
						return false;
					}
					ans = num2/num1;
					break;
					
			}
			list = push(list,ans);
		}
	}
	int ans=list->val;
	list = pop(list);
	if(isEmpty(list))
	{
		printf("Ans: %d",ans);
		return true;
	}
	printf("Invalid expression, more operand than operator\n");
	return false;
}
int main(int argc, char **argv)
{
	char input[100];
	PfixNode *pfix =(PfixNode *)malloc(sizeof(PfixNode)*100);
	scanf("%s",input);
	int x =infixtopostfix(input,pfix);
	//printf("%d\n",x);
	if(x>0)
	{
		int i;
		for(i=0; i<x; i++)
		{
			if(pfix[i].isOperand)
				printf("%d ",pfix[i].val);
			else
				printf("%c ",pfix[i].val);
		}
		printf("\n");
		evaluatepostfix(pfix,x);
	}
	
	return 0;
}

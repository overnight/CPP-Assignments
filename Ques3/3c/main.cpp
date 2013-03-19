#include <stdio.h>
#include <iostream>
using namespace std;
const int PLUS= 43;
const int MINUS =45;
const int MULTIPLY= 42;
const int DIVIDE =47;
template <class T>
struct Node_
{
	T val;
	struct Node_ * next;
};
typedef struct Pfix_
{
	int isOperand;
	int val;
} PfixNode;
template <class T>
class stack
{
	public:
		stack()
		{
			element=NULL;
		}
		void push(T x)
		{
			struct Node_<T> * temp = new struct Node_<T>();
			temp->val=x;
			temp->next=element;
			element=temp;
		}
		void pop()
		{
			if(!empty())
			{
				struct Node_<T> * temp ;
				temp = element;
				element = element->next;
				delete temp;
			}
		}
		T top()
		{
			return element->val;
		}
		bool empty()
		{
			if(element==NULL) return true;
			return false;
		}
		
	private:
		struct Node_<T> * element;
};
bool isDigit(char a)
{
	if(a>47&&a<58) return true;
	return false;
}
int infixtopostfix(char* infix, PfixNode *  pfix)
{
	stack<int> list;
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
				while(!list.empty())
				{
					pfix[j].isOperand=false;
					pfix[j].val=list.top();
					j++;
					list.pop();
				}
				list.push(currchar);
			}
			else if(currchar==PLUS)
			{
				while(!list.empty())
				{
					pfix[j].isOperand=false;
					pfix[j].val=list.top();
					j++;
					list.pop();
				}
				list.push(currchar);
			}
			else if(currchar==MULTIPLY)
			{
				while((!list.empty())&&(list.top()==DIVIDE||list.top()==MULTIPLY))
				{
					pfix[j].isOperand=false;
					pfix[j].val=list.top();
					j++;
					list.pop();
				}
				list.push(currchar);
			}
			else if(currchar==DIVIDE)
			{
				while((!list.empty())&&(list.top()==DIVIDE))
				{
					pfix[j].isOperand=false;
					pfix[j].val=list.top();
					j++;
					list.pop();
				}
				list.push(currchar);
			}
			else
			{
				printf("invalid character %c\n",currchar);
				return -1;
			}
		}
		
	}
	while(!list.empty())
	{
		pfix[j].isOperand=false;
		pfix[j].val=list.top();
		j++;
		list.pop();
	}
	return j;
}
bool evaluatepostfix(PfixNode *  pfix,int length)
{
	stack<int> list;
	int i;
	for(i=0; i<length; i++)
	{
		if(pfix[i].isOperand)
		{
			list.push(pfix[i].val);
		}
		else
		{
			if(list.empty())
			{
				throw 1;
			}
			int num1= list.top();
			list.pop();
			if(list.empty())
			{
				throw 1;
			}
			int num2 = list.top();
			list.pop();
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
						throw 2;
					}
					ans = num2/num1;
					break;
					
			}
			list.push(ans);
		}
	}
	int ans=list.top();
	list.pop();
	if(list.empty())
	{
		printf("Ans: %d",ans);
		return true;
	}
	throw 1;
}
int main(int argc, char **argv)
{
	char input[100];
	PfixNode *pfix =new PfixNode[100];
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
		try
		{
			evaluatepostfix(pfix,x);
			
		}
		catch(int e)
		{
			if(e==1)
			{
				cout<<"Not enough operator/operand"<<endl;
			}
			if(e==2)
			{
				cout<<"Cannot divide by 0"<<endl;
			}
		}
	}
	
	return 0;
}

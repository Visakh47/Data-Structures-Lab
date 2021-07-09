//program to convert infix to postfix and postfix eval
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int i,top=-1,ptop=0;
char postf[50],stack[50];


void pushpost(char ch) { //fn to push to postfix output 
	postf[ptop++] = ch;
}

void push(char ch) {
	top++;
	stack[top] = ch;
}

int priority(char ch) {
	if(ch=='(')
		return 0;
	if(ch=='+'|| ch=='-')
		return 1;
	if(ch=='/'|| ch =='*')
		return 2;
	if(ch=='^')
		return 3;
}

//function to pop from stack
char pop() {
	if(top==-1)
		return -1;
	else 
		return stack[top--]; //top value is reduced
}

void posteval() {
	top =-1; //clearing old stack
	int val=0,x,y;
	char c;
	for(i=0;i<ptop;i++) {
		c = postf[i];
		if(isdigit(c))
			push(c-'0');
		else if(c=='+'|| c=='-'||c=='/' || c=='*'||c=='^')
		{	x = pop();
			y = pop();
			switch(c)
			{
				case '+' : 	val=x+y;
							break;
				case '-' : 	val=y-x;
							break;
				case '/' :  val=y/x;
							break;
				case '*' : 	val = y*x;
							break;
				case '^' :  val = pow(y,x);
							break;
			}
			push(val);
		}
	}
	printf("Evaluation of expression is: %d\n",val);
}

void main() {
	
	int len;
	char expr[100],c,a; //c is for character or symbol scanning and a is for storing popped elements
	printf("Enter infix expression\n");
	gets(expr);
	len = strlen(expr);
	for(i=0;i<len;i++) {
		c= expr[i];
		if(isalnum(c))
			pushpost(c); //push to prefix output if it is alnum
		else {
			if(c=='(')
				push(c);
			else {
				if(c==')')
				{
					a=pop(); //pop the element 
					while(a!='(') {
						pushpost(a); //pop the element and push to postfix
						a = pop();
					}
				}
				else { //operator now
					while(priority(stack[top]) >= priority(c)){
						a = pop();
						pushpost(a);
					}
					push(c); //push the element as long as the element inside stack is not having higher precednece than on coming element 
				}
			}
		}
	}
	
	//push all the remaining element in stack to postfix output 
	while(top!=-1)
	{
		a = pop();
		pushpost(a);
	}
	printf("The PostFix Expression Is :\n");
	for(i=0;i<ptop;i++)
		printf("%c ",postf[i]);
		
	posteval();
	
}
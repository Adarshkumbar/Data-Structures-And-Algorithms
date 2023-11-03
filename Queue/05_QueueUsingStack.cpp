#include<iostream>
#include<cstdlib>
using namespace std;

#define N 5
int stack1[N];
int stack2[N];
int top1=-1,top2=-1,count=0;

void push1(int x);
void push2(int x);
int pop1();
int pop2();
void enqueue(int x)
{
	push1(x);
	if(top1!=-1)	count++;
}
void push1(int x)
{
	if(top1==N-1)
	{
		cout<<"\n!! Stack 1 is Full !!!";
	}
	else
	{
		top1++;
		stack1[top1]=x;
	}
}
void dequeue()
{
	if(top1==-1 && top2==-1)
	{
		cout<<"\n!!Queue is EMpty!!";
	}
	else
	{

		int a,b,i;
		for(i=0;i<count;i++)
		{
			a=pop1();
			push2(a);
		}
		count--;
		cout<<"\nDequed emt is:"<<pop2();
		for(i=0;i<count;i++)
		{
			a=pop2();
			push1(a);
		}
	}
}
int pop1()
{
		return stack1[top1--];
}
void push2(int x)
{
	if(top2==N-1)
	{
		cout<<"\n!!! Stack 2 is Full !!!";
	}
	else
	{
		top2++;
		stack2[top2]=x;
	}
}
int pop2()
{	
		return stack2[top2--];
}
void show()
{
	int i;
	if(top1==-1)
		cout<<"The Queue is Empty";
	else
	{
		cout<<"The Queue Emts Are:";
		for(i=0;i<=top1;i++)
		{
			cout<<stack1[i]<<" ";
		}
	}
}
int main()
{
	int ch;

 	do
 	{
 		cout<<"\n1.Enqueue\t2.Dequeue\t3.Display\t4.Exit:";
 		cin>>ch;
 		int val;
 		switch(ch)
 		{
 			case 1:cout<<"\nEnter val to Enqueue:";
 					cin>>val;
			 		enqueue(val);
 					break;
 			case 2:dequeue();
 					break;
 			case 3:show();
 					break;
 			case 4:cout<<"\nExiting ......";
			 		exit (0);
			default:cout<<"\nInvalid Entry";	
		 }	
	}while(ch!=4);
}



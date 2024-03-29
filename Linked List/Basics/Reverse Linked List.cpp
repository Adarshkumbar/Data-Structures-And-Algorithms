// Reverse linked list

#include <iostream>
using namespace std;
#include<cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */// 0xd21a00    0x791a00
struct node
{
	int data;
	struct node *next;
};
struct xy
{
	int count=0;
	struct node *head=0;
}x;
struct node *newnode;
void NewNODE()							//This Function helps to allocate dynamical mem allocation i.e newnode
{
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->next=0;
	printf("Enter data:");
	scanf("%d",&newnode->data);
		
}
void CreateLIST()
{
	int ch=1;
	struct node* temp;
	while(ch)
	{
		NewNODE();
		if(x.head==NULL)
		{
			temp=x.head=newnode;
			x.count++;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
			x.count++;
		}
		printf("1.Add\n0.Stop\n:");
		scanf("%d",&ch);		
	}
}
void Reverse()
{
	struct node *prevnode,*currnode,*nextnode;
	prevnode=NULL;
	currnode=nextnode=x.head;
	while(nextnode!=NULL)
	{
		nextnode=nextnode->next;
		currnode->next=prevnode;
		prevnode=currnode;
		currnode=nextnode;
	}
	x.head=prevnode;
}
void Display()
{
	
	printf("The elements Are: ");
	struct node *temp=x.head;
	while(temp!=0)
	{
		cout<<"\t"<<temp->data;
		temp=temp->next;
	}
	cout<<"\nNo of emts: "<<x.count<<"\t";
	//cout<<"\nHead="<<x.head;
	cout<<" Val at head:"<<x.head->data<<endl;
}
int main(int argc, char** argv) 
{
	CreateLIST();
	Display();
	Reverse();
	Display();

}

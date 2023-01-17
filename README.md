
// singly linked-list
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
void Insertion()
{
	int ch,k;
	struct node *temp=x.head;
	printf("-----Select Where to Insert New data----\n1.Beginning\t2.End\t3.Position:\n");
	scanf("%d",&ch);
	if(ch<1 || ch>3)
	{
		cout<<"!!invalid entry!!\n";
	}
	else
	if(ch==1)
	{
	NewNODE();
	newnode->next=x.head;
	x.head=newnode;
	x.count++;
	}
	if(ch==2)
	{
		NewNODE();
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		x.count++;
	}	
	if(ch==3)
	{
		int posi,i=1;
		printf("Enter the Posi:");
		scanf("%d",&posi);
		if(posi<1 ||posi>x.count)
		{
			printf("invalid Entry");
		}
		else
		{
			while(i<posi)
			{
				temp=temp->next;
				i++;
			}
			NewNODE();
			newnode->next=temp->next;
			temp->next=newnode;
			x.count++;
		}
	}
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
void Deletion()
{
	int ch;
	struct node *p,*q;
	printf("-----Select DELETE data----\n1.Beginning\t2.End\t3.Position:\n");
	scanf("%d",&ch);
	if(x.head==NULL)
		printf("List if Empty");
	else
	{
		if(ch<1 || ch>3)
		{
			cout<<"!!invalid entry!!\n";
		}
		else
		if(ch==1)
		{
			p=x.head;
			x.head=x.head->next;
			free(p);
			x.count--;
		}
		if(ch==2)
		{
			p=x.head;
			while(p->next!=NULL)
			{
				q=p;
				p=p->next;
			}
			q->next=NULL;
			free(p);
			x.count--;
		}
	}
}	
int main(int argc, char** argv) 
{
	CreateLIST();
	Display();
	printf("size of Head=%d",sizeof(x.head));
//	Insertion();
//	Insertion();
//	Display();
//	Deletion();
//	Deletion();
//	Display();
}

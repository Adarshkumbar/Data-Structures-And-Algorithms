
//  CIRCULAR CAN BE CREATED WITH
//  A)ONLY HEAD B)ONLY TAIL C)BOTH HEAD AND TAIL

#include<iostream>
#include<cstdlib>


using namespace std;

struct node
{
	int data;
	struct node *next;
}*head=0,*tail=0;    //         ptrs of STRUCT NODE TYPE 

struct node *newnode;

void NewN()
{
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter Data:");
	scanf("%d",&newnode->data);
	newnode->next=0;
}
//void CreateCLL()				//Create Circular Linked List   --------USING HEAD AND TAIL-----------
//{
//	NewN();
//	if(head==0)
//	{
//		head=tail=newnode;
//		newnode->next=head;
//	}
//	else
//	{
//		tail->next=newnode;
//		tail=newnode;
//		tail->next=head;
//	}
//}
void CreateCLL()				//Create Circular Linked List   --------USING ONLY TAIL-----------
{
	int ch=1;
	while(ch)
	{
		NewN();
		if(tail==0)
		{
			tail=newnode;
			tail->next=newnode;
		}
		else
		{
			newnode->next=tail->next;
			tail->next=newnode;
			tail=newnode;
		}
		printf("Add more?\tY:N(1:0)");
		scanf("%d",&ch);
	}
}
//void Display()               // DISPLAY for Circular Linked List   --------USING HEAD AND TAIL-----------
//{
//	struct node *temp;
//	cout<<"\nThe list is:\n";
//	temp=head;
//	while(temp->next!=tail->next)
//	{
//		printf(" %d\t",temp->data);
//		temp=temp->next;
//	}
//	printf("%d\t",temp->data);
//}
int countr()
{
	int c=0;
	struct node *temp;
	temp=tail->next;
	while(temp->next!=tail->next)
	{
		c++;
		temp=temp->next;
	}
	c++;
	return c;
}
void Insert()
{
	int ch,i,pos,l=countr();
	i=1;
	printf("1.At Beg 2.At End 3.At posi 4.Exit :");
	scanf("%d",&ch);
	if(ch==1)
	{
		NewN();
		newnode->next=tail->next;
		tail->next=newnode;
	}
	if(ch==2)
	{x:
		NewN();	
		newnode->next=tail->next;
		tail->next=newnode;
		tail=newnode;
	}
	if(ch==3)
	{
		printf("Enter posi:");
		scanf("%d",&pos);
		if(pos<1 || pos>l+1)
			printf("Invalid");
		else if(pos==l+1)
			goto x;
		else
		{
			NewN();
			struct node* temp;
			temp=tail->next;
			while(i<pos-1)
			{
				temp=temp->next;
				i++;
			}
			newnode->next=temp->next;
			temp->next=newnode;
		}
	}
}
void Display()					// DISPLAY for Circular Linked List   --------USING ONLY TAIL-----------
{
	struct node *temp;
	cout<<"\nThe list is:\n";
	temp=tail->next;
	
	do
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}while(temp!=tail->next);
}
void Delete()
{
	int l=countr(),pos,ch,i=1;
	struct node* temp,*q;
	temp=tail->next;						//TEMP POINTING TO BEGINNING OF LIST
	printf("1.Del At Beg\t2.Del At End\t3.Del At Pos:\n");
	scanf("%d",&ch);
	if(tail==0)
	{
		printf("list is Empty");
	}
	else
	{
		if(ch==1)
		{
			tail->next=temp->next;
			free(temp);
		}
		if(ch==2)
		{
			while(temp->next!=tail)
			{
				temp=temp->next;
			}	
			temp->next=tail->next;
			free(tail);
			tail=temp;
		}
		if(ch==3)
		{
			printf("Enter Pos:");
			scanf("%d",&pos);
			if(pos<1 || pos>l)
				printf("Invalid");
			else
			{
				while(i<pos-1)
				{
					temp=temp->next;
					i++;
				}
				q=temp->next;
				temp->next=q->next;
				free(q);
			}
		}
	}
	
}
int main()
{
	CreateCLL();
	Display();
//	Insert();
//	Insert();
//	Display();
	Delete();
	Delete();
	Display();
   cout<<"\nSIZE Is ="<<countr()<<endl;
   //cout<<"\nAT end AND Beg ="<<tail->data<<" "<<tail->next->data;
}

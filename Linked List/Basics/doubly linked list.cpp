// Doubly linked list in c/c++ 

//just change header files of c to run

#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *head=0,*newnode;
int count();
void NewN()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter Data:");
	scanf("%d",&newnode->data);	
	newnode->left=newnode->right=NULL;
}
void CreateDLL()
{
	int ch=1;
	struct node *temp;
	while(ch)
	{
		NewN();
		if(head==0)
		{
			head=temp=newnode;
		}
		else
		{
			temp->right=newnode;
			newnode->left=temp;
			temp=newnode;
		}
		printf("1:Add\t2.Stop :");
		scanf("%d",&ch);
	}
}
void Insert()
{
	struct node *temp;
	int ch,pos,i=1;
	cout<<"1.At Beg\t2.At End\t3.At Posi:";
	scanf("%d",&ch);
	if(ch==1)
	{
		NewN();
		newnode->right=head;
		head->left=newnode;
		head=newnode;
	}
	if(ch==2)
	{
		NewN();
		temp=head;
		while(temp->right!=NULL)
		{
			temp=temp->right;
		}
		newnode->left=temp;
		temp->right=newnode;
		temp=newnode;
	}
	if(ch==3)
	{
		i=1;
		int l=count();
		printf("\nEnter Posi:");
		scanf("%d",&pos);
		if(pos<1 || pos>l)
			printf("!!!Invalid Posi!!!");
		else
		{
			NewN();
			temp=head;
			while(i<pos-1)
			{
				temp=temp->right;
				i++;
			}
			newnode->left=temp;
			newnode->right=temp->right;
			temp->right->left=newnode;
			temp->right=newnode;
		}
	}
}
void Delete()
{
	struct node *temp;
	temp=head;
	int ch,pos,i=1,X;
	cout<<"1.At Beg\t2.At End\t3.At Posi:";
	scanf("%d",&ch);
	if(count()==0)
		printf("No list ");
	else if(count()==1)
	{
		temp=head;
		free(temp);
		head=0;
	}
	else
	{
		if(ch==1)
		{	
			temp=head;
			head=head->right;
			head->left=0;
			free(temp);
		}	
		if(ch==2)
		{
			temp=head;
			while(temp->right!=NULL)
			{
				temp=temp->right;
			}
			temp->left->right=0;
			free(temp);

		}
		if(ch==3)
		{
			int l=count();
			printf("Enter Pos:");
			scanf("%d",&pos);
			
			if(pos<1 || pos>count())
				printf("Invalid");
			else if(pos==l)
			{
				temp=head;
				while(temp->right!=NULL)
				{
					temp=temp->right;
				}
				temp->left->right=0;
				free(temp);	
			}
				
			else if (pos==1)
			{
				head=0;
				free(temp);
			}
			else
			{
				i=1;
				while(i<pos)
				{
					temp=temp->right;
					i++;
				}
				temp->left->right=temp->right;
				temp->right->left=temp->left;	
				free(temp);
			}
		}
	}
}
void Display()
{
	struct node *temp;
	temp=head;
	if(head==0)
	{
		printf("Empty\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->right;
		}
	}
}
int count()
{
	int c=0;
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		temp=temp->right;
		c++;
	}
	return c;
}
int main()
{
	CreateDLL();
	Display();	
//	Insert();
//	Insert();
//	Display();
	Delete();
	Delete();
	Display();
	printf("Length=%d",count());
}

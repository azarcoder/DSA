#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
void insertbegin();
void insertend();
void insertpos();
void delbegin();
void delend();
void delpos();
void display();
void updatepos();
typedef struct node nd;
nd *head=NULL;
int main()
{
	int ch;
	while(1)
	{
	printf("\n---List functions---\n1.Insert at begining\n2.Disply\n3.Insert at end\n4.Insert at position\n\
5.Delete at begining\n6.Delete at end\n7.Delete at position\n8.Update at position\n9.Exit\n--------------------");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		int p;
		case 1:
			insertbegin();
			break;
		case 2:
			printf("\nElement inside list: ");
			display(head);
			break;
		case 3:
			insertend();
			break;
		case 4:
			printf("\nEnter the position:\n");
			scanf("%d",&p);
			if(p==1)
				insertbegin();
			else
				insertpos(p);
			break;
		case 5:
			delbegin();
			break;
		case 6:
			delend();
			break;
		case 7:
			printf("\nEnter the position:\n");
			scanf("%d",&p);
			if(p==1) 
				delbegin();
			else
				delpos(p);
			break;
		case 8:
			printf("\nEnter the position:\n");
			scanf("%d",&p);
			updatepos(p);
			break;
		case 9:
			exit(0);
			break;
		default:
			printf("INVALID CHOICE :(");
	}
	}
	return 0;
}
void insertbegin()
{
	nd *temp = (nd*) malloc(sizeof(nd));
	printf("Enter element you want to insert:");
	scanf("%d",&temp->data);
	if(head==NULL)
	{
		temp->next=NULL;
		head = temp;
	}
	else
	{
		temp->next = head;
		head=temp;
	}
	printf("%d value inserted!\n",temp->data);
}
void display(nd *p)
{
	if(p==NULL) printf("list is empty!\n");
	while(p)
	{
		printf("%d,",p->data);
		p=p->next;
	}
}
void insertend()
{
	nd *newnode;
	newnode = (nd*)malloc(sizeof(nd));
	printf("Enter element you want to insert:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	else
	{
		nd *temp = head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
	printf("\n%d inserted sucessfully!\n",newnode->data);
}
void insertpos(int p)
{
	int c=1,i;
	nd *temp=head;
	nd *newnode=(nd*)malloc(sizeof(nd));
	if(head==NULL) 
		printf("List empty!\n");
	else
	{
		while(temp->next!=NULL)
		{
			c++;
			temp=temp->next;
		}
		if(p>c) printf("Position out of range!");
		else
		{
			temp=head;
			printf("Enter a element you want to insert at position %d : ",p);
			scanf("%d",&newnode->data);
			for(i=1;i<p-1;i++)
			{
				temp=temp->next;
			}
			newnode->next=temp->next;
			temp->next=newnode;
			printf("%d inserted!\n",newnode->data);
		}
	}		
}
void delbegin()
{
	nd *temp;
	if(head==NULL) 
		printf("List empty!\n");
	else
	{
		temp=head;
		head=temp->next;
		free(temp);
		printf("First element deleted!\n");
	}
}
void delend()
{
	nd *temp,*prev;
	if(head==NULL)
	{
		printf("List empty!\n");
		return;
	}
	else if(head->next==NULL)
	{
		temp=head;
		head=temp->next;//assign head address as null
		printf("last element deleted!\n");
		free(temp);
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;
		printf("last element deleted!\n");
		free(temp);	
	}
}
void delpos(int p)
{
	nd *temp=head,*prev;
	if(head==NULL)
	{
		printf("List empty!\n");
		return;
	}
	else
	{	
		temp=head;
		for(int i=1;i<p;i++)
		{
			prev=temp;
			temp=temp->next;
			if(temp==NULL)
			{
				printf("Invalid position!\n");
				return;
			}
		}
		prev->next=temp->next;
		printf("%d deleted successfully!\n",temp->data);
	}
}
void updatepos(int p)
{
	if(head==NULL)
	{
		printf("list empty!\n");
	}
	else
	{
		nd *temp=head;
		for(int i=1;i<p;i++)
			temp=temp->next;
		printf("Enter new data:");
		scanf("%d",&temp->data);
		printf("Updated successfully!\n");
	}
}

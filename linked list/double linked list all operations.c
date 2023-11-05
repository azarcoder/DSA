#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL,*tail=NULL;

void insertbegin();
void insertend();
void insertpos();
void delbegin();
void delend();
void delpos();
void display();
void updatepos();

int main()
{
	int ch;
	while(1)
	{
	printf("\n---List functions---\n1.Insert at begining\n2.Display\n3.Insert at end\n4.Insert at position\n\
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
			display();
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
	struct node *newnode = (struct node*) malloc (sizeof(struct node));
	if(head==NULL && tail==NULL)
	{	
		printf("Enter element:");
		scanf("%d",&newnode->data);
		head=newnode;
		tail=newnode;
		head->next=NULL;
		head->prev=NULL;
		puts("process done!");
	}
	else
	{
		printf("Enter element:");
		scanf("%d",&newnode->data);
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
		head->prev=NULL;
		puts("process done!");
	}
}
void display()
{
	int c;
	struct node *temp;
	printf("\n1.head to tail\n2.tail to head\n");
	puts("choice:");
	scanf("%d",&c);
	if(c==1)
	{
		temp=head;
		while(temp)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
	else if(c==2)
	{
		temp=tail;
		while(temp)
		{
			printf("%d ",temp->data);
			temp=temp->prev;
		}
	}
	
}
void insertend()
{
	struct node *newnode = (struct node*) malloc (sizeof(struct node));
	if(tail==NULL && head==NULL)
	{
		printf("Enter element:");
		scanf("%d",&newnode->data);
		head=newnode;
		tail=newnode;
		head->next=NULL;
		head->prev=NULL;
		puts("process done!");
	}
	else
	{
		printf("Enter element:");
		scanf("%d",&newnode->data);
		tail->next=newnode;
		newnode->prev=tail;
		tail=newnode;
		tail->next=NULL;
		puts("process done!");
	}
}
void insertpos(int p)
{
	struct node *newnode = (struct node*) malloc (sizeof(struct node));
	if(head==NULL)
	{
		printf("list empty!");
	}
	else
	{
		int c=0;
		struct node *temp=head;
		printf("Enter element:");
		scanf("%d",&newnode->data);
		while(temp)
		{
			c++;
			temp=temp->next;
		}
		if(p>c)
			printf("range out of list!\n");
		else
		{
			free(temp);
			temp=head;
			for(int i=1;i<p-1;i++,temp=temp->next);
			
			newnode->next = temp->next;
			newnode->prev = temp;
			temp->next=newnode;
			temp=temp->next;
			temp=temp->next;
			temp->prev=newnode;
			puts("insertion done!");
		}
		
	}
}
void delbegin()
{
	if(head==NULL && tail==NULL)
	{
		printf("List empty!\n");
	}
	else
	{
		if(head->next==NULL)
		{
			head=NULL;
			tail=NULL;
		}
		else
		{
			head=head->next;
			head->prev=NULL;
		}
		puts("deleted!");
	}
}
void delend()
{
	if(head==NULL && tail==NULL)
	{
		printf("List empty!\n");
	}
	else
	{
		if(head->next==NULL)
		{
			head=NULL;
			tail=NULL;
		}
		else
		{
			tail=tail->prev;
			tail->next=NULL;
		}
		puts("deleted!");
	}
}
void delpos(int p)
{
	
	if(head==NULL)
		printf("list empty!");
	else
	{
		int c=0;
		struct node *pre,*cur;
		cur=head;
		while(cur)
		{	
			cur=cur->next;
			c++;
		}
		if(p==c)
			delend();
		else if(p>c)
			printf("range out of list!\n");	
		else
		{	
			cur=head;
			pre=head;
			for(int i=0;i<p-1;i++)
			{
				pre=cur;
				cur=cur->next;
			}
			pre->next = cur->next;
			cur = cur->next;
			cur->prev=pre;
			printf("deleted success\n");		
		 }	
		 
}
}
void updatepos(int p)
{
	if(head==NULL)
		printf("list empty!");
	else
	{
		int c=0;
		struct node *cur;
		while(cur)
		{	
			cur=cur->next;
			c++;
		}
		free(cur);
		if(p>c) printf("list out of range:(\n");
		else
		{
			struct node *temp=head;
			for(int i=1;i<p;i++,temp=temp->next);
			printf("old value:%d\t",temp->data);
			printf("Enter a new value:");
			scanf("%d",&temp->data);
			puts("updated!");
		}
	}
}
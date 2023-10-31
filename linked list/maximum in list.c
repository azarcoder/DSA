//store array of elements in linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head = NULL;
void create();
void display();
int count(struct node*);
int sum(struct node*);
int max(struct node*);
int main()
{
	int a[]={1,2,3,4,5};
	create(a,5);
//	display(head);
//	printf("\nNo of element is:%d",count(head));
//	printf("\nSum of element is:%d",sum(head));
	printf("\nmax:%d",max(head));
	return 0;
}
void create(int a[],int n)
{
	int i;
	struct node *temp,*last;
	head = (struct node*) malloc(sizeof(struct node));
	head->data=a[0];
	head->next=NULL;
	last=head;
	for(i=1;i<n;i++)
	{
		temp = (struct node*) malloc(sizeof(struct node));
		temp->data=a[i];
		temp->next=NULL;
		last->next=temp;
		last=temp;
	}
}
void display(struct node *head)
{
	if(head!=NULL)
	{
//		display(head->next);//print backward
		printf("%d ",head->data);
		display(head->next);//print forward
	}
}
int count(struct node *p)
{
	if(p==NULL)
		return 0;
	else
		return count(p->next)+1; 
}
int sum(struct node *p)
{
	if(p==NULL)
		return 0;
	else
		return sum(p->next)+p->data; 
}
int max(struct node *p)
{
	int x=0;
	if(p==NULL)
		return INT_MIN;
	else
	{	
		x=max(p->next);
		return x>p->data?x:p->data;
	}
}
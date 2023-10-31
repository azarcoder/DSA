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
int main()
{
	int a[]={1,4,2,6,7};
	create(a,5);
	display(head);
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
		display(head->next);//print backward
		printf("%d ",head->data);
//		display(head->next);//print forward
	}
}
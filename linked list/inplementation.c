#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *head,*a,*b,*c,*temp;
	head=NULL;
	a = (struct node*) malloc(sizeof(struct node));
	b = (struct node*) malloc(sizeof(struct node));
	c = (struct node*) malloc(sizeof(struct node));
	temp = (struct node*) malloc(sizeof(struct node));
	a->data=10;
	a->next=b;
	b->data=20;
	b->next=c;
	c->data=30;
	c->next=NULL;
	head=a;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	
}
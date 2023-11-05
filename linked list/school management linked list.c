#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	int id,marks;
	char psw[8],name[20];
};
struct staff
{
	int id;
	char psw[8];
};
struct node
{
	int isStudent;//1 for strudent, 0 for staff
	struct student studentdata;
	struct staff staffdata;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL,*tail=NULL;

//functions
int students();
void signup();
int login();
int staffs();
int s_signup();
int s_login();
int main()
{
	int c;
	while(1)
	{
		puts("***School Management system ***");
		printf("1.Students\n2.Teachers\n3.Exit\n");
		puts("choice:");
		scanf("%d",&c);
		switch(c)
		{
			int n;
			case 1:
				students();
				break;
			case 2:
				staffs();
				break;
			case 3:
				exit(0); 
				break;
			default:
				printf("INVALID OPTION!\n");

		}
	}
	return 0;
}
int students()
{
	int n,i=1,x;
	printf("1.Signup\n2.Login\n3.Exit\n");
	puts("choice:");
	scanf("%d",&n);
	if(n==1)
	{
		puts("how much students data you want to insert?");
		scanf("%d",&x);
		while(i++<=x)
			signup();
	}
	else if(n==2)
		login();
	else if(n==3)
		return main();
}
void signup()
{
	struct node *newnode =(struct node*) malloc(sizeof(struct node));
	if(head==NULL)
	{	
		printf("Enter name:");
		scanf("%s",newnode->studentdata.name);
		printf("ID:");
		scanf("%d",&newnode->studentdata.id);
		printf("Password:");
		scanf("%s",newnode->studentdata.psw);
		printf("Marks:");
		scanf("%d",&newnode->studentdata.marks);
		newnode->isStudent=1;
		puts("Successfully signed in!");
		newnode->isStudent=1;
		head=newnode;
		tail=newnode;
		head->next=NULL;
		head->prev=NULL;
	}
	else
	{                     
		printf("Enter name:");
		scanf("%s",newnode->studentdata.name);
		printf("ID:");
		scanf("%d",&newnode->studentdata.id);
		printf("Password:");
		scanf("%s",newnode->studentdata.psw);
		printf("Marks:");
		scanf("%d",&newnode->studentdata.marks);
		newnode->isStudent=1;
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
		head->prev=NULL;
	}
}
int login()
{
	if(!head)
	{
		printf("\nNo data found!");
		return main();
	}
	else
	{
		puts("*** STUDENT LOGIN ***\n");
		int id,n,flag=0;
		char pass[8];
		printf("Enter id:");
		scanf("%d",&id);
		printf("Enter password:");
		scanf("%s",pass);
		struct node *temp=head;
		while(temp)
		{
			if(id==temp->studentdata.id && strcmp(pass,temp->studentdata.psw)==0 &&temp->isStudent)
			{
				flag=1;
				break;
			}
			temp=temp->next;
		}
		if(flag)
		{
			puts("Login successful!");
			while(1)
			{
				printf("1.Display your data\n2.logout()\n");
				printf("choice:\n");
				scanf("%d",&n);
				if(n==1)
				{
					temp=head;
					if(!head)
						printf("list empty!\n");
					else
					{
						while(temp)
						{
							if(temp->studentdata.id==id)
							{
								printf("ID:%d\tName:%s\tMark:%d\n",temp->studentdata.id,temp->studentdata.name,temp->studentdata.marks);
								break;
							}
							temp=temp->next;
						}
					}
				}
				else if(n==2)
				{
					return main();
				}
			}
		}
		else
			puts("login error!");
	}
}
int staffs()
{
	int n;
	printf("1.staff Creation\n2.staff Login\n3.Exit\n");
	puts("choice:");
	scanf("%d",&n);
	if(n==1)
		s_signup();
	else if(n==2)
		s_login();
	else if(n==3)
		return main();
}
int s_signup()
{
	if(!head)
	{
		struct node *newnode=(struct node*) malloc(sizeof(struct node));
		printf("ID:");
		scanf("%d",&newnode->staffdata.id);
		printf("Password:");
		scanf("%s",newnode->staffdata.psw);
		puts("Successfully signed in!");
		newnode->isStudent=0;
		newnode->next=NULL;
		newnode->prev=NULL;
		head=newnode;
	}
	else
	{
		struct node *newnode=(struct node*) malloc(sizeof(struct node));
		struct node *t;
		printf("ID:");
		scanf("%d",&newnode->staffdata.id);
		printf("Password:");
		scanf("%s",newnode->staffdata.psw);
		newnode->isStudent=0;
		t=head;
		while(t->next!=NULL)
			t=t->next;
		t->next=newnode;
		newnode->prev=t;
		newnode->next=NULL;

		puts("Successfully signed in!");
	}
}
int s_login()
{
	if(!head)
	{
		printf("\nNo data found!");
		return main();
	}
	else
	{
		puts("*** TEACHER LOGIN ***\n");
		int id,n,flag=0,pid;
		char pass[8];
		printf("Enter id:");
		scanf("%d",&id);
		printf("Enter password:");
		scanf("%s",pass);
		struct node *temp=head;
		while(temp)
		{
			if(id==temp->staffdata.id && strcmp(pass,temp->staffdata.psw)==0 && temp->isStudent==0)
			{
				flag=1;
				break;
			}
			temp=temp->next;
		}
		if(flag)
		{
			puts("Login successful!");
			while(1)
			{
				printf("1.Display all students data\n2.display particular data\n3.modify data\n4.delete data\n5.logout()\n");
				printf("choice:\n");
				scanf("%d",&n);
				if(n==1)
				{
					
					if(head==NULL)
						printf("list empty!\n");
					else
					{
						temp=head;
						while(temp)
						{
							if(temp->isStudent)
								printf("ID:%d\tName:%s\tMark:%d\tpassword:%s\n",temp->studentdata.id,temp->studentdata.name,temp->studentdata.marks,temp->studentdata.psw);
							temp=temp->next;
						}
					}
				}
				else if(n==2)
				{
						struct node *temp=tail;
						int f=0;
						printf("Enter student id:");
						scanf("%d",&pid);
						
						while(temp)
						{
							if(temp->studentdata.id==pid)
							{
								f=1;
								break;
							}
							temp=temp->prev;	
						}
						if(f)
						{
							printf("ID:%d\tName:%s\tMark:%d\tpassword:%s\n",temp->studentdata.id,temp->studentdata.name,temp->studentdata.marks,temp->studentdata.psw);
						}
						else
							printf("no data found!\n");
					}
				
				else if(n==3)
				{
					if(head==NULL)
						printf("list empty!");
					else
					{
						struct node *temp=head;
						int f=0;
						printf("Enter student id:");
						scanf("%d",&pid);
						while(temp)
						{
							if(temp->studentdata.id==pid)
							{
								f=1;
								break;
							}
							temp=temp->next;	
						}
						if(f)
						{
							printf("Enter name:");
							scanf("%s",temp->studentdata.name);
							printf("ID:");
							scanf("%d",&temp->studentdata.id);
							printf("Password:");
							scanf("%s",temp->studentdata.psw);
							printf("Marks:");
							scanf("%d",&temp->studentdata.marks);
							temp->isStudent=1;
							puts("updated!");
						}
						else
							printf("no student record\n");
					}
				}
				else if(n==4)
				{
					if(head==NULL)
						printf("***no students data found***\n");
					else
					{
						int f=0;
						struct node *temp=head,*pre=head;
						puts("enter id:");
						scanf("%d",&pid);
						if(temp->next==NULL)
						{
							head=NULL;
							tail=NULL;
							free(temp);
							printf("deleted!\n");
						}
						else
						{
						
						    while(temp)
							{
								if(temp->studentdata.id==pid)
								{
									f=1;
									break;
								}
								pre=temp;
								temp=temp->next;	
							}
							if(f)
							{
								pre->next = temp->next;
								temp = temp->next;
								temp->prev=pre;
								printf("deleted success\n");
							}
							else
							{
								printf("No data found!\n");
							}
						}	
					}	
				}
				else if(n==5)
				{
					return main();
				}
				
			}
		}
		else
			puts("login error!");
	}
}
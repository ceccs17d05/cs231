#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	struct Node *prev;
	int info ;
	struct Node *next;
}node;

void createdub(node**,node**);
void insertAtBeg(node **,node**,int);
void display(node *);

void main()
{
	int ch, item, pos;
	node *start ,*end ;
	start = end = NULL;
	createdub(&start,&end);
	printf("The list is");
	display(start);
	printf("Enter the item to be inserted at begining");
	scanf("%d",&item);
	insertAtBeg(&start,&end,item);
	printf("Now the list is");
	display(start);
	
}

void createdub(node **start,node **end)
{       
	int i,item ,k=1;
	printf("Enter number of node");
	scanf("%d",&i);
	while(i)
	{ 
    	node *ptr;
		printf("Enter the info for node %d ",k);
		scanf("%d",&item);
		ptr=(node*)malloc(sizeof(node));
		ptr->info=item;
		if(*start==NULL)
		{
			ptr->prev = ptr->next = NULL ;
			*start = *end = ptr ;
		}
		else
		{
			ptr->prev = *end;
        	(*end)->next = ptr ;
			ptr->next= NULL;
			(*end)=ptr;
		}
		i--;
		k++;
	}
}
void insertAtBeg(node **start,node **end,int item )
{
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	if(*start==NULL)
	{
		*start=ptr;
		*end=ptr;
	}
	else
	{
		ptr->prev = NULL;
		ptr->next=*start;
		(*start)->prev=ptr;
		*start=ptr;
	}
}

void display(node *start)
{
     while(start !=NULL)
     { 
     	printf("%d",start->info);
       	start = start->next;
     }
}

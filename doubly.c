#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
	struct node *prev;
	};
struct node *head;
void insertion_beginning();
void insertion_last();
void insertion_specified();
void deleition_beginning();
void deleition_last();
void deleition_specified();
void display();
void search();
void main()
{
	int choice=0;
	while (choice !=9)
   {
	printf("**DOUBLY LINKED LIST**\n");
	printf("Choose any option from the list given below:\n");
	printf("\n1.Insertion at beginning\n2.Insertion at the end\n3.Insertion in between\n4.Deleition at beginning\n5.Deleition from last\n6.deleition between nodes\n7.Display\n8.Search\n9.Exit\n");
	printf("Enter any choice:\n");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
		insertion_beginning();
		break;
		case 2:
		insertion_last();
		break;
		case 3:
		insertion_specified();
		break;
		case 4:
		deleition_beginning();
		break;
		case 5:
		deleition_last();
		break;
		case 6:
		deleition_specified();
		break;
		case 7:
		display();
		break;
		case 8:
		search();
		break;
		case 9:
		exit(0);
		break;
		default:
		printf("Alert: Enter a valid input\n");
	}
   }
}
	void insertion_beginning()
	{
		struct node *ptr;
		int item;
		ptr=(struct node*)malloc(sizeof(struct node));
		if (ptr==NULL)
		{
		  printf("\nOverflow");
		}
		else
		{
		  printf("\nEnter item:");
		  scanf("%d",&item);
		
		if(head==NULL)
		{
		  ptr->next=NULL;
		  ptr->prev=NULL;
		  ptr->data=item;
		  head=ptr;
		}
		
		else
		{
		  ptr->data=item;
		  ptr->prev=NULL;
		  ptr->next=head;
		  head->prev=ptr;
		  head=ptr;
		}
		}
		
		printf("Node is inserted\n");
	}
	
	void insertion_last()
	{
		struct node *ptr,*temp;
		int item;
		ptr=(struct node*)malloc (sizeof(struct node));
		if (ptr==NULL)
		{
		  printf("\nOverflow");
		}
		else
		{
		  printf("\nEnter item:");
		  scanf("%d",&item);
		  ptr->data=item;
		if(head==NULL)
		{
		  ptr->next=NULL;
		  ptr->prev=NULL;
		  head=ptr;
		}
		
		else
		{
		  temp=head;
		while(temp->next!=NULL)
		{
		  temp=temp->next;	
		}
		  temp->next=ptr;
		  ptr->prev=temp;
		  ptr->next=NULL;
		}
		}
		
		printf("Node is inserted\n");
	}
	
	void insertion_specified()
	{
		struct node *ptr,*temp;
		int item,i,loc;
		ptr=(struct node*)malloc(sizeof(struct node));
		if (ptr==NULL)
		{
		  printf("\nOverflow");
		}
		else
		{
		  temp=head;
		  printf("Enter the location:");
		  scanf("%d",&loc);
		  for (i=1;i<loc-1;i++)
		   {
		     temp=temp->next;
		     if(temp==NULL)
			{
				printf("there are less than %d elements\n",loc);
				return;
			}	

		   }
		   printf("Enter value:");
		   scanf("%d",&item);
		   ptr->data=item;
		   ptr->next=temp->next;
		   ptr->prev=temp;
		   temp->next=ptr;
		   temp->next->prev=ptr;
		   printf("\nNode is inserted\n");
		}
	}
	
	void deleition_beginning()
	{
		struct node *ptr;
		if(head==NULL)
		{
		  printf("Underflow\n");
		}

		else if(head->next==NULL)
		{
		  head=NULL;
		  free(head);
		  printf("\n node is deleted\n");	
		}

		else
		{
		  ptr=head;
		  head=head->next;
		  head->prev=NULL;
		  free(ptr);
		  printf("\n node is deleted\n");
		}
	}
	void deleition_last()
	{
		struct node *ptr,*temp;
		if (head==NULL)
		{
		printf("\nUnderflow");
		}
		else if(head->next==NULL)
		{
		  head=NULL;
		  printf("\nnode is deleted\n");	
		}
		else
	        {
		  ptr=head;
		  while(ptr->next!=NULL)
		  {
	             ptr=ptr->next;
		  }
		  temp=ptr->prev;
		  temp->next=NULL;
		  ptr->prev=NULL;
		  printf("\nNode is deleted\n");
		}

	}

	void deleition_specified()
	{
		struct node *ptr,*temp1,*temp;
		int val;

		printf("enter the data to delete:\n");
		scanf("%d",&val);

		ptr=head;

		while(ptr->data!=val)
		       {	
		        ptr=ptr->next;
		       }
			temp=ptr->prev;
			temp1=ptr->next;
			temp->next=temp1;
			ptr->prev=NULL;
			ptr->next=NULL;
			temp1->prev=temp;
		
		   
	}
	
	void display()
	{
		struct node *ptr;
		printf("\n\nRESULT:\n\n");
		ptr=head;
		while(ptr!=NULL)
		{
		 printf("%d\n",ptr->data);
		 ptr=ptr->next;
		}
	}
	void search()
 	{
	 	struct node *ptr;
		int item,i=0,flag;
		ptr=head;
		if(ptr==NULL)
		{
		printf("Empty list\n");
		}
		else
		{
		 printf("Enter the element you want to search:");
		 scanf("%d",&item);
		}
		while (ptr!=NULL)
		{
		   if(ptr->data==item)
			{
			  printf("Item you have searched is found at the location %d",i+1);
			  flag=0;
			  break;
			}
		   else
			{
			  flag=1;
			}
			  i++;
			  ptr=ptr->next;
		}
		if(flag==1)
		{
		  printf("Item you have searched for is not found at the location.");
		}
	}
	
		  



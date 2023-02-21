

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *ptr;
};

struct node *head=NULL;

void insert_beg();
void delete_beg();
void insert_end();
void delete_end();
void insert_pos(int);
void delete(int);
void disp();
void main(){
	int ch=0,key;
	do{
		printf("\nSingly Linked List...\n\t1.Insert at beginning\n\t2.Delete from beginning\n\t3.Insert at end\n\t4.Delete from end");
		printf("\n\t5.Insert post given element\n\t6.Delete given element\n\t7.Display\n\t8.Exit\nEnter your choice(1-8):");
		scanf("%d",&ch);
		switch(ch){
			case 1: insert_beg();
				break;
			case 2: delete_beg();
				break;
			case 3: insert_end();
				break;
			case 4: delete_end();
				break;
			case 5: printf("\n Enter the element post which the new element needs to be inserted:");
				scanf("%d",&key);
				insert_pos(key);
				break;
			case 6: printf("\n Enter the element to be deleted from the list:");
				scanf("%d",&key);
				delete(key);
				break;
			case 7: disp();
				break;
			case 8: printf("\nExit!!!");
				exit;
				break;
			default:printf("Invalid choice!!");
		}
	}while(ch!=8);
}


void insert_beg(){
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	if (new==NULL){
		printf("\nInsufficient memory!!");	
	}
	else{
		if(head==NULL)
			head=new;
		else{
			new->ptr=head;
			head=new;		
		}
	}
	disp();
}


void delete_beg(){
	if(head==NULL)
		printf("\nUnderflow!!\nNo elements in the list\nDeletion not possible...");
	else{
		if(head->ptr==NULL){
			printf("\nElement deleted is %d",head->data);
			head=NULL;		
		}
		else{
			printf("\nElement deleted is %d",head->data);
			head=head->ptr;		
		}	
	}
	disp();
}


void insert_end(){
	struct node *new,*temp=NULL;
	new=(struct node*)malloc(sizeof(struct node));
	if (new==NULL){
		printf("\nInsufficient memory!!");	
	}
	else{
		if(head==NULL)
			head=new;
		else{
			temp=head;
			while(temp->ptr!=NULL)
				temp=temp->ptr;
			temp->ptr=new;		
		}
	}
	disp();
}


void delete_end(){
	struct node *temp=NULL,*prev=NULL;
	if(head==NULL)
		printf("\nUnderflow!!\nNo elements in the list\nDeletion not possible...");
	else{
		if(head->ptr==NULL){
			printf("\nElement deleted is %d",head->data);
			head=NULL;		
		}
		else{
			temp=head;
			while(temp->ptr!=NULL){
				prev=temp;
				temp=temp->ptr;
			}
			printf("\nElement deleted is %d",temp->data);
			prev->ptr=NULL;
			free(temp);
				
		}	
	}
	disp();
}


void insert_pos(int key){
	struct node *new,*temp=NULL,*hold;
	new=(struct node*)malloc(sizeof(struct node));
	if (new==NULL){
		printf("\nInsufficient memory!!");	
	}
	else{
		if(head==NULL)
			head=new;
		else{
			temp=head;
			while(temp->data!=key || temp->ptr!=NULL)
				temp=temp->ptr;
			if(temp->data==key){
				hold=temp->ptr;
				temp->ptr=new;
				new->ptr=hold;				
			}
			else if(temp->ptr==NULL)
			{
				printf("\n%d not found in list.\nHence inserting to the end of list.",key);			
				temp->ptr=new;			
			}			
		}
	}
	disp();
}


void delete(int key){
	struct node *temp=NULL,*prev=NULL;
	if(head==NULL)
		printf("\nUnderflow!!\nNo elements in the list\nDeletion not possible...");
	else{
		if(head->ptr==NULL){
			printf("\nElement deleted is %d",head->data);
			head=NULL;		
		}
		else{
			temp=head;
			while(temp->data!=key || temp->ptr!=NULL){
				prev=temp;
				temp=temp->ptr;
			}
			if(temp->data==key){
				prev->ptr=temp->ptr;
				free(temp);					
			}
			else if(temp->ptr==NULL)
			{
				printf("\n%d not found in list.\nDeletion not possible.",key);					
			}
		}
	}
	disp();	
}

void disp(){
	struct node *temp=NULL;
	if(head==NULL)
		printf("\nEmpty List!!\nNo elements in the list..");
	else{
		printf("\n Singly linked list:\n");
		temp=head;
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp=temp->ptr;		
		}
	}
}

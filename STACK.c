#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
struct node
{
int data;
struct node *next;
};
struct node *top=NULL;
struct node *new;
struct node *temp=NULL;
void main()
{
int opt;
do
{
printf("\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n");
printf("Enter your choice:");
scanf("%d",&opt);
switch(opt)
{
case 1:push();
break;
case 2:pop();
break;
case 3:display();
break;
case 4:exit(0);
break;
}
}while(opt!=4);
}

void push()
{
new=(struct node*) malloc(sizeof(struct node));
if(new==NULL)
{ 
printf("Stack is OVERFLOW\n");
}
else
{
printf("Enter the data to push:");
scanf("%d",&new->data);
new->next=top;
top=new;
}
}

void pop()
{
struct node *ptr;
if(top==NULL)
{
printf("Stack is UNDERFLOW\n");
}
else
{
printf("Element to poped is %d\n",top->data);
ptr=top;
top=top->next;
free(ptr);
}
}

void display()
{
struct node *ptr;
ptr=top;
if(ptr==NULL)
{
printf("Stack is empty\n");
}
else
{
printf("Stack elements\n");
while(ptr!=NULL)
{
printf("%d\n",ptr->data);
ptr=ptr->next;
}
}

} 

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*llink;
	struct node*rlink;
};
typedef struct node*NODE;
NODE insert_pos(NODE);
NODE delete_pos(NODE);
NODE delete_front(NODE);
NODE insert_rear(NODE);
void display(NODE);

NODE getnode();
void main()
{
	NODE first=NULL;
	int option;
	clrscr();
	while(1)
	{
		printf("\doubly linked list operation\n");
		printf("\n1.insert\n2.delete\n3.display\n4.exit\n");
		printf("enter your choice: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:printf("\n1.insert rear\n2.insert position\n enter your choice: ");
			scanf("%d", &option);
			switch (option){
				case 1:first=insert_rear(first);
					getch();
					clrscr();
					break;
				case 2:first=insert_pos(first);
					getch();
					clrscr();
					break;
				default:printf("invalid choice\n");

			}
			break;
			case 2:first=delete_pos(first);
				getch();
				clrscr();
				break;
			case 3:display(first);
				getch();
				clrscr();
				break;
			case 4:exit(0);
			default:printf("invalid choice\n");
		}
	}
}
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	return temp;
}
NODE insert_pos(NODE first)
{
	int pos, count;
	NODE temp, ptr;
	temp=getnode();
	temp->llink=temp->rlink=NULL;
	if(first==NULL)
	{
		printf("enter the data: ");
		scanf("%d", &temp->data);
		printf("%d is successfully inserted\n", temp->data);
		first=temp;
		return first;
	}
	count=1;
	printf("enter the position: ");
	scanf("%d", &pos);
	ptr=first;
	while(ptr->rlink!=NULL)
	{
		ptr=ptr->rlink;
		count++;
	}
	if(pos>count)
	{
		printf("Invalid position\n");
		return first;
	}
	printf("enter the data: ");
	scanf("%d", &temp->data);
	printf("%d is successfully inserted\n",temp->data);
	if(pos==1)
	{
		temp->rlink=first;
		first->llink=temp;
		first=temp;
		return first;
	}
	ptr=first;
	count=1;
	while(count<pos)
	{
	ptr=ptr->rlink;
	count++;
	}
	ptr->llink->rlink=temp;
	temp->llink=ptr->llink;
	temp->rlink=ptr;
	ptr->llink=temp;
	return first;
}
NODE  delete_pos(NODE first)
{
	NODE ptr;
	int pos, count;
	if(first==NULL)
	{
		printf("no nodes");
		return first;
	}
	ptr=first;
	count=1;
	while(ptr->rlink!=NULL)
	{
		ptr=ptr->rlink;
		count++;
	}
	printf("enter the position: ");
	scanf("%d", &pos);
	if(pos>count)
	{
		printf("invalid postion\n");
		return first;
	}
	if(pos==1)
	{
		first=delete_front(first);
		return first;
	}
	ptr=first;
	count=1;
	while(count<pos)
	{
		ptr=ptr->rlink;
		count++;
	}
	printf("%d is successfully deleted\n", ptr->data);
	ptr->llink->rlink=ptr->rlink;
	ptr->rlink->llink=ptr->llink;
	free(ptr);
	return first;
}
void display(NODE first)
{
	NODE temp;
	if(first==NULL)
	printf("no nodes");
	else {
		for(temp=first;temp->rlink!=NULL;temp=temp->rlink)
		printf("%d=>", temp->data);
		printf("%d", temp->data);
	}
}
NODE insert_rear(NODE first)
{
	NODE temp, ptr;
	temp=getnode();
	printf("enter the data: ");
	scanf("%d", &temp->data);
	printf("%d is successfully inserted\n", temp->data);
	temp->rlink=temp->llink=NULL;
	if(first==NULL){
		first=temp;
		return first;
	}
	ptr=first;
	while(ptr->rlink!=NULL)
	ptr=ptr->rlink;
	ptr->rlink=temp;
	temp->llink=ptr;
	return first;
}
NODE delete_front(NODE first)
{
	NODE ptr;
	ptr=first;
	first->rlink->llink=NULL;
	first=first->rlink;
	printf("%d is successfully deleted", ptr->data);
	return first;
}

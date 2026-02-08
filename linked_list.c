#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
typedef struct node*NODE;

NODE insert_rear(NODE);
NODE insert_front(NODE);
NODE delete_rear(NODE);
NODE delete_front(NODE);
NODE getnode();
void display(NODE);

void main()
{
	NODE first=NULL;
	int option;
	clrscr();
	while(1)
	{
		printf("\nDouble ended queue operation\n");
		printf("\n1.entry restricted queue\n 2.exit restricted queue\n 3.display \n4.exit\n");
		printf("\nenter your choice: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: printf("Entry restricetd operation\n");
			printf("\n1.insert \n2.delete from front \n3.delete from rear\n");
			printf("enter your choice: ");
			scanf("%d", &option);
			switch(option)
			{
				case 1:first=insert_rear(first);
				getch();
				clrscr();
				break;
				case 2:first=delete_front(first);
				getch();
				clrscr();
				break;
				case 3:first=delete_rear(first);
				getch();
				clrscr();
				break;
				default:printf("invalid choice\n");
			}
			case 2:printf("\nexit restricetd operation\n");
			printf("1.delete\n 2.insert from front\n 3.insert frpm rear\n");
			printf("enter your choice: ");
			scanf("%d", &option);
			switch(option)
			{
				case 1:first=delete_front(first);
				getch();
				clrscr();
				break;
				case 2:first=insert_front(first);
				getch();
				clrscr();
				break;
				case 3:first=insert_rear(first);
				getch();
				clrscr();
				break;
				default:printf("inavlid choice\n");
			}
			break;
			case 3:display(first);
			getch();
			clrscr();
			break;
			case 4:exit(0);
			default:printf("inavlid choice\n");
		}
	}
}
NODE getnode()
{
	NODE temp;
	temp=(NODE)malloc(sizeof(struct node));
	return temp;
}
NODE insert_front(NODE first)
{
	NODE temp;
	temp=getnode();
	printf("enter the data: ");
	scanf("%d", &temp->data);
	temp->link=first;
	first=temp;
	printf("%d is successfully inerted\n",temp->data);
	return first;
}
NODE delete_front( NODE first)
{
	NODE temp;
	if(first==NULL)
	{
	printf("no nodes present");
	return first;
	}
	temp=first;
	first=first->link;
	printf("%d is successfully deleted\n", temp->data);
	free(temp);
	return first;
}
NODE insert_rear(NODE first)
{
	NODE temp, ptr;
	temp=getnode();
	printf("enter the data: ");
	scanf("%d", &temp->data);
	printf("%d is successfully inserted\n", temp->data);
	temp->link=NULL;
	if(first==NULL)
	{
	first=temp;
	return first;
	}
	ptr=first;
	while(ptr->link!=NULL)
	ptr=ptr->link;
	ptr->link=temp;
	return first;
}
NODE delete_rear(NODE first)
{
	NODE ptr, prev;
	if(first==NULL)
	{
	printf("no nodes present\n");
	return first;
	}
	ptr=first;
	while(ptr->link!=NULL)
	{
	prev=ptr;
	ptr=ptr->link;
	}
	printf("%d is successfully removed\n", ptr->data);
	prev->link=NULL;
	free(ptr);
	return first;
}
void display(NODE first)
{
NODE temp;
if(first==NULL)
printf("no nodes present\n");
else
{
for(temp=first; temp->link!=NULL; temp=temp->link)
printf("%d=>", temp->data);
printf("%d=>", temp->data);
}
}

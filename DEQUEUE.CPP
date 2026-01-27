#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	int data;
	struct node*next;
};
typedef struct node*NODE;

NODE getnode(){
	NODE temp=(NODE)malloc(sizeof(struct node));
	return temp;
}

NODE insert_front(NODE first){
	NODE temp=getnode();
	printf("enter a value: ");
	scanf("%d", &temp->data);
	temp->next=first;
	first=temp;
	printf("%d is successfully added", temp-data);
	return first;
}
NODE insert_rear(NODE first){
	NODE temp=getnode(), ptr;
	printf("Enter a value: ");
	scanf("%d", &temp->data);
	temp->next=NULL;
	if(first==NULL){
		first=temp;
		printf("%d is successfully inserted", temp->data);
		return first;
	}
	ptr=first;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=temp;
	printf("%d is successfullly inserted",temp->data);
	return first;
}
NODE delete_front(NODE first);
	NODE temp;
	if(first==NULL)
	{
		printf("no nodes\n");
		return first;
	}
	temp=first;
	first=first->next;
	printf("%d is successfully deleted", temp->data);
	free(temp);
	return first;
}
NODE delete_rear(NODE first){
	NODE ptr, prev;
	if(first==NULL){
		printf("no nodes");
		return first;
	}
	if(first->next==NULL){
		printf("%d is successfully deleted", first->data);
		free(first);
		return NULL;
	}
	ptr=first;
	while(ptr->next!=NULL){
		prev=ptr;
		ptr=ptr->next;
	}
	printf("%d is successfully deleted", ptr->data);
	prev->next=NULL;
	free(ptr);
	return first;
}
void display(NODE first){
	NODE temp;
	if(first==NULL){
		printf("no nodes");
		return;
	}
	printf("queue elements\n");
	for(temp=first; temp!=NULL; temp=temp->next)
		printf("%d=>", temp->data);
	printf("NULL\n");
}
void main(){
	NODE first=NULL;
	int option;
	crlscr();
	while(1){
		printf("queues operation\n");
		printf("\n1.entry restricted operation\n2.exit restricted operation\3.display\n4.exit");
		printf("enter your choice: ");
		scanf("%d", &option);
		switch(option){
			case 1: printf("entry restricted operations\n");
				printf("\n1.insert rear(only)\n2.delete_front\n3.delete_rear\n");
				printf("enter your choice: ");
				scanf("%d", &option);
				switch(option){
					case 1: first=insert_rear(first);
						break;
					case 2: first=delete_front(first);
						break;
					case 3: first=delete_rear(first);
						break;
					default:printf("enter valid choice\n");
				}
				break;
			case 2: printf("exit restricted operations\n");
				printf("\n1.delete front\n2.insert front\n3.insert rear\n");
				printf("enter your choice: ");
				scanf("%d", &option);
				switch(option){
					case 1:first=delete_front(first);
						break;
					case 2:first=insert_front(first);
						break;
					case 3:first=insert_rear(first);
						break;
					default:printf("enter your choice: ");
						break;
				}
				break;
			case 3:display(first);
				first;
			case 4:exit(0); default:printf("invalid choice\n");
		}
		getch();
		clrscr();
	}
}





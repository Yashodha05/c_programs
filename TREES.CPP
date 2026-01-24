#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*left;
	struct nodde*right;
};

typedef struct node*NODE;
NODE insertion(NODE);
NODE deletion(NODE);
void inorder(NODE);
NODE getnode();
void main(){
	int option;
	NODE root;
	clrscr();
	root=getnode();
	printf("enter the data for root node\n");
	scanf("%d", &root->data);
	while(1){
		printf("\ntree operation\n");
		printf("\n1.insert\n2.delete\n3.display\n4.exit");
		scanf("%d", &option);
		switch(option){
			case 1: root=insertion(root);
				getch();
				clrscr();
				break;
			case 2: root=deletion(root);
				getch();
				clrscr();
				break;
			case 3: printf("\ninorder traversal\n");
				inorder(root);
				getch();
				clrscr();
				break;
			case 4: exit(0); default: printf("invalid choice");
		}
	}
}
NODE insertion(NODE root){
	NODE prev, temp, temp1;
	int item;
	temp1=getnode();
	printf("enter the data: ");
	scanf("%d", &item);
	printf("%d is successfully inserted\n", temp1->data);
	item=temp1->data;
	prev=NULL;
	temp=root;
	while(temp!=NULL)
	{
		prev=temp;
		if(item<temp->data)
		temp=temp->llink;
		else
		temp=temp->rlink;
	}
	if(item<prev->data)
	prev->rlink=temp1;
	else
	prev->rlink=temp1;
	return root;
}
NODE getnode()
{
	NODE temp=malloc(sizeof(struct node));
	temp->rlink=temp-llink=NULL;
	return temp;
}

NODE deletiton(NODE root){
	NODE cur, parent, suc, q;
	int item;
	if(root==NULL)
	{
		printf("NO elements in tree\n");
		return root;
	}
	printf("enter the elements to be deleted: ");
	scanf("%d", &item);
	parent=NULL;
	cur=root;
	while(cur!=NULL &&item!=cur->data){
		parent=cur;
		if(item<cur->data)
		cur=cur->llink;
		else
		cur=cur->rlink;
	}
	if(cur==NULL){
		printf("%d not found", item);
		return root;
	}
	if(cur->llink==NULL)
	q=cur->rlink;
	else
	if(cur->rlink==NULL)
	q=cur->llink;
	else{
	suc=cur->rlink;
	while(suc->llnik!=NULL)
	suc=suc->llink;
	suc->llink=cur->llink;
	q=cur->rlink;
	}
	if(cur==parent->llink)
		parent->llink=q;
	else
		parent->rlink=q;
	free(cur);
	printf("%d is successfully deleted\n",item);
	return root;
}
void inorder(NODE root){
	if(root!=0)
	{
		inorder(root->llink);
		printf("%d=>", root->data);
		inorder(root->rlink);
	}
}


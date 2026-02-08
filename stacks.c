//1a. Implement stacks using Arrays

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 5
int stack[SIZE];
int push(int);
int pop(pop);
void display(int);

int main()
	int top=-1, option;
	clrscr();
	while(1){
		printf("stack operations\n");
		printf("\n1.push\n2.pop\n3.display\4.exit\n");
		printf("enter your choice: ");
		scanf("%d", &option);
		switch(option){
			case 1:top=push(top);
			       getch();
			       clrscr();
			       break;
			case 2:top=pop(top);
			       getch();
			       clrscr();
			       break;
			case 3:display(top);
				getch();
				clrscr();
				break;
			case 4:exit(0);default: printf("inavlid choice:");
		}
	}
}
int push(int top){
	int item;
	if(top==(SIZE-1))
	{
		printf("overflow\n");
		return top;
	}
	printf("enter the data: ");
	scanf("%d", &item);
	stack[++top]=item;
	printf("%d is successfully inserted", item);
	return top;
}
int pop(int top){
	if(top==-1){
		printf("underflow\n");
		return top;
	}
	printf("%d is successfully deleted",stack[top]);
	top--;
	return top;
}
int display(int top){
	int i;
	if(top==-1){
		printf("no nodes");
		return top;
	}
	printf("stack status");
	for(i=top; i>=0; i--){
	printf("%d=>",stack[i]);
	}
}


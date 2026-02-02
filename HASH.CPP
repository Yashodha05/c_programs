#include<stdio.h>
#include<stdlin.h>
#include<conio.h>
void main(){
	int a[100], a1[100], a2[100],i,result,n;
	clrscr();
	printf("enter the number of elements: ");
	scanf("%d", &n);
	printf("enter the elements:\n");
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
		a1[result]=a2[i]=a1[i];
		printf("Location:a[%d], value:%d\n", result, a1[result]);
	}
	printf("hash table\n");
	for(i=0; i<n;i++)
		printf("%d", a2[i]);
		getch();
}

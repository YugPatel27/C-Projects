#include <stdio.h>
int withdraw(int);
int deposit(int);
void printline();
int display(char [],int,int);
int main()
{
	char name[10];
	int accno,balance,w,e,g;
	
	printf("Enter your name, account number : ");
	scanf("%s %d",name,&accno);
	printf("Enter the balance ammount : ");
	scanf("%d",&balance);
	balance = withdraw(balance);
	display(name,accno,balance);
	balance = deposit(balance);
	display(name,accno,balance);
}
int withdraw(int a)
{
	int d;
	printf("\n Enter the withdarw ammount : ");
	scanf("%d",&d);
	
	a = a - d;
	return a;
}
int deposit(int b)
{
	int f;
	printf("\n Enter the deposit ammount : ");
	scanf("%d",&f);
	b = b + f;
	return b;
}
int display(char nm[],int acc, int c)
{
	printline();
	printf("\n Hello  : %s , \n account number : %d , \n your balance : %d",nm,acc,c);
	printline();
}
void printline(){
	int i;
	printf("\n");
	for(i=1; i <= 30; i++){
		printf("*");
	}
	printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for product
struct product {
    int id;
    char name[20];
    float price;
    int quantity;
};

// Declare global variables
struct product products[100];
int ans=0;
FILE *fp;

// Function prototypes
void view_products();
void add_quantity();
void add_product();
void buy_product();

int main() {
    int choice;
    ans=1;
    fp = fopen("Project.txt","a+");
    // Message for display
    printf("--------------Welcome to the online shopping portal------------\n");
    printf("Please choose one of the following options:\n");
    printf("1. Company staff\n");
    printf("2. Buyer\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    
    switch (choice) {
        case 1:
            // Company staff mode
        do
        {
            printf("Please choose one of the following options:\n");
            printf("1. View products\n");
            printf("2. Add quantity\n");
            printf("3. Add product\n");
            printf("4. Exit\n");

            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    view_products();
                    break;
                case 2:
                    add_quantity();
                    break;
                case 3:
                    add_product();
                    break;
                case 4:
                    printf("Thank you for using the online shopping portal\n");
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
            }
            break;
              printf("Do you want to continue PRESS 1 TO CONTINUE,otherwise any key");
              scanf("%d",&ans);
        }while(ans==1);
        case 2:
            // Buyer mode
            do
			{
            printf("Please choose one of the following options:\n");
            printf("1. View products\n");
            printf("2. Buy product\n");
            printf("3. View items bought\n");
            printf("4. Exit\n");

            scanf("%d", &choice);

			switch (choice) {
                case 1:
                    view_products();
                    break;
                case 2:
                    buy_product();
                    break;
                case 3:
                    // Implement the view_items() function if needed
                    printf("View items bought\n");
                    break;
                case 4:
                    printf("Thank you for using the online shopping portal.\nDo visit again.\n");
                    break;
                default:
                    printf("Invalid choice\n");
                    break;
            }
            break;
           printf("Do you want to continue PRESS 1 TO CONTINUE,otherwise any key");
            scanf("%d",&ans);
        }while(ans==1);
    }
 fclose(fp);
}

void view_products() 
{
	int i;
	fp = fopen("Project.txt","r+");
     printf("\n                    **** INVENTORY ****                           ");
	 printf("\n------------------------------------------------------------------\n");
   		printf("| CODE | NAME | QUANTITY | PRICE |\n");
   		printf("------------------------------------------------------------------\n");
		while(fscanf(fp,"\n%d %s %f %d",&products[i].id,products[i].name,&products[i].price,&products[i].quantity)!=EOF)
		{
   		printf("\n%d     %s       %f        %d\n",products[i].id,products[i].name,products[i].price,products[i].quantity);
   		printf("------------------------------------------------------------------\n");
   		}
   		  fclose(fp);
 }

void add_quantity() {
    int id,qty;
    int i,n;
     fp = fopen("Project.txt","a+");
   	 if (fp == NULL) 
	{ 
	printf("Error opening file\n"); 
	exit(1); 
	}
    printf("Enter the product ID to update quantity: ");
    scanf("%d", &id);
      	
    for (i=0; i<n; i++) {
        if (products[i].id == id) {
            printf("Enter the quantity to add: ");
            scanf("%d", &qty);
            products[i].quantity += qty;
            printf("Quantity updated successfully.\n");
            return;
        }
         else
    printf("Product not found\n");
    }
    fclose(fp);
}

void add_product()
     {
    int n,i;
    if (n == 100) {
        printf("No space to add new product.\n");
        return;
    }
    // Adding product
    for(i=0; i<n; i++)
    {
	fflush(stdin);
    printf("Enter the product ID: \n");
    scanf("%d",&products[n].id);
    fflush(stdin);
    printf("Enter the product Name: \n");
    scanf("%s",products[n].name);
 	fflush(stdin); 
    printf("Enter the product Price: \n");
    scanf("%f",&products[n].price);
	fflush(stdin);   
    printf("Enter the product Quantity: \n");
    scanf("%d",&products[n].quantity);
    }
    // Printing details in file
    fp = fopen("Project.txt", "a+");
	fprintf(fp,"%d %s %2.3f %d\n",products[n].id,products[n].name,products[n].price,products[n].quantity);
    n++;
    fclose(fp);
    printf("Product added successfully\n");
}

void buy_product() {
    int id;
	int i,n;
    printf("Enter the product ID to buy: ");
    scanf("%d",&id);

    fp = fopen("Project.txt","a+");
    for (i=0; i<n; i++) {
        if (products[i].id == id)
	   {
            printf("You bought one %s for %2.3f.\n", products[i].name, products[i].price);
            products[i].quantity--;
        }
        else
          printf("Product not available or out of stock.\n");
    }
    fclose(fp);
}

#include <stdio.h>
#include <string.h>

#define NUM_HOSPITALS 3
#define NUM_PATIENTS 3

struct Hospital {
    char name[50];
    char city[50];
    int beds;
    float price;
    float rating;
    int reviews;
};

struct Patient {
    char name[50];
    int age;
    int preferredHospital;
    char disease[50];
};


void printHospital(struct Hospital hosp) {
    printf("Hospital Name: %s\n", hosp.name);
    printf("City: %s\n", hosp.city);
    printf("Total Beds: %d\n", hosp.beds);
    printf("Price per Bed: $%.2f\n", hosp.price);
    printf("Rating: %.1f\n", hosp.rating);
    printf("Reviews: %d\n", hosp.reviews);
    printf("\n");
}


void printPatient(struct Patient patient) {
    printf("Patient Name: %s\n", patient.name);
    printf("Age: %d\n", patient.age);
    printf("Disease: %s\n", patient.disease);
    printf("Preferred Hospital: %d\n", patient.preferredHospital + 1); 
    printf("\n");
}


void sortByPrice(struct Hospital hospitals[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (hospitals[j].price > hospitals[j + 1].price) {
                struct Hospital temp = hospitals[j];
                hospitals[j] = hospitals[j + 1];
                hospitals[j + 1] = temp;
            }
        }
    }
}


void sortByRating(struct Hospital hospitals[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (hospitals[j].rating < hospitals[j + 1].rating) {
                struct Hospital temp = hospitals[j];
                hospitals[j] = hospitals[j + 1];
                hospitals[j + 1] = temp;
            }
        }
    }
}

void checkAvailability(struct Hospital hospitals[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Hospital %d (%s) has %d beds available.\n", i + 1, hospitals[i].name, hospitals[i].beds);
    }
}

int main() 
{
    struct Hospital hospital[NUM_HOSPITALS];
    struct Patient patient[NUM_PATIENTS];

  
    int i;
    for (i = 0; i < NUM_HOSPITALS; ++i) {
        printf("Enter details for hospital %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", hospital[i].name);
        printf("City: ");
        scanf(" %[^\n]", hospital[i].city);
        printf("Total Beds: ");
        scanf("%d", &hospital[i].beds);
        printf("Price per Bed: ");
        scanf("%f", &hospital[i].price);
        printf("Rating: ");
        scanf("%f", &hospital[i].rating);
        printf("Reviews: ");
        scanf("%d", &hospital[i].reviews);
        printHospital(hospital[i]);
    }

    for (i = 0; i < NUM_PATIENTS; ++i) {
        printf("Enter details for patient %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", patient[i].name);
        printf("Age: ");
        scanf("%d", &patient[i].age);
        printf("Disease: ");
        scanf(" %[^\n]", patient[i].disease);
        patient[i].preferredHospital = 0; 
        printPatient(patient[i]);
    }

    
    int sortOption;
    do {
        printf("Choose sorting option:\n1. Price\n2. Rating\n");
        scanf("%d", &sortOption);

        if (sortOption != 1 && sortOption != 2) {
            printf("Invalid option. Please choose again.\n");
        }

    } while (sortOption != 1 && sortOption != 2);

    switch (sortOption) {
        case 1:
            sortByPrice(hospital, NUM_HOSPITALS);
            break;
        case 2:
            sortByRating(hospital, NUM_HOSPITALS);
            break;
    }

   
    for (i = 0; i < NUM_PATIENTS; ++i) {
        printf("Details of the preferred hospital for patient %d:\n", i + 1);
        printHospital(hospital[patient[i].preferredHospital]);
    }

    checkAvailability(hospital, NUM_HOSPITALS);
}

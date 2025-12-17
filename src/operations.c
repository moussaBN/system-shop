#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

void loadProducts(Product *products, int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open file: %s\n", filename);
        exit(1);
    }

    *count = 0;
    while (fscanf(file, "%s %d %d", products[*count].name,
                  &products[*count].price, &products[*count].stock) != EOF) {
        (*count)++;
    }

    fclose(file);
}

void saveProducts(Product *products, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Unable to save file: %s\n", filename);
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %d\n", products[i].name, products[i].price, products[i].stock);
    }

    fclose(file);
}

void sellProduct(Product *products, int count) {
    char name[50];
    int sold;

    printf("Enter product name: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Enter quantity to sell: ");
            scanf("%d", &sold);

            if (sold > products[i].stock) {
                printf("Error: Not enough stock!\n");
            } else {
                products[i].stock -= sold;
                printf("Sold %d %s(s). Remaining stock: %d\n", sold, products[i].name, products[i].stock);
            }
            return;
        }
    }

    printf("Product not found.\n");
}

void displayInventory(Product *products, int count) {
    printf("\n--- Inventory ---\n");
    for (int i = 0; i < count; i++) {
        printf("%s - $%d - %d in stock\n", products[i].name, products[i].price, products[i].stock);
    }
}

void restockProduct(Product *products, int count) {
    char name[50];
    int amount;

    printf("Enter product name to restock: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Enter quantity to add: ");
            scanf("%d", &amount);

            products[i].stock += amount;
            printf("Restocked %s. New stock: %d\n", products[i].name, products[i].stock);
            return;
        }
    }

    printf("Product not found.\n");
}
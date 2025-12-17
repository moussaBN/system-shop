#ifndef OPERATIONS_H
#define OPERATIONS_H

typedef struct {
    char name[50];
    int price;
    int stock;
} Product;

void loadProducts(Product *products, int *count, const char *filename);
void saveProducts(Product *products, int count, const char *filename);
void sellProduct(Product *products, int count);
void displayInventory(Product *products, int count);
void restockProduct(Product *products, int count);

#endif
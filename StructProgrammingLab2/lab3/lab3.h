#ifndef LAB3_H
#define LAB3_H

#include <iostream>
using namespace std;

const int MAX_SIZE = 10;
int current_size = 0;

typedef struct Item {
    int release;
    char *string;
    struct Item *next;
} Item;

typedef struct Node {
    int key;
    struct Item *info;
} Node;

void initTable();
int printMenu();
int readGoodInt();
Node *findNode(int key);

void showTable(Node **node, int size, int rel=-1);
void addItem(int key, char str[80]);
void removeItem();
void findItem();

Node *node[MAX_SIZE];

#endif // LAB3_H

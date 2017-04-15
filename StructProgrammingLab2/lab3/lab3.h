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

class OrderedTable {
public:
    explicit OrderedTable();
    ~OrderedTable();

    bool addNode(int key);
    bool addNextItem(int key);

    Node *findNode(int key);
    Item *findItem(int key, int rel);

    Node *findBinaryNode(int key);
    Node *findBinaryItem(int key, int rel);

    bool removeNode(int key);
    bool removeItem(int key, int rel);

private:
    int current_size;
    Node *node[MAX_SIZE];
};

void initTable();
void freeTable();
int printMenu();
int readGoodInt();
Node *findNode(int key);

void showTable(Node **node, int size, int rel=-1);
void addItem(int key, char str[80]);
void removeItem();

/// Ищет по ключу ноду, если rel != -1, то определенную версию
void findItem(int key, int rel=-1);

Node *node[MAX_SIZE];

#endif // LAB3_H

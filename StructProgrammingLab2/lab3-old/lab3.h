#ifndef LAB3_H
#define LAB3_H

#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

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
    Item *findBinaryItem(int key, int rel);

    Node *removeNode(int key);
    Item *removeItem(int key, int rel);

private:
    int current_size;
    Node *node[MAX_SIZE];
};

#endif // LAB3_H

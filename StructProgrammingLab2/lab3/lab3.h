#ifndef LAB3_H
#define LAB3_H

#include <iostream>
using namespace std;

const size_t MAX_SIZE = 10;
const size_t STRING_SIZE = 80;

typedef struct Item {
    int release;
    char *string;
    struct Item *next;

    Item() : release(0), string(NULL), next(NULL) {}

} Item;

typedef struct Node {
    int key;
    struct Item *info;

    Node() : key(-1), info(NULL) {}

} Node;

class OrderedTable {
public:
    explicit OrderedTable(const char *filename);
    ~OrderedTable();

    bool addItem(int key, const char str[STRING_SIZE]);

    Node *findPlaceForNewNode(int key);
//    Node *findNode(int key);

    Item *findBinaryItem(int key, int rel);
    Node *findBinaryNode(int key);

    bool removeItem(int key, int rel);
    bool removeNode(int key);

    Node **getAllNode();
    int getCurrentSize();
    void clearTable();

    /// Serialize
    bool serialize();
    bool desirialize();

    const char *getFilename();

private:

    void calculateCurrentSize();
    Node *binarySearch(int key, size_t last_size);
    /// Значение ближайшего после поиска
    size_t closest_after_search;

    size_t current_size;
    Node *node[MAX_SIZE];
    const char *filename;
};

#endif // LAB3_H

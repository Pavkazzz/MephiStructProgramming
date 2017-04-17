#include <limits>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "lab3.h"

/*

void addItem(int key, char str[80]) {


    Node *foundNode = findNode(key);

    /// Новый key
    size_t string_length = strlen(str) + 1;

    if (foundNode->info == NULL) {
        Item *item = new Item;
        item->next = NULL;
        item->release = 0;
        item->string = (char *)malloc(string_length * sizeof(char));
        strncpy(item->string, str, string_length);
        foundNode->info = item;
        foundNode->key = key;
        current_size++;
    } else {
        /// Новый item
        Item *item = foundNode->info;
        int last_relase = item->release;

        while (item->next != NULL) {
            item = item->next;
            last_relase = item->release;
        }

        last_relase++;
        item->next = new Item;
        item->next->next = NULL;
        item->next->release = last_relase;
        item->next->string = (char *)malloc(string_length * sizeof(char));
        memcpy(item->next->string, str, string_length);
    }



}

Node *findNode(int key) {
    /// TODO: Бинарный поиск

    /// Поиск если есть
    for (int i=0; i<current_size; i++) {
        if (node[i]->info != NULL) {
            if (node[i]->key == key) {
                return node[i];
            }
        }
    }

    /// Пустое следующее
    for (int i=0; i<MAX_SIZE; i++) {
        if (node[i]->info == NULL) {
            return node[i];
        }
    }
    /// Кончились пустые значения
    /// Что делать?
    exit(1);

    //    return node[current_size];
}
void removeItem() {

}

void findItem(int key, int rel) {

    Node *node = findNode(key);

    if (node->key != key) {
        cout << "Такого ключа нет в таблице" << endl;
        return ;
    }

    /// Все версии
    if (rel == -1) {
        showTable(&node, 1);
    } else {
        showTable(&node, 1, rel);
    }

}

*/

OrderedTable::OrderedTable()
{
    for (int i=0; i<MAX_SIZE; i++) {
        node[i] = new Node;
        node[i]->key = 0;
        node[i]->info = NULL;
    }
}

OrderedTable::~OrderedTable()
{
    for (int i=0; i<MAX_SIZE; i++) {
        if (node[i]->info != NULL) {
            Item *item = node[i]->info;
            while(item != NULL) {
                Item *next_item = item->next;
                delete item;
                item = next_item;
            }
        }
        delete node[i];
    }
}

bool OrderedTable::addNode(int key)
{

    Node *node = findNode(key);
    if (node->info == NULL) {
        Item *item = new Item;
        item->next = NULL;
        item->release = 0;
        item->string = (char *)malloc(string_length * sizeof(char));
        strncpy(item->string, str, string_length);
        foundNode->info = item;
        foundNode->key = key;
        current_size++;
    }
}

bool OrderedTable::addNextItem(int key)
{

}

Node *OrderedTable::findNode(int key)
{

}

Item *OrderedTable::findItem(int key, int rel)
{

}

Node *OrderedTable::findBinaryNode(int key)
{
    /// Todo
    return findNode(key);
}

Item *OrderedTable::findBinaryItem(int key, int rel)
{

}

Node *OrderedTable::removeNode(int key)
{

}

Item *OrderedTable::removeItem(int key, int rel)
{

}

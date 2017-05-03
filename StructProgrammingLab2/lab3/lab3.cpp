#include <limits>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "lab3.h"

OrderedTable::OrderedTable(const char *filename)
{
    for (size_t i=0; i<MAX_SIZE; i++) {
        node[i] = new Node;
    }

    this->filename = filename;
    current_size = 0;
    closest_after_search = 0;
}

OrderedTable::~OrderedTable()
{
    for (size_t i=0; i<MAX_SIZE; i++) {
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

bool OrderedTable::addItem(int key, const char str[STRING_SIZE])
{
    Node *foundNode = findPlaceForNewNode(key);

    if (foundNode == NULL) {
        return false;
    }

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
        /// Add another item
//        Item *item = foundNode->info;
//        int last_relase = item->release;
//        last_relase++;

        Item *item = new Item;
        item->release = foundNode->info->release+1;
        item->next = foundNode->info;
        item->string = (char *)malloc(string_length * sizeof(char));
        strncpy(item->string, str, string_length);
        foundNode->info = item;
    }
    /// TODO: return status if fail
    return true;
}


//Item *OrderedTable::findItem(int key, int rel)
//{
//    Node *node = findNode(key);

//    /// found node
//    if (node->key == key && node->info != NULL) {
//        Item *item = node->info;
//        while(item != NULL) {
//            if(item->release == rel) {
//                return item;
//            }
//            item = item->next;
//        }
//    }
//    return NULL;
//}

//Node *OrderedTable::findNode(int key)
//{

//    /// search in added
//    for (int i=0; i<current_size; i++) {
//        if (node[i]->info != NULL) {
//            if (node[i]->key == key) {
//                return node[i];
//            }
//        }
//    }

//    /// find the first empty
//    for (int i=0; i<MAX_SIZE; i++) {
//        if (node[i]->info == NULL) {
//            return node[i];
//        }
//    }
//    /// All field's are filled
//    /// What to do?
//    return NULL;
//}


Node *OrderedTable::findPlaceForNewNode(int key)
{
    if (current_size == 0 ) {
        return node[0];
    }

    if (current_size == MAX_SIZE) {
        return NULL;
    }
    /// Если нашли с таким ключом
    Node *node_b = binarySearch(key, current_size);
    if (node_b != NULL) {
        return node_b;
    }

    for (size_t j=current_size; j>closest_after_search; j--) {
//        node[j] = node[j-1];
        memcpy(node[j], node[j-1], sizeof(Node));
    }
    node[closest_after_search]->info = NULL;
    node[closest_after_search]->key = -1;


    return node[closest_after_search];

}

Item *OrderedTable::findBinaryItem(int key, int rel)
{
    Node *node = findBinaryNode(key);

    /// found node
    if (node != NULL) {
        Item *item = node->info;
        while(item != NULL) {
            if(item->release == rel) {
                return item;
            }
            item = item->next;
        }
    }
    return NULL;
}

Node *OrderedTable::findBinaryNode(int key)
{
    return binarySearch(key, current_size);
}


Node *OrderedTable::binarySearch(int key, size_t last_size)
{
    size_t first = 0;
    size_t last = last_size;
    if (first == last) {
        closest_after_search = 0;
        return NULL;
    }

    if (key < node[first]->key) {
        closest_after_search = 0;
        return NULL;
    }

    if (key > node[last-1]->key) {
        closest_after_search = last;
        return NULL;
    }


    while (first < last) {
        size_t mid = first + (last - first) / 2;
        if (key <= node[mid]->key) {
            last = mid;
        } else {
            first = mid + 1;
        }
    }

    if (node[last] != NULL && node[last]->key == key) {
        closest_after_search = last;
        return node[last];
    }

    closest_after_search = last;
    return NULL;
}

bool OrderedTable::removeItem(int key, int rel)
{
    Node *node = findBinaryNode(key);
    if (node != NULL) {
        Item *item = node->info;
        Item *prev_item = NULL;

        while (item != NULL) {
            if (item->release == rel) {

                if (prev_item == NULL) {
                    node->info = item->next;
                    if (node->info == NULL) {
                        current_size--;
                        node->key = -1;
                    }
                } else {
                    prev_item->next = item->next;
                }
//                prev_item = item;
                delete item;
                return true;
            }
            item->release--;
            prev_item = item;
            item = item->next;
        }
    }

    return false;
}

bool OrderedTable::removeNode(int key)
{
    Node *node = findBinaryNode(key);
    if (node != NULL) {
        Item *item = node->info;
        Item *next_item = NULL;
        while(item != NULL) {
            next_item = item->next;
            delete item;
            item = next_item;
        }

        for (size_t j=current_size-1; j>closest_after_search; j--) {
            memcpy(this->node[j-1], this->node[j], sizeof(Node));
        }

        this->node[current_size-1]->info = NULL;
        this->node[current_size-1]->key = -1;


        current_size--;
    } else {
        /// No item with this key
        return false;
    }

    return true;
}

Node **OrderedTable::getAllNode()
{
    return node;
}

int OrderedTable::getCurrentSize()
{
    return current_size;
}

void OrderedTable::clearTable()
{
    for (size_t i=0; i<MAX_SIZE; i++) {
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

    for (size_t i=0; i<MAX_SIZE; i++) {
        node[i] = new Node;
        node[i]->key = 0;
        node[i]->info = NULL;
    }

    current_size = 0;

}

bool OrderedTable::serialize()
{
    FILE *ptr_to_file;
    ptr_to_file = fopen(filename, "wb");
    if (!ptr_to_file) {
        return false;
    }

    for (size_t i=0; i<MAX_SIZE; i++) {
        fwrite(&node[i]->key, sizeof(node[i]->key), 1, ptr_to_file);

        size_t pr_node;
        if (node[i]->info == NULL) {
            pr_node = 0;
        } else {
            pr_node = 1;
        }
        fwrite(&pr_node, sizeof(pr_node), 1, ptr_to_file);

        Item *item = node[i]->info;
        while(item != NULL) {
            size_t len = strlen(item->string) + 1;
            fwrite(&len, sizeof(size_t), 1, ptr_to_file);
            fwrite(item->string, len, 1, ptr_to_file);
            fwrite(&item->release, sizeof(item->release), 1, ptr_to_file);
            size_t pr_end_item = 0;
            if (item->next == NULL) {
                pr_end_item = 1;
            }
            fwrite(&pr_end_item, sizeof(size_t), 1, ptr_to_file);
            item = item->next;
        }

    }
    pclose(ptr_to_file);
    return true;
}

bool OrderedTable::desirialize()
{
    FILE *ptr_to_file;
    ptr_to_file = fopen(filename, "rb");

    if (!ptr_to_file) {
        return false;
    }

    clearTable();

    for (size_t i=0; i<MAX_SIZE; i++) {
        fread(&node[i]->key, sizeof(node[i]->key), 1, ptr_to_file);
        node[i]->info = NULL;
        size_t pr_node;
        fread(&pr_node, sizeof(pr_node), 1, ptr_to_file);
        if (pr_node == 1) {

            Item *last_item = NULL;
            size_t str_len;
            for (;;) {
                Item *item = new Item;
                if (node[i]->info == NULL) {
                    node[i]->info = item;
                } else {
                    last_item->next = item;
                }
                fread(&str_len, sizeof(str_len), 1, ptr_to_file);
                item->string = new char[str_len];
                fread(item->string, str_len, 1, ptr_to_file);
                fread(&item->release, sizeof(item->release), 1, ptr_to_file);



                size_t pr_end_item;
                fread(&pr_end_item, sizeof(pr_end_item), 1, ptr_to_file);
                if (pr_end_item > 0) {
                    break;
                } else {
                    last_item = item;
                }
            }
        }
    }
    calculateCurrentSize();

    pclose(ptr_to_file);
    return true;
}

const char *OrderedTable::getFilename()
{
    return filename;
}

void OrderedTable::calculateCurrentSize()
{
    current_size = 0;
    for (size_t i=0; i<MAX_SIZE; i++) {
        if (node[i]->info != NULL) {
            current_size++;
        }
    }
}


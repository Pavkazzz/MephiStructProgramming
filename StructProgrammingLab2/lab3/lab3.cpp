#include <limits>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "lab3.h"

void initTable() {
    for (int i=0; i<MAX_SIZE; i++) {
        node[i] = new Node;
        node[i]->key = 0;
        node[i]->info = NULL;
    }
}

int readGoodInt()
{
    int i;
    while (!(cin >> i)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Плохое число, введите еще раз" << endl;
    }

    return i;
}

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

void findItem() {

    cout << "Введите ключ <int>:" << endl;
    int i = readGoodInt();

    cout << "Введите версию: <int> или все значения<int:-1>" << endl;
    int rel = readGoodInt();


    Node *node = findNode(i);

    if (node->key != i) {
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

void showTable(Node **node, int size, int rel) {
    if (size == 0) {
        cout << "Таблица пустая" << endl;
    } else {
        cout << "Таблица:" << endl;
        for (int i=0; i<size; i++) {
            if (node[i]->info != NULL) {
                Item *current_item = node[i]->info;
                cout << "    Ключ: " << node[i]->key << endl;
                while (current_item != NULL) {
                    if (rel == -1 || rel == current_item->release) {

                        cout << "        Версия: " << current_item->release << \
                                " Значение: " << current_item->string << endl;
                    }
                    current_item = current_item->next;
                }
            }
        }
    }
}

int printMenu() {
    cout << "0 - Выход, ";
    cout << "1 - Вывод таблицы, ";
    cout << "2 - Добавление в таблицу, ";
    cout << "3 - Удаление из таблицы, ";
    cout << "4 - Поиск в таблице по ключу" << endl;
    int i = readGoodInt();
    return i;
}

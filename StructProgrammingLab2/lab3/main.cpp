#include "lab3.cpp"


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

int printMenu() {
    cout << "------------" << endl;
    cout << "0 - Выход ";
    cout << "1 - Вывод таблицы ";
    cout << "2 - Добавление в таблицу " << endl;
    cout << "3 - Удаление из таблицы ";
    cout << "4 - Поиск в таблице по ключу ";
    cout << "5 - Имя файла" << endl;
    int i = readGoodInt();
    return i;
}




void showTable(Node **node, int size) {
    if (size == 0) {
        cout << "Таблица пустая" << endl;
    } else {
        cout << "Таблица:" << endl;
        for (int i=0; i<size; i++) {
            if (node[i]->info != NULL) {
                Item *current_item = node[i]->info;
                cout << "    Ключ: " << node[i]->key << endl;
                while (current_item != NULL) {

                    cout << "        Версия: " << current_item->release << \
                            " Значение: " << current_item->string << endl;

                    current_item = current_item->next;
                }
            }
        }
    }
}

void showCell(Item *item) {
    if (item != NULL) {
        cout << "Найден эллемент" << endl;
        cout << "    Версия: " << item->release << \
                " Значение: " << item->string << endl;
    } else {
        cout << "Не найден эллемент" << endl;
    }
}

/// Отображаем строку
void showRow(Node *node) {
    if (node != NULL) {
        showTable(&node, 1);
    } else {
        cout << "Не найден ключ";
    }
}

int main(/*int argc, char *argv[]*/)
{

    OrderedTable *table = new OrderedTable("my_table.bin");

    table->desirialize();

    int res = printMenu();
    while(res != 0) {

        int key = -1;
        char str[STRING_SIZE] = {0};
        int rel = 0;

        switch (res) {
        case 1:
            /// Вывод таблицы
            showTable(table->getAllNode(), table->getCurrentSize());
            break;
        case 2:
            /// Добавление в таблицу
            cout << "Введите ключ <int>:" << endl;
            key = readGoodInt();

            cout << "Введите значение <char[" << STRING_SIZE << "]>:" << endl;
            cin >> str;

            table->addItem(key, str);
            table->serialize();
            break;
        case 3:
            /// Удаление из таблицы
            cout << "Введите ключ <int>:" << endl;
            key = readGoodInt();

            cout << "Введите версию: <uint> или все значения<-1>" << endl;
            rel = readGoodInt();

            if (rel == -1) {
                if (table->removeNode(key)) {
                    cout << "Строка успешно удалена" << endl;
                }
            } else {
                if (rel >= 0) {
                    if (table->removeItem(key, rel)) {
                        cout << "Эллемент успешно удален из таблицы" << endl;
                    }
                }
            }
            break;
        case 4:
            /// Поиск в таблице
            cout << "Введите ключ <int>:" << endl;
            key = readGoodInt();

            cout << "Введите версию: <uint> или все значения<-1>" << endl;
            rel = readGoodInt();

            if (rel == -1) {
                showRow(table->findBinaryNode(key));
            } else {
                if (rel >= 0) {
                    showCell(table->findBinaryItem(key, rel));
                }
            }
            break;
        case 5:
            cout << "Имя файла: " << table->getFilename() << endl;
            break;
        default:
            cout << "Нет такого пункта меню" << endl;
            break;
        }

        res = printMenu();
    }

    table->serialize();
    delete table;
    return 0;
}

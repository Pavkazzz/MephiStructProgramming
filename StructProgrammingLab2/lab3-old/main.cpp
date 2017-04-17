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
    cout << "0 - Выход, ";
    cout << "1 - Вывод таблицы, ";
    cout << "2 - Добавление в таблицу, ";
    cout << "3 - Удаление из таблицы, ";
    cout << "4 - Поиск в таблице по ключу" << endl;
    int i = readGoodInt();
    return i;
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


int main(/*int argc, char *argv[]*/)
{

    initTable();

    int res = printMenu();
    while(res != 0) {

        int key = -1;
        char str[80] = {0};
        int rel = 0;

        switch (res) {
        case 1:
            showTable(node, current_size);
            break;
        case 2:

            cout << "Введите ключ <int>:" << endl;
            key = readGoodInt();

            cout << "Введите значение <char[80]>:" << endl;
            cin >> str;

            addItem(key, str);
            break;
        case 3:
            removeItem();
            break;
        case 4:
            cout << "Введите ключ <int>:" << endl;
            key = readGoodInt();

            cout << "Введите версию: <int> или все значения<int:-1>" << endl;
            rel = readGoodInt();

            findItem(key, rel);
            break;
        default:
            cout << "Нет такого пункта меню" << endl;
            break;
        }

        res = printMenu();
    }

    return 0;
}

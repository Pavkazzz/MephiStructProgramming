#include <lab3.cpp>

int main(/*int argc, char *argv[]*/)
{

    initTable();

    int res = printMenu();
    while(res != 0) {

        int key = -1;
        char str[80] = {0};

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
            findItem();
            break;
        default:
            cout << "Нет такого пункта меню" << endl;
            break;
        }

        res = printMenu();
    }

    return 0;
}

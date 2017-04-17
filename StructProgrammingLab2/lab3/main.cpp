#include "lab3.cpp"


int readGoodInt()
{
    int i;
    while (!(cin >> i)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "������ �����, ������� ��� ���" << endl;
    }

    return i;
}

int printMenu() {
    cout << "------------" << endl;
    cout << "0 - ����� ";
    cout << "1 - ����� ������� ";
    cout << "2 - ���������� � ������� " << endl;
    cout << "3 - �������� �� ������� ";
    cout << "4 - ����� � ������� �� �����" << endl;
    int i = readGoodInt();
    return i;
}




void showTable(Node **node, int size) {
    if (size == 0) {
        cout << "������� ������" << endl;
    } else {
        cout << "�������:" << endl;
        for (int i=0; i<size; i++) {
            if (node[i]->info != NULL) {
                Item *current_item = node[i]->info;
                cout << "    ����: " << node[i]->key << endl;
                while (current_item != NULL) {

                    cout << "        ������: " << current_item->release << \
                            " ��������: " << current_item->string << endl;

                    current_item = current_item->next;
                }
            }
        }
    }
}

void showCell(Item *item) {
    if (item != NULL) {
        cout << "������ ��������" << endl;
        cout << "    ������: " << item->release << \
                " ��������: " << item->string << endl;
    } else {
        cout << "�� ������ ��������" << endl;
    }
}

/// ���������� ������
void showRow(Node *node) {
    if (node != NULL) {
        showTable(&node, 1);
    } else {
        cout << "�� ������ ����";
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
            /// ����� �������
            showTable(table->getAllNode(), table->getCurrentSize());
            break;
        case 2:
            /// ���������� � �������
            cout << "������� ���� <int>:" << endl;
            key = readGoodInt();

            cout << "������� �������� <char[" << STRING_SIZE << "]>:" << endl;
            cin >> str;

            table->addItem(key, str);
            table->serialize();
            break;
        case 3:
            /// �������� �� �������
            cout << "������� ���� <int>:" << endl;
            key = readGoodInt();

            cout << "������� ������: <uint> ��� ��� ��������<-1>" << endl;
            rel = readGoodInt();

            if (rel == -1) {
                if (table->removeNode(key)) {
                    cout << "������ ������� �������" << endl;
                }
            } else {
                if (rel >= 0) {
                    if (table->removeItem(key, rel)) {
                        cout << "�������� ������� ������ �� �������" << endl;
                    }
                }
            }
            break;
        case 4:
            /// ����� � �������
            cout << "������� ���� <int>:" << endl;
            key = readGoodInt();

            cout << "������� ������: <uint> ��� ��� ��������<-1>" << endl;
            rel = readGoodInt();

            if (rel == -1) {
                showRow(table->findBinaryNode(key));
            } else {
                if (rel >= 0) {
                    showCell(table->findBinaryItem(key, rel));
                }
            }
            break;
        default:
            cout << "��� ������ ������ ����" << endl;
            break;
        }

        res = printMenu();
    }

    table->serialize();
    delete table;
    return 0;
}

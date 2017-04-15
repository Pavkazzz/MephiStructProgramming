#include <QString>
#include <QtTest>
#include "../../lab3.cpp"

class Lab3testsTest : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void initTestCase();
    void addDataTestCase();
    void findItemTestCase();
//    void removeDataTestCase();
    void cleanupTestCase();
};

void Lab3testsTest::initTestCase()
{
    initTable();
    QCOMPARE(current_size, 0);
    QCOMPARE(MAX_SIZE, 10);
}


void Lab3testsTest::addDataTestCase()
{
    int key = 1;
    char str1[80] = {"qwe"};
    char str2[80] = {"asd"};
    char str3[80] = {"zxc"};

    int key2 = 2;
    char str4[80] = {"gfh"};

    addItem(key, str1);
    addItem(key, str2);
    addItem(key, str3);

    addItem(key2, str4);

//    showTable(node, current_size);

    QCOMPARE(node[0]->info->string, str1);
    QCOMPARE(node[0]->info->next->string, str2);
    QCOMPARE(node[0]->info->next->next->string, str3);

    QCOMPARE(node[1]->info->string, str4);
}

void Lab3testsTest::findItemTestCase()
{
    findItem(1, -1);
}

//void Lab3testsTest::removeDataTestCase()
//{
//    removeItem();
//}


void Lab3testsTest::cleanupTestCase()
{
    freeTable();
}

QTEST_APPLESS_MAIN(Lab3testsTest)

#include "tst_lab3teststest.moc"

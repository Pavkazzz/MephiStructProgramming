#include <QString>
#include <QtTest>
#include "../../lab3.h"

int key1 = 5;
char str1[80] = {"qwe"};
char str2[80] = {"asd"};
char str3[80] = {"zxc"};

int key2 = 3;
char str4[80] = {"gfh"};
char str5[80] = {"rty"};

int key3 = 1;
char str6[80] = {"cvb"};

class Lab3testsTest : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void initTestCase();
    void addDataTestCase();
    void removeDataTestCase();

    void usage1TestCase();

    void fileTestCase();

    void cleanupTestCase();

private:
    OrderedTable *table;
};

void Lab3testsTest::initTestCase()
{
    table = new OrderedTable("my_test_table.bin");

    QCOMPARE(MAX_SIZE, (size_t)10);
    QCOMPARE(STRING_SIZE, (size_t)80);
}

void Lab3testsTest::cleanupTestCase()
{
    delete table;
}

void Lab3testsTest::addDataTestCase()
{
    table->addItem(key1, str1);
    table->addItem(key1, str2);
    table->addItem(key1, str3);
    table->addItem(key2, str4);
    table->addItem(key2, str5);
    table->addItem(key3, str6);



    QCOMPARE(table->findBinaryItem(key1, 0)->string, str1);
    QCOMPARE(table->findBinaryItem(key1, 1)->string, str2);
    QCOMPARE(table->findBinaryItem(key1, 2)->string, str3);

    QCOMPARE(table->findBinaryItem(key2, 0)->string, str4);
    QCOMPARE(table->findBinaryItem(key2, 1)->string, str5);

}


void Lab3testsTest::removeDataTestCase()
{
    table->clearTable();
    table->addItem(key1, str1);
    table->addItem(key1, str2);
    table->addItem(key1, str3);
    table->addItem(key2, str4);
    table->addItem(key2, str5);

    /// Remove node
    QCOMPARE(table->findBinaryItem(key2, 0)->string, str4);
    QCOMPARE(table->findBinaryItem(key2, 1)->string, str5);
    QCOMPARE(table->findBinaryNode(key2)->key, key2);
    table->removeNode(key2);
    QVERIFY(table->findBinaryItem(key2, 1) == NULL);
    QVERIFY(table->findBinaryItem(key2, 0) == NULL);
    QVERIFY(table->findBinaryNode(key2) == NULL);

    QCOMPARE(table->findBinaryNode(key1)->key, key1);
    QCOMPARE(table->findBinaryItem(key1, 1)->string, str2);
    /// Remove from middle of the list
    table->removeItem(key1, 1);
    qDebug() << table->findBinaryItem(key1, 0);
    qDebug() << table->findBinaryItem(key1, 1);
    qDebug() << table->findBinaryItem(key1, 2);

    QCOMPARE(table->findBinaryItem(key1, 1)->string, str3);

    /// Remove from end of the list
    QCOMPARE(table->findBinaryItem(key1, 1)->string, str3);
    table->removeItem(key1, 1);
    QVERIFY(table->findBinaryItem(key1, 1) == NULL);

    /// Remove first item of node
    table->addItem(key1, str2);
    table->addItem(key1, str3);

    QCOMPARE(table->findBinaryItem(key1, 0)->string, str1);
    table->removeItem(key1, 0);
    QCOMPARE(table->findBinaryItem(key1, 0)->string, str2);

}

void Lab3testsTest::usage1TestCase()
{
    table->clearTable();
    QCOMPARE(table->getCurrentSize(), 0);

    table->addItem(1, "qwe");
    table->removeItem(1, 0);

    QCOMPARE(table->getCurrentSize(), 0);
}

void Lab3testsTest::fileTestCase()
{
    table->clearTable();
    table->addItem(key1, str1);
    table->addItem(key1, str2);
    table->addItem(key2, str3);
    table->addItem(key2, str4);

    QCOMPARE(table->findBinaryItem(key1, 0)->string, str1);
    QCOMPARE(table->findBinaryItem(key1, 1)->string, str2);
    QCOMPARE(table->findBinaryItem(key2, 0)->string, str3);
    QCOMPARE(table->findBinaryItem(key2, 1)->string, str4);

    table->serialize();
    table->clearTable();
    table->desirialize();


    QCOMPARE(table->findBinaryItem(key1, 0)->string, str1);
    QCOMPARE(table->findBinaryItem(key1, 1)->string, str2);
    QCOMPARE(table->findBinaryItem(key2, 0)->string, str3);
    QCOMPARE(table->findBinaryItem(key2, 1)->string, str4);
}



QTEST_APPLESS_MAIN(Lab3testsTest)

#include "tst_lab3teststest.moc"

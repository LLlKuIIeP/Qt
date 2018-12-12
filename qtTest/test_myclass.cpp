#include "test_myclass.hpp"

Test_MyClass::Test_MyClass(QObject *parent) : QObject(parent)
{

}

// ------------------------------------------------------------------------------------------------------------
void Test_MyClass::min()
{
    MyClass maClass;

    //Тесты на QCOMPARE
    QCOMPARE(maClass.min(25, 0), 0);
    QCOMPARE(maClass.min(-12, -5), -12);
    QCOMPARE(maClass.min(2007, 2007), 2007);
    QCOMPARE(maClass.min(-12, 5), -12);


    //для тестов с передачей данных должен быть метод [имя_тестируемого_метода]_data например min_data()
    //имена должны совпадать QTest::addColumn<int>("arg1") и в макросе QFETCH(int, arg1)
    QFETCH(int, arg1);
    QFETCH(int, arg2);
    QFETCH(int, result);

    QCOMPARE(maClass.min(arg1, arg2), result);
}

// ------------------------------------------------------------------------------------------------------------
void Test_MyClass::max()
{
    MyClass maClass;

    //Тесты на QCOMPARE
    QCOMPARE(maClass.max(25, 0), 25);
    QCOMPARE(maClass.max(-12, -5), -5);
    QCOMPARE(maClass.max(2007, 2007), 2007);
    QCOMPARE(maClass.max(-12, 5), 5);

    //для тестов с передачей данных должен быть метод [имя_тестируемого_метода]_data например min_data()
    //имена должны совпадать QTest::addColumn<int>("arg1") и в макросе QFETCH(int, arg1)
    QFETCH(int, arg1);
    QFETCH(int, arg2);
    QFETCH(int, result);

    QCOMPARE(maClass.max(arg1, arg2), result);
}

void Test_MyClass::min_data()
{
    //создается таблица со строками данных
    QTest::addColumn<int>("arg1");
    QTest::addColumn<int>("arg2");
    QTest::addColumn<int>("result");

    //добавляем строки в таблицу
    QTest::addRow("min_test1") << 25 << 0 << 0;
    QTest::addRow("min_test2") << -12 << -5 << -12;
    QTest::addRow("min_test3") << 2007 << 2007 << 2007;
    QTest::addRow("min_test4") << -12 << 5 << -12;
}

void Test_MyClass::max_data()
{
    //создается таблица со строками данных
    QTest::addColumn<int>("arg1");
    QTest::addColumn<int>("arg2");
    QTest::addColumn<int>("result");

    //добавляем строки в таблицу
    QTest::addRow("max_test1") << 25 << 0 << 25;
    QTest::addRow("max_test2") << -12 << -5 << -5;
    QTest::addRow("max_test3") << 2007 << 2007 << 2007;
    QTest::addRow("max_test4") << -12 << 5 << 5;
}

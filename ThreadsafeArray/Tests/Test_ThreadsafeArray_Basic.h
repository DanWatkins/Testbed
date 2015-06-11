#include "AutoTest.h"
#include <ThreadsafeArray.h>

/**
 * @brief Verifies that ThreadsafeArray performs operations
 * correctly when used inside a single thread.
 */
class Test_ThreadsafeArray_Basic : public QObject
{
    Q_OBJECT

private slots:
    void addCheckSize()
    {
        ThreadsafeArray<int> a;
        a.add(4);
        QCOMPARE(1, a.count());
        a.add(5);
        a.add(0);
        QCOMPARE(3, a.count());
    }

    void randomAccess()
    {
        ThreadsafeArray<int> a;
        a.add(78);
        a.add(3957);

        QCOMPARE(a[0], 78);
        QCOMPARE(a[1], 3957);
    }


    void removeCheckCapacity1()
    {
        ThreadsafeArray<int> a;
        QCOMPARE(a.capacity(), 0);
        a.add(100);
        a.add(120);
        a.add(140);
        QCOMPARE(a.count(), 3);

        a.remove(1);
        QCOMPARE(a.count(), 2);
        QCOMPARE(a.capacity(), 3);
        QCOMPARE(100, a[0]);
        QCOMPARE(140, a[1]);
    }


    void removeCheckCapacity2()
    {
        ThreadsafeArray<int> a;
        a.add(50);
        a.add(60);
        a.add(70);
        a.add(80);
        a.add(90);
        a.add(100);
        QCOMPARE(a.count(), 6);
        QCOMPARE(a.capacity(), 6);

        a.remove(3);
        QCOMPARE(a.count(), 5);
        QCOMPARE(a.capacity(), 6);
        QCOMPARE(a[0], 50);
        QCOMPARE(a[1], 60);
        QCOMPARE(a[2], 70);
        QCOMPARE(a[3], 90);
        QCOMPARE(a[4], 100);

        a.remove(0);
        QCOMPARE(a.count(), 4);
        QCOMPARE(a.capacity(), 6);
        QCOMPARE(a[0], 60);
        QCOMPARE(a[1], 70);
        QCOMPARE(a[2], 90);
        QCOMPARE(a[3], 100);
    }
};

DECLARE_TEST(Test_ThreadsafeArray_Basic)

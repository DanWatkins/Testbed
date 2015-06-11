#include "AutoTest.h"
#include <ThreadsafeArray.h>

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

        QCOMPARE(78, a[0]);
        QCOMPARE(3957, a[1]);
    }
};

DECLARE_TEST(Test_ThreadsafeArray_Basic)

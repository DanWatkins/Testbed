#ifndef ThreadsafeArray_h
#define ThreadsafeArray_h

#include <QtCore/QMutex>
#include <cstring>

template<typename T>
class ThreadsafeArray
{
public:
    void add(const T& element)
    {
        if (mData)
        {
            T *old = mData;
            mData = new T[mCount+1];

            std::memcpy(mData, old, mCount*sizeof(T));

            delete [] old;
        }
        else
            mData = new T[1];

        mData[mCount] = element;
        mCount++;
    }


    int count() const
    {
        return mCount;
    }


    const T& operator[](int index) const
    {
        return mData[index];
    }

private:
    int mCount = 0;
    T *mData = nullptr;
};

#endif

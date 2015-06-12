#ifndef ThreadsafeArray_h
#define ThreadsafeArray_h

#include <QtCore/QMutex>
#include <cstring>

/**
 * I declare this impossible for now. How can we reasonably support operator[] and remove(int)
 * without allowing users to blow their whole foot off easily?
 */
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
        mCapacity++;
    }


    void remove(int index)
    {
        for (int i=index; i < mCount+1; i++)
        {
            mData[i] = mData[i+1];
        }

        mCount--;
    }


    int count() const { return mCount; }


    int capacity() const { return mCapacity; }


    const T& operator[](int index) const { return mData[index]; }

private:
    int mCount = 0;
    int mCapacity = 0;
    T *mData = nullptr;
};

#endif

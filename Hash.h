#ifndef Hash_h
#define Hash_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <functional>

template <typename Key, typename Value>
class Hash
{
public:
    Hash(uint16_t bucketCount = 0, uint16_t valuesPerBucket = 50)
        : mData(0)
    {
        if (bucketCount)
            rebucket(bucketCount, valuesPerBucket);
    }
    bool insert(const Key &key, Value &&value)
    {
        bool ok;
        void *val = findOrInsert(key, &ok);
        if (ok) {

        }

        const std::hash<Key> hash;
        const size_t h = hash(key);
        const uint16_t bucketIdx = h % bucketCount();
    }
protected:
    unsigned char *data() const { return mData; }
private:
    void *findOrInsert(const Key &key, bool *ok)
    {
        const std::hash<Key> hash;
        const size_t h = hash(key);
        const uint16_t bucketIdx = h % bucketCount();
    }
    int findInBucket(void *bucket, const Key &key)
    {
        uint16_t c = valuesPerBucket();
        while (c) {
    }
    void rebucket(uint16_t newBucketCount, uint16_t newValuesPerBucket)
    {
        unsigned char *old = 0;
        uint16_t oldBucketCount = 0, oldValuesPerBucket = 0;
        if (mData) {
            // needs to be done
            // oldBucketCount = bucketCount();
            // const int size = HeaderSize + bucketCount() * bytesPerBucket();
            // old = malloc(size);
            // memcpy(old, mData, size);
        }
        const int size = HeaderSize + (newBucketCount * ((newValuesPerBucket * (sizeof(Value) + sizeof(Key))) + sizeof(uint16_t)));
        mData = realloc(size);
        memset(mData, 0, size);
        *reinterpret_cast<uint16_t*>(mData) = newBucketCount;
        *reinterpret_cast<uint16_t*>(mData + sizeof(uint16_t)) = newValuesPerBucket;
    }
    virtual unsigned char *realloc(int size) { return reinterpret_cast<unsigned char*>(::realloc(data(), size)); }
    enum {
        BucketCountIndex = 0, // sizeof(uint16_t)
        ValuesPerBucketIndex = sizeof(uint16_t),
        HeaderSize = sizeof(uint16_t) * 2,
    };
    uint16_t bucketCount() const { assert(mData); return *reinterpret_cast<uint16_t*>(mData); }
    uint16_t valuesPerBucket() const { return reinterpret_cast<uint16_t*mData[
    int bytesPerBucket() const { return (sizeof(Value) + sizeof(Key)) *  bucketSize(); }
    unsigned char *bucket(uint16_t bucketIdx) const { return bucketsPtr() + (bytesPerBucket() * bucketIdx); }
    Value *value(uint16_t bucketIdx, int valueIdx) const {
        unsigned char *b = bucket(bucketIdx);
        b += sizeof(uint16_t);
        return b[valueIdx];
    }
    unsigned char *bucketsPtr() { return mData + HeaderSize; }

    unsigned char *mData;
};

#endif

#ifndef DATASTRUCTURES_CHAINING_HASHMAP_H
#define DATASTRUCTURES_CHAINING_HASHMAP_H

#include <algorithm>
#include <vector>
#include <cstddef>
#include <iostream>


using std::vector;

template <typename KeyObject, typename ValObject>
class ChainingHashMap {
public:
    ChainingHashMap(size_t size = 64, double threshold = 0.75) : size{size},
                                                                 threshold{threshold},
                                                                 buckets(size) {}

    void put(KeyObject key, ValObject val) {
        if (loadFactor() >= threshold) {
            rehash();
        }

        auto index = getIndex(key);

        auto bucketIndex = std::find(buckets[index].begin(), buckets[index].end(), key);

        if (bucketIndex == buckets[index].end()) {
            buckets[index].push_back(node{key, val});
            count++;
        } else {
            (*bucketIndex).val = val;
        }
    }

    ValObject get(KeyObject key) {
        auto index = getIndex(key);
        auto bucketIndex = std::find(buckets[index].begin(), buckets[index].end(), key);

        if (bucketIndex == buckets[index].end()) {
            return nullptr;
        } else {
            return (*bucketIndex).val;
        }
    }

    void del(KeyObject key) {
        auto index = getIndex(key);
        auto bucketIndex = std::find(buckets[index].begin(), buckets[index].end(), key);

        if (bucketIndex == buckets[index].end()) {
            return;
        } else {
            buckets[index].erase(bucketIndex);
            --count;
        }
    }


private:
    void rehash() {
        size <<= 1;

        vector<Bucket> newBuckets(size);

        for (auto bucket : buckets) {
            for (auto node : bucket) {
                auto index = getIndex(node.key);
                newBuckets[index].push_back(node);
            }
        }

        buckets = std::move(newBuckets);
    }

    size_t getIndex(KeyObject key) {
        return hash(key) & (size - 1);
    }

    inline double loadFactor() {
        return (double) count / (double) size;
    }

    struct node {
        KeyObject key;
        ValObject val;

        bool operator==(KeyObject other) {
            return key == other;
        }
    };

    typedef vector<node> Bucket;

    double threshold;

    size_t count;
    size_t size;
    vector<Bucket> buckets;

    std::hash<KeyObject> hash;
};

#endif //DATASTRUCTURES_CHAINING_HASHMAP_H

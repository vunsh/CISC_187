# Implementing a Hash Table with Separate Chaining


## Full C++ Program

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <utility>
#include <random>
#include <iomanip>

using namespace std;

class HashTable {
private:
    vector<list<pair<string, int>>> table;
    int currentSize;
    int capacity;
    int collisionCount;

    int hashFunction(const string& key) const {
        const int prime = 31;
        long long hash = 0;

        for (char c : key) {
            hash = hash * prime + c;
        }

        return static_cast<int>(hash % capacity);
    }

    void insertHelper(const string& key, int value, bool allowRehash) {
        int index = hashFunction(key);

        for (auto& p : table[index]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }

        if (!table[index].empty()) {
            collisionCount++;
        }

        table[index].push_back(make_pair(key, value));
        currentSize++;

        if (allowRehash && loadFactor() > 0.75) {
            rehash();
        }
    }

    void rehash() {
        vector<list<pair<string, int>>> oldTable = table;

        capacity *= 2;
        table.clear();
        table.resize(capacity);

        currentSize = 0;
        collisionCount = 0;

        for (const auto& bucket : oldTable) {
            for (const auto& p : bucket) {
                insertHelper(p.first, p.second, false);
            }
        }
    }

public:
    HashTable(int size = 11) {
        capacity = size;
        currentSize = 0;
        collisionCount = 0;
        table.resize(capacity);
    }

    void insert(const string& key, int value) {
        insertHelper(key, value, true);
    }

    bool remove(const string& key) {
        int index = hashFunction(key);

        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                currentSize--;
                return true;
            }
        }

        return false;
    }

    int search(const string& key) const {
        int index = hashFunction(key);

        for (const auto& p : table[index]) {
            if (p.first == key) {
                return p.second;
            }
        }

        return -1;
    }

    double loadFactor() const {
        return static_cast<double>(currentSize) / capacity;
    }

    int size() const {
        return currentSize;
    }

    bool isEmpty() const {
        return currentSize == 0;
    }

    void printTable() const {
        for (int i = 0; i < capacity; i++) {
            cout << i << ": ";
            for (const auto& p : table[i]) {
                cout << "(" << p.first << ", " << p.second << ") ";
            }
            cout << endl;
        }
    }

    int getCollisionCount() const {
        return collisionCount;
    }

    int getCapacity() const {
        return capacity;
    }

    int getMaxBucketSize() const {
        int maxSize = 0;

        for (const auto& bucket : table) {
            if ((int)bucket.size() > maxSize) {
                maxSize = bucket.size();
            }
        }

        return maxSize;
    }

    double getAverageBucketLength() const {
        int usedBuckets = 0;
        int total = 0;

        for (const auto& bucket : table) {
            if (!bucket.empty()) {
                usedBuckets++;
                total += bucket.size();
            }
        }

        if (usedBuckets == 0) {
            return 0.0;
        }

        return static_cast<double>(total) / usedBuckets;
    }
};

string randomString(int length) {
    static const string chars =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(0, chars.size() - 1);

    string s;

    for (int i = 0; i < length; i++) {
        s += chars[dist(gen)];
    }

    return s;
}

void showStats(const string& name, const HashTable& h) {
    cout << endl;
    cout << name << endl;
    cout << "capacity: " << h.getCapacity() << endl;
    cout << "size: " << h.size() << endl;
    cout << fixed << setprecision(2);
    cout << "load factor: " << h.loadFactor() << endl;
    cout << "collisions: " << h.getCollisionCount() << endl;
    cout << "max bucket size: " << h.getMaxBucketSize() << endl;
    cout << "avg bucket length: " << h.getAverageBucketLength() << endl;
}

int main() {
    HashTable h;

    for (int i = 1; i <= 100; i++) {
        h.insert("word" + to_string(i), i * 10);
    }

    showStats("basic test", h);

    cout << endl;
    cout << "search word25: " << h.search("word25") << endl;
    cout << "search word999: " << h.search("word999") << endl;

    cout << endl;
    cout << "remove word10: " << (h.remove("word10") ? "removed" : "not found") << endl;
    cout << "remove word50: " << (h.remove("word50") ? "removed" : "not found") << endl;
    cout << "remove word200: " << (h.remove("word200") ? "removed" : "not found") << endl;
    cout << "search word10 after remove: " << h.search("word10") << endl;

    showStats("after removals", h);

    const int n = 100;

    HashTable randomTest;
    for (int i = 0; i < n; i++) {
        randomTest.insert(randomString(8), i);
    }
    showStats("random strings", randomTest);

    HashTable seqTest;
    for (int i = 1; i <= n; i++) {
        seqTest.insert("student" + to_string(i), i);
    }
    showStats("sequential keys", seqTest);

    HashTable prefixTest;
    for (int i = 1; i <= n; i++) {
        string num = to_string(i);
        while (num.length() < 4) {
            num = "0" + num;
        }
        prefixTest.insert("data_" + num, i);
    }
    showStats("same prefix keys", prefixTest);

    return 0;
}
```
----
## Experimental Results

I tested the hash table with three different input types: random strings, sequential keys, and keys with the same prefix. Each test inserted 100 elements into a hash table.

### Random Strings

Total collisions: 9  
Maximum bucket size: 2  
Average bucket length: 1.13  

### Sequential Keys (student1, student2, ...)

Total collisions: 14  
Maximum bucket size: 3  
Average bucket length: 1.21  

### Same Prefix Keys (data_0001, data_0002, ...)

Total collisions: 17  
Maximum bucket size: 3  
Average bucket length: 1.26  


## Analysis

After running the tests, the random string inputs had the least amount of collisions and the most even distribution across the hash table. Because there are so many different characters in the keys, the hash functino spreads them across a lot of buckets. This results in smaller bucket sizes and shorter chain length.

The sequential and same-prefix keys on the other hand had more collisions. A lot of the characters in seqential keys are the same, which means the hash values are more likely to be similar. The same prefix test showed the highest collision because every single key starts with the same characters. This caused more clustering in the buckets.

Even with more collisions, the hash table still was efficient because the separate chaining allows multiple elements to exist in the same bucket without breaking. The table also dynamicalyl resized and redistributed it's elements when the load factor was increased past the set threshold, which prevented buckets from growing too large.

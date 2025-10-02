#include <iostream>
#include <vector>
#include <list>
#include <utility> // For std::pair

class HashTable {
    int tableSize;
    std::vector<std::list<std::pair<int, int>>> table;

public:
    HashTable(int size) : tableSize(size) {
        table.resize(tableSize);
    }

    int hashFunction(int key) {
        return key % tableSize;
    }

    void insert(int key, int value) {
        int index = hashFunction(key);
        for (auto& kv : table[index]) {
            if (kv.first == key) {
                kv.second = value; // Update existing key
                return;
            }
        }
        table[index].emplace_back(key, value);
    }

    bool search(int key, int& value) {
        int index = hashFunction(key);
        for (const auto& kv : table[index]) {
            if (kv.first == key) {
                value = kv.second;
                return true;
            }
        }
        return false;
    }

    void remove(int key) {
        int index = hashFunction(key);
        auto& chain = table[index];
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->first == key) {
                chain.erase(it);
                return;
            }
        }
    }

    void display() {
        for (int i = 0; i < tableSize; ++i) {
            std::cout << i << ": ";
            for (const auto& kv : table[i]) {
                std::cout << "{" << kv.first << ", " << kv.second << "} -> ";
            }
            std::cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht(7);
    ht.insert(10, 100);
    ht.insert(20, 200);
    ht.insert(15, 150);
    ht.insert(7, 70);
    ht.insert(32, 320);

    ht.display();

    int value;
    if (ht.search(15, value)) {
        std::cout << "Found key 15 with value " << value << "\n";
    } else {
        std::cout << "Key 15 not found\n";
    }

    ht.remove(20);
    std::cout << "After removing key 20:\n";
    ht.display();

    return 0;
}

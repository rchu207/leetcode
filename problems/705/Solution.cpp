// 705. Design HashSet

class MyHashSet {
public:
    MyHashSet() {
        table.resize(5);
    }
    
    void add(int key) {
        table[hashFunc(key)].insert(key);
    }
    
    void remove(int key) {
        table[hashFunc(key)].erase(key);
    }
    
    bool contains(int key) {
        return (table[hashFunc(key)].count(key) == 1);
    }

private:
    vector<unordered_set<int>> table;
    std::function<int(int)> hashFunc = [](int key) { return key % 5; };
};

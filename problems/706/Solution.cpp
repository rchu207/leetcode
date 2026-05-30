// 706. Design HashMap

class MyHashMap {
public:
    MyHashMap() {
        table.resize(10);
    }
    
    void put(int key, int value) {
        table[hashFunc(key)][key] = value;
    }
    
    int get(int key) {
        auto& entry = table[hashFunc(key)];
        if (entry.count(key) > 0) {
            return entry[key];
        } else {
            return -1;
        }
    }
    
    void remove(int key) {
        table[hashFunc(key)].erase(key);
    }
    
private:
    vector<unordered_map<int, int>> table;
    function<int(int)> hashFunc = [](int key) { return (key % 10); };
};

class HashTable {
private:
    std::vector<int> table;
    int size;

    int hash(int key) {
        return (std::hash<int>()(key) % size + size) % size; // хеш-функция
    }

public:
    HashTable(int size) {
        this->size = size;
        table.resize(size, -1); // инициализируем все ячейки значениями -1
    }

    ~HashTable() {
        table.clear();
    }

    void add(int key) {
        int index = hash(key);
        int i = 1;
        while (table[index] != -1) { // квадратичное решение коллизий
            index = (index + i * i) % size;
            i++;
        }
        table[index] = key;
    }

    void remove(int key) {
        int index = hash(key);
        int i = 1;
        while (table[index] != -1 && table[index] != key) {
            index = (index + i * i) % size;
            i++;
        }
        if (table[index] == key) {
            table[index] = -1;
        }
    }

    bool search(int key) {
        int index = hash(key);
        int i = 1;
        while (table[index] != -1 && table[index] != key) {
            index = (index + i * i) % size;
            i++;
        }
        return table[index] == key; // если значение найдено, возвращаем true, иначе false
    }

    void print() {
        for (int i = 0; i < size; i++) {
            if (table[i] != -1) {
                std::cout << i << " : " << hash(table[i]) << std::endl;
            }
        }
    }
};

class MultiwayMerge {
private:
    std::vector<std::vector<int>> tapes; // "ленты"
    std::vector<int> output; // результирующая последовательность
public:
    MultiwayMerge(std::vector<std::vector<int>> tapes) : tapes(tapes) {
        for (auto& tape : tapes) {
            MergeSort(tape);
        }
        merge(); // сортировка
    }

    MultiwayMerge(std::vector<std::string> filepaths, std::string outputFilePath) {
        // чтение данных из файлов и сохранение их в ленты
        for (const auto& filepath : filepaths) {
            std::ifstream file(filepath, std::ios::binary);
            std::vector<int> tape;

            int num;
            while (file >> num) {
                tape.push_back(num);
            }

            file.close();
            
            //Сортруем ленту
            MergeSort(tape);
            tapes.push_back(tape);
            tape.clear();
        }

        merge(); // сортировка
        writeOutputToFile(outputFilePath); // запись результата в файл
    }

    ~MultiwayMerge() {}

    // Сортировка слиянием ////
    void MergeSortImpl(std::vector<int>& values, std::vector<int>& buffer, int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;
            MergeSortImpl(values, buffer, l, m);
            MergeSortImpl(values, buffer, m + 1, r);

            int k = l;
            for (int i = l, j = m + 1; i <= m || j <= r; ) {
                if (j > r || (i <= m && values[i] < values[j])) {
                    buffer[k] = values[i];
                    ++i;
                }
                else {
                    buffer[k] = values[j];
                    ++j;
                }
                ++k;
            }
            for (int i = l; i <= r; ++i) {
                values[i] = buffer[i];
            }
        }
    }

    void MergeSort(std::vector<int>& values) {
        if (!values.empty()) {
            std::vector<int> buffer(values.size());
            MergeSortImpl(values, buffer, 0, values.size() - 1);
        }
    }
    //////////////////////////
    void merge() {
        // Количество лент и все ленты, которые нужно объединить
        int k = tapes.size();
        std::vector<int> indices(k, 0);
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
        std::queue<int> q;

        // Наполняем очередь первыми элементами каждой ленты
        for (int i = 0; i < k; i++) {
            if (!tapes[i].empty()) {
                min_heap.push(tapes[i][0]);
                q.push(i);
            }
        }

        // Начинаем слияние
        while (!min_heap.empty()) {
            // Извлекаем минимальный элемент из кучи
            int min_elem = min_heap.top();
            min_heap.pop();

            // Добавляем этот элемент в выходную последовательность
            output.push_back(min_elem);
            // Сортируем слиянием после добавление элемента;
            MergeSort(output);
            // Получаем номер ленты и увеличиваем соответствующий индекс
            int tape = q.front();
            indices[tape]++;
            q.pop();

            // Добавляем следующий элемент этой ленты в кучу
            if (indices[tape] < tapes[tape].size()) {
                min_heap.push(tapes[tape][indices[tape]]);
                q.push(tape);
            }
        }
    }

    std::vector<int> getOutput() const {
        return output;
    }

    void writeOutputToFile(const std::string& filepath) {
        std::ofstream file(filepath, std::ios::binary);

        for (int element : output) {
            file.write((char*)&element, sizeof(element));
        }

        file.close();
    }
};

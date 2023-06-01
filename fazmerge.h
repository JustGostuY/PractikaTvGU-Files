class MultiwayMerge {
private:
    std::vector<std::vector<int>> tapes; // "ленты"
    std::vector<int> output; // результирующая последовательность
public:
    MultiwayMerge(std::vector<std::string> filepaths, std::string outputFilePath) {
        // чтение данных из файлов и сохранение их в ленты
        for (const auto& filepath : filepaths) {
            std::ifstream file(filepath, std::ios::binary);
            std::vector<int> tape;

            while (true) {
                int num;
                file.read((char*)&num, sizeof(num));

                if (file.eof()) {
                    break;
                }

                tape.push_back(num);
            }

            file.close();
            std::sort(tape.begin(), tape.end());

            tapes.push_back(tape);
        }

        merge(); // сортировка
        writeOutputToFile(outputFilePath); // запись результата в файл
    }

    ~MultiwayMerge() {}

    void merge() {
        std::priority_queue<
            std::pair<int, int>,
            std::vector<std::pair<int, int>>,
            std::greater<std::pair<int, int>>
        > heap; // куча сортировки

        for (int i = 0; i < tapes.size(); i++) { // заполнение кучи первыми элементами из каждой ленты
            if (!tapes[i].empty()) {
                heap.push(std::make_pair(tapes[i][0], i));
            }
        }

        while (!heap.empty()) {
            int element = heap.top().first;
            int tapeIndex = heap.top().second;
            heap.pop();

            output.push_back(element);
            tapes[tapeIndex].erase(tapes[tapeIndex].begin()); // удаляем из ленты элемент, который уже был добавлен в рез-тат

            if (!tapes[tapeIndex].empty()) { // добавляем следующий элемент из ленты, если там что-то осталось
                heap.push(std::make_pair(tapes[tapeIndex][0], tapeIndex));
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

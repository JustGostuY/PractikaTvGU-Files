
#include "includes.h"
#include "bin_tree.h"
#include "fazmerge.h"
#include "sq_hashtable.h"

bool isNumeric(const std::string& str) {
	// проверяем первый символ на "-" (минус)
	if (str.size() > 0 && str[0] == '-') {    // если первый символ "-", проверяем, что остальные символы - цифры
		return str.size() > 1 && all_of(str.begin() + 1, str.end(), ::isdigit);
	}
	else {
		// если первый символ не "-", проверяем, что все символы - цифры
		return all_of(str.begin(), str.end(), ::isdigit);
	}
}

void getcommands_menu() {
	std::cout << "Данная консоль поддерживает следующие команды: \n1 - Задание по внешним сортировкам; \n2 - Задание по хэшированию; \n3 - Задание по АВЛ и Бинарным деревьям \n4 - Список команд; \n5 - Выход." << std::endl;
}

void getcommands_hash() {
	std::cout << "Данная консоль поддерживает следующие команды: \n1 - Cоздать новую хэштаблицу; \n2 - Добавить в хэштаблицу ключ; \n3 - Удалить из хэштаблицы ключ; \n4 - Найти ключ в хэштаблице; \n5 - Отобразить текущие хэштаблицы; \n6 - Вывести хэштаблицу в консоль; \n7 - Выйти в главное меню.\n" << std::endl;
}

void getcommands_merge() {
	std::cout << "Данная консоль поддерживает следующие команды (Использование текстовых файлов в консоли невозможно): \n1 - Тест с готовыми файлами (4 файла из директории, сохранение туда же); \n2 - Тест с готовыми векторами (4 вектора); \n3 - Ввести свои ленты \n4 - Список команд; \n5 - Выход." << std::endl;
}

void getcommands_tree() {
	std::cout << "Данная консоль поддерживает следующие команды: \n1 - Cоздать новое дерево; \n2 - Добавить в дерево узел; \n3 - Удалить из дерева узел; \n4 - Найти узер в дереве; \n5 - Отобразить текущие деревья; \n6 - Вывести дерево в консоль; \n7 - Выйти в главное меню.\n" << std::endl;
}

int main() {

	SetConsoleOutputCP(1251); 
	SetConsoleCP(1251);
	SetConsoleTitle(L"Автор студент 14 группы ТвГУ: Жуков Даниил");

	std::string temp_command;
	bool listcommands = false;
	std::vector<HashTable> hash_tables;
	std::vector<BinarySearchTree> binary_trees;
	std::cout << "Здравствуйте, добро пожаловать в практическую часть отчета по практике\n" << std::endl;
	getcommands_menu();
	while (true) {
		if(listcommands)
			std::cout << "4 - Список команд; \n";

		std::cout << ">> ";
		listcommands = true;
		std::getline(std::cin, temp_command);

		if (temp_command == "1") {
			system("cls");
			std::cout << "Вы попали в задание по внешним сортировкам!\n";
			while (true){
				getcommands_merge();
				std::cout << ">> ";
				std::getline(std::cin, temp_command);
				if (temp_command == "1") {
					std::vector<std::string> filepaths{
						"input1.txt",
						"input2.txt",
						"input3.txt",
						"input4.txt"
					};

					std::string outputFilePath = "output.txt";

					std::cout << "Вектора после слияния (записаны в файл): " << std::endl;

					MultiwayMerge m2(filepaths, outputFilePath);
					std::vector<int> output2 = m2.getOutput();

					for (int element : output2) {
						std::cout << element << " ";
					}
					std::cout << std::endl;
					system("pause");
					system("cls");
					continue;

				}
				if (temp_command == "2") {
					std::vector<std::vector<int>> tapes{
						{ 1, 5, 8, 5 },
						{ 2, 3, 7 },
						{ 4, 6, 9, 100, 432, 23 },
						{ 10, 9, 93, 44, 66}
					};

					std::cout << "Тестовые вектора: " << std::endl;
					for (auto& tape : tapes) {
						for (int item = 0; item < tape.size(); item++) {
							std::cout << tape[item] << " ";
						}
						std::cout << std::endl;
						
					}
					std::cout << std::endl;
					std::cout << "Вектора после слияния: " << std::endl;
					MultiwayMerge m1(tapes);
					std::vector<int> output1 = m1.getOutput();

					for (int element : output1) {
						std::cout << element << " ";
					}
					std::cout << std::endl;
					system("pause");
					system("cls");
					continue;
				}
				if (temp_command == "3") {
					while (true)
					{
						std::vector<std::vector<int>> tapes{};
						int number_vector = 0;
						std::cout << "Вводите данные для каждого вектора через пробел (только целые числа), введите \"Stop\" - чтобы остановиться: " << std::endl;
						while (true)
						{
							std::vector<int> numbers;
							if (temp_command == "Stop") {
								break;
							}
							else {
								number_vector++;
								std::cout << "Вектор #" << number_vector << " >> ";
								std::getline(std::cin, temp_command);
								std::istringstream iss(temp_command);
								int num;
								while (iss >> num) {
									numbers.push_back(num);
								}
								tapes.push_back(numbers);
								numbers.clear();
							}
						}
						std::cout << std::endl;
						std::cout << "Вектора после слияния: " << std::endl;
						MultiwayMerge m1(tapes);
						std::vector<int> output1 = m1.getOutput();

						for (int element : output1) {
							std::cout << element << " ";
						}
						std::cout << std::endl;
						system("pause");
						system("cls");
						break;

					}
				}
				if (temp_command == "4") {
					system("cls");
					continue;
				}
				if (temp_command == "5") {
					system("cls");
					break;
				}
			}
		}
		
		else if (temp_command == "2") {
			system("cls");
			std::cout << "Вы попали в задание по хэштаблицам!\n";
			while (true) {
				getcommands_hash();
				std::cout << ">> ";
				std::getline(std::cin, temp_command);
				if (temp_command == "1") {

				while(true){
						std::cout << "Size: ";
						std::getline(std::cin, temp_command);

						bool test_int = isNumeric(temp_command);
						int size;

						if (!test_int) {
							std::cout << "Введите целое число >0;\n";
							continue;
						}
						else {
							size = stoi(temp_command);
							if (size <= 0) {
								std::cout << "Введите целое число >0;\n";
								continue;
							}
						}

						std::cout << "Новая хэштаблица создана\n";
						HashTable a(size);
						hash_tables.push_back(a);
						system("pause");
						system("cls");
						break;
					}
				}
				else if (temp_command == "2") {
					while (true) {
						std::cout << "Index table: ";
						std::getline(std::cin, temp_command);

						bool test_int = isNumeric(temp_command);
						int index;

						if (!test_int) {
							std::cout << "Введите целое число >0 и <количества хэш таблиц;\n";
							system("pause");
							system("cls");
							continue;
						}
						else {
							index = stoi(temp_command);
							if(index > hash_tables.size() - 1){
								std::cout << "Введите целое число >0 и <количества хэш таблиц;\n";
								system("pause");
								system("cls");
								continue;
							}
						}

						std::cout << "Key value: ";
						std::getline(std::cin, temp_command);

						test_int = isNumeric(temp_command);;
						int value;


						if (!test_int) {
							std::cout << "Введите целое число;\n";
							system("pause");
							system("cls");
							continue;
						}

						value = stoi(temp_command);
						std::cout << "Ключ добавлен в таблицу: " << index << std::endl;
						hash_tables[index].add(value);
						system("pause");
						system("cls");
						break;
					}
				}
				else if (temp_command == "3") {
					while (true) {
						std::cout << "Index table: ";
						std::getline(std::cin, temp_command);

						bool test_int = isNumeric(temp_command);
						int index;


						if (!test_int) {
							std::cout << "Введите целое число >0 и <количества хэш таблиц;\n";
							system("pause");
							system("cls");
							continue;
						}
						else{
							index = stoi(temp_command);
							if (index > hash_tables.size() - 1) {
								std::cout << "Введите целое число >0 и <количества хэш таблиц;\n";
								system("pause");
								system("cls");
								continue;
							}
						}

						std::cout << "Key value: ";
						std::getline(std::cin, temp_command);

						test_int = isNumeric(temp_command);
						int value;


						if (!test_int) {
							std::cout << "Введите целое число;\n";
							system("pause");
							system("cls");
							continue;
						}
							
						value = stoi(temp_command);

						if(hash_tables[index].search(value))
							std::cout << "Ключ удален\n";
						else {
							std::cout << "Ключ не найден\n";
						}
						hash_tables[index].remove(value);
						system("pause");
						system("cls");
						break;
					}
				}
				else if (temp_command == "4") {
					while(true){
						std::cout << "Index table: ";
						std::getline(std::cin, temp_command);

						bool test_int = isNumeric(temp_command);
						int index;

						if (!test_int) {
							std::cout << "Введите целое число >0 и <количества хэш таблиц;\n";
							system("pause");
							system("cls");
							continue;
						}
						else {
							index = stoi(temp_command);
							if (index > hash_tables.size() - 1) {
								std::cout << "Введите целое число >0 и <количества хэш таблиц;\n";
								system("pause");
								system("cls");
								continue;
							}
						
						}


						std::cout << "Key value: ";
						std::getline(std::cin, temp_command);
						test_int = isNumeric(temp_command);
						int value;


						if (!test_int) {
							std::cout << "Введите целое число;\n";
							system("pause");
							system("cls");
							continue;
						}
						
						value = stoi(temp_command);

						if(hash_tables[index].search(value))
							std::cout << "Ключ найден\n";
						else
							std::cout << "Ключ не найден\n";

						system("pause");
						system("cls");
						break;
					}
				}
				else if (temp_command == "5") {
					std::cout << "Текущие хэштаблицы: (Используйте номер для выбора таблицы)\n";
					for (int i = 0; i < hash_tables.size(); i++) {
						std::cout << "Индекс таблицы: " << i << std::endl;
					}
					system("pause");
					system("cls");
					continue;
				}
				else if (temp_command == "6") {
					std::cout << "Index table: ";
					std::getline(std::cin, temp_command);

					bool test_int = isNumeric(temp_command);
					int index;


					if (!test_int) {
						std::cout << "Введите целое число >0 и <количества хэш таблиц;\n";
						system("pause");
						system("cls");
						continue;
					}
					else {
						index = stoi(temp_command);
						if (index > hash_tables.size() - 1) {
							std::cout << "Введите целое число >0 и <количества хэш таблиц;\n";
							system("pause");
							system("cls");
							continue;
						}
					}

					hash_tables[index].print();
					system("pause");
					system("cls");

				}
				else if (temp_command == "7") {
					system("cls");
					break;
				}
				else{
					system("cls");
					continue;
				}
			}
		}

		else if (temp_command == "3") {
			system("cls");
			std::cout << "Вы попали в задание по АВЛ и Бинарным деревьям поиска!\n";
			while (true) {
				getcommands_tree();
				std::cout << ">> ";
				std::getline(std::cin, temp_command);
				if (temp_command == "1") {
					std::cout << "Новое дерево создано\n";
					BinarySearchTree a;
					binary_trees.push_back(a);
					system("pause");
					system("cls");
				}
				else if (temp_command == "2") {
					while (true) {
						std::cout << "Index tree: ";
						std::getline(std::cin, temp_command);

						bool test_int = isNumeric(temp_command);
						int index;


						if (!test_int) {
							std::cout << "Введите целое число >0 и <количества деревьев;\n";
							system("pause");
							system("cls");
							continue;
						}
						else {
							index = stoi(temp_command);
							if (index > binary_trees.size() - 1) {
								std::cout << "Введите целое число >0 и <количества деревьев;\n";
								system("pause");
								system("cls");
								continue;
							}
						}

						std::cout << "Key value: ";
						std::getline(std::cin, temp_command);

						test_int = isNumeric(temp_command);
						int value;


						if (!test_int) {
							std::cout << "Введите целое число;\n";
							system("pause");
							continue;
						}
							
						value = stoi(temp_command);

						std::cout << "Ключ добавлен в дерево: " << index << std::endl;
						binary_trees[index].add(value);
						system("pause");
						system("cls");
						break;
					}
				}
				else if (temp_command == "3") {
					while (true) {
						std::cout << "Index tree: ";
						std::getline(std::cin, temp_command);

						bool test_int = isNumeric(temp_command);
						int index;


						if (!test_int) {
							std::cout << "Введите целое число >0 и <количества деревьев;\n";
							system("pause");
							system("cls");
							break;
						}
						else {
							index = stoi(temp_command);
							if (index > binary_trees.size() - 1) {
								std::cout << "Введите целое число >0 и <количества деревьев;\n";
								system("pause");
								system("cls");
								break;
							}
						}

						std::cout << "Key value: ";
						std::getline(std::cin, temp_command);

						test_int = isNumeric(temp_command);
						int value;

						if (!test_int) {
							std::cout << "Введите целое число;\n";
							system("pause");
							continue;
						}
								
						value = stoi(temp_command);

						if (binary_trees[index].search(value) != nullptr)
							std::cout << "Ключ удален\n";
						else {
							std::cout << "Ключ не найден\n";
						}
						binary_trees[index].remove(value);
						system("pause");
						system("cls");
						break;
					}
				}
				else if (temp_command == "4") {
					while (true) {
						std::cout << "Index tree: ";
						std::getline(std::cin, temp_command);

						bool test_int = isNumeric(temp_command);
						int index;

						if (!test_int) {
							std::cout << "Введите целое число >0 и <количества деревьев;\n";
							system("pause");
							continue;
						}
						else {
							index = stoi(temp_command);
							if (index > binary_trees.size() - 1) {
								std::cout << "Введите целое число >0 и <количества деревьев;\n";
								system("pause");
								continue;
							}

						}


						std::cout << "Key value: ";
						std::getline(std::cin, temp_command);
						test_int = isNumeric(temp_command);
						int value;

						if (!test_int) {
							std::cout << "Введите целое число;\n";
							system("pause");
							continue;
						}
								
						value = stoi(temp_command);

						if (binary_trees[index].search(value))
							std::cout << "Ключ найден\n";
						else
							std::cout << "Ключ не найден\n";

						system("pause");
						system("cls");
						break;
					}
				}
				else if (temp_command == "5") {
					std::cout << "Текущие деревья: (Используйте номер для выбора таблицы)\n";
					for (int i = 0; i < binary_trees.size(); i++) {
						std::cout << "Индекс таблицы: " << i << std::endl;
					}
					system("pause");
					system("cls");
					continue;
				}
				else if (temp_command == "6") {
					std::cout << "Index table: ";
					std::getline(std::cin, temp_command);

					bool test_int = isNumeric(temp_command);
					int index;


					if (!test_int) {
						std::cout << "Введите целое число >0 и <количества деревьев;\n";
						system("pause");
						system("cls");
						break;
					}
					else {
						index = stoi(temp_command);
						if (index > binary_trees.size() - 1) {
							std::cout << "Введите целое число >0 и <количества деревьев;\n";
							system("pause");
							system("cls");
							break;
						}
					}

					binary_trees[index].print();
					system("pause");
					system("cls");

				}
				else if (temp_command == "7") {
					system("cls");
					break;
				}
				else {
					system("cls");
					continue;
				}
			}
		}

		else if (temp_command == "4") {
			getcommands_menu();
			listcommands = false;
			continue;
		}

		else if (temp_command == "5") {
			std::exit(1);
		}

		else {
			std::cerr << "Err: Неизвестная команда" << std::endl;
			system("pause");
			system("cls");
			continue;
		}

	}

}



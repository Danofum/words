#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

int main()
{
    // Устанавливаем кодировки ввода и вывода для консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Просим пользователя ввести строку
    cout << "Введите строку: " << endl;
    string str;
    getline(cin, str); // Считываем строку полностью
    char separator[] = " "; // Разделитель слов — пробел
    int maxLength{ 0 }; // Переменная для хранения максимальной длины слова
    int minLength = 2 ^ 32; // Переменная для хранения минимальной длины слова (инициализирована большим числом)
    int checkChar{ 0 }; // Счетчик символов в текущем слове
    str.push_back(*separator); // Добавляем разделитель в конец строки, чтобы обработать последнее слово

    // Векторы для хранения текущих слов и всех слов максимальной/минимальной длины
    vector<char> longWord; // Текущее длинное слово
    vector<char> shortWord; // Текущее короткое слово
    vector<vector<char>> allLongWords; // Все слова максимальной длины
    vector<vector<char>> allShortWords; // Все слова минимальной длины

    // Первый проход по строке — находим минимальную и максимальную длину слов
    for (unsigned int i = 0; i < str.length(); i++) {
        if (str[i] != *separator) {
            checkChar++; // Увеличиваем счетчик символов
        }
        else {
            if (checkChar < minLength) { // Обновляем минимальную длину слова
                minLength = checkChar;
            }
            if (checkChar > maxLength) { // Обновляем максимальную длину слова
                maxLength = checkChar;
            }
            checkChar = 0; // Обнуляем счетчик для следующего слова
        }
    }

    // Второй проход по строке — группируем слова по длине
    for (unsigned int i = 0; i < str.length(); i++) {
        if (str[i] != *separator) {
            longWord.push_back(str[i]); // Добавляем символ в текущее длинное слово
            shortWord.push_back(str[i]); // Добавляем символ в текущее короткое слово
        }
        else {
            if (longWord.size() == maxLength) {
                allLongWords.push_back(longWord); // Сохраняем слово в список длинных слов
            }
            if (shortWord.size() == minLength) {
                allShortWords.push_back(shortWord); // Сохраняем слово в список коротких слов
            }
            longWord.clear(); // Очищаем вектор для следующего слова
            shortWord.clear(); // Очищаем вектор для следующего слова
        }
    }

    // Выводим результат: максимальная длина слова и сами слова
    cout << "Максимальная длина слова: " << maxLength << endl << "Самые длинные слова: ";
    for (int i = 0; i < allLongWords.size(); i++) {
        for (int j = 0; j < maxLength; j++) {
            cout << allLongWords[i][j]; // Выводим символы слова
        }
        if (i != allLongWords.size() - 1) {
            cout << ", "; // Разделяем слова запятой
        }
        else {
            cout << "." << endl; // Завершаем вывод точки
        }
    }

    // Выводим результат: минимальная длина слова и сами слова
    cout << "Минимальная длина слова: " << minLength << endl << "Самые короткие слова: ";
    for (int i = 0; i < allShortWords.size(); i++) {
        for (int j = 0; j < minLength; j++) {
            cout << allShortWords[i][j]; // Выводим символы слова
        }
        if (i != allShortWords.size() - 1) {
            cout << ", "; // Разделяем слова запятой
        }
        else {
            cout << "." << endl; // Завершаем вывод точки
        }
    }

    return 0; // Завершаем выполнение программы
}
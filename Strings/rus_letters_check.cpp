#include <iostream>
#include <Windows.h>

using namespace std;


//функция проверяет символ на то, является ли он буквой рус. алф.
bool is_rus_letter(char c) {
    return (c >= 'А' && c <= 'я') || c == 'ё' || c == 'Ё';
}

//функция определяет индекс буквы c
int index_of_letter(char c) {
    if (c == 'ё' || c == 'Ё') {
        return 32;
    }

    return (c-'А')%32;
}

//функция определяет букву по индексу
char letter_of_index(int index) {
    if (index == 32) {
        return 'Ё';
    }

    return 'А' + index;
}

//функция считывает строку склавиатуры до точки
string scan_string() {
    string str = "";
    char temp; //буферная переменная для считывания символов
    printf("Введите строку: ");
    while (true) {
        temp = cin.get(); //считываем буферный символ
        if (temp == '.') { //если встретили точку, строка считана, возвращаем ее
            cin.get(); //вводим Enter
            return str;
        }
        else { //иначе добавляем символ к строке
            str += temp;
        }
    }
}

//функция проверяет строку на корректность
bool check_string(string str) {

    bool check = false;
    
    //проверяем строку на пустоту
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] != ' ') {
            check = true;
            break;
        }
    }

    //проверяем посторонние символы
    for (size_t i = 0; i < str.size(); ++i) {
        if (!is_rus_letter(str[i]) && str[i] != ' ') { //если символ не буква и не пробел
            printf("Ошибка. Встречен недопустимый символ: '%c'\n", str[i]);
            return false;
            
        }
    }
    
    if (!check) {
        printf("Ошибка. Введена пустая строка.\n");
    }
    return check;
}

//функция обрабатывает строку по условию 
void proc_string(string str) {

    //кол-во возможных букв
    const int alphabet_size = 33;

    //массив хранит кол-во совпадений каждой буквы в тексте
    int count[alphabet_size] = {};

    //массив хранит информацию о буквах, которые мы уже вывели (нужен для единоразового вывода каждой буквы)
    bool is_printed[alphabet_size] = {};


    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] != ' ') {
            ++count[index_of_letter(str[i])];
        }
    }

    printf("\nБуквы входящие в текст не менее двух раз: ");
    for (size_t i = 0; i < str.size(); ++i) {
        int ind_i = index_of_letter(str[i]); //определяем индекс очередной буквы
        if (count[ind_i] > 1 && !is_printed[ind_i]) {   //если эта буква встречается больше 1-го раза и она еще не выводилась
            printf("%c ", letter_of_index(ind_i));
            is_printed[ind_i] = true;
        }
    }

    printf("\nБуквы входящие в текст по одному разу: ");
    for (size_t i = 0; i < str.size(); ++i) {
        int ind_i = index_of_letter(str[i]); //определяем индекс очередной буквы
        if (count[ind_i] == 1 && !is_printed[ind_i]) {   //если эта буква встречается больше 1-го раза и она еще не выводилась
            printf("%c ", letter_of_index(ind_i));
            is_printed[ind_i] = true;
        }
    }printf("\n");
}

int main() {

    //устанавливаем кодировку ввода/вывода дял кириллицы
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //ссчитываем текст
    string text = scan_string();
    
    //пока текст не проходит проверку, запрашиваем новый
    while (!check_string(text)) {
        text = scan_string();
    }

    //обрабатываем согласно заданию
    proc_string(text);

    return 0;
}

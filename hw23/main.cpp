//
//  main.cpp
//  hw23
//
//  Created by Дима on 11.10.23.
//

//Домашнее задание №20
//Тема: файлы
//Задание
//Создайте приложение «Валидатор HTML-файлов». Приложение запрашивает у пользователя путь к файлу,
//после чего проверяет файл на валидность. Критерием валидности для вашего проекта являются правила:
//все открытые теги должны закрываться, если был знак < его должен закрыть знак >. По итогам валидации
//нужно отобразить результат проверки на экран. Используйте для работы с файлами потоки.


#include <iostream>
#include <fstream>
using namespace std;


void validator(){
    int openCount = 0;
    int closeCount = 0;
    char value[1000];
    cout << "enter a way to the file: ";
    cin >> value;
    cin.getline(value, sizeof(value));
    ifstream file(value);
    char ch;
    if(file.is_open()){
    while(!file.eof()){
        file.get(ch);
        cout << ch;
        if(ch == '<'){
            openCount++;
        }
        if(ch == '>'){
            closeCount++;
        }
    }
    if(openCount == closeCount){
        cout << "all right" << endl;
    }
    else{
        cout << "error" << endl;
    }
    file.close();
    }
}
int main() {
   
    validator();
}

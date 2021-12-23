#include <iostream>
#include <string>
#include <cstring>
#include "numbers.hpp"

#define SPACE 1

using namespace std;

// Вывод одной "Большой" цифры
void drawSingleNumber(char arr[ARR_SIZE][ARR_SIZE]) {
    for (int i = 0; i < ARR_SIZE; i++) {
        for (int j = 0; j < ARR_SIZE; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

// Конвертация простых цифр в "Большие"
void takeBIGNumbers(int *numbers, int length, char BIG_numbers[][ARR_SIZE][ARR_SIZE]) {
    for (int j = 0; j < ARR_SIZE; j++) {                // Строка
        for (int i = 0; i < length; i++) {              // Цифра
            for (int k = 0; k < ARR_SIZE; k++) {        // Колонка
                switch (numbers[i]) {
                    case 0:
                        BIG_numbers[i][j][k] = zero[j][k];
                        break;

                    case 1:
                        BIG_numbers[i][j][k] = one[j][k];
                        break;

                    case 2:
                        BIG_numbers[i][j][k] = two[j][k];
                        break;

                    case 3:
                        BIG_numbers[i][j][k] = three[j][k];
                        break;

                    case 4:
                        BIG_numbers[i][j][k] = four[j][k];
                        break;

                    case 5:
                        BIG_numbers[i][j][k] = five[j][k];
                        break;

                    case 6:
                        BIG_numbers[i][j][k] = six[j][k];
                        break;

                    case 7:
                        BIG_numbers[i][j][k] = seven[j][k];
                        break;

                    case 8:
                        BIG_numbers[i][j][k] = eight[j][k];
                        break;

                    case 9:
                        BIG_numbers[i][j][k] = nine[j][k];
                        break;
                }
            }
        }
    }
}

// Вывод на экран "Больших цифр"
void drawBIGNumbers(int *numbers, int length, char BIG_numbers[][ARR_SIZE][ARR_SIZE]) {
    for (int j = 0; j < ARR_SIZE; j++) {
        for (int i = 0; i < length; i++) {
            for (int k = 0; k < ARR_SIZE; k++) 
                cout << BIG_numbers[i][j][k];

            #if SPACE == 1
                cout << " ";
            #endif
        }
        cout << endl;
    }
}

// Разделение аргумента приложения на отдельные цифры типа int
void divideArgToInt(int value, int *arr, int length) {
    int div = 1;

    // Формируем делитель
    for (int i = 1; i < length; i++)
        div *= 10;

    // Делим число на разряды
    for (int i = 0; i < length; i++) {
        arr[i] = (value / div) % 10;
        div /= 10;
    }
}

// Разделение аргумента приложения на отдельные цифры типа char
void divideArgToChar(char *value, char *arr, int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = value[i];
    }
}


int main(int argc, char* argv[]) {
    if(argc != 2) {
        cout << "Invalid argument!" << endl << endl;
        return 1;
    }

    int length = strlen(argv[1]);
    int numbers[length];
    char BIG_numbers[length][ARR_SIZE][ARR_SIZE];
    
    cout << argv[1] << endl << endl;

    divideArgToInt(atoi(argv[1]), numbers, length);
    takeBIGNumbers(numbers, length, BIG_numbers);
    drawBIGNumbers(numbers, length, BIG_numbers);
    
    cout << endl;
    return 0;
}


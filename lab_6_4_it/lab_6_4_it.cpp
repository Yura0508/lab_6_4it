// lab_6_4_it.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Функція для генерації масиву
void Create(int* b, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++)
        b[i] = Low + rand() % (High - Low + 1);
}

// Функція для виведення масиву
void Print(const int* b, const int size) {
    for (int i = 0; i < size; i++)
        cout << setw(4) << b[i];
    cout << endl;
}

// Функція для знаходження максимального значення та його індексу
int Max(int* a, const int size, int& index) {
    int max = a[0];
    index = 0;
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
            index = i;
        }
    }
    return max;
}

// Функція для обчислення добутку елементів між першим і другим нульовими
int ProductBetweenZeros(int* a, const int size) {
    int firstZeroIndex = -1;
    int secondZeroIndex = -1;

  
    for (int i = 0; i < size; i++) {
        if (a[i] == 0) {
            if (firstZeroIndex == -1) {
                firstZeroIndex = i;
            }
            else {
                secondZeroIndex = i;
                break;
            }
        }
    }
    if (firstZeroIndex == -1 || secondZeroIndex == -1 || secondZeroIndex <= firstZeroIndex + 1) {
        return 0; 
    }
    int product = 1;
    for (int i = firstZeroIndex + 1; i < secondZeroIndex; i++) {
        product *= a[i];
    }
    return product;
}


// Функція для вибору непарних і парних елементів
int* SeparateOddsAndEvens(int* a, const int size) {
    int* newArray = new int[size]; // Новий масив
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (i % 2 != 0) {
            newArray[index] = a[i];
            index++;
        }
    }
    // Заповнення нового масиву парними
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            newArray[index] = a[i];
            index++;
        }
    }
    return newArray; // Повертаємо новий масив
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    cout << " n (size): ";
    cin >> n;

    // Перевірка на коректність введення
    if (n <= 0) {
        cout << "NaN" << endl;
        return 1;
    }

    int* b = new int[n]; 
    const int Low = 0;
    const int High = 10;

   
    Create(b, n, Low, High);
    cout << "massif b:" << endl;
    Print(b, n);

    int maxIndex;
    int maxValue = Max(b, n, maxIndex);
    cout << "max b[" << maxIndex << "]: " << maxValue << endl;

    int product = ProductBetweenZeros(b, n);
    cout << "product: " << product << endl;

    int* separatedArray = SeparateOddsAndEvens(b, n);
    cout << "now massif:" << endl;
    Print(separatedArray, n);

    delete[] b;           
    delete[] separatedArray; 
    return 0;
}
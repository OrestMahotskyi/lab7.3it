#include <iostream>
#include <iomanip>

using namespace std;

// Функція для введення матриці
void InputMatrix(int** matrix, int rowCount, int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
        cout << endl;
    }
}

// Функція для виведення матриці
void PrintMatrix(int** matrix, int rowCount, int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// Функція для підрахунку кількості рядків з нульовими елементами
int CountRowsWithZeros(int** matrix, int rowCount, int colCount) {
    int count = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            if (matrix[i][j] == 0) {
                count++;
                break; // переходимо до наступного рядка
            }
        }
    }
    return count;
}

// Функція для знаходження номера стовпця з найдовшою серією однакових елементів
void FindLongestEqualSequenceColumn(int** matrix, int rowCount, int colCount, int& column) {
    int maxLength = 0;
    column = -1; // Якщо не знайдено, номер стовпця буде -1

    for (int j = 0; j < colCount; j++) {
        int currentLength = 1;
        int bestLength = 1;

        for (int i = 1; i < rowCount; i++) {
            if (matrix[i][j] == matrix[i - 1][j]) {
                currentLength++;
            } else {
                bestLength = max(bestLength, currentLength);
                currentLength = 1; // Скидаємо лічильник
            }
        }
        bestLength = max(bestLength, currentLength); // Остання перевірка

        if (bestLength > maxLength) {
            maxLength = bestLength;
            column = j; // Оновлюємо номер стовпця
        }
    }
}

int main() {
    int rowCount, colCount;

    cout << "Введіть кількість рядків (k): ";
    cin >> rowCount;
    cout << "Введіть кількість стовпців (n): ";
    cin >> colCount;

    // Динамічне виділення пам'яті для матриці
    int** matrix = new int*[rowCount];
    for (int i = 0; i < rowCount; i++) {
        matrix[i] = new int[colCount];
    }

    // Введення елементів матриці
    InputMatrix(matrix, rowCount, colCount);
    // Виведення матриці
    PrintMatrix(matrix, rowCount, colCount);

    // Підрахунок кількості рядків з нульовими елементами
    int count = CountRowsWithZeros(matrix, rowCount, colCount);
    cout << "Кількість рядків, що містять хоча б один нульовий елемент: " << count << endl;

    // Знаходження номера стовпця з найдовшою серією однакових елементів
    int longestColumn;
    FindLongestEqualSequenceColumn(matrix, rowCount, colCount, longestColumn);
    cout << "Номер стовпця, у якому міститься щонайдовша серія однакових елементів: " << longestColumn << endl;

    // Звільнення пам'яті
    for (int i = 0; i < rowCount; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
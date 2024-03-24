#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdlib>

using namespace std;

double geometricMean(double arr[], int size) {
    double product = 1.0;

    for (int i = 0; i < size; i++) {
        product *= arr[i];
    }

    return pow(product, 1.0 / size);
}

// Функція для пірамідального сортування
void heapify(double arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(double arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    int rows, columns;

    cout << "Введiть кiлькiсть стовпцiв : ";
    cin >> rows;
    cout << "Введiть кiлькiсть рядкiв: ";
    cin >> columns;

    double** matrix = new double* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[columns];
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    cout << "Матриця:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    double* geometricMeans = new double[columns];
    for (int j = 0; j < columns; j++) {
        double* column = new double[rows];
        for (int i = 0; i < rows; i++) {
            column[i] = matrix[i][j];
        }
        geometricMeans[j] = geometricMean(column, rows);
        delete[] column;
    }

    heapSort(geometricMeans, columns);

    cout << "\nВiдсортоване середнє геометричне для кожного стовпця:\n";
    for (int j = 0; j < columns; j++) {
        cout << "Стовпець " << j + 1 << ": " << geometricMeans[j] << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] geometricMeans;

    return 0;
}

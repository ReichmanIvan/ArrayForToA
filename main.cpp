#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

void quickSort(int array[], int low, int high);
int partition(int array[], int low, int high);

int main()
{
    setlocale(LC_ALL, "Russian");
    const size_t N = 10;
    int array[N] = {};
    srand(time(NULL));

    cout << "Изначальный массив:\n";
    for (size_t i = 0; i < N; i++)
    {
        array[i] = 0 + rand() % 10000;
        cout << array[i] << '\t';
    }
    cout << "\n";

    // (1) Пузырьковая сортировка
    for (size_t i = 0; i < N - 1; i++)
    {
        for (size_t j = 0; j < N - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int b = array[j];
                array[j] = array[j + 1];
                array[j + 1] = b;
            }
        }
    }

    cout << "Массив после пузырьковой сортировки:\n";
    for (size_t i = 0; i < N; i++)
    {
        cout << array[i] << "\t";
    }
    cout << "\n";

    // (2) Сортировка вставками
    int buff = 0;
    int i, j = 0;
    for (i = 1; i < N; i++)
    {
        buff = array[i]; // запомним обрабатываемый элемент
        for (j = i - 1; j >= 0 && array[j] > buff; j--)
            array[j + 1] = array[j];
        array[j + 1] = buff; // поставим запомненный элемент на его место
    }

    cout << "Массив после сортировки вставками:\n";
    for (int i = 0; i < N; i++)
    {
        cout << array[i] << "\t";
    }

    // (3) Быстрая сортировка
    quickSort(array, 0, N - 1);
    cout << "\n";
    cout << "Массив после быстрой сортировки:\n";
    for (int i = 0; i < N; i++)
    {
        cout << array[i] << "\t";
    }
    cout << "\n";

    return 0;
}

// Функция быстрой сортировки
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high); // Разбиение массива
        quickSort(array, low, pi - 1); // Сортировка левой части
        quickSort(array, pi + 1, high); // Сортировка правой части
    }
}

// Функция разбиения массива
int partition(int array[], int low, int high)
{
    int pivot = array[high]; // Выбираем последний элемент как опорный
    int i = (low - 1); // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}
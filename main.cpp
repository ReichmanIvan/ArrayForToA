#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

void quicksorting(int* array, int N)
{
    //Указатели в начало и в конец массива
    int i = 0;
    int j = N - 1;

    //Центральный элемент массива
    int mid = array[N / 2];

    //Делим массив
    do
    {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (array[i] < mid)
        {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (array[j] > mid)
        {
            j--;
        }

        //Меняем элементы местами
        if (i <= j)
        {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;

            i++;
            j--;
        }
    }

    while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0)
    {
        //"Левый кусок"
        quicksorting(array, j + 1);
    }

    if (i < N)
    {
        //"Првый кусок"
        quicksorting(&array[i], N - i);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    const int N = 10;
    int array[N] = {};
    srand(time(NULL));
    cout << "Изначальный массив:\n";
    for (int i = 0; i < 9; i++)
    {
        array[i] = 0 + rand() % 9;
        cout << array[i] << '\t';
    }
    cout << "\n";

    /* (1)bubble
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        if (array[j] > array[j + 1])
        {
          int b = array[j];
          array[j] = array[j + 1];
          array[j + 1] = b;
        }
      }
    }
    cout << "\n";

    cout << "Массив в отсортированном виде:\n";
    for (int i = 0; i < 9; i++)
    {
      cout << array[i] << "\t";

    }
    cout << "\n";
    */

    /*(2)
    int buff = 0;
    int i, j;
    for (i = 1; i < N; i++)
    {
      buff = array[i]; // запомним обрабатываемый элемент
      // и начнем перемещение элементов слева от него
      // пока запомненный не окажется меньше чем перемещаемый
      for (j = i - 1; j >= 0 && array[j] > buff; j--)
        array[j + 1] = array[j];

      array[j + 1] = buff; // и поставим запомненный на его новое место
    }

    cout << "Массив после вставки:\n";
    for (int i = 1; i < N; i++)
    {
      // вывод отсортированного массива
      cout << array[i] << '\t';
    }
    */

    //(3)
    quicksorting(array, N);
    cout << "Массив после быстрой сортировки:\n";
    for (int i = 0; i < 9; i++)
    {
        cout << array[i] << "\t";

    }
    cout << "\n";
    return 0;
}
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

void quicksorting(int* array, int N)
{
    //��������� � ������ � � ����� �������
    int i = 0;
    int j = N - 1;

    //����������� ������� �������
    int mid = array[N / 2];

    //����� ������
    do
    {
        //��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
        //� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
        while (array[i] < mid)
        {
            i++;
        }
        //� ������ ����� ���������� ��������, ������� ������ ������������
        while (array[j] > mid)
        {
            j--;
        }

        //������ �������� �������
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


    //����������� ������, ���� ��������, ��� �����������
    if (j > 0)
    {
        //"����� �����"
        quicksorting(array, j + 1);
    }

    if (i < N)
    {
        //"����� �����"
        quicksorting(&array[i], N - i);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    const int N = 10;
    int array[N] = {};
    srand(time(NULL));
    cout << "����������� ������:\n";
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

    cout << "������ � ��������������� ����:\n";
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
      buff = array[i]; // �������� �������������� �������
      // � ������ ����������� ��������� ����� �� ����
      // ���� ����������� �� �������� ������ ��� ������������
      for (j = i - 1; j >= 0 && array[j] > buff; j--)
        array[j + 1] = array[j];

      array[j + 1] = buff; // � �������� ����������� �� ��� ����� �����
    }

    cout << "������ ����� �������:\n";
    for (int i = 1; i < N; i++)
    {
      // ����� ���������������� �������
      cout << array[i] << '\t';
    }
    */

    //(3)
    quicksorting(array, N);
    cout << "������ ����� ������� ����������:\n";
    for (int i = 0; i < 9; i++)
    {
        cout << array[i] << "\t";

    }
    cout << "\n";
    return 0;
}
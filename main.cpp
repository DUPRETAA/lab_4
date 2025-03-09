/*
1) 	Реализовать с использованием массива двунаправленное кольцо (просмотр возможен в обе стороны, от последнего элемента можно перейти к первому).
2) 	Распечатать полученный массив, начиная с К-ого элемента и до К-1 ( по кольцу влево).
3) 	Добавить в кольцо после элементов с индексами кратными 5 элементы равные 0.
4) 	Распечатать полученный массив, начиная с К-ого элемента (и до К+1  по кольцу вправо).
*/

#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

void Out(int*& arr, int size, int element, int direction) {
    bool end = false;

    for(int i=element;i<=size&&i>0;i=i+direction) {
        if (end) if (i==element) {i=-1; continue;}
        cout << arr[i-1] << " ";
        if (!(i+direction<=size&&i+direction>0)) {
            end = true;
            if (!(i+direction)) i=size+1; else i=0; 
        }
    }
    cout << endl;
}

void Add(int*& arr, int& size, int index) {
    int* newarr = new int[++size];

    for (int i = 0; i < size; i++) {
        if (i < index) newarr[i] = arr[i];
        else newarr[i+1] = arr[i];
    }
    newarr[index] = 0;

    delete[] arr;
    arr = newarr;
    newarr = nullptr;

    return;
}

int main() {
    setlocale(LC_ALL, "russian");
    srand(time(NULL));

    int N=11;
/*    while (N<1) {
        cout << "Введите количество элементов массива: ";
        cin >> N;
        cout << endl;
    }
*/
    int k;
    int* arr = new int[N]{};

    cout << "Массив: ";
    for (int i; i<N; i++) {
        arr[i] = rand()%101-50;
        cout << arr[i] << " ";
    }

    while (k<1 || k> N) {
    cout << endl << "Введите элемент K, с которого будет начинаться вывод: ";
    cin >> k;
    }

    Out(arr, N, k, -1);

    for (int i=N-1; i>=0;i--) {
        if (i%5==0)  {
            Add(arr, N, i+1);
            if(i<k-1)k++;
        }
    }

//    for (int i=0;i<N;i++) cout << arr[i] << " ";

    Out(arr, N, k, 1);

    return 0;
}
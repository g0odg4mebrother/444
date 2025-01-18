#include <iostream>
using namespace std;

int* allocateMemory(int size) {
    return new int[size];
}

void initializeArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = 0; 
    }
}

void printArray(const int* arr, int size) {
    if (size == 0) {
        cout << "Массив пуст" << endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void deleteArray(int* arr) {
    delete[] arr;
}

int* addElementToEnd(int* arr, int& size, int value) {
    int* newArr = new int[size + 1]; 

    for (int i = 0; i < size; ++i) { 
        newArr[i] = arr[i];
    }

    newArr[size++] = value; 

    delete[] arr; 
    return newArr;
}

int* insertAtIndex(int* arr, int& size, int index, int value) {
    if (index < 0 || index > size) {
        cerr << "Индекс вне диапазона!" << endl;
        return arr;
    }

    int* newArr = new int[size + 1]; 

    for (int i = 0; i < index; ++i) { 
        newArr[i] = arr[i];
    }

    newArr[index] = value; 

    for (int i = index + 1; i <= size; ++i) { 
        newArr[i] = arr[i - 1];
    }

    size++; 

    delete[] arr;
    return newArr;
}

int* removeAtIndex(int* arr, int& size, int index) {
    if (index < 0 || index >= size) {
        cerr << "Индекс вне диапазона!" << endl;
        return arr;
    }

    int* newArr = new int[size - 1]; 

    for (int i = 0; i < index; ++i) {
        newArr[i] = arr[i];
    }

    for (int i = index; i < size - 1; ++i) { 
        newArr[i] = arr[i + 1];
    }
    size--; 

    delete[] arr;
    return newArr;
}

int main() {
    int size = 5;
    int* arr = allocateMemory(size); 
    initializeArray(arr, size);     

    printArray(arr, size);

    arr = addElementToEnd(arr, size, 10);   // Добавляем элемент в конец
    printArray(arr, size);

    arr = insertAtIndex(arr, size, 2, 20);  // Вставляем элемент по индексу
    printArray(arr, size);

    arr = removeAtIndex(arr, size, 3);      
    printArray(arr, size);

    deleteArray(arr);                       

    return 0;
}

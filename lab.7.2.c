#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void initializeArray(int array[], int size) {// Функція для ініціалізації масиву випадковими числами
    srand(time(0)); // Ініціалізуємо генератор випадкових чисел
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 201 - 100; // Генеруємо число в діапазоні [-100;100]
    }
}
void printArray(int array[], int size) {// Функція для виведення масиву на екран
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int countElementsGreaterThanFive(int array[], int size) {// Функція для підрахунку кількості елементів масиву, більших за число п'ять
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > 5) {
            count++;
        }
    }
    return count;
}
int main() {
    int size = 10; // Розмір масиву
    int array[size]; // Оголошуємо масив
    initializeArray(array, size);// Ініціалізуємо та виводимо масив
    printf("Масив: ");
    printArray(array, size);
    int count = countElementsGreaterThanFive(array, size);// Знаходимо кількість елементів, більших за число п'ять, та виводимо результат
    printf("Кількість елементів, більших за число п'ять: %d\n", count);

    return 0;
}
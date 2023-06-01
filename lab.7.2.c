#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sizeinput() {//введення розміру масиву вручну
    int size;
    printf("Введіть розмір масиву: ");
    scanf("%d", &size);
    return size;
}

void arraymaker(int array[], int size) {//створення масиву із псевдогенератором чисел
    srand(time(0));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 201 - 100;
    }
}

void arrayprinter(int array[], int size) {//виведення масиву на екран
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int maxelementfinder(int array[], int size) {//знаходження максимального елементу
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

void numbersaftermax(int array[], int size) {//вивід чисел які стоять після макс числа
    int max = maxelementfinder(array, size);
    printf("Числа, які стоять після максимального числа (%d): ", max);
    int printNumbers = 0;
    for (int i = 0; i < size; i++) {
        if (printNumbers) {
            printf("%d ", array[i]);
        }
        if (array[i] == max) {
            printNumbers = 1;
        }
    }
    printf("\n");
}

int aftermaxsum(int array[], int size) {//сума чисел які стоять після макс числа
    int max = maxelementfinder(array, size);
    int sum = 0;
    int foundMax = 0;

    for (int i = 0; i < size; i++) {
        if (foundMax) {
            sum += array[i];
        }

        if (array[i] == max) {
            foundMax = 1;
        }
    }

    return sum;
}

int biggerthanfivecounter(int array[], int size) {//заходження к-сті чисел більше за 5
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > 5) {
            count++;
        }
    }
    return count;
}

void biggerthanfiveprinter(int array[], int size) {//вивід к-сті чисел більше за 5
    int count = biggerthanfivecounter(array, size);
    printf("Кількість елементів масиву, більших за число п'ять: %d\n", count);
}

int main() {
    int size = sizeinput();
    int array[size];
    arraymaker(array, size);
    printf("Масив: ");
    arrayprinter(array, size);
    numbersaftermax(array, size);
    int sum = aftermaxsum(array, size);
    printf("Сума елементів, розташованих після максимального елемента: %d\n", sum);
    biggerthanfiveprinter(array, size);
    return 0;
}

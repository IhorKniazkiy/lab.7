#include <stdio.h>
#include <stdlib.h>

void uvinput(double* u, double* v) {//введення значень u та v
    printf("Введіть значення u: ");
    scanf("%lf", u);
    printf("Введіть значення v: ");
    scanf("%lf", v);
}

double formulaone(double x, double y) { //розв'язання першої формули

    double f = ((x + y) / (x * x + x * y + y * y)) + (x / (1 + y * y)) + (y / (1 + x * x));
        if (x*x + x*y + y*y <= 0 || 1+y*y <= 0 || 1+x*x <= 0) //перевірка на діленння на 0
        {
        printf("Ділити на 0 неможиливо. Приклад не може бути розв'язаний.");
        exit(0);
        } else {
    return f;
    }
}

double formulatwo(double u, double v) {//розрахунок другої формули з закликанням f з першої формули
    double z = formulaone(u, v) + formulaone(u + v, u * v) + formulaone(u * u, v * v) + formulaone(0.1, 0.1);
    return z;
}

int main() {//вивід результату
    double u, v;
    uvinput(&u, &v);
    double z = formulatwo(u, v);
    printf("Результат обчислень z: %.2lf\n", z);
    return 0;
}
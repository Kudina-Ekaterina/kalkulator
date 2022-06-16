#include <stdio.h>
char regul;
int main(int argc, char *argv[])
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    char e;
    do
    {
        // перечислим функции и обозначения функций
        printf ("знак суммы +\n");
        printf ("знак разности -\n");
        printf ("знак умножения *\n");
        printf ("знак деления /\n");
        printf ("знак возведения в степень ^\n");
        printf ("знак факториала !\n");
        double a,b,d; // задаем переменные типа double
        char c; // задаем переменную типа char
        printf ("введите операцию "); // просим ввести знак нужной операции
        scanf (" %c", &c); // вводим с
        switch (c) //блок функций
        {
            case '+': // блок суммы
            printf ("введите первое число a= ");
            scanf (" %lg", &a);
            printf ("введите второе число b= ");
            scanf (" %lg", &b);
            printf (" %lg plus %lg = %lg", a,b,a+b);
            break;
            case '-': // блок разности
            printf ("введите первое число a= ");
            scanf (" %lg", &a);
            printf ("введите второе число b= ");
            scanf (" %lg", &b);
            printf (" %lg minus %lg = %lg", a,b,a-b);
            break;
            case '*': // блок умножения
            printf ("введите первое число a= ");
            scanf (" %lg", &a);
            printf ("введите второе число b= ");
            scanf (" %lg", &b);
            printf (" %lg multiply by %lg = %lg", a,b,a*b);
            break;
            case '/': // блок деления
            printf ("введите первое число a= ");
            scanf (" %lg", &a);
            printf ("введите второе число b= ");
            scanf (" %lg", &b);
            printf (" %lg divide by %lg = %lg", a,b,a/b);
            break;
            case '^': // блок возведения в степень
            printf ("введите первое число a= ");
            scanf (" %lg", &a);
            printf ("введите второе число b= ");
            scanf (" %lg", &b);
            d=a; // приравниваем, чтобы посчитать степень
            for (int i=1;i<b;i++)
            {
                d=d*a;
            }
            printf (" %lg в степени %lg = %lg", a,b,d);
            break;
            case '!': // блок факториала
            printf ("введите число a= ");
            scanf (" %lg", &a);
            double h = 1;
            double s;
            s = a;
            if (a > 0) for(h = 1; h < s; h++)
            {
                a = a * (s - h);
            }
            if (a == 0) printf("0! = 1");
            else if (a < 0) printf("Факториал отрицательного числа не вычисляется");
            else printf("\n%lf! = %lf",s,a);
            break;
            default: puts ("nop");
        }
    puts ("\nХотите продолжить? Введите y, если да, n, если нет");
    scanf (" %c", &e);
    }
while (e!='n');
return 0;
}

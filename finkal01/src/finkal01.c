#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    char a = 'y', operation, regime; // объявляем переменные для хранения продолжения работы, операции, режима
    double *x, *y, *result; // объявляем переменные для хранения входных данных и результата
    unsigned long long res; // объявляем переменную для хранения результатов факториала и степени
    int size; // переменная для хранения размера вектора
    while(a == 'y') {
    	// перечислим функции и обозначения функций
    	printf("работа с векторами v\n");
    	printf("работа с числами s\n");
    	printf ("знак суммы двух чисел или векторов +\n");
    	printf ("знак разности двух чисел или векторов -\n");
    	printf ("знак умножения или скалярного произведения векторов*\n");
    	printf ("знак деления /\n");
    	printf ("знак возведения в степень ^\n");
    	printf ("знак факториала !\n");
    	printf("выберете режим, введите v - для работы с веторами или s - для работы с числами\n"); // просим пользователя выбрать режим работы
    	scanf(" %c", &regime);
    	printf("введите знак операции\n"); // просим пользователя ввести знак операции
    	scanf(" %c", &operation);
    	switch(regime) {
    		case 'v': // обработка векторных операций
    			printf("введите размерность вектора\n"); // просим пользователя ввести размерность вектора
    			scanf("%i", &size);
    			x = malloc(size * sizeof(double)); // выделяем память для хранения входных векторов
    			y = malloc(size * sizeof(double));
    			if (operation == '+' || operation == '-') {
    				result = malloc(size * sizeof(double)); // выделяем память для хранения результата операции
    			}
    			else {
    				result = malloc(sizeof(double));
    				*result = 0;
    			}
    			printf("введите координаты первого вектора\n"); // просим пользователя ввести координаты первого вектора
    			for (int i = 0; i < size; i++) scanf("%lf", &x[i]); // считываем первый вектор
    			printf("введите координаты второго вектора\n"); // просим пользователя ввести координаты второго вектора
    			for (int i = 0; i < size; i++) scanf("%lf", &y[i]); // считываем второй вектор
    			switch(operation) {
    				case '+':
    					for (int i = 0; i < size; i++) result[i] = x[i] + y[i]; // вычисляем сумму векторов
    					break;
    				case '-':
    					for (int i = 0; i < size; i++) result[i] = x[i] - y[i]; // вычисляем разность векторов
    					break;
    				case '*':
    					for (int i = 0; i < size; i++) *result += x[i] * y[i]; // вычисляем скалярное произведение векторво
    					break;
    			}
    			printf("( ");
    			for (int i = 0; i < size; i++) {
    				if (i == size - 1) {
    					printf("%lf", x[i]);
    				}
    				else printf("%lf ", x[i]);
    			}
    			printf(" ) %c ( ", operation);
    			for (int i = 0; i < size; i++) {
    				if (i == size - 1) {
    					printf("%lf", y[i]);
    				}
    				else printf("%lf ", y[i]);
    			}
    			if (operation == '*') {
    				printf(" ) = %lf\n", *result);
    			}
    			else {
    				printf(" ) = ( ");
    				for (int i = 0; i < size; i++){
    					if (i == size - 1){
    				    	printf("%lf", result[i]);
    				    }
    				    else printf("%lf ", result[i]);
    				}
    				printf(" )\n");
    			}
    			free(x);
    			free(y);
    			free(result);
    			break;
    		case 's':
    			res = 1;
    			x = malloc(sizeof(double));
    			y = malloc(sizeof(double));
    			if (operation == '!') {
    				printf("введите число для нахождения факториала\n");
    				scanf("%lf", x);
    			}
    			else {
    				printf("введите первое число\n"); // просим пользователя ввести первое число
    				scanf("%lf", x); // записываем первое число в переменную
    				printf("введите второе число\n"); // просим пользователя ввести второе число
    				scanf("%lf", y); // записываем второе число в переменную
    			}
       			switch(operation) {
    				case '+':
    					printf("%lf %c %lf = %lf\n", *x, operation, *y, *x + *y);
    					break;
    				case '-':
    					printf("%lf %c %lf = %lf\n", *x, operation, *y, *x - *y);
    					break;
    				case '/':
    					printf("%lf %c %lf = %lf\n", *x, operation, *y, *x / *y);
    					break;
    				case '*':
    					printf("%lf %c %lf = %lf\n", *x, operation, *y, *x * *y);
    					break;
    				case '!':
    					res = *x;
    					if (*x > 0) {
    						for (int i = res - 1; i > 0; i--) {
    							res *= i;
    						}
    						printf("%lf! = %llu\n", *x, res);
    					}
    					else printf("факториала отрицательного числа не существует\n");
    					break;
    				case '^':
    					result = malloc(sizeof(double));
    					*result = 1;
    					if (*y < 0) {
    						for (int i = 1; i <= -(*y); i++) {
    							*result *= *x;
    						}
    						*result = (1/(*result));
    					}
    					else {
    						for (int i = 1; i <= *y; i++) {
    					   		*result *= *x;
    					   	}
    					}
    					printf("%lf ^ %lf = %lf\n", *x, *y, *result);
    					free(result);
    					break;

    			}
       			free(x);
       			free(y);
       			break;
    	}
    	printf("хотите продолжить? Введите y, если да, n, если нет\n");
    	scanf(" %c", &a);
    }
    return 0;
}

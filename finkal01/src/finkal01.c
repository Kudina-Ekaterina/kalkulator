#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    FILE *input, *output;
    char input_name[256], output_name[256];
    char a = 'y', operation, regime; // объявляем переменные для хранения продолжения работы, операции, режима
    double *x, *y, *result; // объявляем переменные для хранения входных данных и результата
    unsigned long long res; // объявляем переменную для хранения результатов факториала и степени
    int size; // переменная для хранения размера вектора
    while(a == 'y') {
    	printf("введите имя файла для чтения данных\n"); // просим пользователя ввести имя файла с входными данными
    	scanf("%s", input_name); // считываем имя файла с входными данными
    	printf("введите имя файла для записи результата\n"); // просим пользователя ввести имя файла для записи результата
    	scanf("%s", output_name); // считываем имя файла для записи результатов
    	input = fopen(input_name, "r"); // открываем входной файл
    	// открываем выходной файл, если файл существует, то произойдёт дозапись, иначе создастся новый файл
    	if ((output = fopen(output_name, "a")) == NULL) {
    		output = fopen(output_name, "w");
    	}
    	while(feof(input) == 0) {
			fscanf(input, " %c", &operation);
			fscanf(input, " %c", &regime);
			switch(regime) {
				case 'v': // обработка векторных операций
					fscanf(input, "%i", &size);
					x = malloc(size * sizeof(double)); // выделяем память для хранения входных векторов
					y = malloc(size * sizeof(double));
					if (operation == '+' || operation == '-') {
						result = malloc(size * sizeof(double)); // выделяем память для хранения результата операции
					}
					else {
						result = malloc(sizeof(double));
						*result = 0;
					}
					for (int i = 0; i < size; i++) fscanf(input, "%lf", &x[i]); // считываем первый вектор
					for (int i = 0; i < size; i++) fscanf(input, "%lf", &y[i]); // считываем второй вектор
					switch(operation) {
						case '+':
							for (int i = 0; i < size; i++) result[i] = x[i] + y[i]; // вычисляем сумму векторов
							break;
						case '-':
							for (int i = 0; i < size; i++) result[i] = x[i] - y[i]; // вычисляем разность векторов
							break;
						case '*':
							for (int i = 0; i < size; i++) *result += x[i] * y[i]; // вычисляем скалярное произведение векторов
							break;
					}
					fprintf(output, "( ");
					for (int i = 0; i < size; i++) {
						if (i == size - 1) {
							fprintf(output, "%lf", x[i]);
						}
						else fprintf(output, "%lf ", x[i]);
					}
					fprintf(output, " ) %c ( ", operation);
					for (int i = 0; i < size; i++) {
						if (i == size - 1) {
							fprintf(output, "%lf", y[i]);
						}
						else fprintf(output, "%lf ", y[i]);
					}
					if (operation == '*') {
						fprintf(output, " ) = %lf\n", *result);
					}
					else {
						fprintf(output, " ) = ( ");
						for (int i = 0; i < size; i++){
							if (i == size - 1){
								fprintf(output, "%lf", result[i]);
							}
							else fprintf(output, "%lf ", result[i]);
						}
						fprintf(output, " )\n");
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
						fscanf(input, "%lf", x);
					}
					else {
						fscanf(input, "%lf", x); // записываем первое число в переменную
						fscanf(input, "%lf", y); // записываем второе число в переменную
					}
					switch(operation) {
						case '+':
							fprintf(output, "%lf %c %lf = %lf\n", *x, operation, *y, *x + *y);
							break;
						case '-':
							fprintf(output, "%lf %c %lf = %lf\n", *x, operation, *y, *x - *y);
							break;
						case '/':
							fprintf(output, "%lf %c %lf = %lf\n", *x, operation, *y, *x / *y);
							break;
						case '*':
							fprintf(output, "%lf %c %lf = %lf\n", *x, operation, *y, *x * *y);
							break;
						case '!':
							res = *x;
							if (*x > 0) {
								for (int i = res - 1; i > 0; i--) {
									res *= i;
								}
								fprintf(output,"%lf! = %llu\n", *x, res);
							}
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
							fprintf(output, "%lf ^ %lf = %lf\n", *x, *y, *result);
							free(result);
							break;

					}
					// освобождаем память
					free(x);
					free(y);
					break;
			}
    	}
    	// закрываем файлы
    	fclose(input);
    	fclose(output);
    	printf("хотите продолжить? введите y, если да, n, если нет\n");
    	scanf(" %c", &a);
    }
    return 0;
}

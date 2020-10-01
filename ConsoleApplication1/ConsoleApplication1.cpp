// Олег Смаранди ИДБ-19-03

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

struct element {
    int sum = 0;
    int value;
};

int calculate_digit_sum(int value) {
    int digit_sum = 0;
    if (value > 0) {
        while (value) {
            digit_sum += value % 10;
            value /= 10;
        }
    }
    return digit_sum;
}

int calculate_sum(int const element_i, int const element_j, int n, int m, element matrix[10][10]) {

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == element_j && i > element_i) {

                matrix[element_i][element_j].sum += calculate_digit_sum(matrix[i][j].value);
            }

            if (j > element_j && i == element_i) {

                matrix[element_i][element_j].sum += calculate_digit_sum(matrix[i][j].value);
            }
            if ((j >= element_j && i >= element_i) && j - i == element_j - element_i) {

                matrix[element_i][element_j].sum += calculate_digit_sum(matrix[i][j].value);
            }
        }
    }

    return matrix[element_i][element_j].sum;
}

void main(void)
{   
    element matrix[10][10];
    int i, j, n, m, N;
    int NUM = 1;
    
    scanf("%d", &n);
    scanf("%d", &m);
    N = n * m;

    // ввод массива
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j].value);
        } 
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            matrix[i][j].sum = calculate_sum(i, j, n, m, matrix);
        }
    }
    

    //вывод таблицы
    printf("\xDA\xC4\xC4\xC4\xC2\xC4\xC4\xC2\xC4\xC4\xC2\xC4\xC4\xC4\xC4\xBF\n");
    printf("\xB3NUM\xB3 i\xB3 j\xB3 SUM\xB3\n");
    printf("\xC3\xC4\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xb3\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (N > NUM) {
                printf("\xB3");
                cout << setfill(' ') << setw(3) << NUM << "\xB3" << setw(2) << i << "\xB3" << setw(2) << j << "\xB3" << setw(3) << matrix[i][j].sum << " \xB3\n";
                printf("\xC3\xC4\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC5\xC4\xC4\xC4\xC4\xb3\n");
                NUM += 1;
                continue;
            }
            if (N == NUM) {
                printf("\xB3");
                cout << setfill(' ') << setw(3) << NUM << "\xB3" << setw(2) << i << "\xB3" << setw(2) << j << "\xB3" << setw(3) << matrix[i][j].sum << " \xB3\n";
                printf("\xC0\xC4\xC4\xC4\xC1\xC4\xC4\xC1\xC4\xC4\xC1\xC4\xC4\xC4\xC4\xd9\n");
                NUM += 1;
            }
    
        }
    }   
}

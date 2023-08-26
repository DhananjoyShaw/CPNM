// quadratic equations
#include <stdio.h>
#include <math.h>
int main() {
    float a, b, c;
    float r1, r2,d;
    printf("Enter the values of a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);
    d = (b * b) - (4 * a * c);
    if (d > 0) {
        r1 = (-b + sqrt(d)) / (2 * a);
        r2 = (-b - sqrt(d)) / (2 * a);
        printf("The real roots are: %f and %f", r1, r2);
    } else if (d == 0) {
        r1 = -b / (2 * a);
        r2 = -b / (2 * a);
        printf("Roots are equal: %f and %f", r1, r2);
    } else {
        printf("Roots are imaginary");}
    return 0;}

// first and last digit
#include <stdio.h>
int main()
{
    int number, fd, ld;
    printf("Enter a number: ");
    scanf("%d", &number);
    ld = number % 10;
    while (number >= 10)
    {
        number /= 10;
    }
    fd=number;
    printf("First digit: %d\n", fd);
    printf("Last digit: %d\n", ld);
    return 0;
}

// pascal triangle
#include <stdio.h>
long factorial(int n)
{
    long result = 1;
    for (int c = 1; c <= n; c++)
    {
        result = result * c;
    }
    return result;
}
int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= (n - i - 2); j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("%ld ", factorial(i) / (factorial(j) * factorial(i - j)));
        }
        printf("\n");
    }
    return 0;
}

// perfect numbers
#include <stdio.h>
int checkperfect(int n1)
{
    int i, sum=0;
    for (i = 1; i < n1; i++)
    {
        if (n1 % i == 0)
        {
            sum += i;
        }
    }
    if (sum == n1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void perfectnumbers(int start , int last)
{
    while (start<= last)
    {
        if (checkperfect(start))
        {
            printf("%d ",start);
        }
       start++;
    }
}
int main()
{
    int start,end;
    printf("Input lowest search limit of perfect numbers: ");
    scanf("%d", &start);
    printf("Input highest search limit of perfect numbers: ");
    scanf("%d", &end);
    printf("\nPerfect numbers between %d and %d are:\n", start, end);
    perfectnumbers(start, end);
    printf("\n\n");
    return 0;
}

// interchanging diagonals
#include <stdio.h>
void main()
{
    int array[10][10];
    int i, j, m, n, a;
    printf("Enter the order of the matrix: ");
    scanf("%d%d", &m, &n);
    if (m == n)
    {
        printf("Enter the elements of the matrix:\n");
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                scanf("%d", &array[i][j]);
            }
        }
        printf("The given matrix is:\n");
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                printf("%d ", array[i][j]);
            }
            printf("\n");
        }
        for (i = 0; i < m; ++i)
        {
            a = array[i][i];
            array[i][i] = array[i][n - i - 1];
            array[i][n - i - 1] = a;
        }
        printf("The matrix after changing the main diagonal and secondary diagonal:\n");
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                printf("%d ", array[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("The given order is not a square matrix.\n");
    }
}

// Matrix Multiplication
#include <stdio.h>
#define ROW 3
#define COL 3
void matrixInput(int mat[][COL]);
void matrixPrint(int mat[][COL]);
void matrixMultiply(int mat1[][COL], int mat2[][COL], int res[][COL]);
int main()
{
    int mat1[ROW][COL];
    int mat2[ROW][COL];
    int product[ROW][COL];
    printf("Enter elements in the first matrix of size %dx%d\n", ROW, COL);
    matrixInput(mat1);
    printf("Enter elements in the second matrix of size %dx%d\n", ROW, COL);
    matrixInput(mat2);
    matrixMultiply(mat1, mat2, product);
    printf("Product of both matrices is:\n");
    matrixPrint(product);
    return 0;
}
void matrixInput(int mat[][COL])
{
    int row, col;
    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            scanf("%d", &mat[row][col]);
        }
    }
}
void matrixPrint(int mat[][COL])
{
    int row, col;
    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            printf("%d ", mat[row][col]);
        }
        printf("\n");
    }
}
void matrixMultiply(int mat1[][COL], int mat2[][COL], int res[][COL])
{
    int row, col, i;
    int sum;
    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            sum = 0;
            for (i = 0; i < COL; i++)
            {
                sum += mat1[row][i] * mat2[i][col];
            }
            res[row][col] = sum;
        }
    }
}

// sparse matrix
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int row, col, i, j, a[10][10], count = 0;
    printf("Enter row");
    scanf("%d", &row);
    printf("Enter Column");
    scanf("%d", &col);
    printf("Enter Element of Matrix1");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Elements are:");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf(" ");
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (a[i][j] == 0)
                count++;
        }
    }
    if (count > ((row * col) / 2))
        printf("Matrix is a sparse matrix ");
    else
        printf("Matrix is not sparse matrix");
}

// strong number
#include <stdio.h>
int factorial(int num)
{
    int fact = 1;
    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }
    return fact;
}
int isStrong(int num)
{
    int temp = num;
    int sum = 0;
    while (temp > 0)
    {
        int digit = temp % 10;
        sum += factorial(digit);
        temp /= 10;
    }
    return (sum == num);
}
int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (isStrong(number))
    {
        printf("%d is a strong number.\n", number);
    }
    else
    {
        printf("%d is not a strong number.\n", number);
    }
    return 0;
}

// swaping using pointers and functions
#include <stdio.h>
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int a, b;
    printf("Enter values for a and b\n");
    scanf("%d%d", &a, &b);
    printf("\n\nBefore swapping: a = %d and b = %d\n", a, b);
    swap(&a, &b);
    printf("\nAfter swapping: a = %d and b = %d\n", a, b);
    return 0;
}

// print array using pointers
#include <stdio.h>
#define MAX_SIZE 100
int main()
{
    int array[MAX_SIZE];
    int i, n;
    printf("Enter the number of elements (up to %d): ", MAX_SIZE);
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    int *ptr = &array[0];
    printf("\nArray elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", *ptr);
        ptr++;
    }
    return 0;
}

// Inpuy 2D array (user defined)
#include <stdio.h>
int main()
{
    int matrix[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("The %d %d element is", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\n");
    printf("The given matrix is \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// Array and subarray
#include <stdio.h>
int main()
{
    int i, n, j = 0;
    int arr[100], sub1[100], sub2[100], arr2[100];
    printf("Enter the value of n : ");
    scanf("%d", &n);
    for (i = 0; i < 2 * n; i++)
    {
        printf("Enter the value at index %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("The original; array is : ");
    for (i = 0; i < 2 * n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        sub1[i] = arr[i];
    }
    for (i = n; i < 2 * n; i++)
    {
        sub2[i] = arr[i];
    }
    printf("The subarray 1 is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", sub1[i]);
    }
    printf("\n");
    printf("The subarray 2 is : ");
    for (i = n; i < 2 * n; i++)
    {
        printf("%d ", sub2[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        arr2[j++] = sub1[i];
    }
    for (i = n; i < 2 * n; i++)
    {
        arr2[j++] = sub2[i];
    }
    printf("The original; array is : ");
    for (i = 0; i < 2 * n; i++)
    {
        printf("%d ", arr2[i]);
    }
    return 0;
}

// reverse array using pointers
#include <stdio.h>
void reverseArray(int *arr, int size)
{
    int *start = arr;
    int *end = arr + size - 1;
    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
int main()
{
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter elements in the array:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nArray before reversing: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    reverseArray(arr, size);
    printf("\nArray after reversing: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

// Armstrong Number
#include <stdio.h>
int isarmStrong(int num)
{
    int temp = num;
    int sum = 0;
    while (temp > 0)
    {
        int digit = temp % 10;
        sum = sum + (digit * digit * digit);
        temp /= 10;
    }
    if (sum == num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void armstrongnumbers(int start, int last)
{
    while (start <= last)
    {
        if (isarmStrong(start))
        {
            printf("%d ", start);
        }
        start++;
    }
}
int main()
{
    int start, end;
    printf("Input lowest search limit of perfect numbers: ");
    scanf("%d", &start);
    printf("Input highest search limit of perfect numbers: ");
    scanf("%d", &end);
    printf("\nPerfect numbers between %d and %d are:\n", start, end);
    armstrongnumbers(start, end);
    printf("\n\n");
    return 0;
}

// switch case Calculator
#include <stdio.h>
int main()
{
    double num1, num2, result;
    char operator;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    switch (operator)
    {
    case '+':
        result = num1 + num2;
        printf("Result: %.2lf\n", result);
        break;
    case '-':
        result = num1 - num2;
        printf("Result: %.2lf\n", result);
        break;
    case '*':
        result = num1 * num2;
        printf("Result: %.2lf\n", result);
        break;
    case '/':
        if (num2 != 0)
        {
            result = num1 / num2;
            printf("Result: %.2lf\n", result);
        }
        else
        {
            printf("Error: Division by zero\n");
        }
        break;
    default:
        printf("Error: Invalid operator\n");
    }
    return 0;
}

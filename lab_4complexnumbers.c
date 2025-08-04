#include <stdio.h>
typedef struct {
    float real;
    float imag;
} Complex;
Complex add(Complex n1, Complex n2) {
    Complex temp;
    temp.real = n1.real + n2.real;
    temp.imag = n1.imag + n2.imag;
    return temp;
}
Complex multiply(Complex n1, Complex n2) {
    Complex temp;
    temp.real = n1.real * n2.real - n1.imag * n2.imag;
    temp.imag = n1.real * n2.imag + n1.imag * n2.real;
    return temp;
}
Complex subtract(Complex n1, Complex n2) {
    Complex temp;
    temp.real = n1.real - n2.real;
    temp.imag = n1.imag - n2.imag;
    return temp;
}

int main() {
    Complex num1, num2, result;
    printf("Enter the real and imaginary parts for the first complex number: ");
    scanf("%f %f", &num1.real, &num1.imag);
    printf("Enter the real and imaginary parts for the second complex number: ");
    scanf("%f %f", &num2.real, &num2.imag);
    result = add(num1, num2);
    printf("Sum = %.1f + %.1fi\n", result.real, result.imag);
    result = multiply(num1, num2);
    printf("Product = %.1f + %.1fi\n", result.real, result.imag);
    result = subtract(num1, num2);
    printf("Difference = %.1f + %.1fi\n", result.real, result.imag);

    return 0;
}


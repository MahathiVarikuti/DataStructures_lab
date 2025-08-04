#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float real;
    float imag;
} Complex;

Complex add(Complex *c1, Complex *c2) {
    Complex result;
    result.real = c1->real + c2->real;
    result.imag = c1->imag + c2->imag;
    return result;
}

Complex subtract(Complex *c1, Complex *c2) {
    Complex result;
    result.real = c1->real - c2->real;
    result.imag = c1->imag - c2->imag;
    return result;
}

Complex multiply(Complex *c1, Complex *c2) {
    Complex result;
    result.real = c1->real * c2->real - c1->imag * c2->imag;
    result.imag = c1->real * c2->imag + c1->imag * c2->real;
    return result;
}

int main() {
    Complex c1, c2, result;
    printf("Enter real and imaginary parts of first complex number: ");
    scanf("%f %f", &c1.real, &c1.imag);
    printf("Enter real and imaginary parts of second complex number: ");
    scanf("%f %f", &c2.real, &c2.imag);

    result = add(&c1, &c2);
    printf("Sum: %.2f + %.2fi\n", result.real, result.imag);

    result = subtract(&c1, &c2);
    printf("Difference: %.2f + %.2fi\n", result.real, result.imag);

    result = multiply(&c1, &c2);
    printf("Product: %.2f + %.2fi\n", result.real, result.imag);

    return 0;
}

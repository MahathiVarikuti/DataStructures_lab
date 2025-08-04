#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct {
    int coeff;
    int exp_x;
    int exp_y;
} Term;

typedef struct {
    Term terms[MAX_TERMS];
    int num_terms;
} Polynomial;

void addPolynomials(Polynomial *p1, Polynomial *p2, Polynomial *result) {
    int i = 0, j = 0, k = 0;
    while (i < p1->num_terms && j < p2->num_terms) {
        if (p1->terms[i].exp_x == p2->terms[j].exp_x && p1->terms[i].exp_y == p2->terms[j].exp_y) {
            result->terms[k].coeff = p1->terms[i].coeff + p2->terms[j].coeff;
            result->terms[k].exp_x = p1->terms[i].exp_x;
            result->terms[k].exp_y = p1->terms[i].exp_y;
            i++;
            j++;
        } else if (p1->terms[i].exp_x > p2->terms[j].exp_x || (p1->terms[i].exp_x == p2->terms[j].exp_x && p1->terms[i].exp_y > p2->terms[j].exp_y)) {
            result->terms[k] = p1->terms[i];
            i++;
        } else {
            result->terms[k] = p2->terms[j];
            j++;
        }
        k++;
    }
    while (i < p1->num_terms) {
        result->terms[k++] = p1->terms[i++];
    }
    while (j < p2->num_terms) {
        result->terms[k++] = p2->terms[j++];
    }
    result->num_terms = k;
}

void multiplyPolynomials(Polynomial *p1, Polynomial *p2, Polynomial *result) {
    result->num_terms = 0;
    for (int i = 0; i < p1->num_terms; i++) {
        for (int j = 0; j < p2->num_terms; j++) {
            result->terms[result->num_terms].coeff = p1->terms[i].coeff * p2->terms[j].coeff;
            result->terms[result->num_terms].exp_x = p1->terms[i].exp_x + p2->terms[j].exp_x;
            result->terms[result->num_terms].exp_y = p1->terms[i].exp_y + p2->terms[j].exp_y;
            result->num_terms++;
        }
    }
}

void printPolynomial(Polynomial *p) {
    for (int i = 0; i < p->num_terms; i++) {
        printf("%dx^%dy^%d ", p->terms[i].coeff, p->terms[i].exp_x, p->terms[i].exp_y);
        if (i < p->num_terms - 1) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    Polynomial p1 = {{{3, 2, 1}, {4, 1, 0}}, 2};
    Polynomial p2 = {{{1, 1, 1}, {2, 0, 1}}, 2};
    Polynomial result;

    printf("Polynomial 1: ");
    printPolynomial(&p1);
    printf("Polynomial 2: ");
    printPolynomial(&p2);

    addPolynomials(&p1, &p2, &result);
    printf("Sum: ");
    printPolynomial(&result);

    multiplyPolynomials(&p1, &p2, &result);
    printf("Product: ");
    printPolynomial(&result);

    return 0;
}

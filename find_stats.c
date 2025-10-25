#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main(void) {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of elements. Must be a positive integer.\n");
        return 1;
    }

    double num;
    double sum = 0.0;
    double min = DBL_MAX;
    double max = -DBL_MAX;

    for (int i = 0; i < n; ++i) {
        printf("Enter number %d: ", i + 1);
        if (scanf("%lf", &num) != 1) {
            fprintf(stderr, "Invalid input. Expected a number.\n");
            return 1;
        }
        sum += num;
        if (num < min) min = num;
        if (num > max) max = num;
    }

    double avg = sum / n;

    printf("\nResults:\n");
    printf("Smallest: %g\n", min);
    printf("Largest: %g\n", max);
    printf("Average: %.6f\n", avg);

    return 0;
}

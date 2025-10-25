#include <stdio.h>

int main(void) {
    int n;
    printf("Simple Expense Tracker (beginner)\n");
    printf("How many expenses do you want to enter? (max 50): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 50) {
        printf("Invalid number. Please run the program again with 1-50.\n");
        return 1;
    }

    double amount;
    double total = 0.0;
    double max = -1.0;
    double min = -1.0;

    for (int i = 0; i < n; ++i) {
        printf("Enter expense #%d amount (example: 12.50): ", i + 1);
        if (scanf("%lf", &amount) != 1 || amount < 0) {
            printf("Invalid amount. Please run the program again and enter non-negative numbers.\n");
            return 1;
        }
        total += amount;
        if (i == 0 || amount > max) max = amount;
        if (i == 0 || amount < min) min = amount;
    }

    double average = total / n;
    printf("\nSummary:\n");
    printf("Total expenses : %.2f\n", total);
    printf("Average expense: %.2f\n", average);
    printf("Highest expense: %.2f\n", max);
    printf("Lowest expense : %.2f\n", min);

    return 0;
}
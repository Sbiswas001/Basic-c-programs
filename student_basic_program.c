/* ==============================================================
   File Name   : student_basic_program.c
   Author      : Agnibesh Maity
   Description : A simple C program that performs basic operations:
                 1. Print a greeting
                 2. Calculate sum of two numbers
                 3. Check even or odd
                 4. Find factorial of a number
   Created On  : October 2025
   ============================================================== */

#include <stdio.h>

// --------------------------------------------------------------
// Function to calculate factorial
// --------------------------------------------------------------
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

// --------------------------------------------------------------
// Main Function
// --------------------------------------------------------------
int main() {
    int choice, a, b, n;

    printf("=============================================\n");
    printf("🧠 BASIC C PROGRAM - MULTI FUNCTION TOOL 🧠\n");
    printf("=============================================\n");

    printf("1️⃣  Print Greeting Message\n");
    printf("2️⃣  Sum of Two Numbers\n");
    printf("3️⃣  Check Even or Odd\n");
    printf("4️⃣  Find Factorial\n");
    printf("5️⃣  Exit\n");
    printf("---------------------------------------------\n");

    while (1) {
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nHello, World! 🌎 Welcome to C Programming!\n");
                break;

            case 2:
                printf("\nEnter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("Sum = %d\n", a + b);
                break;

            case 3:
                printf("\nEnter a number: ");
                scanf("%d", &n);
                if (n % 2 == 0)
                    printf("%d is Even.\n", n);
                else
                    printf("%d is Odd.\n", n);
                break;

            case 4:
                printf("\nEnter a number: ");
                scanf("%d", &n);
                printf("Factorial of %d = %d\n", n, factorial(n));
                break;

            case 5:
                printf("\n👋 Exiting... Have a great day!\n");
                return 0;

            default:
                printf("⚠️ Invalid choice! Try again.\n");
        }
    }

    return 0;
}


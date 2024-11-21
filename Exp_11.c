#include <stdio.h>
#include <math.h>

// Function to calculate factorial of n
double factorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate log2 of a number
double log_base2(double x) {
    return log(x) / log(2);
}

int main() {
    int n = 25;  // Number of letters in the Playfair cipher grid
    double fact = factorial(n);
    double log2_fact = log_base2(fact);
    
    printf("The approximate number of possible keys is 2^%.0f.\n", log2_fact);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 13 // Max number of entries in the file

//Function to find the index of the minimum sales
int min_sales(double numbers[], int n) {
    double min = numbers[0];
    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
            min_index = i;
        }
    }
    return min_index;
}

//Function to find the index of the maximum sales
int max_sales(double numbers[], int n) {
    double max = numbers[0];
    int max_index = 0;
    for (int i = 1; i < n; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
            max_index = i;
        }
    }
    return max_index;
}

//Function to calculate the average sales
double average_sales(double numbers[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }
    return (sum / n);
}

int main() {
    //Array to hold the months
    const char *months[] = {"January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};

    FILE *file; //File pointer

    double numbers[MAX_ENTRIES]; //Array to hold the numbers
    int i = 0; //Counter for number of entries

    // Open the file for reading
    file = fopen("salesfigures.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read numbers from the file and store them in the array
    while (fscanf(file, "%lf", &numbers[i]) != EOF) {
        i++;
    }

    // Close the file
    fclose(file);

    // Print the monthly sales report
    printf("\nMonthly Sales Report for 2024:\n");
    printf("\nMonth\tSales\n");
    for (int j = 0; j < i; j++) {
        printf("%s ", months[j]);
        printf("%.2f\n", numbers[j]);
    }

    // Print the sales summary report
    printf("\nSales Summary Report:\n");
    printf("\nMinimum Sales: %.2f (%s)", numbers[min_sales(numbers, i) ], months[min_sales(numbers, i)]);
    printf("\nMaximum Sales: %.2f (%s)", numbers[max_sales(numbers, i) ], months[max_sales(numbers, i)]);
    printf("\nAverage Sales: %.2f\n", average_sales(numbers, i));

    // Print the six-month moving average report
    printf("\nSix-Month moving average report:");
    for (int j = 0; j < i - 5; j++) {
        double sum = 0;
        for (int k = j; k < j + 6; k++) {
            sum += numbers[k];
        }
        printf("\n%s - %s: %.2f", months[j], months[j + 5], sum / 6);
    }

    // Print the sales report in descending order
    printf("\n\nSales report (highest to lowest):");
    printf("\nMonth\tSales\n");
    for (int j = 0; j < i; j++) {
        printf("%s ", months[max_sales(numbers, i) ]);
        printf("$%.2f\n", numbers[max_sales(numbers, i) ]);
        numbers[max_sales(numbers, i) ] = -1;
    }

    return 0;
}

#include "register.h"
#include <stdio.h>
#include <stdlib.h>

void print_item(int rows, int cols, int data[][cols]) {
// Header Row: Print the header row with month names separated by tabs using "\t"
  printf("Jan\tFeb\tMar\tApr\tMay\tJun\tJul\tAug\tSep\tOct\tNov\tDec\n");
// Data Printing Loop: For each element in the row (from January to December):
// 1. Print the corresponding data value from the provided two-dimensional array (data) for the specified row (rows) and column (i).

  for (int i = 0; i < cols; i++) {
    printf("%d", data[rows][i]);
// 2. Check if the current element is not the last one in the row (i < cols - 1):
    if (i < cols - 1) {
// If true, print a tab character ("\t") to separate the current element from the next one.
      printf("\t");
    } else {
// If false (it's the last element in the row), print a newline character ("\n") to move to the next line.
      printf("\n");
    }
  }
}

void total_sales(int rows, int cols, int data[][cols]) {
// Open a new file named "sales.txt" for writing.
  FILE *f1 = fopen("sales.txt", "w");
// header line to the file with column names: "Item" and "Sales".
  fprintf(f1, "%s\t%s\n", "Item", "Sales");
  for (int i = 0; i < rows; i++) {
// 1. Initialize a variable current_row_sales to 0 to keep track of the total sales for the current row.
    int current_row_sales = 0;
// 2. For each element in the row:
    for(int j = 0; j < cols; j++){
// Add the value of the current element to current_row_sales.
    current_row_sales += data[i][j];
    }
// 3. Check if the row index is less than 10:
    if (i < 10) {
// If true, write the row index with a leading zero, followed by the total sales, to the file.
      fprintf(f1, "0%d\t%d\n", i, current_row_sales);
    } else {
// If false, write the row index and the total sales to the file.
      fprintf(f1, "%d\t%d\n", i, current_row_sales);
    }
// d. Reset current_row_sales to 0 for the next row.
    current_row_sales = 0;
  }
// Close File: Close the file when all data is written.
fclose(f1);
}


void top_overall(int rows, int cols, int data[][cols]) {
  // Initialize Variables: Set previous_best and current_best to 0, and winner to 0.
  int previous_best = 0;
  int current_best = 0;
  int winner = 0;
  // Loop for each row of data:
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
// For each element in the row, add its value to current_best.
      current_best += data[i][j];
    }
// Check for Winner: Compare the current_best with the previous_best 
// to determine if the current row has a higher total.
    if (current_best > previous_best) {
// If true, update the winner to the current row index, and update previous_best to the new total.
      winner = i;
      previous_best = current_best;
    }
    current_best = 0;
  }
// Print Result: Print the result indicating the most popular item based on the row with the highest total.
  printf("The most popular item is item %d.\n", winner);
}




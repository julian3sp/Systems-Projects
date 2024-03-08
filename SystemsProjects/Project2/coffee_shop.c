#include "register.h"
#include <stdio.h>
#include <stdlib.h>
/***************************************************
* int main(void)
* - Opens and reads the monthly sales files and stores their info
* into a 50x12 array
* - Prompts the user for a number and based upon that either:
*   -Prints an item and its monthly sales
*   -Writes the total sales of all items to a file sales.txt
*   -Finds the best selling item and prints it to the terminal
* Parameters:
* void
* Returns:
* 0
************************************************/
int main(void) {
// declare variables, including the number of rows in the array, columns in the array and the array itself
// make an array of strings to store the names of each month
  int numRows = 50;
  int numCols = 12;
  int data[50][12];
  char *months[12] = {
      "Jan_2023_data.txt", "Feb_2023_data.txt", "Mar_2023_data.txt",
      "Apr_2023_data.txt", "May_2023_data.txt", "Jun_2023_data.txt",
      "Jul_2023_data.txt", "Aug_2023_data.txt", "Sep_2023_data.txt",
      "Oct_2023_data.txt", "Nov_2023_data.txt", "Dec_2023_data.txt"};
  int user_input;
// first iterate over the files using a for loop with i being less than columns (same as number of months)
    for (int i = 0; i < numCols; i++) {
// Open the i'th file in the array of months
    FILE *x = fopen(months[i], "r");
// Error checking: after you open the file check if it is equal to 'NULL', 
// if it is, return an error statement and exit the program
    if (x == NULL) {
      printf("Error opening file: %s\n", months[i]);
      exit(1);
    }
// Now, we can iterate over the rows for whichever column we are currently on, 
// scan each rows info until we reach the last column
    int j = 0;
    while (fscanf(x, "%*d %*s %d", &data[j][i]) > 0 && j < numRows) {
      j++;
    }
// then we close the file we are working on, this is repeated until the last column/month is reached and read
    fclose(x);
  }
// once we are done with reading the files, prompt the user for which program theyd like to run and scan their input
puts("Which program would you like to run?\n(1) Output the monthly sales of "
     "an item.\n(2) Calculate overall sales for all items.\n(3) Find the "
     "most popular item.");
scanf("%d", &user_input);
// use if/if else statements to run a different function upon the data depending on the users input
if (1 == user_input) {
  int input = 0;
  puts("Which item?");
  scanf("%d", &input);
  print_item(input, numCols, data);
} else if (2 == user_input) {
  total_sales(numRows, numCols, data);
} else if (3 == user_input) {
  top_overall(numRows, numCols, data);
}
//satisfy the return type
return 0;
}
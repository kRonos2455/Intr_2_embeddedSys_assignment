/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief The implementation file of the c1m1 assignment
 *
 * This file includes all the required functions implementations in the c1m1 assignment
 *
 * @author Arun B John
 * @date 14/9/2023
 *
 */



#include <stdio.h>
#include "stat.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char minimum = 0;
  unsigned char maximum = 0;
  float mean = 0;
  unsigned char median = 0;

  /* Statistics and Printing Functions Go Here */
  printf("original array: \n");
  print_array(test, SIZE);
  median = find_median(test, SIZE);
  mean = find_mean(test, SIZE);
  maximum = find_maximum(test, SIZE);
  minimum = find_minimum(test, SIZE);
  print_statistics(minimum, maximum, mean, median);
  sort_array(test, SIZE);
  printf("a after sorting: \n");
  print_array(test, SIZE);
}

void print_statistics (unsigned char minimum, unsigned char maximum, float mean, unsigned char median){
  printf("The minimum is %d \n", minimum);
  printf("The maximum is %d \n", maximum);
  printf("The mean is %f \n", mean);
  printf("The median is %d \n", median);
}


void print_array(unsigned char *a, unsigned int b){
  for (unsigned int i=0; i<b; i++){
    printf("%d,", *(a + i));
  }
  printf("\n");
}

unsigned char find_median (unsigned char *a, unsigned int b){
  unsigned char median = 0;
  median = *(a + (b / 2) -1);
  return median;
}

float find_mean (unsigned char *a, unsigned int b){
  unsigned int t = 0; // variable to store the t value throughout the mean finding process
  float mean = 0;
  for (unsigned int i=0; i<b; i++){
    t += a[i] /* *(a + i) */;
  }
  printf("acc = %d \n", t);
  mean = t / ((float) b); //must type cast one of the two integers to float for accurate calculation.
  return mean;
}

unsigned char find_maximum (unsigned char *a, unsigned int b){
  unsigned char maximum = *a; // initalize the maximum variable with the value of the first a element
  for (unsigned int i=1; i<b; i++){ // start the loop from the second elemnt
    if (*(a + i) > maximum){
      maximum = *(a + i);
    }
    else {} // do nothing.
  }
  return maximum;
}

unsigned char find_minimum (unsigned char *a, unsigned int b){
  unsigned char minimum = *a; // initalize the minimum variable with the value of the first a element
  for (unsigned int i=1; i<b; i++){ // start the loop from the second elemnt
    if (*(a + i) < minimum){
      minimum = *(a + i);
    }
    else {} // do nothing.
  }
  return minimum;
}

void sort_array(unsigned char *a, unsigned int b){
  char flag = 0; //this flag is to indicate if a swap process has occurred at least once in the loop
  unsigned char temp;
  do {
    flag =0; //set flag to default at every new 'do' operation
    for (unsigned int index=0; index<b; index++){
      if (a[index] > a[index +1] || a[index] == a[index +1]) {
        continue;
      }
      else if (a[index] < a[index +1]) {
        //swap elements//
        temp = a[index];
        a[index] = a[index+1];
        a[index+1] = temp;

        flag = 1; // a swap process has occurred at least once in this loop
      }
    }
  }
  while (flag ==1); // the a is not sorted as long as a swap operation is occurred at least once
}

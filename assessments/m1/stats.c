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
 * @brief A program that calculates basic statistics of an array of numbers
 *
 * This program calculates the min, max, median, and mean of an array of numbers.
 * These numbers are hardcoded in the main function and are unsigned chars.
 * The program also prints the statistics after calculating them.
 *
 * @author Jose Acuna
 * @date 04.19.2019
 *
 */

#include <stdio.h>
#include "stats.h"
#include <string.h>
#include <stdlib.h>

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  unsigned int len = (unsigned int) strlen(test);
  printf("The input array:\n");
  print_array(test, len);
  printf("\n\nStatistics about the array:\n");
  print_statistics(test, len);
  printf("\n\nThe sorted array:\n");
  sort_array(test, len);
  print_array(test, len);
  
}

/* Add other Implementation File Code Here */


void print_statistics(unsigned char * arr, unsigned int len){
  unsigned char median = find_median(arr, len);
  unsigned char mean = find_mean(arr, len);
  unsigned char max = find_maximum(arr, len);
  unsigned char min = find_minimum(arr, len);

  printf("min: %d\n", min);
  printf("max: %d\n", max);
  printf("mean: %d\n", mean);
  printf("median: %d\n\n", median);
}


void print_array(unsigned char * arr, unsigned int len){
  for (unsigned int i = 0; i < len; i++){
    printf("%3u ", arr[i]);
    if (len == 40){
      if ( i % 8 == 7){
        printf("\n");
      }
    }
  }
  printf("\n");
}


unsigned char find_median(unsigned char * arr, unsigned int len){
  unsigned char * copy = (char *) malloc(len * sizeof (unsigned char));
  for (unsigned int i = 0; i < len; i++){
    copy[i] = (unsigned char) arr[i];
  }
  sort_array(copy, len);
  unsigned char result = 0;
  if (len % 2 == 1){
    result = copy[len / 2 + 1];
  }
  else{
    unsigned char num1 = copy[len / 2];
    unsigned char num2 = copy[len / 2 + 1];
    result = (unsigned char) (num1 + num2) / 2;
  }

  return result;
  
}


unsigned char find_mean(unsigned char * arr, unsigned int len){
  unsigned int sum = 0;
  for (unsigned int i = 0; i < len; i++){
    sum += arr[i];
  }
  float fmean = (float) sum / len;
  unsigned char mean = (unsigned char) fmean;
  return mean;
}


unsigned char find_maximum(unsigned char * arr, unsigned int len){
  unsigned char max = arr[0];
  for (unsigned int i = 1; i < len; i++){
    if (max > arr[i]){
      max = arr[i];
    }
  }
  return max;

}


unsigned char find_minimum(unsigned char * arr, unsigned int len){
  unsigned char min = arr[0];
  for (unsigned int i = 1; i < len; i++){
    if (min < arr[i]){
      min = arr[i];
    }
  }
  return min;
}


void sort_array(unsigned char * arr, unsigned int len){
  for (unsigned int i = 0; i < len; i++){
    for (unsigned int j = 0; j < len - i - 1; j++){
      unsigned char num1 = arr[j];
      unsigned char num2 = arr[j+1];
      if (num1 > num2){
        arr[j+1] = num1;
        arr[j] = num2;
      }
    }
  }
}




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
 * @file stats.h
 * @brief This is the header file for stats.c
 *
 * This file declares all functions being used in stats.c
 *
 * @author Jose Acuna
 * @date 04.19.2019
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief Calculates and prints statistics for a given array of numbers
 *
 * Makes calls to other functions that calculate the min, max, median, and mean
 * of a given array. These values are stored and printed.
 *
 * @param arr A pointer to the first elemenet of an array of unsigned chars.
 *            Basic statistics will be derived from this array.
 * @param len The length of arr
 *
 * @return void
 */
void print_statistics(unsigned char * arr, unsigned int len);

/**
 * @brief Prints the values of a given array of numbers
 * 
 * Since elements of the array range from 0 to 255, then each element takes
 * up at most 3 characters. Any elements that are less than digits are filled
 * in with leading spaces.
 * The array is printed as a 5x8 2D array of unsigned chars for cleanliness
 *
 * @param arr A pointer to the first element of an array of unsigned chars.
 *            This array will be printed
 * @param len The length of arr, assumed to be 40 elements
 *
 * @return void
 */
void print_array(unsigned char * arr, unsigned int len);

/**
 * @brief Finds the median value of a given array of numbers
 *
 * The median is the middle element of a sorted array. The given array
 * is copied, sorted, and the middle element is selected. If there are two
 * middle elements, then their average is considered the median
 *
 * @param arr A pointer to the first elemenet of an array of unsigned chars.
 *            The median of this array is calculated
 * @param len The length of arr
 *
 * @return The median of arr
 */
unsigned char find_median(unsigned char * arr, unsigned int len);

/**
 * @brief Finds the mean value of a given array of numbers
 *
 * The mean is the average number of an array, given by the sum of all 
 * elements divided by the number of elements in the array.
 *
 * @param arr A pointer to the first elemenet of an array of unsigned chars.
 *            The mean of this array is calculated
 * @param len The length of arr
 *
 * @return The mean of arr. The instructions weren't clear what type
 * this should be so I cast the mean as an unsigned char.
 */
unsigned char find_mean(unsigned char * arr, unsigned int len);

/**
 * @brief Finds the maximum value of a given array of numbers
 *
 * The maximum is the largest number of an array. The first number is
 * assumed to be the maximum but as the array is traversed, the maximum
 * is set to any numbers larger than the assumed maximum
 *
 * @param arr A pointer to the first elemenet of an array of unsigned chars.
 *            The maximum of this array is calculated
 * @param len The length of arr
 *
 * @return The maximum of arr
 */
unsigned char find_maximum(unsigned char * arr, unsigned int len);

/**
 * @brief Finds the minimum value of a given array of numbers
 *
 * The minimum is the smallest number of an array. The first number is
 * assumed to be the minimum but as the array is traversed, the minimum
 * is set to any numbers smaller than the assumed minimum
 *
 * @param arr A pointer to the first elemenet of an array of unsigned chars.
 *            The minimum of this array is calculated
 * @param len The length of arr
 *
 * @return The minimum of arr
 */
unsigned char find_minimum(unsigned char * arr, unsigned int len);

/**
 * @brief Sorts a given array of numbers from smallest to largest
 *
 * Performs a bubble sort on the given array. As the array is traversed,
 * the largest value bubbles to the end of the array and subsequent traversals
 * bubble the next largest values to the end until the array is sorted.
 *
 * @param arr A pointer to the first elemenet of an array of unsigned chars.
 *            This array is sorted
 * @param len The length of arr
 *
 * @return void
 */
void sort_array(unsigned char * arr, unsigned int len);


#endif /* __STATS_H__ */

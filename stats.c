//------------------------------------------------(Libraries and Macros)
#include <ctype.h>
#include <math.h>
// for the square root function; you will need to compile with the -lm tag at
// the end.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ARRAY_SIZE 100
//-------------------------------------------------(Task 1 Functions)
float findMin(float arr[], int size);
float findMax(float arr[], int size);
float calculateAverage(float arr[], int size);
int findIndexOf(float arr[], int size, float num);
int countOccurences(float arr[], int size, float num);
void printFirst100(float arr[]);
//-------------------------------------------------(Task 2 Functions)

// TA Help for Median, Mode, and sortArray functions

float calculateMedian(float arr[], int size);
float calculateMode(float arr[], int size);
float calculateRange(float arr[], int size);
float calculateStandardDeviation(float arr[], int size, float mean);
float calculateVariance(float arr[], int size, float mean);
void sortArray(float arr[], int size);

//---------------------------------------------(Main Function)
int main() {
  float balance[ARRAY_SIZE];
  int size = ARRAY_SIZE;
  float num;
  float mean = calculateAverage(balance, size);
  // Initialize the array with random values between 0 and 100
  srand((unsigned int)time(NULL));
  for (int i = 0; i < size; i++) {
    balance[i] = ((float)rand() / (float)(RAND_MAX)) *
                 100.0; // Random float values from 0 to 100
  }

  // float *myBalance = (float *)&balance;

  int input = 0;
  while (input != 13) {
    printf(
        "\n Welcome to the Data Explorer: Building Essential Data Analysis "
        "Tools "
        "in C! Please choose an option by entering the corresponding number:");
    printf(
        "\n 1. Find the minimum value\n 2. Find the maximum value\n 3. "
        "Calculate "
        "the average\n 4. Find the index of a given number:\n 5. Count the "
        "occurences of a given number\n 6. Print the first 100 elements\n 7. "
        "Calculate the Median\n 8. Calculate the Mode\n 9. Calculate the "
        "Range\n 10. Calculate the Standard Deviation\n 11. Calculate "
        "Variance\n 12. Sort the Array\n");

    int input;
    int userInput = scanf("%d", &input);

    switch (input) {
    case 1:
      printf("\nMin is :%f\n", findMin(balance, size));
      break;
    case 2:
      printf("\nMax is:%f\n", findMax(balance, size));
      break;
    case 3:
      printf("\n Average is:%f\n", calculateAverage(balance, size));
      break;
    case 4:
      printf("%d", findIndexOf(balance, size, num));
      break;
    case 5:
      scanf("%f", &num);
      printf("\n Count of Occurences:%d\n",
             countOccurences(balance, size, num));
      break;
    case 6:
      printFirst100(balance);
      break;

    case 7:
      printf("\n Median is:%f\n", calculateMedian(balance, size));
      break;
    case 8:
      printf("\nMode is: %.2f\n", calculateMode(balance, size));
      break;
    case 9:
      printf("\nRange is:%f\n", calculateRange(balance, size));
      break;
    case 10:
      printf("\nStandard Deviation is:%f\n",
             calculateStandardDeviation(balance, size, mean));
      break;
    case 11:
      printf("\nVariance is:%f\n", calculateVariance(balance, size, mean));
      break;
    case 12:
      sortArray(balance, size);
      // break statement?

    default:
      printf("Exit");
    }
  }
}
//------------------------------------------------(Outside of int main())

//------------------------------------------------(Task 1)
float findMin(float arr[], int size) {
  // int lowTemp = 0;
  float lowTemp = arr[0];
  for (int i = 0; i < size; i++) {
    // int temp;
    // int enterTemp = scanf("%d", &temp);
    if (arr[i] <= lowTemp) {
      lowTemp = arr[i];
    }
  }
  return lowTemp;
}

float findMax(float arr[], int size) {

  float max = arr[0];

  // Need to set this value to the entire balance[] array
  for (int i = 0; i < size; i++) {
    if (arr[i] >= max) {
      max = arr[i];
    }
  }
  return max;
}

float calculateAverage(float arr[], int size) {
  printf("Elements of array c: ");
  // for (int i = 0; i < ARRAY_SIZE; i++) {
  // printf("%d ", balance[i]);
  int n = size; // Calculate the number of elements
  int sum = 0;
  float average;

  // Calculate the sum of array elements using a loop
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  // Calculate the average
  average = (float)sum / n;

  return average;
}

int findIndexOf(float arr[], int size, float num) {
  // Finds the index of the first occurrence of a given number in the array.
  printf("\nEnter a number\n");
  int givenNumber = scanf("%f", &num);
  // int temp;
  // if (temp == num){temp = num; index= i}
  // int index;

  for (int i = 0; i < size; i++) {
    float epsilon = 1e-9; // A small tolerance value
                          /*if (abs(arr[i] - num) < epsilon) {
                            // The floats are considered approximately equal
                            return i;
                          }*/
    if (num == arr[i])
      return i;
  }
  return -1;
}

int countOccurences(float arr[], int size, float num) {

  int count = 0;

  for (int i = 0; i < size; i++) {
    // arr[i] == num
    if ((int)(arr[i] * 10.0) == (int)(num * 10.0)) {
      count++;
    } 
  }
  return count;
}

void printFirst100(float arr[]) {
  for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d. %.2f\n", i, arr[i]);
  }
}

//-----------------------------------------------------------(Task 2)

float calculateMedian(float arr[], int size) {
  float median = 0;
  sortArray(arr, size);
  // find the max size of the array and then divide by two and find the index
  // of that.

  // for (int i = 0; i < size / 2; i++) {
  //   if (arr[i] == size / 2) {
  //     float median = i;
  //   }
  // }

  if (size % 2 == 0) {
    // even
    //  6/2 = 4
    // (6/2)-1 = 3

    return (arr[(size / 2) - 1] + arr[size / 2]) / 2;

  } else
    return arr[size / 2];
}

float calculateMode(float arr[], int size) {

  float temp;
  int maxOccurrences = 0;
  int occurrence = 0;

  for (int i = 0; i < size; i++) {

    for (int j = 0; i < size; i++) {
      occurrence = countOccurences(arr, size, arr[j]);
    }

    if (occurrence > maxOccurrences) {
      maxOccurrences = occurrence;
      temp = arr[maxOccurrences];
    }
  }

  return temp;
}



float calculateRange(float arr[], int size) {

  // float range = findMax(arr, size) - findMin(arr, size);
  // return range;
  float max = findMax(arr, size);
  float min = findMin(arr, size);
  float range = max - min;
  return range;
}

float calculateStandardDeviation(float arr[], int size, float mean) {
  // calculates sample standard deviation
  
  float numerator = 0;
  mean = calculateAverage(arr, size);
  for (int i = 0; i < size; i++) {

    numerator = ((arr[i] - mean) * (arr[i] - mean)) +
                (((arr[i] + 1) - mean) * ((arr[i] + 1) - mean));
  }

  float sd = sqrtf(numerator / (size - 1));
  return sd;
}

float calculateVariance(float arr[], int size, float mean) {
  float value = calculateStandardDeviation(arr, size, mean);
  float variance = value * value;
  return variance;
}

void sortArray(float arr[], int size) {

  for (int i = 1; i < size; ++i) {
    int temp = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = temp;
  }
}

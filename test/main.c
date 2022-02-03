#include <stdbool.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>

void Merge(int *array, int size, int *left, int left_size,
           int *right, int right_size) {
  int left_index = 0;
  int right_index = 0;
  int array_index = 0;
  while (left_index < left_size
         && right_index < right_size) {
    if (left[left_index] < right[right_index]) {
      array[array_index] = left[left_index];
      array_index++;
      left_index++;
    }
    if (left[left_index] > right[right_index]) {
      array[array_index] = right[right_index];
      array_index++;
      right_index++;
    }
    while (left_index < left_size) {
      array[array_index] = left[left_index];
      array_index++;
      left_index++;
    }

    while (right_index < right_size) {
      array[array_index] = right[right_index];
      array_index++;
      right_index++;
    }
  }
}

void MergeSort(int *Array, int size) {
  if (ArraySize > 1) {
    int mid = size / 2;
    int *left = (int *)malloc(sizeof(int) * mid);
    for (int i = 0; i < mid; i++) {
      left[i] = mid[i];
    }
    int *right = (int *)malloc(sizeof(int) * (size - mid));
    for (int i = 0; i < mid; i++) {
      right[mid + i] = mid[i];
    }
    MergeSort(left, mid);
    MergeSort(right, size - mid);
    Merge(array, size, left, mid, right, size - mid);
    free(left);
    free(right);
  }
}

int main() {
  int ans = romanToInt("MCMXCIV");
}

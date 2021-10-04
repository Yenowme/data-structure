#include <stdio.h>
#include <stdlib.h>

# define MAX 8

int sorted[MAX] = { 0, };

void merge(int arr[], int left, int mid, int right)
{
  int i;
  int j;
  int k;

  i = left;
  j = mid + 1;
  k = left;

  while (i <= mid && j <= right)
  {
    if (arr[i] <= arr[j])
      sorted[k++] = arr[i++];
    else
      sorted[k++] = arr[j++];
  }

  if (i > mid)
  {
    for (int l = j; l <= right; l++)
      sorted[k++] = arr[l];
  }
  else
  {
    for (int l = i; l <= mid; l++)
      sorted[k++] = arr[l];
  }

  for (int idx = left; idx <= right; idx++)
    arr[idx] = sorted[idx];
}

void mergeSort(int arr[], int start, int end)
{
  int mid;
  //반으로 쪼갠다
  if (start < end)
  {
    mid = start + (end - start) / 2; // overflow 방지
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
  }
}

void printArr(int arr[])
{
  printf("arr : ");
  for(int i=0; i<MAX; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(){

  int arr[MAX] = {0, 3, 6, 2, 4, 7, 9, 8};
  printArr(arr);
  mergeSort(arr, 0, MAX - 1);
  printArr(arr);
}

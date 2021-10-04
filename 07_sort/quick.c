#include <stdio.h>
#include <stdlib.h>

# define MAX 8
# define SWAP(x, y, tmp) ( (tmp) = (x), (x) = (y), (y) = (tmp) )

int partition(int arr[], int left, int right)
{
  int pivot;
  int tmp;
  int low;
  int high;

  pivot = arr[left];
  low = left + 1;
  high = right;

  while (low <= high)
  {
    while  (low <= right && arr[low] < pivot)
      low++;

    while (high >= left && arr[high] > pivot)
      high--;

    if (low < high)
      SWAP(arr[low], arr[high], tmp);
  }
  SWAP(arr[left], arr[high], tmp);

  return (high);
}

void quick(int arr[],int start, int end)
{
  if ( start >= end)
    return ;
  int newStart = partition(arr, start, end);
  quick(arr, start, newStart);
  quick(arr, newStart+1, end);
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

int main ()
{
  int tmp;
  int arr[MAX] = {0, 3, 6, 2, 4, 7, 9, 8};
  printArr(arr);
  quick(arr, 0, MAX-1);
  printArr(arr);
}

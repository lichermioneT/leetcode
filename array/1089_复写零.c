#include <stdio.h>

void removeZeros(int* arr, int arrSize)
{
  
  int dest = 0;
  int i = 0;
  while(dest < arrSize)
  {
    if(arr[i] == 0)
    {
      dest += 2;
    }
    else 
    {
      dest += 1;
    }
    i++;
  }

  i--;
  int index = arrSize-1;

  if(dest > arrSize)
  {
    arr[index--] = arr[i];
    i--;
  }

  while(i >= 0)
  {
    if(arr[i] == 0)
    {
      arr[index--] = 0;
      arr[index--] = 0;
    }
    else 
    {
      arr[index--] = arr[i];
    }
    i--;
  }
}


int main()
{

  /*
   *int arr[] ={ 1,0,2,3,0,4,5,0};
   */
  int arr[] ={1,2,3};
  int sz = sizeof(arr) / sizeof(arr[0]);
  
  removeZeros(arr, sz);

  for(int i = 0; i < sz; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");








  return 0;
}

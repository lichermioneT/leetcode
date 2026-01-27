#include <stdio.h>


void print_arr(int* arr, int sz)
{
  for(int i = 0; i < sz; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int removDuplicate(int* arr, int sz)
{
  if(sz < 2)
  {
    return sz;
  }
  
  /*                 i 
   *int arr[] = {1,1,2,2,3,3,3,4,4,4,5,6,7,7,8,8,8};
                     index  
   */
  int index = 2;
  for(int i = 2; i < sz; i++)
  {
    if(arr[index - 2] != arr[i])
    {
       arr[index++] = arr[i];
    }
  }
  return index;
}



int main()
{
  int arr[] = {1,1,2,2,3,3,3,4,4,4,5,6,7,7,8,8,8};
  int sz = sizeof(arr) / sizeof(arr[0]);
  print_arr(arr, sz);
  removDuplicate(arr, sz);
  print_arr(arr, sz);












  return 0;
}

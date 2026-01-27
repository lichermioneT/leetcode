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
  if(sz == 0)
  {
    return 0;
  }

  /*                     i  
   *int arr[] = {1,1,2,2,3,3,3,4,4,4,5,6,7,7,8,8,8};
   *             index
   */
  int index = 0;
  for(int i = 1; i < sz; i++)
  {
    if(arr[index] != arr[i])  // index和i的元素不相等，index往前面移动一个，然后赋值。相等的值就跳过了
    {
      arr[++index]  = arr[i];
    }
  }
  return  index;
}

int main()
{
  /*
   *这里的元素已经排序完成
   */
  int arr[] = {1,1,2,2,3,3,3,4,4,4,5,6,7,7,8,8,8};
  int sz = sizeof(arr) / sizeof(arr[0]);
  print_arr(arr, sz);
  removDuplicate(arr, sz);
  print_arr(arr, sz);
  return 0;
}

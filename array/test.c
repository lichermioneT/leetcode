#include <limits.h>
#include <stdio.h>

int max()
{
  int int_max = INT_MAX;
  int sum = 0;
  while(int_max)
  {
    int t = int_max % 10;
    sum += t * t;
    int_max /= 10;
  }
  return sum;
}

int main()
{

  printf("%d %d \n", INT_MAX, max());

  return 0;
}

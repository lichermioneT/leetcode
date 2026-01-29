#include <stdio.h>

int triangleNumber(int* nums, int numsSize) 
{

    for(int i = 0; i < numsSize - 1; i++)
    {
        
        for(int j = 0; j < numsSize - 1 - i; j++)
        {
            if(nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }


    int ret = 0;
    for(int i = numsSize - 1; i >=2; i--)
    {
        int left = 0;
        int right = i-1;
        
        while(left != right)
        {
            if(nums[left] + nums[right] > nums[i])
            {
                ret += right-left;
                right--;
            }
            else 
            {
                left++;
            }
        }
    }

    return ret;
}



int main()
{
  int arr[] = {2,2,3,4};
  int sz = sizeof(arr) / sizeof(arr[0]);
  printf("%d \n", triangleNumber(arr, sz));


}

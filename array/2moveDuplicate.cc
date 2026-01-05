#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class solution
{
public:
    solution()
    {}
    size_t removeDuplicate(vector<int>& nums)
    {
        if(nums.size() <= 2)
        {
          return nums.size();
        }

        int index = 2; // 从第三个元素开始 
        for(int i = 2; i < nums.size(); i++)
        {
            if(nums[i] != nums[index-2])
            {
              nums[index++] = nums[i];
            }

        }
        return index;
    }

    /*
     *使用双指针思想，利用有序数组的特性，通过比较当前元素与已保留元素中倒数第二个是否相同，来控制每个元素最多保留两次，从而在 O(n) 时间、O(1) 空间内完成去重。
     *index记录当前元素，
     *i遍历循环
     */
    ~solution()
    {}
};

int main()
{

/*
 *;cs 注释
 *;cu 取消注释
 */

  vector<int> v1 = {1,1,1,2,3,3,3,4,5,6,6,7,8,8};
  for(auto & e : v1) {cout<< e << " ";} cout<<endl;
  solution().removeDuplicate(v1);
  for(auto & e : v1) {cout<< e << " ";} cout<<endl;


  return 0;
}

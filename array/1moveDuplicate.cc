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
      if(nums.empty())
      {
        return 0;
      }
     
      // 记录当前的元素
      size_t index = 0;
      for(size_t i = 1; i < nums.size(); i++) // 遍历每一个元素
      {
        if(nums[index]  != nums[i]) // 不等于的话就替换了，等于的话i就直接跳过
        {
          nums[++index] = nums[i];  // 前置加加是应为需要判断
        }
      }
// 双指针index指向需要判断的元素
// 双制作i    遍历真个元素

// 思路
// 一个指针记录当前元素，一个指针遍历数组。
// 记录从0开始，遍历从1开始
// 如果相等则不管，不相等则++，在赋值
      return  index+1;
    }
    size_t removeDuplicate_STL(vector<int>& nums)
    {
      return distance(nums.begin(), unique(nums.begin(), nums.end()));
    }

    ~solution()
    {}
};

int main()
{

/*
 *;cs 注释
 *;cu 取消注释
 */
  vector<int> v1 = {1,1,2,3,3,3,4,5,6,6,7,8,8};

/*
 *  for(const auto& e : v1)
 *  {
 *    cout<< e << " ";
 *  }
 *  cout<<endl;
 *
 *  size_t i = solution().removeDuplicate(v1);
 *  cout<< i <<endl;
 *  for(const auto& e : v1)
 *  {
 *    cout<< e << " ";
 *  }
 *  cout<<endl;
 *
 */

  
  for(const auto& e : v1)
  {
    cout<< e << " ";
  }
  cout<<endl;

  size_t i = solution().removeDuplicate_STL(v1);
  cout<< i <<endl;
  for(const auto& e : v1)
  {
    cout<< e << " ";
  }
  cout<<endl;

  


  return 0;
}

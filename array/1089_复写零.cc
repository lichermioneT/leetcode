#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
  void duplicate(vector<int>& arr)
  {
    int n = arr.size();
    int cur = 0;
    int i = 0;      // 双指针的上指针，这个计算需要最后一个被处理的元素。
    while(cur < n)
    {
      if(arr[i] == 0)
      {
        cur += 2;
      }
      else 
      {
        cur += 1;
      }
      i++;
    }
  
    i--; // 数组的元素数从开始的，最后一次进行++了。
    int index = n - 1; // index双指针的下标,数组 是从零开始的。

    if(cur > n)
    {
        arr[index] = 0; // 特殊情况，最后一个元素一定是零的。
        index--;
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
};


int main()
{

  vector<int> v = {1,0,2,3,0,4,5,0};
  Solution().duplicate(v);
  for(auto& e : v)
  {
    cout<< e << " ";
  }

  cout<<endl;


  vector<int> v1 = {1,0,2,3,0,4};
  Solution().duplicate(v1);
  for(auto& e : v1)
  {
    cout<< e << " ";
  }

  cout<<endl;


  vector<int> v2 = {1,2,3};
  Solution().duplicate(v2);
  for(auto& e : v2)
  {
    cout<< e << " ";
  }

  cout<<endl;

  return 0;
}

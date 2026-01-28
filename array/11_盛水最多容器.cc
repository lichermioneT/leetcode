#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxArea(vector<int>& height)
  {
    int left = 0;
    int right = height.size()-1;
    int ret = 0;

    while(left < right)
    {
      int v  = min(height[left], height[right]) * (right - left);
      ret = max(ret, v);

      if(height[left] < height[right]) left++;
      else right--;
    }


    return ret;
  }

};



int main()
{
  vector<int> v = {1,8,6,2,5,4,8,3,7};
  cout<< Solution().maxArea(v) <<endl;





  return 0;
}

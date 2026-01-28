#include <iostream>
using namespace std;

class Solution 
{
  public:
    bool isHappy(int n)
    {
      int slow = n;
      int fast  = bitSum(n);
      while(fast != slow)
      {
        slow = bitSum(slow);
        fast = bitSum(bitSum(fast));
      }
      return fast == 1;
    }
private:
    int bitSum(int n)
    {
      int sum = 0;
      while(n > 0)
      {
        int t =  n % 10;
        sum += t * t;
        n /= 10;
      }
      return sum;
    }
};



int main()
{

  cout<< Solution().isHappy(19) <<endl;
  cout<< Solution().isHappy(2) <<endl;







  return 0;
}

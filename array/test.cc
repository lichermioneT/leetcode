#include <iostream>
#include <vector>
using namespace std;

int main()
{

  vector<int> v1 = {1,1,2,2,3,4,4,6,7};
  int len = 0;
  for(int i = 0; i < v1.size(); i++)
  {
    if(v1[len] != v1[i])
    {
      v1[++len] = v1[i];
    }
  }
  

  for(auto & e : v1)
  {
    cout<< e << endl;
  }



  return 0;
}

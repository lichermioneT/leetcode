#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{

  vector<int>  v = {1,1,1,2,3,3, 4,4,5,5,10};
                  /*
                   {1,2,3,4,5,10,4,4,5,5,10};
                   */
  for(auto& e : v)
  {
    cout<< e << " ";
  }
  cout<<endl;
  vector<int>::iterator it = unique(v.begin(), v.end());
  
  cout<< *(it++)  <<endl;
  cout<< *(it += 2)  <<endl;
    
  for(auto& e : v)
  {
    cout<< e << " ";
  }
  cout<<endl;

  return 0;
}

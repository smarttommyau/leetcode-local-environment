#include <bits/stdc++.h>
#include "leetcode.hpp"

using namespace std;
class Solution{
  public:
    //method which return thing
    vector<vector<int>> method1(vector<int> &nums){
      //do your stuff
      return vector<vector<int>>();
    }
    //method that use the pass in value as resurlt
    void method2(vector<int> &nums){
      //do something with nums
    }

};
int main(){
  Solution s;
  vector<int> nums1,nums2;
  //method1
  cin >> nums1;
  cout << s.method1(nums1);
  //method2
  cin >> nums2;
  s.method2(nums2);
  cout << nums2;
  return 0;
}

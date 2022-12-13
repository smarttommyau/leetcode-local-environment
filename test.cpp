#include <bits/stdc++.h>
#include <type_traits>
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
  // vector<vector<vector<int>>> nums1,nums2;
  Node* root;
  //method1
  cin >> root;
  // cout << root->left->left->val;
  Node out = *root;
  // cout << out.children[0]->val;
  // cout << out.children[2]->children[0]->val;
  cout << out;
  //method2
  // cin >> nums2;
  // s.method2(nums2);
  // cout << nums2;
  return 0;
}

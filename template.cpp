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
    //method that work with TreeNode (Work same for ListNode)
    TreeNode* method3(TreeNode* root){
      return root;
    }

};
int main(){
  Solution s;
  vector<int> nums1,nums2;
  TreeNode * root;
  //method1
  cin >> nums1;
  cout << s.method1(nums1);
  //method2
  cin >> nums2;
  s.method2(nums2);
  cout << nums2;
  //method3
  cin >> root;
  //ListNode work same as TreeNode require the conversion before TreeNode
  TreeNode outnode = *s.method3(root);//Cannot use TreeNode* directly, as the address will be output if use TreeNode*
  cout << outnode;

  return 0;
}

# leetcode-local-environment
A C++ library that can take input just like leetcode testcase, and structure from leetcode, to allow local coding and debugging for leetcode to become very simple.\
***You can use you FAVOURITE IDE editors on LEETCODE.***
> Issues for new structure to be support are welcomed
# How to use it
Simply clone this repo and ```#include "leetcode.hpp"```, you may take reference on ```template.cpp```
# Currently supported feature
1. multi-dimentional vector input output(bool,int,char)
2. Basic support for TreeNode structure for graph questions
3. cin and cout support for TreeNode
4. cin and cout support for ListNode
5. cin and cout support for Node
# Template
Look at the ***template.cpp*** gives a simple template.\
You can simpily copy and paste the method to the template to start code and debug locally.
# Vector
> multi-dimensional vector are support(bool,int,char)
```
[[0,0,1],[1,2,3]]
[[true,false],[false,true]]
[["h","e","l","l","o"],["w","o","r","l","d"]]
```
## Code (int 2d vector as exmaple)
### Input
```
vector<vector<int>> v;
cin >> v;
```
### Output 
```
vector<vector<int>> v{{0,0,1},{1,2,3};
cout << v;
```
### STDOUT 
```
[[0,0,1],[1,2,3]]
```
# TreeNode/ListNode/Node
> Support for struct TreeNode,ListNode,Node
## Supported Options
1. All contruction methods(also allow auto-completion to work)
2. Input and output with cin,cout
## Format(same as Leetcode)
### TreeNode
![Binary_tree_v2](https://user-images.githubusercontent.com/75346987/206894919-3c640bd4-0dc7-4a44-b95a-1e06b9417612.svg)
```
[1,7,9,2,6,null,9,null,null,5,11,5,null]  
```
### ListNode
![IMG_20221213_113712](https://user-images.githubusercontent.com/75346987/207221033-92061466-5b23-48e0-add5-b5902292f0d1.jpg)
```
[1,2,3,4,5]
```
### Node
![narytreeexample](https://user-images.githubusercontent.com/75346987/207221048-bbdfff6e-4401-47f5-8606-994c721b8e69.png)
```
[1,null,3,2,4,null,5,6]
```
## Code for all kind of Node pointers
```
//code for input
//work similar for ListNode*,Node* too
TreeNode * root;
cin >> root;
//code for output
TreeNode outnode = *root;//cannot use TreeNode* to output as all pointer will output the address directly
cout << outnode;
```
# TODO
1. More kind of vector support
2. Support more kind of leetcode like input

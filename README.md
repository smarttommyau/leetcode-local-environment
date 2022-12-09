# leetcode-local-environment
A C++ library that can take input just like leetcode testcase, and structure from leetcode, to allow local coding and debugging for leetcode to become very simple.\
***You can use you FAVOURITE IDE editors on LEETCODE.***
> Issues for new structure to be support are welcomed
# You can input vector like
> multi-dimensional vector are support(bool,int,char)
```
[[0,0,1],[1,2,3]]
```
## code 
```
vector<vector<int>> v;
cin >> v;
```

# Multi-dimensional vector can also be eaily output
## code
```
vector<vector<int>> v{{0,0,1},{1,2,3};
cout << v;
```
## output 
```
[[0,0,1],[1,2,3]]
```
# Template
Look at the template.cpp gives a simple template.\
You can simpily copy and paste the method to the template to start code and debug locally.

# Currently supported feature
1. multi-dimentional vector input output(bool,int,char)
2. Basic support for TreeNode structure for graph questions

#TODO
1. More kind of vector support
2. Support more kind of leetcode like input
3. cin and cout support for TreeNode

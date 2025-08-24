#include <istream>
#include <ostream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>

//structures
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Node { //class only for auto complete
public:
    int val;
    std::vector<Node*> children;
    Node* left;
    Node* right;
    Node* next;

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}

};
class NodeChildren { //Called Node in leetcode but there are multiple vairant
public:
    int val;
    std::vector<NodeChildren*> children;

    NodeChildren() {}

    NodeChildren(int _val) {
        val = _val;
    }

    NodeChildren(int _val, std::vector<NodeChildren*> _children) {
        val = _val;
        children = _children;
    }
};
class NodeLeftRightNext {//Called Node in leetcode but there are multiple vairant
public:
    int val;
    NodeLeftRightNext* left;
    NodeLeftRightNext* right;
    NodeLeftRightNext* next;

    NodeLeftRightNext() : val(0), left(NULL), right(NULL), next(NULL) {}

    NodeLeftRightNext(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    NodeLeftRightNext(int _val, NodeLeftRightNext* _left, NodeLeftRightNext* _right, NodeLeftRightNext* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
//vector output
template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
    if(v.size()==0){ //catch size equal 0
        out <<"[]";
        return out;
    }
         out << '[';
         bool ischar = std::is_same<char,T>::value;//check if it is a vector<char>
         for(auto x:v){
              out << (ischar?"'":"") << x << (ischar?"'":"") << ",";//ouput 'char'/int
         }
         out << "\b]"; // use two ANSI backspace characters '\b' to overwrite final ", "

    return out;
}

//vector input
//for vector<char>
std::istream& operator>> (std::istream& in, std::vector<char>& v) {
    v.clear();
    char c = in.peek();
    while(c=='\n'||c==' '){
        in.get();
        c = in.peek();
    }
    std::string str;
    std::getline(in,str,']');
    v.reserve(str.size()/4);
    for(std::string::iterator it=str.begin();it<str.end();++it){
        if(*it == '\"' || *it == ','|| *it == '['||*it=='\'')
            continue;
        v.push_back(*it);
    }
    return in;
}
//for vector<int>
std::istream& operator>> (std::istream& in, std::vector<int>& v) {
    v.clear();
    char c = in.peek();
    while(c=='\n'||c==' '){
        in.get();
        c = in.peek();
    }
    std::string str;
    std::getline(in,str,']');
    std::stringstream os;
    for(std::string::iterator it=str.begin();it<str.end();++it){
        if(*it == '[' )
            continue;
        if(*it == ','||it==str.end()-1){
            int temp;
            if(it==str.end()-1)// append the last char for this case
                os << *it;
            os >> temp;
            v.push_back(temp);
            os.clear();
            continue;
        }
        if(*it>'9'||*it<'0')
            continue;
        os << *it;
    }
    return in;
}
//for vector<bool>
std::istream& operator>> (std::istream& in, std::vector<bool>& v) {
    v.clear();
    char c = in.peek();
    while(c=='\n'||c==' '){
        in.get();
        c = in.peek();
    }
    std::string str;
    std::getline(in,str,']');
    for(char x:str){
        if(x=='f')
            v.push_back(false);
        else if(x=='t')
            v.push_back(true);
    }
    return in;
}
template <class T>
std::istream& operator>> (std::istream& in, std::vector<T>& v) {
    v.clear();
    char c = in.peek();
    while(c=='\n'||c==' '){
        in.get();
        c = in.peek();
    }
    std::string str;
    int count =0;
    //take input
    do{
      char x = in.peek();
      if(x=='[')
        count++;
      if(x==']')
        count--;
      if(count>=0)
        str += in.get();
    }while(count >0);
    count =0;
    for(char x:str)
        if(x == '[') count++;
        else break;
    count--;
    std::string sample(count,']');
    size_t lst = 1;
    size_t pos = str.find(sample);
    
    while(pos!=std::string::npos&&pos-lst>=count){
        T temp;
        std::string tmp = std::string(str,lst,pos+count-1);
        std::stringstream os(tmp); 
        os >> temp;
        v.push_back(temp);
        lst = pos+count+1;
        pos = str.find(sample,lst);
    }
    return in;
}

//output TreeNode
//cannot use TreeNode* as std lib will simpily bypass the custom function and output the address
std::ostream& operator<< (std::ostream& out, const TreeNode & root) {
   out  << "[";
   std::queue<TreeNode*> q;
   TreeNode* r = new TreeNode(root.val,root.left,root.right);
   if(r)
     q.push(r);
   int lstNull=0;
   while(!q.empty()){
     int i=0;
     std::queue<TreeNode*> q2 = q;
     while(!q2.empty()){//check if this height of the tree only contains null
       if(q2.front()!=nullptr)
         break;
       q2.pop();
       i++;
     }
     if(i==q.size())
       break;
     for(int size=q.size();size>0;size--){
       TreeNode* node = q.front();
       if(node==nullptr){
         q.pop();
         out << "null,";
         lstNull++;
         continue;
       }
       q.pop();
       out << node->val << ",";
       lstNull=0;
         q.push(node->left);
         q.push(node->right);
     }
   }
  out << std::string(5*lstNull,'\b')+"\b]";//n * 5 * \b delete the last n null and the last comma
    return out;
}

//input TreeNode
std::istream& operator>> (std::istream& in, TreeNode* & root) {
    char c = in.peek();
    while(c=='\n'||c==' '){
        in.get();
        c = in.peek();
    }
  std::string str;
  std::getline(in,str,']');
    if(str.size()==1){
     root = nullptr;
        return in;
    }
  size_t pos = str.find(',');
    if(pos==std::string::npos)
      pos = str.size();
  size_t lst = 1;
  std::queue<TreeNode*> q;
  std::queue<std::pair<TreeNode*,bool>> parent;//parent, and left or right
  root = new TreeNode();
  q.push(root);
  parent.push({nullptr,true});
  while(lst<=pos){
    std::string s(str,lst,pos-lst);
    if(s=="null"){
      delete q.front();
      if(parent.front().second){
        parent.front().first->left = nullptr;
      }else{
        parent.front().first->right = nullptr;
      }
    }else {
      int x = stoi(s);
      q.front()->val = x;
      q.front()->left = new TreeNode();
      q.front()->right= new TreeNode();
      q.push(q.front()->left);q.push(q.front()->right);
      parent.push({q.front(),true}),parent.push({q.front(),false});
    }
    parent.pop();
    q.pop();
    lst = pos+1;
    pos = str.find(',',pos+1);
    if(pos==std::string::npos)
      pos = str.size();
  }

  while(!q.empty()){
    delete q.front();
    if(parent.front().second){
      parent.front().first->left = nullptr;
    }else{
      parent.front().first->right = nullptr;
    }
    parent.pop();
    q.pop();
    TreeNode node = *root;
  }
  return in;
}
//output ListNode
//cannot use ListNode* as std lib will simpily bypass the custom function and output the address
std::ostream& operator<< (std::ostream& out, const ListNode list) {
   out  << "[";
   ListNode* r = new ListNode(list.val,list.next);
   while(r){
       out << r->val << ",";
       r = r->next;
   }
   out <<"\b]";
    return out;
}
// input ListNode
std::istream& operator>> (std::istream& in, ListNode*& list) {
    char c = in.peek();
    while(c=='\n'||c==' ')
        c = in.get();
    std::string str;
    std::getline(in,str,']');
    if(str.size()==1){
     list = nullptr;
        return in;
    }
    std::stringstream os;
    ListNode* node = list;
    bool first =true;
    for(std::string::iterator it=str.begin();it<str.end();++it){
        if(*it == '[' )
            continue;
        if(*it == ','||it==str.end()-1){
            int temp;
            if(it==str.end()-1)// append the last char for this case
                os << *it;
            os >> temp;
            if(first){
                node->val = temp;
                first = false;
            }else{
                node->next = new ListNode(temp);
                node = node->next;
            }
            os.clear();
            continue;
        }
        if(*it>'9'||*it<'0')
            continue;
        os << *it;
    }
    return in;
}

//output NodeChildren variant of node (called node in leetcode)
// beware that a char before the output will be deleted
//cannot use NodeChildren * as std lib will simpily bypass the custom function and output the address
std::ostream& operator<< (std::ostream& out, const NodeChildren node) {
  int lstNull = 0;
  out << "[";
  out << node.val;
  out << ",null,";
  lstNull++;
  std::vector<NodeChildren*> nodes = node.children;
  std::queue<std::vector<NodeChildren*>> q;
  std::queue<int> num;
  q.push(node.children);
  num.push(1);
  num.push(node.children.size());
  while(!q.empty()){
    std::queue<std::vector<NodeChildren*>> tempq = q;
    while(!tempq.empty()&&tempq.front().size()==0){
      tempq.pop();
    }
    if(tempq.size()==0)
      break;
    int temp = num.front();
    num.pop();
    for(int i = 0;i<temp;i++){
      std::vector<NodeChildren*> tempNode = q.front();
      q.pop();
      if(tempNode.size()==0){
          out << "null,";
          lstNull++;
      }
      for(auto x:tempNode){
        out << x->val << ",";
        lstNull=0;
        q.push(x->children);
        num.push(x->children.size());
      }

      if(tempNode.size()!=0){
        out << "null,";
        lstNull++;
      }
    }
  }
  out << std::string(5*lstNull,'\b')+"\b]";//n * 5 * \b delete the last n null and the last comma
  return out;
}
//input NodeChildren
std::istream& operator>> (std::istream& in, NodeChildren*& node) {
    char c = in.peek();
    while(c=='\n'||c==' '){
        in.get();
        c = in.peek();
    }
  std::string str;
  std::getline(in,str,']');
    if(str.size()==1){
     node = nullptr;
        return in;
    }
  node = new NodeChildren();
  size_t pos = str.find(',');
    if(pos==std::string::npos)
      pos = str.size();
  size_t lst = 1;
  bool start = true;
  std::queue<NodeChildren*> parent;
  while(lst<=pos){
    std::string s(str,lst,pos-lst);
    if(parent.empty()){
      int x = stoi(s);
      node->val = x;
      parent.push(node);
    }else if(s=="null"){
      if(!start) parent.pop();
      else start = false;
    }else {
      int x = stoi(s);
      NodeChildren * newnode = new NodeChildren();
      parent.front()->children.push_back(newnode);
      newnode->val = x;
      parent.push(newnode);
    }
    lst = pos+1;
    pos = str.find(',',pos+1);
    if(pos==std::string::npos)
      pos = str.size();
  }
  return in;
}

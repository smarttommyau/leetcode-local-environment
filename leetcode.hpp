#include <istream>
#include <ostream>
#include <queue>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

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
              out << (ischar?"\"":"") << x << (ischar?"\"":"") << ",";//ouput 'char'/int
         }
         out << "\b]"; // use two ANSI backspace characters '\b' to overwrite final ", "

    return out;
}

//vector input
//for vector<char>
std::istream& operator>> (std::istream& in, std::vector<char>& v) {
    v.clear();
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
    std::string str;
    int count =0;
    //take input
    do{
      char x = in.peek();
      if(x=='[')
        count++;
      if(x==']')
        count--;
      if(count>0)
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
         continue;
       }
       q.pop();
       out << node->val << ",";
         q.push(node->left);
         q.push(node->right);
     }
   }
   out <<"\b]";
    return out;
}

//input TreeNode

std::istream& operator>> (std::istream& in, TreeNode* & root) {
  std::string str;
  std::getline(in,str,']');
  size_t pos = str.find(',');
  size_t lst = 1;
  std::stringstream os;
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
    std::string str;
    std::getline(in,str,']');
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

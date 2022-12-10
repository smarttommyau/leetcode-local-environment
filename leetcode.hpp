#include <ios>
#include <istream>
#include<vector>
#include<iostream>
#include<sstream>
#include<iterator>
#include<algorithm>

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
              out << (ischar?"\"":"") << x << (ischar?"\"":"") << ", ";//ouput 'char'/int
         }
         out << "\b\b]"; // use two ANSI backspace characters '\b' to overwrite final ", "

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
    getline(in,str);
    int count =0;
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


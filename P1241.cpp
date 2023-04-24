//平衡括号序列
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution{
    public:
        Solution();
        void print_char();
    private:
        stack<char> in;
        vector<char> out;
};

Solution::Solution(){
    char c;
    c=getchar();
    while(c!='\n'){
        if(c=='('||c=='['){
            in.push(c);
            out.push_back(c);
            if(c=='(')  out.push_back(')');
            if(c=='[')  out.push_back(']');
        }
        if(c==')' || c==']'){
            if(in.empty()){
                if( c==')' )
                    out.push_back('(');
                else
                    out.push_back('[');
            }
            if( c==')' ){
                if(in.top()=='('){
                    char ch=in.top();
                    in.pop();
                    out.push_back( ch );
                }
                out.push_back('(');
                out.push_back(c);
            }
            if( c==']' ){
                if(in.top()=='['){
                    char ch=in.top();
                    in.pop();
                    out.push_back( ch );
                }
                out.push_back('[');
                out.push_back(c);
            }
        }
        c=getchar();
    }
}

void Solution::print_char(){
    auto iter=out.begin();
    while(iter!=out.end()){
        printf("%c",*iter);
        iter++;
    }
}

int main(){
    Solution a;
    a.print_char();
    system("pause");
    return 0;
}
    
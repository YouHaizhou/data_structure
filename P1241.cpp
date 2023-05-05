//平衡括号序列        错误版本
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
            if(!in.empty()){                          //不等于0，说明之前栈已有元素，
                char ch=in.top();
                out.push_back(ch);                       //将已有元素以及对应匹配元素加入输出队列
                if(ch=='(')  out.push_back(')');
                if(ch=='[')  out.push_back(']');
                in.pop();                               //清空栈顶元素，并将读入的元素压入栈顶
                in.push(c);                             
            }
            else
                in.push(c);
        }

        if(c==')' || c==']'){                       //如果是右括符
            if(in.empty()){                         //先判断栈是否为空
                if( c==')' )
                    out.push_back('(');
                else
                    out.push_back('[');
            }

            if( c==')' ){
                if(in.top()=='('){                  //匹配就清空栈顶元素，并加到输出队列中
                    char ch=in.top();
                    in.pop();
                    out.push_back( ch );
                }
                else
                    out.push_back('(');                 //未匹配自动添加对应括符到输出队列中
            }

            if( c==']' ){
                if(in.top()=='['){
                    char ch=in.top();
                    in.pop();
                    out.push_back( ch );
                }
                else
                    out.push_back('[');
            }
            out.push_back(c);               //判断该右括符是否有对应括符后，将该右括符也加到输出队列
        }
        c=getchar();                        //读入下一个字符
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
    
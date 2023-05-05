#include<iostream>
using namespace std;

class Solution{
    public:
        Solution();
        void handle_11();
        void handle_21();
    private:
        char ch[(int)1e5];
        int len=0;
};

Solution::Solution(){
    char c;
    int i=0;
    while(cin>>c,c!='E'){
        if(c=='\n')         //没有必要，cin>>这种方式会忽略空白字符
            continue;
        else{
            ch[i++]=c;
            len++;
        }
    }
}

void Solution::handle_11(){
    int Win=0,Lose=0;
    for(int i=0;i<len;i++){
        if(Win==11||Lose==11){
            if((Win-Lose)>=2 || (Lose-Win)>=2){
                cout<<Win<<":"<<Lose<<endl;
                Win=0;
                Lose=0;
            }
        }
        if(ch[i]=='W')
            Win++;
        else
            Lose++;
    }
    if(Win!=0||Lose!=0){
        cout<<Win<<":"<<Lose<<endl;
    }
}

void Solution::handle_21(){
    int Win=0,Lose=0;
    for(int i=0;i<len;i++){
        if(Win==21||Lose==21){
            if((Win-Lose)>=2 || (Lose-Win)>=2){
                cout<<Win<<":"<<Lose<<endl;
                Win=0;
                Lose=0;
            }
        }
        if(ch[i]=='W')
            Win++;
        else
            Lose++;
    }
    if(Win!=0||Lose!=0){
        cout<<Win<<":"<<Lose<<endl;
    }
}

int main(){
    Solution a;
    a.handle_11();
    cout<<endl;
    a.handle_21();
    system("pause");
    return 0;
}
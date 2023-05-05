#include<iostream>

using namespace std;

class Solution{
    public:
        Solution();
        void view_through();
        int count(int ,int );
    private:
        char map[100][100];     //定义一个二维数组
        int row,line;
};

Solution::Solution(){
    cin>>row>>line;
    for(int i1=0;i1<row;i1++){
        for(int i2=0;i2<line;i2++){
            cin>>map[i1][i2];
        }
    }
}

void Solution::view_through(){
    //依次遍历map元素，如果是？，调用count函数，如果是*，就忽略该元素
    for(int i1=0;i1<row;i1++){               //map.size()是行数
        for(int i2=0;i2<line;i2++){       //map[i1].size()是列数
            if(map[i1][i2]=='?'){
                cout<<count(i1,i2);
            }
            //如果不是？，以字符形式输出该元素到屏幕上
            else
                cout<<map[i1][i2];
        }
        cout<<endl;
    }
}

int Solution::count(int i1,int i2){         //计数该坐标在map图中相邻(左，右，上，下，左上，右上，左下，右下)的*个数
    int count=0;
    if(map[i1-1][i2-1]=='*'){
        count++;
    }
    if(map[i1-1][i2]=='*'){
        count++;
    }
    if(map[i1-1][i2+1]=='*'){
        count++;
    }
    if(map[i1][i2-1]=='*'){
        count++;
    }
    if(map[i1][i2+1]=='*'){
        count++;
    }
    if(map[i1+1][i2-1]=='*'){
        count++;
    }
    if(map[i1+1][i2]=='*'){
        count++;
    }
    if(map[i1+1][i2+1]=='*'){
        count++;
    }
    return count;
}

int main(){
    Solution s;
    s.view_through();
    system("pause");
    return 0;
}

//乒乓球计分
#include<iostream>

using namespace std;

int cnt=0;              //用于记录读入字符个数，后续show函数会使用，要声明成全局变量
char ch[70000];         //储存W和L的数组
void show(int n){
    int a=0,b=0;
    for(int i=0;i<cnt;i++){
        if(ch[i]=='W') a++;
        if(ch[i]=='L') b++;
        if( (a>=n||b>=n) && ((a-b)>=2||(b-a)>=2) ){     //满足输出时的条件
            cout<<a<<":"<<b<<endl;
            a=0;                                //输出后，a，b要归零，可能有下一次输出
            b=0;
        }
    }
    /*                                      //循环结束后可能比赛未打完，按理需要判断a，b是否为零，才确定是否要输出
        if(a!=0||b!=0)
        cout<<a<<":"<<b<<endl;
    */
        cout<<a<<":"<<b<<endl;

}

int main(){
    char c;
    while(cin>>c,c!='E'){       //（cin>>ch&&ch!='E）效果相同
        ch[cnt++]=c;
    }
    show(11);
    cout<<endl;
    show(21);
    system("pause");
    return 0;
}

//总结
/* 
    1.第一次处理，用类的方式处理，写了两个handle函数来处理11和21的情况，实际可以用一个show函数，通过传入参数来判断处理哪种情况（简化代码）
    2. ch[cnt++]=c;可以直接用读入后的cnt代表数组长度，而不用单独声明一个len来储存长度
    3.
*/
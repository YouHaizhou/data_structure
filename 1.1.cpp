
#include<iostream>
#include<vector>
#include<unordered_set> //基于哈希表的关联式容器，容器内元素不重复，适合查找容器中的元素
using namespace std;

//判断是否存在重复元素（哈希表）

class Solution {
public:
    bool containsDuplicate() {
        unordered_set<int> s;
        for(int x:nums){                   //等同于(int i=0；i<nums.max_size();i++)        
            if(s.find(x)!=s.end()) return true; //若查找成功find函数会返回指向查找数的地址，否则返回end（）
            s.insert(x);
        }
        return false;
    }
    Solution(){
        int num;
        while(cin>>num){
            nums.push_back(num);
        }
    }
    vector<int> nums;
};

int main()
{
    Solution a;
    if(a.containsDuplicate()){
        cout<<"repeated number";
        system("pause");
        return 1;
    }
    cout<<"none repeated number";
    system("pause");
    return 1;
}
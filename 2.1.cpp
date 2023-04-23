#include<vector>
#include<iostream>
#include<unordered_map>   //基于哈希表的关联式容器，适合查找元素
using namespace std;

class Solution {
public:
        pair<int,int> twoSum(int target) {              //pair< , >用于配对两个任意类型的值，常用于一起返回两个值
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);     //find函数查找哈希表中的键
            if (it != hashtable.end()) {
                return {it->second, i};     //it- >second表示键为target-nums[i]对应的值，it->first同理
            }
            hashtable[nums[i]] = i;         //nums[i]表示键，i表示键对应的值，键存储i还是nums[i]，看自己需求
        }
        return {};
    }

    Solution(){
        int num;
        while(cin>>num){
            nums.push_back(num);
        }
        cin.clear();                    //清除cin对象的状态标志
        cin.ignore(114514,'\n');           //第一个参数表示从缓冲区取出n个字符并忽略，第二个参数表示取到该参数的字符时函数终止
    }

    vector<int> nums;
};

int main()
{
   Solution a;
   int target;
   cin>>target;
   cout<<a.twoSum(target).first<<" "<<a.twoSum(target).second;
   system("pause");
   return 1;
}
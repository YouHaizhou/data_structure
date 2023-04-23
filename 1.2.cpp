#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

//动态分配问题，

class Solution {
public:
    int maxSubArray() {
            int len=nums.size();
            int* pre=new int[len];
            pre[0]=nums[0];
            for(int i=1;i<len;i++){
                if(pre[i-1]>0) pre[i]=pre[i-1]+nums[i];     //pre数组里存储的是第n项结尾的连续子数组的最大和
                else pre[i]=nums[i];
            }
            int maxans=pre[0];
            for(int i=1;i<len;i++){
                if(maxans<pre[i]) maxans=pre[i];
            }
            return maxans;
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
   cout<<a.maxSubArray();
   system("pause");
   return 1;
}
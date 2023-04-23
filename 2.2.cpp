#include<vector>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class Solution {           
public:
    void merge() {
        
        int end=nums1.size()-1;            //采用逆向思维，从尾部开始，使得空间复杂度为o(1);
        while(p>=0 || q>=0){
            if(p==-1) nums1[end--]=nums2[q--];         //两种特殊情况
            if(q==-1) nums1[end--]=nums1[p--];
            if(nums1[p]>nums2[q]){
                nums1[end--]=nums1[p--];            //在p，q均大于等于0时，end一定符合条件
            }
            else {
                nums1[end--]=nums2[q--];            
            }
        }
    }
    /*
    void print(){
        for(int i:nums1){
            cout<<i<<"";
        }
    }
    */
   void print(){
    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }
   }
    /*
    void print(){
       for(auto i=nums1.begin();i !=nums1.end();i++){       //使用迭代器即指针,只会输出nums1原来的长度
            cout<<*i<<" ";                                  
       }
    }
    */
    Solution(){
        int num;
    
        while (cin >> num) {
            nums1.push_back(num);
            if (cin.get() == '\n') break;       //识别到换行符，终止读入
        }
        
        while (cin >> num) {
            nums2.push_back(num);
            if (cin.get() == '\n') break;
        }
        p=nums1.size()-1;
        q=nums2.size()-1;
        nums1.resize( nums1.size()+nums2.size() );
    }
    vector<int> nums1,nums2;
    int p,q;
};

int main()
{
   Solution a;
   a.merge();
   a.print();
   system("pause");
   return 1;
}
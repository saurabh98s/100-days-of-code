#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int count=0;
        int max=0;
        for(int num:nums){
            if (num==1){
                count++;
            }
            else{
                if(count>max){
                    max=count;
                    
                }
                count=0;
            }
        }
        if(count>max){
            return count;
        }
        return max;
    }
};
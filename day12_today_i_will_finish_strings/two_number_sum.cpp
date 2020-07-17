#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

// given inputs are: [3,5,-4,8,11,1,-1,6],10
// we sort them :    [-4,-1,1,3,5,6,8,11],10

vector<int> two_number_sum(vector<int> array,int targetsum) {

    sort(array.begin(),array.end());

    for (int i = 0; i < array.size(); i++)
    {
            cout<<array[i];
    }
    int left=0;
    int right=array.size()-1;
    while (left<right)
    {
        int currentSum=array[left]+array[right];
        if (currentSum==targetsum)
        {
            return{array[left],array[right]};
        } else if (currentSum< targetsum)
        {
            left++;
        } else if (currentSum> targetsum)
        {
            right--;
        }
    }
    return {};  
}
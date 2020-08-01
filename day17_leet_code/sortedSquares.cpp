#include<string>
#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int>squared;
        for(int i=0;i<A.size();i++){
            int square=(A[i]*A[i]);
            cout<<square<<endl;
            A[i]=square;
        }
        sort(A.begin(), A.end()); 
        return A;
    }
};
#include<vector>
#include<iostream>
using namespace std;

vector<vector<int> > transpose(vector<vector <int> > vec) {
    if(vec.size() ==0){
        return vec;
    }
    int rows=vec.size();
    int columns=vec[0].size();
    if (rows!=columns)
    {
        return vec;
    }
    int length = vec.size();
    for (int i = 0; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
         swap(vec[i][j],vec[j][i]);
        }
        
    }
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length/2; j++)
        {
         swap(vec[i][j],vec[i][length-1-j]);
        }
        
    }

    return vec;
    
}

int main(int argc, char const *argv[])
{
    vector<vector<int> > vec{ { 1, 2, 3 }, 
                         { 4, 5, 6 }, 
                         { 7, 8, 9} }; 
    auto matrix=transpose(vec);
    for (int i = 0; i < matrix.size(); i++) { 
        for (int j = 0; j < matrix[i].size(); j++) 
            cout << matrix[i][j] << " "; 
        cout << endl; 
    } 
    return 0; 
}

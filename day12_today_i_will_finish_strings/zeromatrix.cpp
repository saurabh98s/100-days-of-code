#include<iostream>
#include<vector>
using namespace std;

void zeroRows(vector<vector<int>> matrix,int row) {

    for (int i = 0; i < matrix[0].size(); i++)
    {
        matrix[row][i]=0;
    }
    
}

void zeroCols(vector<vector<int>> matrix,int col) {

    for (int i = 0; i < matrix.size(); i++)
    {
        matrix[i][col]=0;
    }
    
}

vector<vector<int>> checkForZero(vector<vector<int>> matrix){

    vector<int> rows;
    vector<int> cols;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j]==0)
            {
                rows[i]=true;
                cols[i]=true;
            }
            
        }
        
    }
    for (int row = 0; row < rows.size(); row++)
    {
        if (rows[row])
        {
           zeroRows(matrix,row);
        }
        
    }

    for (int col = 0; col < rows.size(); col++)
    {
        if (cols[col])
        {
           zeroCols(matrix,col);
        }
        
        /* code */
    }
    return matrix;
}


int main(int argc, char const *argv[])
{
    vector<vector<int> > vec{ { 1, 2, 3 }, 
                         { 4, 5, 6 }, 
                         { 7, 8, 9} }; 
    auto matrix=checkForZero(vec);
    for (int i = 0; i < matrix.size(); i++) { 
        for (int j = 0; j < matrix[i].size(); j++) 
            cout << matrix[i][j] << " "; 
        cout << endl; 
    }
    return 0;
}

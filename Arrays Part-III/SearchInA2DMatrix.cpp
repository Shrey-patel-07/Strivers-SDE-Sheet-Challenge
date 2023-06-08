#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &mat, int target) {
  int n = mat.size();
  int m = mat[0].size();
  for(int i=0;i<n;i++)
  {
      if(target>=mat[i][0] && target<=mat[i][m-1])
      {
          for(int j=0; j<m; j++)
          {
              if(target == mat[i][j])
              return true;
          }
      }
  }
  return false;
}
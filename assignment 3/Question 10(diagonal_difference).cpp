//https://www.hackerrank.com/challenges/diagonal-difference/submissions/code/294519094




#include <bits/stdc++.h>
using namespace std;



int main(){
        int n,sum1=0,sum2=0,sumo;
    cin>>n;
    int A[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0;i<n;i++){
            sum1+=A[i][i];
    }


      for(int i=0;i<n;i++){
            sum2+=A[i][n-i-1];
      }
      sumo=abs(sum1-sum2);
    cout<<sumo;
    return 0;

}

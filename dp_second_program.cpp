#include <iostream>

using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    long long int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
   for(int i=0;i<n;i++) {
    dp[i][0] = arr[i][0];
   }
   for(int i=1;i<m;i++){
    long long int fmax = -1;long long int smax = -1;
    for(int j=0;j<n;j++){
        if (dp[j][i-1] > fmax) {
            smax = fmax;fmax = dp[j][i-1];
        } else if (dp[j][i-1] > smax) {
            smax = dp[j][i-1];
        }
    }
    for(int j=0;j<n;j++){
        if(dp[j][i-1] == fmax){
            dp[j][i] = arr[j][i]+smax;
        } else {
            dp[j][i] = arr[j][i]+fmax;
        }
    }
   }
    long long int ma = dp[0][m-1];
    
    for(int i=1;i<n;i++){
        if(ma < dp[i][m-1]){
            ma = dp[i][m-1];
        }
    }
    cout<<ma<<endl;
    return 0;
}
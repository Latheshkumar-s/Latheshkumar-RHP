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
    for(int i=0;i<m;i++){
        dp[0][i] = arr[0][i];
    }
    for(int i=1;i<n;i++) {
        long long int fmax = -1;
        long long int smax = -1;
        for(int j=0;j<m;j++){
            if (dp[i-1][j] >= fmax) {
                smax = fmax;
                fmax = dp[i-1][j];
            }
            else if (dp[i-1][j] > smax) {
                smax = dp[i-1][j];
            }
        }
        for(int j=0;j<m;j++){
            if(dp[i-1][j] == fmax){
                dp[i][j] = smax+arr[i][j];
            }
            else{
                dp[i][j] = fmax+arr[i][j];
            }
        }
    }
    long long int ma = dp[n-1][0];
    
    for(int j=1;j<m;j++){
        if(ma < dp[n-1][j]){
            ma = dp[n-1][j];
        }
    }
    cout<<ma<<endl;
    return 0;
}
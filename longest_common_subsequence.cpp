#include <iostream>
int main() {
    std::string s1,s2;
    std::cin>>s1>>s2;
    int len1=s1.length(), len2=s2.length();
    int dp[len1+1][len2+1];
    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            dp[i][j] = 0;
        }
    }
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
                dp[i][j] = std::max(dp[i][j-1],dp[i-1][j]);
        }
    }
    std::cout<<dp[len1][len2]<<std::endl;
    return 0;
}
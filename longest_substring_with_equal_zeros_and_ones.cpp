#include <iostream>
#include <map>
int main() {

    std::map<int,int> m;
    int count_0=0,count_1=0;
    std::string s;
    std::cout<<"Enter string:"<<std::endl;
    std::cin>>s;
    int maxLen = 0;
    m[0] = -1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            count_0++;
        } else{
            count_1++;
        }
        if(m.find(count_1-count_0) != m.end()){
            maxLen=std::max(maxLen, i-m[count_1-count_0]);
        } else {
            m[count_1-count_0] = i;
        }
    }
    std::cout<<"Length of the longest substring:"<<maxLen<<std::endl;
    return 0;
}
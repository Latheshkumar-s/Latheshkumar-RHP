#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int n1,n2,count=0;
  cin>>n1>>n2;
  vector<int> arr1(n1),arr2(n2);
  for(int i=0;i<n1;i++){
    cin>>arr1[i];
  }
  for(int i=0;i<n2;i++){
    cin>>arr2[i];
  }
  sort(arr1.begin(),arr1.end());sort(arr2.begin(),arr2.end());
  n1--;n2--;
  while (n1>=0 && n2>=0) {
    if ((arr1[n1]*2)>=arr2[n2]){
      n1--;n2--;count++;
    } else {
      n2--;
    }
  }
  cout<<count;
  return 0;
}
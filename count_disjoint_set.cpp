#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int find(vector<int> &ldr, int id){
    if(ldr[id] == id){
        return id;
    }
    ldr[id] = find(ldr, ldr[id]);
    return ldr[id];
    
}

void join(vector<int> &ldr, int lt, int rt){
    int ldrlt = find(ldr, lt);
    int ldrrt = find(ldr, rt);
    ldr[ldrrt] = ldrlt;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M; cin>>N>>M;
    vector<int> ldr(N+1);
    for(int i=1;i<=N;i++) ldr[i] = i;
    for(int i=0;i<M;i++){
        int lt,rt; cin>>lt>>rt;
        join(ldr,lt,rt);
    }
    set<int> distinctLeaders;
    for(int i=1;i<=N;i++){
        distinctLeaders.insert(find(ldr, i));
    }
    for(int i : ldr){
        cout<<i<<" ";
    }
    cout<<distinctLeaders.size()<<"\n";
}
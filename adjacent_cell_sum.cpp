#include <iostream>
int main(){
    int r,c;
    int row,col;
    std::cin>>r>>c;
    int arr[r][c];
    int d[8][2] = {{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
    int sum = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            std::cin>>arr[i][j];
    }
    std::cout<<"Array input finished"<<std::endl;
    std::cout<<"Enter cell row and column"<<std::endl;
    std::cin>>row>>col;
    for(int i=0;i<8;i++){
        int nr=row+d[i][0],nc=col+d[i][1];
        if(nr>=0 && nr<r && nc>=0 && nc<c)
            sum+=arr[nr][nc];
    }
    std::cout<<"Sum of adjacent cells:"<<sum<<std::endl;
    return 0;
}
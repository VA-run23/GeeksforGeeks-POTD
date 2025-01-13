//Program to calculate the number of days required to get n geekBits
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of geekBits you want : ";
    cin >> n;
    int x = 0;
    int count = 0;
    for(int i = 1;i<=n;i++){

        x ++;count++;
        if(i %8 ==0){
            x = x+ 8;
        }
        if(x >=n){
            break;
        }

    }
    cout<<"To get"<<n<<" geekBits, you need to wait for "<<count<<" days"<<endl;

    return 0;
}

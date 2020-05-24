#include<iostream>
using namespace std;
int main()
{
    int a, n;
    int bus[1000];
    bool flag;
    long long left, right, middle, nextday, t, d;
    cin >> a;
    for(int index=1; index<=a; index++) {
        cin >> n >> d;
        for(int i=0; i<n; i++)
            cin >> bus[i];

        left=1;
        right=d;
        while(left<=right) {
            middle=(left+right)>>1;
            nextday=middle;
            flag=true;
            for(int i=0; i<n; i++){
                if(nextday%bus[i]!=0){
                    t=nextday/bus[i]+1;
                    if(t*bus[i]>d){
                        right=middle-1;
                        flag=false;
                        break;
                    }
                    nextday=t*bus[i];
                }
            }
            if(flag)
                left=middle+1;
        }
        cout << "Case #" << index << ": " << right << endl; 
    }
    return 0;
}

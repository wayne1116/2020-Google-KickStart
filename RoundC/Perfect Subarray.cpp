#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
// can't use the c++ map structure, or it will be TLE
int map1[20000001];
int main()
{
    int a, n;
    int number[100001];
    int square[4000];
    for(int i=0; i<=3162; i++)
        square[i]=i*i;

    cin >> a;
    for(int index=1; index<=a; index++){
        cin >> n;
        int psum=0;
        int nsum=0;
        for(int i=0; i<n; i++){
            cin >> number[i];
            if(number[i]>0)
                psum+=number[i];
            else
                nsum-=number[i];
        }
        int limit=sqrt(psum);
        long long result=0;
        int dp=0;
        memset(map1, 0, sizeof(int)*(psum+nsum+1));
        map1[nsum]=1;

        for(int i=0; i<n; i++){
            dp+=number[i];
            for(int j=0; j<=limit; j++){
                if(nsum+dp-square[j]>=0)
                    result+=map1[nsum+dp-square[j]];
                else
                    break;
            }
            map1[nsum+dp]+=1;
        }
        cout << "Case #" << index << ": " << result << endl;
    }
    return 0;
}

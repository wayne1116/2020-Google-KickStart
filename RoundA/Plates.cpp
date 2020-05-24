#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a;
    int stacknumber, plates, target;
    int stacks[64][64];
    int dp[64][2048];

    cin >> a;
    for(int index=1; index<=a; index++) {
        cin >> stacknumber >> plates >> target;
        for(int i=0; i<64; i++) {
            for(int j=0; j<2048; j++) 
                dp[i][j]=0;
        }

        for(int i=0; i<stacknumber; i++) {
            stacks[i][0]=0;
            for(int j=1; j<=plates; j++) {
                cin >> stacks[i][j];
                stacks[i][j]+=stacks[i][j-1];
            }
        }
        
        int limit=min(target, plates);
        for(int i=0; i<=limit; i++)
            dp[0][i]=stacks[0][i];
        for(int i=limit+1; i<=target; i++)
            dp[0][i]=dp[0][i-1];

        for(int i=1; i<stacknumber; i++) {
            for(int j=1; j<=plates; j++) {
                for(int k=target; k-j>=0; k--) {
                    dp[i][k]=max(dp[i-1][k], max(dp[i][k], dp[i-1][k-j]+stacks[i][j]));
                }
            }
        }

        cout << "Case #" << index << ": " << dp[stacknumber-1][target] << endl;
    }
    return 0;
}


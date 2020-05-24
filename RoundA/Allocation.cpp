#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a, i;
    int n, money;
    int prices[500001];
    cin >> a;
    for(int index=1; index<=a; index++){
        cin >> n >> money;
        for(int i=0; i<n; i++)
            cin >> prices[i];
        sort(prices, prices+n);
        int sum=0;
        for(i=0; i<n; i++) {
            if(sum+prices[i]>money)
                break;
            sum+=prices[i];
        }
        cout << "Case #" << index << ": " << i << endl; 
    }
    return 0;
}

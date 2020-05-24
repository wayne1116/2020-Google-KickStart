#include<iostream>
using namespace std;
int main()
{
    int a, n, k, i;
    int number[100001];
    cin >> a;
    for(int index=1; index<=a; index++){
        cin >> n >> k;
        for(i=0; i<n; i++)
            cin >> number[i];
        
        int start=0;
        int result=0;
        while(start<n){
            if(number[start]==k){
                for(i=0; i<k && start+i<n; i++){
                    if(number[start+i]!=k-i)
                        break;
                }
                if(i>=k)
                    ++result;
                start+=i;
            }
            else ++start;
        }

        cout << "Case #" << index << ": " << result << endl;
    }
    return 0;
}

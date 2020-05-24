#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int a;
    int n, k;
    int prevsession;
    int currsession;
    int diff[100000];

    cin >> a;
    for(int index=1; index<=a; index++) {
        cin >> n >> k;
        
        cin >> prevsession;
        int Max=0;
        for(int i=0; i<n-1; i++) {
            cin >> currsession;
            diff[i]=currsession-prevsession;
            if(diff[Max]<diff[i])
                Max=i;
            prevsession=currsession;
        }

        int result=1;
        if(diff[Max]>1) {
            // when K = 1 
            if(k==1){
                // find the maximum number
                result=max(diff[Max]>>1, diff[Max]-(diff[Max]>>1));
                for(int i=0; i<n-1; i++) {
                    if(i!=Max) 
                        result=max(result, diff[i]);
                }
            } else {
                // find the optimal difference using binary search
                int left=1;
                int right=diff[Max];
                while(left<=right) {
                    int middle=(left+right)>>1;
                    int key=0;
                    for(int i=0; i<n-1; i++) {
                        int remain=(diff[i]%middle==0)?1:0;
                        key+=(diff[i]/middle)-remain;
                    }
                    if(key>k)
                        left=middle+1;
                    else
                        right=middle-1;
                }
                result=left;
            }
        }
        cout << "Case #" << index << ": " << result << endl;
    }
    return 0;
}

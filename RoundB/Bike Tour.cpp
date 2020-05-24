#include<iostream>
using namespace std;
int main()
{
    int a, n;
    int point[128];
    cin >> a;
    for(int index=1; index<=a; index++) {
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> point[i];
        
        int result=0;
        for(int i=1; i<n-1; i++){
            if(point[i]>point[i-1] && point[i]>point[i+1])
                ++result;
        }

        cout << "Case #" << index << ": " << result << endl;
    }
    return 0;
}

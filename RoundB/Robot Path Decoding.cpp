#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int a;
    long long mod=1000000000;
    string line;
    stack<long long> s1;
    stack<pair<long long,long long> > s2;
    cin >> a;
    for(int index=1; index<=a; index++){
        cin >> line;
        int i=0;
        long long h=0;
        long long v=0;
        while(i<line.size()){
            if(line[i]>='2' && line[i]<='9'){
                s2.push(pair<long long, long long>(h, v));
                s1.push(line[i]-'0');
                h=v=0;
                i+=2;
                continue;
            }
            else if(line[i]==')'){
                long long iter=s1.top();
                s1.pop();
                h*=iter;
                v*=iter;
                pair<long long, long long> t=s2.top();
                s2.pop();
                h=(h+t.first)%mod;
                v=(v+t.second)%mod;
            }
            else if(line[i]=='S')
                ++h;
            else if(line[i]=='N')
                --h;
            else if(line[i]=='W')
                --v;
            else
                ++v;
            h%=mod;
            v%=mod;
            ++i;
        }

        cout << "Case #" << index << ": " << (v+mod)%mod+1 << " " << (h+mod)%mod+1 << endl;
    }
    return 0;
}

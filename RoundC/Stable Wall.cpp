#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int a, row, col;
    int build1[26];
    int build2[26];
    bool taken[26];
    string line[32];
    cin >> a;
    for(int index=1; index<=a; index++) {
        cin >> row >> col;
        for(int i=0; i<26; i++){
            build1[i]=0;
            build2[i]=0;
            taken[i]=false;
        }
        for(int i=0; i<row; i++){
            cin >> line[i];
        }

        for(int i=0; i<col; i++) {
            int c=line[0][i]-'A';
            taken[c]=true;
            for(int j=1; j<row; j++) {
                int base=line[j][i]-'A';
                if(base!=c){
                    build1[c]|=(1<<base);
                    build2[base]|=(1<<c);
                    taken[base]=true;
                    c=base;
                }
            }
        }

        int total=0;
        queue<int> qu;
        for(int i=0; i<26; i++){
            if(build1[i]==0 && taken[i]){
                qu.push(i);
            }
            if(taken[i]) ++total;
        }

        cout << "Case #" << index << ": ";
        if(qu.size()==0)
            cout << "-1" << endl;
        else{
            string result;
            while(qu.size()>0){
                int c=qu.front();
                char t=(c+'A');
                qu.pop();
                result+=t;
                int clear=1<<c;
                for(int i=0; i<26; i++){
                    int mask=1<<i;
                    if((build2[c]&mask)!=0){
                        build1[i]=build1[i]&(~clear);
                        if(build1[i]==0) qu.push(i);
                    }
                }
            }
            cout << (result.size()==total?result:"-1") << endl;
        }
    }
    return 0;
}

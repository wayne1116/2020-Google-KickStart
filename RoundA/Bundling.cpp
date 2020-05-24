#include<iostream>
#include<cstring>
using namespace std;

int sum=0;
char line[1000000];
typedef struct node{
    int count;
    struct node *element[26];
} Node;

void traverse(Node *curr)
{
    for(int i=0; i<26; i++) {
        if(curr->element[i]!=NULL){
            traverse(curr->element[i]);
            delete(curr->element[i]);
        }
    }
}

void Triebuild(struct node *curr, char *line)
{
    int location;
    int len=strlen(line);
    int i=0, j=0;
    
    for(i=0; i<len; i++) {
        location=line[i]-'A';
        if(curr->element[location]==NULL){
            curr->element[location]=new Node;
            curr=curr->element[location];
            curr->count=0;
            for(j=0; j<26; j++)
                curr->element[j]=NULL;
        } else{
            curr=curr->element[location];
        }
        curr->count+=1;
    }
}

int find(Node *curr, int level, int K)
{
    int count=0;
    int i=0;
    int used=0;
    if(curr->count<K && level>0)
        return 0;
    
    for(i=0; i<26; i++){
        if(curr->element[i]!=NULL){
            count+=find(curr->element[i], level+1, K);
        }
    }
    if(curr->count-count>=K) {
        used=(curr->count-count)/K;
        sum+=used*level;
        used*=K;
    }
    return count+used;
}
int main()
{
    int a, i;
    int N, K;
    int index;
    Node root;

    cin >> a;
    for(index=1; index<=a; index++) {
        cin >> N >> K;
        for(int i=0; i<26; i++)
            root.element[i]=NULL;
        root.count=0;

        for(i=0; i<N; i++) {
            cin >> line;
            Triebuild(&root, line);
        }

        sum=0;
        find(&root, 0, K);
        cout << "Case #" << index << ": " << sum << endl;

        traverse(&root);
    }
    return 0;
}

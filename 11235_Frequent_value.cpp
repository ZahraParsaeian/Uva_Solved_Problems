//#define Q11235
#ifdef Q11235

//In his name

//AC

#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef priority_queue<int>pqi;
typedef map<int,int> mi;

int st[400040],num[100010];

int left(int p){  return p<<1; }
int right(int p){  return (p<<1)+1; }

void build(int p, int l, int r){
    if(l==r)
        st[p]=num[l];
    else{
        build(left(p),l,(l+r)/2);
        build(right(p),(l+r)/2+1,r);
        int p1=st[left(p)], p2=st[right(p)];
        if(p1>p2)
            st[p]=p1;
        else
            st[p]=p2;
    }
}

int FV(int p,int l ,int r,int i,int j){
    if(i>r || l>j)  return -1;
    if(l>=i && r<=j)  return st[p];
    int p1=FV(left(p),l,(l+r)/2,i,j);
    int p2=FV(right(p),(l+r)/2+1,r,i,j);
    return(p1 > p2 ? p1 : p2);
}

int main(){

    ios::sync_with_stdio(0);

    int n,q;
    while(cin>>n && n){
        cin>>q;
        int aa,pre;
        cin>>pre;
        int j=1;
        num[1]=j++;
        for(int i=2;i<=n;i++){
            cin>>aa;
            if(aa==pre)
                num[i]=j++;
            else{
                j=1;
                pre=aa;
                num[i]=j++;
            }
        }
        build(1,1,n);
        for(int i=0;i<q;i++){
            int s,f;
            cin>>s>>f;
            int mx=0;
            if(s==f)
                mx=1;
            else if(num[s]>1){
                int tmp=s;
                while(num[s]>1 && s<f)
                    s++;
                if(s==f && num[f]>1)
                    mx=f-tmp+1;
                else
                    mx=s-tmp;
            }
            if(f-s)
                mx=max(mx,FV(1,1,n,s,f));
            cout<<mx<<endl;
        }

    }

    return 0;
}

#endif
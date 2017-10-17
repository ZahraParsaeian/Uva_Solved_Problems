//#define Q12532
#ifdef Q12532

//In his name

//AC

#include<bits/stdc++.h>

using namespace std;

int st[400050],a[100010];

void build(int p,int l,int r){
    if(l==r)
        st[p]=a[l];
    else{
        build((p<<1),l,(l+r)/2);
        build(((p<<1)+1),(l+r)/2+1,r);
        st[p]=st[p<<1]*st[(p<<1)+1];
    }
}

void up(int p,int l,int r, int i , int val){
    if(l>i || r<i)
        return;
    if(l==r)
        st[p]=val;
    else{
        up(p<<1,l,(l+r)/2,i,val);
        up((p<<1)+1,(l+r)/2+1,r,i,val);
        st[p]=st[p<<1]*st[(p<<1)+1];
    }
}

int product(int p,int l,int r,int i,int j){
    if(l>j || r<i)
        return 1;
    if(l>=i && r<=j)
        return st[p];
    return(product(p<<1,l,(l+r)/2,i,j)*product((p<<1)+1,(l+r)/2+1,r,i,j));
}

int main(){

    ios::sync_with_stdio(0);

    int n,k;
    while(cin>>n>>k){
        int b;
        for(int i=1;i<=n;i++){
            cin>>b;
            if(!b)
                a[i]=0;
            else if(b>0)
                a[i]=1;
            else
                a[i]=-1;
        }
        build(1,1,n);
        char c;
        int f,s;
        for(int i=0;i<k;i++){
            cin>>c>>f>>s;
            if(c=='C'){
                if(!s)
                    up(1,1,n,f,0);
                else if(s>0)
                    up(1,1,n,f,1);
                else
                    up(1,1,n,f,-1);
            }
            else if(c=='P'){
                int ans=product(1,1,n,f,s);
                if(!ans)
                    cout<<"0";
                else if(ans>0)
                    cout<<"+";
                else
                    cout<<"-";
            }
        }
        cout<<endl;
    }

    return 0;
}

#endif
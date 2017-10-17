//#define q839
#ifdef q839

//AC

#include<bits/stdc++.h>

using namespace std;

map<int,int>mo;

int isleap(int a){
    if (a % 400 == 0) return true;
    if (a % 100 == 0) return false;
    if (a % 4 == 0) return true;
    return false;
}

int change(int d,int m,int y){
    int cont=d;
    for(int i=1;i<m;i++){
        cont+=mo[i];
    }
    if(isleap(y)&&m>2){
        cont++;
    }
    return cont;
}

int main(){

    ios::sync_with_stdio(0);

    int pre,d,m,y;
    while(cin>>pre>>d>>m>>y && (pre || d || m || y)){
        mo[1]=31,mo[2]=28,mo[3]=31,mo[4]=30,mo[5]=31,mo[6]=30,mo[7]=31,mo[8]=31,mo[9]=30,mo[10]=31,mo[11]=30,mo[12]=31;
        pre+=change(d,m,y) - 1;
        m = 1;
        while(1){
            if(isleap(y)) {
                if(pre<366)
                    break;
                pre -= 366;
            }
            else {
                if(pre<365)
                    break;
                pre -= 365;
            }
            y++;
        }
        if(isleap(y))
            mo[2]=29;
        else
            mo[2]=28;
        //cout << isleap(y) << endl;
        while(pre>=mo[m]){
            pre-=mo[m++];
        }
        cout<<pre + 1<<" "<<m<<" "<<y<<endl;
    }
    return 0;
}


#endif
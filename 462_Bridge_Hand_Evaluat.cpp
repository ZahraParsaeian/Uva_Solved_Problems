#define Q462
#ifdef Q462

#include<bits/stdc++.h>

using namespace std;

vector<int>ac(4),king(4),queen(4),which(4),jack(4),all(4),endd(4);
int sum;

void ezaf(char b,char c){
    int a;
    if(b=='S')
        a=0;
    else if(b=='H')
        a=1;
    else if(b=='D')
        a=2;
    else
        a=3;
    all[a]++;
    if(c=='K') {
        king[a]++;
        sum += 3;
    }
    else if(c=='Q') {
        queen[a]++;
        sum += 2;
    }
    else if(c=='J') {
        sum += 1;
        jack[a]++;
    }
    else if(c=='A') {
        ac[a]++;
        sum += 4;
    }
}

void check(){
    for(int i=0;i<4;i++) {
        //if (king[i] == 1 && which[i] == 0)
        if (king[i] == 1 && all[i] == 1)
            sum -= 1;
        //else if (queen[i] ==1 && (which[i]==0 || which[i]==1))
        else if (queen[i] ==1 && all[i]<=2)
            sum-=1;
        //else if(jack[i]==1 && (which[i]==0 || which[i]==1 || which[i]==2))
        else if(jack[i]==1 && all[i]<=3)
            sum-=1;
    }
}

int ezaf2(){
    int tmp = 0;
    for(int i=0;i<4;i++){
        if(all[i]==2)
            tmp+=1;
        if(all[i]==1 || all[i]==0)
            tmp+=2;
    }
    return tmp;
}

void payan(){
    for(int i=0;i<4;i++){
        if(ac[i]==1 || (king[i]==1 && all[i]>=2) || (queen[i]==1 && all[i]>=3))
            endd[i]=1;
    }
}


int main(){

    string a;
    while(cin>>a){
        sum=0;
        ac.assign(4,0);king.assign(4,0);queen.assign(4,0);which.assign(4,0);jack.assign(4,0);all.assign(4,0);endd.assign(4,0);
        ezaf(a[1],a[0]);
        for(int i=1;i<13;i++){
            cin>>a;
            ezaf(a[1],a[0]);
        }
        payan();
        check();
        bool ok=false;
        int bonus = ezaf2();
        if(sum + bonus <14) {
            cout << "PASS\n";
            continue;
        }

        if(sum>=16){
            bool aya=true;
            for(int i=0;i<4;i++) {
                if (endd[i]==0)
                    aya=false;
            }
            if (aya) {
                cout << "BID NO-TRUMP\n";
                continue;
            }
        }
        int max=all[0];
        char mx='S';
        if(all[1]>max){
            max=all[1];
            mx='H';
        }
        if(all[2]>max){
            max=all[2];
            mx='D';
        }
        if(all[3]>max){
            max=all[3];
            mx='C';
        }
        cout<<"BID "<<mx<<endl;

    }
}

#endif
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

const int N=1010,M=1<<15;
bool fre[M][N][2];
int a[N],r[N],T[N];
int n,res=0,sum=0;

int getbit(int x,int i){
    return 1&(x>>i);
}

int onbit(int x,int i){
    return x|(1<<i);
}

int abs(int a){
    return a>0?a:-a;
}

void cal(int k,int x,int u,int w){
    int z,Mm;
    if(k>n){
        if(w) Mm=(sum+u)/2;
        else Mm=(sum-u)/2;
        if(res<Mm){
            res=Mm;
            for(int i=1;i<=n;i++) r[i]=T[i];
        }
        return;
    }
    if(fre[x][u][w]) return;
    fre[x][u][w]=true;
    for(int i=n-1;i>=0;i--)
    if(getbit(x,i)==0){
        T[k]=i+1;
        z=w;
        if(u<a[i+1]) z=1-w;
        if(u==a[i+1]) z=0;
        cal(k+1,onbit(x,i),abs(u-a[i+1]),z);
    }
}

int main(){
    freopen("candy.inp","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    memset(fre,false,sizeof(fre));
    res=0;
    if(n<=15){
        cal(1,0,0,0);
        //cout<<2*res-sum<<endl;
    }
    else{
        for(int i=1;i<n;i++) r[i]=n-i;
        r[n]=n;
        int sA=0,sB=0;
        for(int i=1;i<=n;i++){
            if(sA>sB) sB+=r[i];
            else
                sA+=r[i];
        }
        if(sA-sB!=n) swap(r[1],r[n]);
    }
    for(int i=1;i<=n;i++) cout<<r[i]<<" ";
}

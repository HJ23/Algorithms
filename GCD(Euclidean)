//euclidean approach

#include<iostream>
#include<unistd.h>
#include<time.h>
using namespace std;
long long euc(long long a,long long b){
//a is always greater than b
    if(a<b){
        long long temp;
        temp=a;
        a=b;
        b=temp;
    }
    if(a%b==0){
        return b;
    }
    else{
        long df=a%b;
        euc(b,df);
    }
    

}


int main(){
    clock_t start=clock();
    cout<<euc(123489123233468,567887344268)<<endl;
    cout<<(float)(clock()-start)/CLOCKS_PER_SEC;
}

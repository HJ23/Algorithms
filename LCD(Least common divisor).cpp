//eucledian approach

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
long long lcd(long long a,long long b){
    if(a<b){
        long long temp;
        temp=a;
        a=b;
        b=temp;
    }
    return (a/euc(a,b))*b;

};


int main(){
    clock_t start=clock();
    cout<<lcd(65,10)<<endl;
    cout<<(float)(clock()-start)/CLOCKS_PER_SEC;
}

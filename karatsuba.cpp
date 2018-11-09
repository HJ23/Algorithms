
//simple KARATSUBA Algorithm
// Please check github repository for resource usage 

#include<iostream>
#include<unistd.h>
#include<fstream>
#include<string>
#include<math.h>
#include<time.h>

using namespace std;
int value=1;
int multiply(unsigned int,unsigned int);
int main(){
    clock_t start=clock();
    cout<<102034*5000;
    
    cout<<endl;
    cout<<(float)(clock()-start)/CLOCKS_PER_SEC<<endl;
    cout<<"newone----------"<<endl;
    start=clock();
    cout<<multiply(102034,5000);
    cout<<endl;
    cout<<(float)(clock()-start)/CLOCKS_PER_SEC;        
    
}

int multiply(unsigned int x,unsigned int y){
    unsigned int z0,z1,z2;
    string sx=to_string(x);
    string sy=to_string(y);
    int xn=sx.length();
    int yn=sy.length();
    if(xn<yn){
        unsigned int temp=yn;
        yn=xn;
        xn=temp;
        unsigned int tempp=x;
        x=y;
        y=tempp;
    }
    yn--;  //smallest
    
    z2=(int)floor(x/pow(10,yn))*(int)floor(y/(pow(10,yn)));
    z0=(x-(int)floor(x/pow(10,yn))*pow(10,yn))*(y-(int)floor(y/(pow(10,yn)))*pow(10,yn));
    z1=((int)floor(x/pow(10,yn))+(x-(int)floor(x/pow(10,yn))*pow(10,yn)))*((int)floor(y/(pow(10,yn)))+(y-(int)floor(y/(pow(10,yn)))*pow(10,yn)))-z2-z0;
    value=z2*pow(pow(10,yn),2)+z1*pow(10,yn)+z0;
    return value;
};








































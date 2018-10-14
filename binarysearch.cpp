#include<iostream>
#include<math.h>
using namespace std;
int sortedarray[]={12,19,34,43,233,455,534,789,5666,122212,516666};
template <class x>
int binarysearch(x* ,x,int);
int main(int argv,char** argc){

   cout<< binarysearch(sortedarray,516666,11);


}
template <class x>
int binarysearch(x *sortedarray,x obj,int size){
    int n=(int)floor(size/2);
    
    do{
        if(*(sortedarray+n)>obj)
            n=(int)floor(n/2);
        else if(*(sortedarray+n)<obj)
            n=(size+n)/2;
       
    }while(*(sortedarray+n)!=obj);
    n++;
    return n;
    }

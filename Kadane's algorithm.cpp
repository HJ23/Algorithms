#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
vector<int > abc{-2,-3,4,-1,-2,1,5,-3};
vector<int>::iterator p;
p=abc.begin();
int current=*p;
int max=*p;
int start,stop;
for(int x=1;x<abc.size();x++){
    current=*(p+x)+current;
    if(current>max){
        if(*(p+x)>current){
            start=x;
            max=*(p+x);
            current=max;
        }
        else{
            stop=x;
            max=current;
            }
//keep going
    }

}
cout<<start<<endl;
cout<<stop<<endl;
cout<<max;

}

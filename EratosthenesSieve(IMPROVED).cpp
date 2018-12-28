#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
void primesieve(int limit){
vector<int> result;
vector<bool> tf;
tf.push_back(false);
tf.push_back(false);
for(int x=2;x<=limit;x++)
     tf.push_back(true);
for(int x=2;x<=static_cast<int>(sqrt(limit)+1);x++){
    if(tf[x]){
        bool prime=true;
        for(int y=2;y<=static_cast<int>(sqrt(x)+1);y++){
            if(x%y==0 and y!=x){
                prime=false;
                break;}
        }
        if(prime){
            for(int z=2;z<=static_cast<int>(limit/x);z++ )
                tf[x*z]=false;
        }else{
            for(int z=1;z<=static_cast<int>(limit/x);z++ )
                tf[x*z]=false;
        }

    }
}
int n=0;
for(int z=0;z<limit;z++){
     if(tf[z]){
        
         n++;
     }
}
cout<<"result::"<<n;

}





int main(){

primesieve(10000000);


}

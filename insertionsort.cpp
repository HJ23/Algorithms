#include<iostream>
#include<stdint.h>
using namespace std;

int *insertionsort(int*,int );
int array[]={4,5,2,1,6,67,12,4,534,231,113,5345};
int main(int argv,char** argc){

    int *arr=insertionsort(array,12);
    for(int as=0;as<=11;as++){
        cout<<*(arr+as)<<",";
    
    }

}

int *insertionsort(int* array, int size){
//use acctually size
    for(int x1=1;x1<size;x1++){
        for(int y=0;y<=x1;y++){
        
            if(array[x1]<array[y]){
               int a;
                a=array[x1];
                array[x1]=array[y];
                array[y]=a;
            }
        
        }
       
        }
    return array;
    
}

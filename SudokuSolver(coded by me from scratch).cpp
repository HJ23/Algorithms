#include<iostream>
#include<time.h>
#include<vector>
#include<algorithm>
#include<unistd.h>
#include <mutex>
#include <set>
using namespace std;
vector<set<int>> data;
vector<pair<int,int>> coordinates;
int grid[9][9]={{8,0,0,0,0,0,0,0,0},{0,0,3,6,0,0,0,0,0},{0,7,0,0,9,0,2,0,0},
{0,5,0,0,0,7,0,0,0},{0,0,0,0,4,5,7,0,0},{0,0,0,1,0,0,0,3,0},
{0,0,1,0,0,0,0,6,8},{0,0,8,5,0,0,0,1,0},{0,9,0,0,0,0,4,0,0}};

pair<int,int> retcoordinate(int x,int y){
    pair<int,int> sd;
    int rx,ry;
    if(x<=2)
        rx=3;   
    else if(x<=5 && x>2)
        rx=6;
    else if(x<=8 && x>5)
        rx=9;
    if(y<=2)
       ry=3;
    else if(y>2 && y<=5)
       ry=6;
    else if(y>5 && y<=8)
       ry=9;  
    sd.first=rx;
    sd.second=ry;
    return sd;
    
}
//checks number is right for that coordinates?
bool check(int grid[9][9],int x,int y,int number){
for(int zx=0;zx<=8;zx++){
    if(grid[zx][y]==number){
        if(zx!=x)
            return false;
    }
    if(grid[x][zx]==number){
        if(zx!=y)
            return false;
    }
}
 
for(int zx=retcoordinate(x,y).first-3;zx<retcoordinate(x,y).first;zx++){
for(int zy=retcoordinate(x,y).second-3;zy<retcoordinate(x,y).second;zy++){
    if(zx!=x && zy!=y){
        if(grid[zx][zy]==number){
            return false;
        }
    }
}
}

return true;
}
//creates possible sets
void createset(int grid[9][9]){
    pair<int,int> xy;
    set<int> set1={1,2,3,4,5,6,7,8,9};
    for(int x=0;x<=8;x++){
        for(int y=0;y<=8;y++){
            if(grid[x][y]==0){
            set<int> set2;
            set <int> result;
            for(int zx=0;zx<=8;zx++){
                set2.insert(grid[zx][y]);
                set2.insert(grid[x][zx]);
            }
            for(int zy=retcoordinate(x,y).first-3;zy<retcoordinate(x,y).first;zy++){
            for(int zz=retcoordinate(x,y).second-3;zz<retcoordinate(x,y).second;zz++){
                set2.insert(grid[zy][zz]);
            }
                
            }
            //here
            set_difference(set1.begin(),set1.end(),set2.begin(),set2.end(),inserter(result,result.end()));
            if(result.size()==1)
                grid[x][y]=*(result.begin());
            else{
                xy.first=x;
                xy.second=y;
                coordinates.push_back(xy);
            data.push_back(result);}
            }
        }
    }
 
    
}
void print(int grid[9][9]){
    cout<<"\n";
    for(int x=0;x<=8;x++){
        for(int y=0;y<=8;y++){
            cout<<grid[x][y]<<" ";
        }
        cout<<"\n";
    }
}






//main function
int main(int argc,char** argv){
    clock_t start=clock();
    int temp[9][9];
    int n=0,size;
    createset(grid);
    int lenght[data.size()];
    
    for(int y=0;y<data.size();y++){
        lenght[y]=0;
    }
    
    for(int x=0;x<=8;x++){
        for(int y=0;y<=8;y++){
            temp[x][y]=grid[x][y];
        }
    }
    
    
    //everything is ready just iterate!
    while(n!=data.size()){
        size=lenght[n];
        if(size==data.at(n).size()){
            temp[coordinates.at(n).first][coordinates.at(n).second]=0;
            lenght[n]=0;
            n--;
            if(lenght[n]!=data.at(n).size()){
                lenght[n]=lenght[n]+1;
            }
        }
        else{
            set<int>::iterator sd;
            sd=data.at(n).begin();
            advance(sd,size);
            if(check(temp,coordinates.at(n).first,coordinates.at(n).second,*sd)){
                
                temp[coordinates.at(n).first][coordinates.at(n).second]=*sd;
                lenght[n]=size;
                n++;
               
                
            }
            else{
                size+=1;
                lenght[n]=size;  
                
            }
        
        }
        sleep(0.5);
        
        
    
    }
    cout<<double(clock()-start)/CLOCKS_PER_SEC;
      print(temp);
    
    
    
    
    
    
    
    
    /*
    cout<<"\n";
    vector<set<int>>::iterator r;
    set<int>::iterator y;
    for( r=data.begin();r!=data.end();r++){
        for(y=r->begin();y!=r->end();y++){
            cout<<*y;
        }
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"*****************************";
    vector<pair<int,int>>::iterator sd;
    for(sd=coordinates.begin();sd!=coordinates.end();sd++){
        cout<<sd->first<<","<<sd->second;
        cout<<"\n";
    } */
      return 0;
    
}

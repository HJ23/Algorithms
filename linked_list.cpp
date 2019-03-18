#include<iostream>
#include<string>
using namespace std;


template<class T>
class node{
private:T element;
        node<T>* next_link;
        template <class U> 
        friend class linked_list;
};

template<class T>
class linked_list{
private:node<T> *head=nullptr,*tail=nullptr;
        int count=0;
public:void add(T a);
       void delete_link(int pos);
       void update(T element,int pos);
       void show();
};
template<class T>
void linked_list<T>::add(T a){
           count++;
           node<T> *temp=new node<T>;
           temp->element=a;
           temp->next_link=nullptr;
           if(head==nullptr){
              head=temp;
              tail=temp;
               
           }
           else{
               tail->next_link=temp;
               tail=temp;
           }
}
template<class T>
void linked_list<T>::show(){
     node<T> *a;
     a=head;
     while(a!=nullptr){
        cout<<a->element<<endl;
        a=a->next_link;
     }
}
template<class T>
void linked_list<T>::delete_link(int pos){
    if(count>=pos and pos!=1){
    node<T> *pre;node<T> *cur=head;node<T>* next;
    for(int x=1;x<pos;x++){
        pre=cur;
        cur=pre->next_link;
        
    }
    next=cur->next_link;
    pre->next_link=next;
    }
    else if(pos==1){
        head=head->next_link;
    }
}

template<class T>
void linked_list<T>::update(T element,int pos){

     if(count>=pos and pos!=1){
    node<T> *pre;node<T> *cur=head;node<T>* next;
    for(int x=1;x<pos;x++){
        pre=cur;
        cur=pre->next_link;
    }
    cur->element=element;
    }
    else if(pos==1){
        head->element=element;
    }

}




int main(){
linked_list<double> a;
a.add(34.899);
a.add(333);
a.add(444);
a.delete_link(2);
a.update(333333,2);
a.show();

}

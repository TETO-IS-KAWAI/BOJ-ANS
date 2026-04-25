//#include<stdio.h>
//#include<stdlib.h>
//struct Card { char k; int v; Card *next;};
//class Clist {
//  private:
//    Card *head=NULL; int size=0;
//  public:
//    void insertCard(int idx, Card data);
//    void printList();
//};
//void Clist::insertCard(int idx, Card data){
//    if(idx<=0 or idx>size+1) return;
//    Card *p=NULL,*t=head;
//    Card *c=(Card*)malloc(sizeof(Card));
//    *c=data;
//    for(int i=1;i<idx;i++,p=t,t=t->next);
//    c->next=t;
//    if(p) p->next=c;
//    else head=c;
//    size++;
//}
// 
//void Clist::printList(){
//    for(Card *t=head; t!=NULL; t=t->next){
//        printf("%c%d ",t->k,t->v);
//    }
//}
//int main() {
//  Card c;
//  Clist list;
//  int idx;
//  for(int i=0;i<10;i++) {
//    scanf(" %c %d %d",&c.k, &c.v, &idx);
//    list.insertCard(idx, c);
//  }
//  list.printList();
//}

//#include<stdio.h>
//#include<stdlib.h>
//struct Card { int v; char x[11]; Card *next;};
//class Clist {
//  private:
//    Card *head=NULL; int size=0;
//  public:
//    void insertCard(Card data);
//    void printList(int* L);
//    void deleteCard(int idx);
//};
// 
//void Clist::insertCard(Card data){
//    Card *p=NULL,*t=head;
//    Card *c=(Card*)malloc(sizeof(Card));
//    *c=data;
//    for(;t!=NULL and t->v < data.v;p=t,t=t->next);
//    if(!p and t==NULL){
//        c->next=t;
//        head=c;
//        size++;
//    }
//    else if(t==NULL){
//        c->next=t;
//        p->next=c;
//        size++;
//    }
//    else if(data.v!=t->v){
//        c->next=t;
//        if(p) p->next=c;
//        else head=c;
//        size++;
//    }
//}
// 
//void Clist::deleteCard(int idx){
//    Card *p=NULL,*t=head;
//    for(;t!=NULL and t->v < idx;p=t,t=t->next);
//    if(t!=NULL && t->v==idx){
//        if(p) p->next=t->next;
//        else head=t->next;
//        free(t);
//        size--;
//    }
//}
// 
//void Clist::printList(int* L){
//    int j=0;
//    int i=0;
//    for(Card *t=head; t!=NULL; t=t->next){
//        j++;
//        if(j==L[i]){
//            printf("%d %s \n",t->v,t->x);
//            i++;
//        }
//        if(i>=5){
//            break;
//        }
//    }
//}
//  
//int main() {
//  Card c;
//  Clist list;
//  char s;
//  int n;
//  scanf("%d",&n);
//  for(int i=1;i<=n;i++) {
//    scanf(" %c %d %s",&s, &c.v, &c.x);
//    if(s=='I') list.insertCard(c);
//    else list.deleteCard(c.v);
//  }
//  int L[5];
//  for(int i=0;i<5;i++){
//    scanf(" %d",&L[i]);
//  }
//  list.printList(L);
//}

//#include<stdio.h>
//#include<stdlib.h>
//struct Card { char k; int v; Card *next;};
//class Clist {
//  private:
//    Card *head=NULL; int size=0;
//  public:
//    void insertCard(int idx, Card data);
//    void reverse();
//    void printList();
//};
//void Clist::insertCard(int idx, Card data){
//    if(idx<=0 or idx>size+1) return;
//    Card *p=NULL,*t=head;
//    Card *c=(Card*)malloc(sizeof(Card));
//    *c=data;
//    for(int i=1;i<idx;i++,p=t,t=t->next);
//    c->next=t;
//    if(p) p->next=c;
//    else head=c;
//    size++;
//}
// 
//void Clist::printList(){
//    for(Card *t=head; t!=NULL; t=t->next){
//        printf("%c%d ",t->k,t->v);
//    }
//}
// 
//void Clist::reverse(){
//    Card *p=NULL, *t;
//    while(head){
//        t=head->next;
//        head->next=p;
//        p=head;
//        head=t;
//    }
//    head=p;
//}
//int main() {
//  Card c;
//  Clist list;
//  int idx,n,k;
//  scanf("%d%d",&n,&k);
//  for(int i=1;i<=n;i++) {
//    scanf(" %c %d %d",&c.k, &c.v, &idx);
//    if(i%k) list.insertCard(idx, c);
//    else list.reverse();
//  }
//  list.printList();
//}

#include <stdio.h>
#define INF 1000000000

int n, s, a[100010];
int sum, min=INF, st=0, en=0;

int main(){
    scanf("%d%d", &n, &s);
    for(int i=0;i<n;i++){
        scanf("%d", a+i);
    }
    
    while(true){
        if(sum>=s){
            if(en-st<min){
                min=en-st;
            }
            sum-=*(a+st++);
        }else if(en==n){
            break;
        }else{
            sum+=*(a+en++);
        }
    }
    
    if(min==INF){
        printf("0");
    }else{
        printf("%d",min);
    }
}
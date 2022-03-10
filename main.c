#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef   void      (*FunctionPointer)  (int Step );
//         ^                ^         ^
//     return type      type name  arguments



void add(int n){
    clock_t ts;

    ts=clock();
    printf(" add function.\n");
    while((clock()-ts)/CLOCKS_PER_SEC<=5);
    printf(" finished add function.\n");
}

void minus(int n){
 clock_t ts;

 ts=clock();
 printf(" minus function.\n");
 while((clock()-ts)/CLOCKS_PER_SEC<=5);
 printf(" finished minus function.\n");
}

void sum(int n){
 clock_t ts;

 ts=clock();
 printf(" sum function.\n");
 while((clock()-ts)/CLOCKS_PER_SEC<=5);
 printf(" finished sum function.\n");
}

FunctionPointer myfun[3]={add, minus, sum};

struct LinkedList{
 int value;
 struct LinkedList *next;
 struct LinkedList *prev;
} *myls;

int NrItems,n,v,i;
struct LinkedList *head,*tail;


void InsertOneItem(int vl){
  struct LinkedList *current=(struct LinkedList *)malloc(sizeof(struct LinkedList));
  current->value=vl;

  if(head!=NULL)
   head->prev=current;

  current->next=head;
  if(current->next==NULL) tail=current;
  head=current;
}

void DeleteOneItem(int vl){
struct LinkedList *p;

 p=head;
 //search for the item
 while(p->value!=vl){
    p=p->next;
    if(p==NULL) {
        printf("there is no such item!\n");
        break;
    }
 }

 if(p!=NULL){
   if(p==head){//delete the head
      head=p->next;
      p->next->prev=NULL;
   }
   else if(p==tail){//delete the tail
      tail=p->prev;
      p->prev->next=NULL;
   }
   else{//delete some one in the middle
    p->prev->next=p->next;
    p->next->prev=p->prev;
   }

    NrItems--;
 }

}

void PrintList(){
    myls=head;

    //print out the value
    for(n=0;n<NrItems;n++){
      printf("the value of Item %d is %d.\n",n,myls->value);
      myls=myls->next;
    }
}

void ReversePrint(){
    printf("Reversed print:\n");

    myls=tail;
    //reverse the list
    for(n=0;n<NrItems;n++){
        printf("the value of Item %d is %d.\n",n,myls->value);
        myls=myls->prev;
    }
}

void LinkeListTest(){
int num,index;

    printf("Input the number of list items: \n");
    scanf("%d",&NrItems);

    head=NULL;
    tail=NULL;

    //input the value
    for(n=0;n<NrItems;n++){
       printf("the value of Item %d : \n",n);
       scanf("%d",&v);
       printf("you have entered %d\n",v);
       InsertOneItem(v);
    }

    PrintList();
    ReversePrint();

 for(index=0;index<5;index++){
    printf("which one you want to delete?\n");
    scanf("%d",&num);

    DeleteOneItem(num);
    PrintList();
    ReversePrint();
  }
     free(myls);
     free(head);
     free(tail);

}


int main(){
//{   int index,k;
//    clock_t start;
//
//    start=clock();
//
//    for(k=0;k<5;k++){
//
//        while((clock()-start)/CLOCKS_PER_SEC<=2);
//
//        printf("which function you want: \n");
//        scanf("%d",&index);
//
//        if(index<3 && index>0){
//            myfun[index](0);
//        }
//        start=clock();
//    }
    LinkeListTest();


    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef   void      (*FunctionPointer)  (int Step );
//         ^                ^         ^
//     return type      type name  arguments

typedef  struct FunLink{
    int var;
    struct FunLink *next;
    FunctionPointer fp;
} Fun;

Fun *Head=NULL;
Fun *Tail=NULL;
Fun *BeforeTail=NULL;

void InsertAfterTail(FunctionPointer *p){
Fun *current=(Fun *)malloc(sizeof(Fun));

current->fp=p;

if(Tail==NULL && Head==NULL){
    Head=current;
    BeforeTail=current;
    current->next=NULL;
    current->var=1;
}
else{//not the head
    current->var=(BeforeTail->var+1);
    BeforeTail->next=current;
    current->next=Tail;
    BeforeTail=current;
}

}

bool CheckIfPressKey(char x){
  bool r=false;
  //if get anything input from the keyboard,
  //get a char from keyboard and if it's character x, then return true
  if(kbhit()){
    if(getchar()==x)
       r=true;
  }

  return r;
}

void add(int n){
    clock_t ts;
    ts=clock();

    while(!CheckIfPressKey('q')){
      if((clock()-ts)/CLOCKS_PER_SEC>=1){
        printf(" executing add function.\n");
        ts=clock();
      }
    }
    printf(" finished add function.\n");
}

void minus(int n){

 printf(" minus function.\n");

}

void sum(int n){

 printf(" sum function.\n");

}


int main(){
Fun *mylist;


    InsertAfterTail(add);
    InsertAfterTail(minus);
    InsertAfterTail(sum);
    InsertAfterTail(add);
    InsertAfterTail(sum);
    InsertAfterTail(sum);

    mylist=Head;

    while(mylist!=NULL){
          printf("Index %d :\r\n",mylist->var);

          (*(mylist->fp))(0);

          mylist=mylist->next;
    }


    return 0;
}

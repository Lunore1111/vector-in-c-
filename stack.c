


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct{
   int *arr;
   int current;
   int size;
   int capacity;
   }stack;

void i_stack(stack *st,int n);
void push(stack *st,int val);
int pop(stack *st);
bool empty(stack *st);

   
void i_stack(stack *st,int n)
{   (*st).current=0;
    (*st).capacity = n;
    (*st).size=0;
    (*st).arr = (int*)malloc(n*sizeof(int));
    
    
}
void push(stack *st,int val)
{  
    if((*st).current>=(*st).capacity){
        printf("STACK OVERFLOW,\n");
        printf("for adding  element %d",val);
    }
     else
     {
         (*st).arr[(*st).current]= val;
         (*st).current++;
         (*st).size++;
     }
   }
int pop(stack *st)
{
    if((*st).current<1)
    {
        printf("STACK UNDERFLOW,There was only Element");
    }
    else {

        (*st).arr[(*st).current]=0;
        (*st).current--;
        (*st).size--;
    }
    
}
bool empty(stack *st){
    if((*st).size==0) return true;
    return false ;
}

int main(){

stack st;

i_stack(&st,4);

push(&st,1);
push(&st,2);
push(&st,3);

while(!emtpy(&st))
{
    int ele= pop(&st);
    printf("%d",ele);
}


free(st.arr);
return 0;
}

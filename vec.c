     
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
                   
typedef struct{
    int *arr;
    int size;
    int current;
    int limit;
    int capacity;

} vec;

void i_vector(vec *v,int n);
int v_size(vec *v,int *arr);
void v_push(vec *v,int *arr,int value);
void v_pop(vec *v,int *arr);
void v_display(vec *v,int *arr,int n);
void ni_vector(vec *v);
void v_insert(vec *v,int *arr,int position,int value);
bool v_empty(vec *v,int *arr);
void v_clear(vec *v,int *arr);

void i_vector(vec *v,int n)
{
    v->size = n;
    v->arr=(int*)malloc(n*sizeof(int));
    v->current=0;
    v->capacity=0;
    for(int i=0;i<n;i++){
        scanf("%d",&v->arr[i]);
        v->current++;
    }
    v->capacity = n;
  }
int v_size(vec *v,int *arr){

  return v->size;
}
void v_push(vec *v,int *arr,int value)
{
     if(v->limit >= 2){
         v->arr[v->current]=value;
         v->current++;
        v->size++;
        if(v->size>=2)
        {
            v->arr=(int*)realloc(v->arr,(v->limit+2)*sizeof(int));
            v->capacity = v->limit + 2;
        }
     }
 else{
    v->arr=(int*)realloc(v->arr,(v->size +2 ) * sizeof(int));
    v->capacity = v->limit + 2;
    v->arr[v->current] = value;
    v->current++;
    v->size++;
}
  }
void v_pop(vec *v,int *arr)
{
   v->size--;
   v->current--;
}
void v_display(vec *v,int *arr,int n)
{
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}
void ni_vector(vec *v)
{
    v->limit = 2;
    v->arr=(int*)malloc(v->limit*sizeof(int));
    v->size=0;
    v->current=0;
    v->capacity=0;
}

void v_insert(vec *v,int *arr,int position,int value)
{      v->arr = (int*)realloc(v->arr,(v->size+2)*sizeof(int));
       v->capacity = v->size + 2 ;
       for(int i=v->size;i>position;i--)
       {
           v->arr[i]=v->arr[i-1];
       }
       v->arr[position]=value;
       v->size++;
}
bool v_empty(vec *v,int *arr)
{
    if(v->size == 0) return true;

    return false;
}
void v_clear(vec *v,int *arr){
    for(int i=0;i<v->size;i++)
    {
        v_pop(v,v->arr);
        v->size--;
        v->current--;
    }
}
int main (){

 vec v;

 ni_vector(&v);

v_push(&v,v.arr,1);
v_push(&v,v.arr,2);
v_push(&v,v.arr,3);
v_push(&v,v.arr,4);
v_insert(&v,v.arr,2,69);
v_display(&v,v.arr,v.size);

printf("%c",'\n');
vec lt;
ni_vector(&lt);

v_push(&lt,lt.arr,10);
v_push(&lt,lt.arr,20);
v_push(&lt,lt.arr,30);
v_push(&lt,lt.arr,40);
v_insert(&lt,lt.arr,3,25);
v_display(&lt,lt.arr,lt.size);


 free(v.arr);
  return 0;
}

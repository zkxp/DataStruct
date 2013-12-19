#include "stdio.h"
#include "stdlib.h"
#include "Status.h"

#define LIST_INCREMENT 10
#define LIST_SIZE 100


typedef  int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;

int Init_SqList(SqList *L)
{
    (*L).elem=(ElemType *)malloc(LIST_SIZE*sizeof(ElemType));
    if(!(*L).elem ) exit(OVERFLOW );
    (*L).length=0;
    (*L).listsize=LIST_SIZE;
    return OK;
}

void Create_SqList(SqList *L,int n )
{
    int i;
    for(i=0; i<n; i++)
    {
        scanf("%d",&(*L).elem[i]);
        (*L).length++;
    }
}
void Create_SqListByArray(SqList *L,int data[],int k){
    int i;
    for(i=0;i<k;i++){
        (*L).elem[i]=data[i];
        (*L).length++;
    }
}
void DisPlay_SqList(SqList *L)
{
    int i;
    for (i=0; i<(*L).length; i++)
    {
        printf("%d ",(*L).elem[i]);

    }
    printf("\n");
}
void Destroy_SqList(SqList *L)
{
    free((*L).elem) ;
}
int SqList_Insert(SqList *L,int i,ElemType e)
{
    int j;
    ElemType * p;
    if(i<1||i>(*L).length) return ERROR;
    if((*L).length>=(*L).listsize)
    {
        p=(ElemType*)realloc((*L).elem,((*L).listsize+LIST_INCREMENT)*sizeof(ElemType));
        if(!p) exit(OVERFLOW);
        (*L).elem=p;
        (*L).listsize=(*L).listsize+LIST_INCREMENT;
    }
    for(j=(*L).length-1;j>=i-1;j--){
        (*L).elem[j+1]=(*L).elem[j];
    }
    (*L).length++;
    (*L).elem[i-1]=e;

    return OK;

}
//删除指定位置元素，L.elem[j]=L.elem[j+1]
int SqList_delete(SqList *L,int i){
    int j;
    for(j=i-1;j<(*L).length-1;j++){
        (*L).elem[j]=(*L).elem[j+1];
    }
    (*L).length--;
}
int main()
{
    SqList L;
    int data[5];
//    data={3,23,54,9,45};
    data[0]=3,data[1]=83,data[2]=24,data[3]=12,data[4]=48;
    Init_SqList(&L);
    Create_SqListByArray(&L,data,5);
    DisPlay_SqList(&L);
    printf("input location,element:");
    int e,i,m;
    scanf("%d,%d",&i,&e);
    SqList_Insert(&L,i,e);
    DisPlay_SqList(&L);
    printf("input location where you want delet:");
    scanf("%d",&m);
    SqList_delete(&L,m);
    DisPlay_SqList(&L);
    return 0;
}

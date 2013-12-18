#include "stdio.h"
#include "stdlib.h"
#include "Status.h"

#define LIST_INCREMENT 10
#define LIST_SIZE 100


typedef  int ElemType;
typedef struct{
    ElemType *elem;
    int length;
    int listsize;
}SqList;

int Init_SqList(SqList *L){
    (*L).elem=(ElemType *)malloc(LIST_SIZE*sizeof(ElemType));
    if(!(*L).elem ) exit(OVERFLOW );
    (*L).length=0;
    (*L).listsize=LIST_SIZE;
    return OK;
}
void Create_SqList(SqList *L,int n ){
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&(*L).elem[i]);
        (*L).length++;
    }
}
void DisPlay_SqList(SqList *L){
    int i;
    for (i=0;i<(*L).length;i++){
        printf("%d ",(*L).elem[i]);

    }
    printf("\n ");
}
int main()
{
    SqList L;
    Init_SqList(&L);
    Create_SqList(&L,5);
    DisPlay_SqList(&L);
    return 0;
}

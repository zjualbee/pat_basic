#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
typedef struct LNode *List;
struct LNode {
    int Data;
    List Next;
};

List Create()
{
    int d;
    List head=(List)malloc(sizeof(struct LNode)),q;
    head->Next=NULL;
    q=head;
    while(1)
    {
        scanf("%d",&d);
        if(d!=-1)
        {
            List p=(List)malloc(sizeof(struct LNode));
            p->Data=d;
            p->Next=NULL;
            q->Next=p;
            q=p;
        }
        else
            break;
    }
    return head;
}
List Intersection(List a,List b)
{
    a=a->Next;
    b=b->Next;
    List head=(List)malloc(sizeof(struct LNode));
    head->Next=NULL;
    List q=head;
    while(a && b)
    {
        if(a==NULL || a->Data > b->Data)
            b=b->Next;
        else if(b==NULL || a->Data < b->Data)
            a=a->Next;
        else
        {
            List p=(List)malloc(sizeof(struct LNode));
            p->Next=NULL;
            p->Data=b->Data;
            q->Next=p;
            q=p;
            a=a->Next;
            b=b->Next;
        }
    }
    return head;
}

int main()
{
    List a=Create();
    List b=Create();
    List c=Intersection(a,b);
    c=c->Next;
    int flag=0;
    if(c==NULL)
        printf("NULL\n");
    while(c)
    {
        if(flag==0){
            printf("%d",c->Data);
            flag=1;
        }
        else
            printf(" %d",c->Data);
        c=c->Next;
    }
    return 0;
}

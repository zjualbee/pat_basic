#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#define MAXN 100  
#define OK 1  
#define ERROR 0  
  
typedef int BOOL;  
typedef int Status;  
typedef int DataType;  
typedef struct SeQueue  
{  
    DataType data[MAXN];  
    int front;  
    int rear;  
}SeQueue;  
  
Status InitQueue(SeQueue *q)  
{  
    q->front=0;  
    q->rear=0;  
    return OK;  
}  
  
Status ClearQueue(SeQueue *q)  
{  
    memset(q->data,0,sizeof(q->data));  
    q->front=q->rear=0;  
    return OK;  
}  
  
BOOL QueueEmpty(SeQueue q)  
{  
    if(q.front==q.rear)  
        return 1;  
    else  
        return 0;  
}  
  
Status GetHead(SeQueue q,DataType *e)  
{  
    if(q.front==q.rear)  
        return ERROR;  
    (*e)=q.data[q.front];  
    return OK;  
}  
  
Status EnQueue(SeQueue *q,DataType e)  
{  
    if((q->rear+1)==q->front)  
        return ERROR;  
    q->data[q->rear]=e;  
    q->rear=(q->rear+1)%MAXN;  
    return OK;  
}  
  
Status DeQueue(SeQueue *q,DataType *e)  
{  
    if(q->front==q->rear)  
        return ERROR;  
    (*e)=q->data[q->front];  
    q->front=(q->front+1)%MAXN;  
    return OK;  
}  
  
int QueueLength(SeQueue q)
{  
    return (q.rear-q.front+MAXN)%MAXN;
}  
  
Status Display(SeQueue q)  
{  
    int i=q.front;  
    if(q.front==q.rear)  
        return ERROR;  
    while(i!=q.rear)  
    {  
        printf("%3d",q.data[i]);  
        i=(i+1)%MAXN;  
    }  
    printf("\n");  
    return OK;  
}  
  
void menu()  
{  
    printf("---------------------------------------\n");  
    printf("              Menu         Version 1.0 \n");  
    printf("---------------------------------------\n");  
    printf("     1.InitQueue         2.ClearQueue  \n");  
    printf("     3.QueueEmpty        4.GetHead     \n");  
    printf("     5.EnQueue           6.DeQueue     \n");  
    printf("     7.QueueLength       8.Display     \n");  
    printf("     9.Quit                            \n");  
    printf("---------------------------------------\n");  
    printf("Please input your choice:");  
}  
  
int main(int argc,char *argv[])  
{  
    int choice;  
    DataType e;  
    SeQueue q;  
    while(1)  
    {  
        menu();  
        scanf("%d",&choice);  
        switch (choice)  
        {  
            case 1:  
                if(InitQueue(&q))  
                    printf("Init success!\n");  
                else  
                    printf("Init failure!\n");  
                break;  
            case 2:  
                if(ClearQueue(&q))  
                    printf("Clear success!\n");  
                else  
                    printf("Clear failure!\n");  
                break;  
            case 3:  
                if(QueueEmpty(q))  
                    printf("The queue is empty!\n");  
                else  
                    printf("The queue is not empty!\n");  
                break;  
            case 4:  
                if(GetHead(q,&e))  
                    printf("The head of the queue is: %d\n",e);  
                else  
                    printf("Illegal operation!\n");  
                break;  
            case 5:  
                printf("Please input the element you want to Enqueue:");  
                scanf("%d",&e);  
                if(EnQueue(&q,e))  
                    printf("Enqueue success!\n");  
                else  
                    printf("Enqueue failure!\n");  
                break;  
            case 6:  
                if(DeQueue(&q,&e))  
                    printf("%d is out of the queue!\n",e);  
                else  
                    printf("Illegal operation!\n");  
                break;  
            case 7:  
                printf("The length of the queue is: %d\n",QueueLength(q));  
                break;  
            case 8:  
                Display(q);  
                break;  
            case 9:  
                printf("Quit...\n");  
                exit(0);  
                break;  
            default:  
                printf("Illegal input!\n");  
                break;  
        }  
    }  
    return 0;  
}  

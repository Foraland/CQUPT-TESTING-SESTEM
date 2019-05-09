/*��һ������(���ǵݼ�˳��)�������в���һ��Ԫ��Ϊx�Ľ�㣬ʹ������������Ȼ��������������Ϊ��������NΪ6����
**������ʾ��"��������6��Ԫ�ص�ֵ��\n"
**�����ʽ��"%d"
**�����ʾ��"�������������������Ϊ��"
**�����ʽ��"%d "
**������ʾ��"����Ҫ���������x:"
**�����ʽ��"%d"
**�����ʾ��"����������������������Ϊ��"
**�����ʽ��"%d "*/
 
#include <stdio.h>
#include <stdlib.h>
 
#define N 6
 
struct LNode
{                   
    int data;
    struct LNode *next;
}                   ;
 
struct LNode* create_rear(int a[], int n);
void output(struct LNode *h) ;
struct LNode* insert_sort(struct LNode* h, int x);
 
int main(int argc, char *argv[])
{                   
    int a[N], i, x;
    struct LNode* head;
 
    printf("��������%d��Ԫ�ص�ֵ��\n", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
 
    /*�ٴ�������head,�����ֵ����Ϊ����aԪ�ص�ֵ*/
    head = create_rear(a, N);
    /*���������head*/
    printf("�������������������Ϊ��");
    output(head);
 
    printf("����Ҫ���������x:");
    scanf("%d", &x);
    /*�۵��ú���insert_sort����һ��Ԫ��*/
    head = insert_sort(head, x);
    printf("����������������������Ϊ��");
    /*���������������head*/
    output(head);
 
    return 0;
}                   
 
struct LNode* create_rear(int a[], int n)
{                   
    /*�½�һ������h��ÿ��������β��뵽��β���������ͷָ�뷵�� */
    struct LNode *h = NULL;
    struct LNode *s, *r; /*��sָ��Ҫ�����㣬rָ�������β���*/
    int i;
 
    for (i = 0; i < n; i++)
    {                   
        s = (struct LNode *)malloc(sizeof(struct LNode));
        s->data = a[i];
        s->next = NULL;
        if (h == NULL)
            h = s;  /*�������Ϊ�գ���ͷָ��hָ��s*/
        else
            r->next = s;    /*����s���ӵ�β���r֮��*/
        r = s;            /*��rָ��β���*/
    }
    return h;  /*���������ͷָ��*/
}                   
 
void output(struct LNode *h)
{                   
    /*������h�ĸ����������������������������������*/
    struct LNode *p = h;/*�ӵ�һ����㿪ʼ����p����ָ��������*/
    while (p)
    {                   
        /*ֻҪp��һ���ǿս�㣬�������������Ȼ��p����*/
        printf("%d ", p->data);
        p = p->next;  //��p����
    }
    printf("\n");
}                   
 
struct LNode* insert_sort(struct LNode* h, int x)
{                   
    /*���Ѿ�����������h�У�����ֵΪx�Ľ�㣬����������򣬲�����ͷָ�롣*/
    struct LNode *s, *pre, *p;/*��s��ʾ�����㣬preΪp��ǰ��*/
    s = (struct LNode *)malloc(sizeof(struct LNode));
    s->data = x;
 
    if (h == NULL)
    {                   
        /*hΪ������*/
        s->next = NULL;
        h = s;
    }
    if (x <= h->data)
    {                   
        /*x�����������е�һ�����������򣬽�s��������*/
        s->next = h;
        h = s;
    }
    else
    {                   
        p = h;
        while (p && x > p->data)
        {                   
            /*���p���գ���x������p��ָ����������,p���ƣ�preΪp��ǰ��*/
            pre = p;
            p = p->next;
        }
        /*��s���뵽pre��ָ���֮��*/
        s->next = pre->next;
        pre->next = s;
    }
    return h;
}         

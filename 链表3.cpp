/*��һ��������Ԫ��ֵΪx�Ľ��ɾ����������������Ϊ��������ʼ��Ϊ6��Ԫ�أ�
**������ʾ��Ϣ��"��������%d��Ԫ�ص�ֵ��\n"
**�����ʽ��"%d"
**�����ʾ��"�������������������Ϊ��"
**�����ʽ��"%d "
**������ʾ��Ϣ��"����Ҫɾ��������x: "
**�����ʽ��"%d"
**�����ʾ�� "ɾ���������������������Ϊ��"
**�����ʽ��"%d "
 

��������ʾ��1��
��������6��Ԫ�ص�ֵ��
11 22 33 44 55 66
�������������������Ϊ��11 22 33 44 55 66 
����Ҫɾ��������x: 33
ɾ���������������������Ϊ��11 22 44 55 66 

��������ʾ��2��
��������6��Ԫ�ص�ֵ���L
6 2 7 4 5 9
�������������������Ϊ��6 2 7 4 5 9 �L
����Ҫɾ��������x: 8
ɾ���������������������Ϊ��6 2 7 4 5 9 �L*/ 





#include <stdio.h>
#include <stdlib.h>
 
#define N 6
 
struct LNode
{                 
    int data;
    struct LNode *next;
}                 ;
 
struct LNode* create_rear(int a[], int n);
void output(struct LNode *h) ;
struct LNode* delete_node(struct LNode* h, int x);
 
int main(int argc, char *argv[])
{                 
    int a[N], i, x;
    struct LNode* head;
 
    printf("��������%d��Ԫ�ص�ֵ��\n", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
 
    /*��������head,�����ֵ����Ϊ����aԪ�ص�ֵ*/
    head = create_rear(a, N);
    /*ɾ��ǰ�������head*/
    printf("�������������������Ϊ��");
    output(head);
 
    printf("����Ҫɾ��������x: ");
    scanf("%d", &x);
    head = delete_node(head, x);   /*����ɾ������*/
    printf("ɾ���������������������Ϊ��");
    output(head);  /*ɾ�����������head*/
 
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
        s = (struct LNode *) malloc(sizeof(struct LNode));
        s->data = a[i];
        s->next = NULL;
        if (h == NULL)
            h = s;        /*�������Ϊ�գ���ͷָ��hָ��s */
        else
            r->next = s;  /*����s���ӵ�β���r֮��     */
        r = s;                /*��rָ��β���                */
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
 
struct LNode* delete_node(struct LNode* h, int x)
{                 
    /*������h��ֵΪx�Ľ���һ�����ɾ����������ͷָ�롣*/
    struct LNode *pre, *p;/*pre��ָ���Ϊp��ָ����ǰ��*/
 
    p = h;
    while (p && x != p->data)
    {                 
        /*���p���գ���x������p��ָ����������,p���ƣ�preΪp��ǰ��*/
        pre = p;
        p = p->next;
    }
    if (p)
    {                 
        /*���������ҵ���Ҫɾ���Ľ��p����p->dataΪx*/
        if (p == h)
        {                 
            /*pΪ���׽�㣬����pû��ǰ����ɾ����p�ĺ�̽���Ϊ���ף����޸�ͷָ��*/
            h = p->next;
        }
        else
        {                 
            /*ɾ����p�����׽�㣬��p��ǰ��pre��ɾ��ʱ�轫pre�������ӵ�p�ĺ�̽��*/
            pre->next = p->next;
        }
    }
 
    return h;
} 

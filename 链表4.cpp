/*��ջ��Strack����ָ����һ���ڴ棬���������Ϊһ��Ͳ�ṹ���ȷŽ�Ͳ�е����ݱ���Ž�Ͳ�е����ݡ�ѹס����ֻ�к�Ž�Ͳ�е����ݶ�ȡ�����ȷŽ�ȥ�����ݲ��ܱ�ȡ������Ϊ������ȳ�������ջ�ĳ��ȿ��������ӡ���ջ�ṹ��������ʵ�֡����һ������ṹ�����������Ա��һ��������ݣ�һ��Ϊָ����һ���ڵ��ָ�롣��ÿ����һ��������Ҫ�����ջʱ����Ϊ��ѹ���ջ������ʱ��̬����һ������Ľڵ㣬�����ӵ�����Ľ�β����ÿ�δӶ�ջ��ȡ��һ������ʱ����Ϊ��������ջ��������ζ�Ŵ���������һ���ڵ���ȡ���ýڵ�����ݳ�Ա��ͬʱɾ���ýڵ㣬�ͷŸýڵ���ռ���ڴ档
�����������ʵ�ֶ�ջ���ݽṹ����������Ӧ�ð�������������
1��������
2��ѹջ��������5����������ѹ���ջ
3����ջ��������5���������ε�����ջ��ע�⣺��Ϊ����ȳ���ԭ�򣬵���ʱ���������⣬������Ҫɾ���ýڵ��ڴ棩;

**������ʾ��printf("������Ҫѹջ��������");
**�����ʽ��"%d"
**ѹջ�������ʾ��"Push %dth Data:%d\n"
**��ջ�������ʽ��"Pop %dth Data:%d\n"

��������ʾ����
������Ҫѹջ��������1�L
Push 1th Data:1�L
������Ҫѹջ��������2�L
Push 2th Data:2�L
������Ҫѹջ��������3�L
Push 3th Data:3�L
������Ҫѹջ��������4�L
Push 4th Data:4�L
������Ҫѹջ��������5�L
Push 5th Data:5�L
Pop 5th Data:5�L
Pop 4th Data:4�L
Pop 3th Data:3�L
Pop 2th Data:2�L
Pop 1th Data:1�L
*/ 






#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{                    
    int data;
    struct stack *next;
}                     STACK;
STACK *head, *pr;
int nodeNum = 0;                            /* ��ջ�ڵ����Ĵ��� */
STACK *CreateNode(int num);
STACK *PushStack(int num);
int PopStack(void);
int main()
{                    
    int pushNum[5] , popNum[5], i;
    for (i = 0; i < 5; i++)
    {                    
        printf("������Ҫѹջ��������");
        scanf("%d",&pushNum[i]);
        PushStack(pushNum[i]);
        printf("Push %dth Data:%d\n", i + 1, pushNum[i]);
    }
    for (i = 0; i < 5; i++)
    {                    
        popNum[i] = PopStack();
        printf("Pop %dth Data:%d\n", 5 - i, popNum[i]);
    }
    return 0;
}                    
/* �������ܣ�����һ���µĽڵ㣬��Ϊ�ýڵ㸳��ֵ������ָ���µĽڵ��ָ�� */
STACK *CreateNode(int num)
{                    
    STACK *p;
    p = (STACK *)malloc(sizeof(STACK));
    if (p == NULL)
    {                    
        printf("No enough memory!\n");
        exit(0);
    }
    p->next = NULL;              /* Ϊ�½��Ľڵ�ָ���򸳿�ָ�� */
    p->data = num;                   /* Ϊ�½��Ľڵ���������ֵ */
    return p;
}                    
/*  �������ܣ������ͱ���num��ֵѹ���ջ������ָ�������½ڵ��ָ�� */
STACK *PushStack(int num)
{                    
    if (nodeNum == 0) /* ��Ϊ�׽ڵ㣬�����ýڵ��ַ��head��*/
    {                    
        head = CreateNode(num);
        pr = head;
        nodeNum++;  /* ��ջ�ڵ����Ĵ���+1 */
    }
    else             /* �������׽ڵ㣬���½��ڵ���������Ľ�β�� */
    {                    
        pr->next = CreateNode(num);
        pr = pr->next;
        nodeNum++;  /* ��ջ�ڵ����Ĵ���+1 */
    }
    return pr;
}                    
/*  �������ܣ�����ǰջ�������ݵ�����ջ�����شӶ�ջ�е��������� */
int PopStack(void)
{                    
    STACK *p = head;
    int result;
    for (;;)
    {                    
        if (p->next == NULL)     /* �������һ���ڵ� */
        {                    
            break;
        }
        else
        {                    
            pr = p;             /* ��¼���һ���ڵ��ǰһ���ڵ�ĵ�ַ */
            p = p->next;
            nodeNum--;          /* ��ջ�ڵ����Ĵ���-1 */
        }
    }
    pr->next = NULL;          /* ��ĩ�ڵ��ǰһ���ڵ��ó�ĩ�ڵ� */
    result = p->data;
    free(p);
    return result;
}

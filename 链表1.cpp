/*��һ�������������У�������ͷ����β����β����ͷ��
**������ʾ��"\n����������������ʾ������\n"
**������ʾ��"���ֵ��"
**�����ʾ��"\nԭ����\n"
**�����ʽ��"%4d"
**�����ʾ��"\n\n��ת��\n"
**�����ʽ��"%4d"

���������ʾ�����£�
����������������ʾ������
���ֵ��3
���ֵ��4
���ֵ��5
���ֵ��6
���ֵ��7
���ֵ��end
ԭ����
   3   4   5   6   7

��ת��
   7   6   5   4   3*/





#include <stdio.h>
#include <stdlib.h> 
struct line
{                    
    int num;
    struct line *next;
}                     *p1, *p2;
 
struct line *creat()
{                    
    int temp;
    struct line *head = NULL;
 
    printf("\n����������������ʾ������\n���ֵ��");
    while (scanf("%d", &temp))
    {                    
        p1 = (struct line *)malloc(sizeof(struct line));
        (head == NULL) ? (head = p1) : (p2->next = p1);
        p1->num = temp;
        printf("���ֵ��");
        p2 = p1;
    }
    p2->next = NULL;
 
    return head;
}                    
 
output(struct line *outhead)
{                    
    for (p1 = outhead; p1 != NULL; printf("%4d", p1->num), p1 = p1->next);
    {                    
    }
}                    
 
struct line *turnback(struct line *head)
{                    
    struct line *n, *newhead = NULL;
 
    do
    {                    
        p2 = NULL;
        p1 = head;
        while (p1->next != NULL)
        {                    
            p2 = p1;
            p1 = p1->next;
        }
        if (newhead == NULL)
        {                    
            newhead = p1;
            n = newhead->next = p2;
        }
        n = n->next = p2;
        p2->next = NULL;
    }
    while (head->next != NULL);
 
    return newhead;
}                    
 
int main(void)
{                    
    struct line *head;
 
    head = creat();
 
    printf("\nԭ����\n");
    output(head);
    head = turnback(head);
    printf("\n\n��ת��\n");
    output(head);
 
    return 0;
}

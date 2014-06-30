#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

struct Node
{
    int key;
    int value;
    Node *pre, *next;
    Node(): key(0),value(0),pre(NULL),next(NULL){}
    Node(int k, int v): key(k),value(v),pre(NULL),next(NULL){}
};
Node *hashTable[10001];
Node *head;
int capacity;

void removeNode(Node *p)
{
    p->pre->next = p->next;
    p->next->pre = p->pre;
}

void addAfterBefore(Node *p)
{
    p->next = head->next;
    p->next->pre = p;
    head->next = p;
    p->pre = head;
}

int get(int key)
{
    Node *p = hashTable[key];
    if(p != NULL)
    {
        removeNode(p);
        addAfterBefore(p);
        return p->value;
    }
    else return -1;
}

void set(int key, int value)
{
    if(get(key) != -1)//�ҵ���
        head->next->value = value;
    else
    {//û���ҵ�
        if(head->value < capacity)
        {//û�дﵽ��������ͷ������Ԫ��
            Node *p = new Node(key, value);
            hashTable[key] = p;
            addAfterBefore(p);
            ++head->value;
        }
        else
        {//�ﵽ���������滻
            Node *p = head->pre;
            //ɾ���ɽڵ�
            hashTable[p->key] = NULL;
            hashTable[key] = p;
            p->key = key;
            p->value = value;
            removeNode(p);
            //�����½ڵ�
            addAfterBefore(p);
        }
    }
}

int main()
{
    head = new Node;
    head->next = head;
    head->pre = head;
    for(int i=0; i < 10001; i++)
        hashTable[i] = NULL;0
    capacity = 1;
    set(2,1);
    //set(2,2);
    cout << get(2) << endl;
    set(3,2);
    //set(4,1);
    cout << get(2) << endl;
    cout << get(3) << endl;
    system("pause");
}

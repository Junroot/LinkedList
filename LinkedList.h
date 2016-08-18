//
//  LinkedList.h
//  Review
//
//  Created by Junroot on 2016. 8. 18..
//  Copyright © 2016년 ROOT. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Node *head;

// 연결리스트 시작할 때 필수로 함수 실행
void InitList()
{
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
}

// 추가할 값과 위치 받아서 리스트에 추가
int InsertNode(int data, int index)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->value = data;
    
    Node *pointnode = head;
    
    for (int i=0;i<index;++i)
    {
        if (pointnode->next == NULL) return -1;
        pointnode = pointnode->next;
    }
    
    newnode->next = pointnode->next;
    pointnode->next = newnode;
    return 0;
}

// 삭제할 위치 받아서 리스트에서 삭제
int RemoveNode(int index)
{
    Node *pointnode = head;
    
    for (int i=0;i<index;++i)
    {
        if (pointnode->next == NULL) return -1;
        pointnode = pointnode->next;
    }
    
    if (pointnode->next == NULL) return -1;
    
    Node *tempnode = pointnode;
    pointnode = pointnode->next;
    
    tempnode->next=pointnode->next;
    free(pointnode);
    return 0;
}

// 리스트 전체 삭제. 프로그램 종료시 필수 실행.
int RemoveList()
{
    Node *pointnode = head;
    Node *nextnode;
    while (pointnode != NULL)
    {
        nextnode = pointnode->next;
        free(pointnode);
        pointnode = nextnode;
    }
    return 0;
}

// 연결 리스트 출력
int PrintList()
{
    Node *pointnode = head;
    
    while (pointnode->next != NULL)
    {
        pointnode = pointnode->next;
        printf("%d ",pointnode->value);
    }
    puts("");
    return 0;
}

#endif /* LinkedList_h */

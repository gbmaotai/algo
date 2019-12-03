#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "link.h"

#define DEBUG

struct Node * createLink(unsigned int num)
{
    int i=0;
    struct Node *pNodehead = malloc(sizeof(struct Node));
    struct Node *pNode;
     
    pNodehead->data = 0;
    pNodehead->next = NULL;
    pNode = pNodehead;
    for(i=1;i<num;i++)
    {
        pNode->next=malloc(sizeof( struct Node));
		pNode->next->data = i;
		pNode->next->next = NULL;

        pNode = pNode->next;
    }
    return pNodehead;
}

//tailor joint to Num pointer
void makeCircleLink(struct Node *phead,unsigned int num)
{
    struct Node* pTailor,*pJoint;
    unsigned int count=0;
    while(phead->next!=NULL){
        if(count == num)
            pJoint = phead;
        count++;
        phead = phead->next;
    }
    pTailor = phead;
    pTailor->next = pJoint;
}

void print(struct Node *pNode)
{
    while(pNode )
	{
	  	printf("pNode %d \n",pNode->data);
	  	pNode = pNode->next;
	}

}

int deleteNode(struct Node *head,struct Node *p)
{
    struct Node *pNode = head;

    if((p == NULL)||(head == NULL))
        return -1;

//
    if(p->next != NULL){
        //p is not tailor , set post to p
        struct Node* post=p->next;
        p->data=post->data;
        p->next=post->next;
        free( post);
    }else{
        //p is tailor
        while(pNode!=NULL){
            if(pNode->next == p)
             {
                pNode->next = NULL;
                free( pNode);
             }  
        }
    }
    return 0;
}

//reverse
struct Node *reverseList(struct Node *head)
{
    struct Node* pHead = head;
    struct Node *pToDoRev = head->next;
    pHead->next=NULL;   //first node 

    struct Node* pFront = pHead;
    while(pToDoRev)
    {
        struct Node *pSave = pToDoRev->next;  //store next first 
        pToDoRev->next = pFront;                        //break link
        pFront = pToDoRev;                      //move pFront
        pToDoRev = pSave;                       //move pTodorev
    }
    return pFront;
}

//find backwards K 
struct Node* findKbackwards(struct Node* head,int k)
{
	struct Node* p1=head;
	struct Node* p2=head;
	int i;
	for(i=0;i<k;i++)
	{	
		if(p2)
			p2 = p2->next;
		else 
			return NULL;
	}

	while(p2)
	{	
		p1 = p1->next;
		p2 = p2->next;
	}

	printf("find backwards K Node %d\n",p1->data);
	return p1;
	
}	

//find MiddleNode 
struct Node* theMiddleNode(struct Node *head)
{
	struct Node* p1=head;
	struct Node* p2=head;

	while(p1 && p1->next)
	{
		p1 = p1->next->next;
		p2 = p2->next;
	}
	printf("find Middle Node %d\n",p2->data);
	return p2;
}

//check if has circle
//output : meetnode first time
bool hasCircle(struct Node *head,struct Node**MeetNode)
{
    struct Node *slow,*fast;
    //slow pointer move 1 step once time
    //fast pointer move 2 steps once time
    slow = fast = head;

    while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow)
		{
			*MeetNode = slow;
			return true;
		}
	}
	return false;
}

//intput: meetNode first time（meetnode should in circle)
//return RingLength
int getRingLength(struct Node *ringMeetNode)
{
    struct Node *slow,*fast;
    //slow pointer move 1 step once time
    //fast pointer move 2 steps once time    
    slow = fast = ringMeetNode;
    int count=0;
    while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		count++;
		if(fast == slow)
		{
			return count;
		}
	}
	return 0;
}

//input : meetNode : meetnode first time
//return length which is not in the circle
int getLenA(struct Node* head,struct Node *ringMeetNode){
     int lenA=0;
     struct Node *p1,*p2;
     p1 = ringMeetNode;
     p2 = head;

     if(p1 == p2)           //total circle
        return 0;
     
     for(;;){
         p1 = p1->next;
         p2 = p2->next;
         lenA++;
         if(p1 == p2)
             break;
     }
     return lenA;
}

//find JointNode
struct Node* findJointNode(struct Node *head)
{
    struct Node *p1,*p2;
    p1 = p2 = head;

    while(p1 != NULL && p1->next != NULL)
    {
        p1 = p1->next->next;
        p2 = p2->next;
        if(p1 == p2)
            break;
    }

    if(p1 != p2) return NULL;     //no cirle 

    p1 = head;        //p1 from head ,p2 from meetnode of first time
                              
    while(p1 != p2)          
    {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p1;
}


void testLink()
{
    struct Node* phead;
    struct Node* pMeetNode;
    unsigned int length;
    phead = createLink(100);
 //   print(phead);
    findKbackwards(phead,15);
    phead = reverseList(phead);
    theMiddleNode(phead);
    makeCircleLink(phead,0);
    if(hasCircle(phead,&pMeetNode))
        printf("has circle\n");
    else
        printf("no circle\n");
    
    length = getRingLength(pMeetNode);
    printf("circle length %d\n",length);

    length = getLenA(phead,pMeetNode);
    printf("not in circle length %d\n",length);

    pMeetNode = findJointNode(phead);
    printf("Joint point %d\n",pMeetNode->data);
  //  print(phead);
}
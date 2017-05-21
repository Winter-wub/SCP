#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 10

struct queue{
	int data[MAXSIZE];
	int	front;
	int rear;
	int length;
};

struct queue *queue_create();
void enQueue(struct queue *q,int data);
void deQueue(struct queue *q);
int isEmpty (struct queue *q);
void print(struct queue *q);

int main (){
	struct queue *q = queue_create();
	enQueue(q,32);
	enQueue(q,2);
	enQueue(q,4);
	enQueue(q,7);
	enQueue(q,4);
	enQueue(q,8);
	deQueue(q);
	enQueue(q,1);
	deQueue(q);
	enQueue(q,42);
	enQueue(q,27);
	enQueue(q,2);
	enQueue(q,1);
	int i;
	for(i=q->front;i<q->length;i++){
		printf("%d ",q->data[i]);
	}
	print(q);
	return 0;
}

struct queue *queue_create(){
	struct queue *q = malloc(sizeof(struct queue));
	q->front = 0;
	q->length = 0;
	q->rear = 0;
	int i;
	for(i=0;i<=MAXSIZE-1;i++){
		q->data[i] = 0;
	}
	return q;
}

void enQueue(struct queue *q,int data){
	if(q->length < MAXSIZE){
		q->length++;
		q->data[q->rear] = data;
		if(q->rear<MAXSIZE-1)
			q->rear++;
		else
			q->rear = 0;
	}
}

void deQueue(struct queue *q){
	int value = -1;
	if(q->length > 0){
		q->length--;
		value = q->data[q->front];
		q->data[q->front] = 0;
		if(q->front<MAXSIZE-1)
			q->front++;
		else
			q->front = 0;
	}
}

void print(struct queue *q){
	int i;
	printf("\n");
	for(i=q->front;i<=q->length;i++){
		printf("%d " ,q->data[i]);
	}
	if(q->front < q->rear){
		for(i=q->rear;i==q->front-1;i++){
			printf("%d " ,q->data[i]);
		}
	}
	printf("\n");
}

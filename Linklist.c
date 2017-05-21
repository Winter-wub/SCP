#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *insert(struct node *L,int data){
	struct node *newnode = malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = 0;
	if(L == 0){
		return newnode;
	}else{
		L->next = insert(L->next,data);
		return L; 
	}
}

struct node *delete_node(struct node *L,int pos){
	int i;
	struct node *temp = L;
	if(pos == 1){
		return L->next;
	}else{
		for(i=1;i<pos-1;i++){
			temp = temp->next;
		}
		temp->next = temp->next->next;
		return L;
	}
}

int findvalue(struct node *L,int  value){
	int i=1;
	while(L!= 0){
		if(L->data == value){
			return i;
		}
		L = L->next;
		i++;
	}
	return -1;
}

int findIndx(struct node *L,int index){
	int i=1;
	while(L!=0){
		if(i==index){
			return L->data;
		}
		L = L->next;
		i++;
	}
	return -1;
}

void print (struct node *L){
	if(L == 0){
		return ;
	}else{
		printf("%d ",L->data);
		print(L->next);
	}
}

int main(){
	struct node *L = 0;
	int i;
	for(i=1;i<10;i++){
		L = insert(L,i*10);
	}
	print(L);
//	for(i=1;i<=5;i++){
		L = delete_node(L,2);
//	}
	printf("\n");
	print(L);
	printf("\nFind value 20 = index : %d ",findvalue(L,20));
	printf("\nFind index 2 = value : %d ",findIndx(L,2));
	return 0;
}

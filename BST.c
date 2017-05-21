#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct BST {
	int size;
	char word[50];
	struct BST *left;
	struct BST *right;
};

int sizeword(char word[]){
	int i,size=0;
	for(i=0;i<strlen(word);i++){
		size = size + word[i];
	}
	return size;
}

struct BST *add (struct BST *bst,char data[]){
	if(bst == 0){
		struct BST *newnode = malloc(sizeof(struct BST));
		strcpy(newnode->word,data);
		newnode->size = sizeword(data);
		newnode->left = 0;
		newnode->right = 0;
		return newnode;
	}
	else{
		if(bst->size >= sizeword(data)){
			bst->left =  add(bst->left,data);
		}else{
			bst->right = add(bst->right,data);
		}
		return bst;	
	}
}

void print_inorder(struct BST *bst){
	if(bst==0)
		return;
	else{
		print_inorder(bst->left);
		printf(" %s |",bst->word);
		print_inorder(bst->right);
	}
}

void print_minmax(struct  BST *bst){
	struct BST *runnerL = bst;
	struct BST *runnerR = bst;
	while(runnerR->right!=0){
		runnerR = runnerR->right;
	}
	while(runnerL->left!=0){
		runnerL = runnerL->left;
	}
	printf("\nMin = %s\nMax = %s",runnerL->word,runnerR->word);
}

int main(){
	struct 	BST *bst = 0;
	bst = add(bst,"z");
	bst = add(bst,"www");
	bst = add(bst,"i'm wave");
	printf("Inorder List : ");
	print_inorder(bst);
	print_minmax(bst);
	return 0;
}

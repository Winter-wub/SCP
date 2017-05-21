#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct tile{
	int  l;
	int  r;
	struct title *next;
};

struct tile *start_game();//random 1st tile
struct tile *create_tile (int r,int l);
struct tile *insert_tile (struct tile *H,struct tile *d);
struct tile *rotate_tile (struct tile *d);
void display_tile(struct tile *H);

int main(){
	struct tile *domino,*a,*b,*c,*d,*e,*f,*g,*h;
	
	a = create_tile(2,2);
	printf("1:");
	display_tile(a);
	b = create_tile(2,6);
	printf("2:");
	display_tile(b);
	c = create_tile(6,9);
	printf("3:");
	display_tile(c);
	d = create_tile(9,1);
	printf("4:");
	display_tile(d);
	e = create_tile(1,5);
	printf("5:");
	display_tile(e);
	f = create_tile(2,2);
	printf("6:");
	display_tile(f);
	g = create_tile(5,3);
	printf("7:");
	display_tile(g);
	h = create_tile(9,2);
	printf("8:");
	display_tile(h);
	printf("\n");
	/*Play Game*/
	printf("Processing.. : Insert_tile\n\n");
	domino = insert_tile(a,b);
	display_tile(domino);
	domino = insert_tile(domino,c);
	display_tile(domino);
	domino = insert_tile(domino,d);
	display_tile(domino);
	domino = insert_tile(domino,e);
	display_tile(domino);
	domino = insert_tile(domino,f);
	display_tile(domino);
	domino = insert_tile(domino,g);
	display_tile(domino);
	domino = insert_tile(domino,h);
	printf("\n");
	printf("Process: Success!!\n\n");
	display_tile(domino);
	return 0;
}

struct tile *create_tile (int l,int r){
	struct tile *H = (struct tile*)malloc(sizeof(struct tile));
	H->l = l;
	H->r = r;
	H->next = NULL;
	return H;
}
void display_tile(struct tile *H){
	struct tile *runner;
	runner = H;
	while (runner != NULL){
		printf("|[%d]|[%d]|",runner->l,runner->r);
		runner = runner->next;
	}
	printf("\n");
}

struct tile *start_game(){
	srand(time(NULL));
	struct tile *start = (struct tile*)malloc(sizeof(struct tile));
	start->l = rand()%9;
	start->r = rand()%9;
	start->next = NULL;
	return start;
}
struct tile *rotate_tile (struct tile *d){
	struct tile *temp;
	int k;
	temp = d;
	k = temp->l ;
	temp->l = temp->r;
	temp->r = k;
	return temp;
}

struct tile *insert_tile (struct tile *H,struct tile *d){
	struct tile *head,*tail;
	head = H;
	tail = d;
	if(H->l == d->r || H->l == d->l){
		if(H->l == d->r){
			d->next = H;
			return d;
		}
		else if(H->l == d->l){
			rotate_tile(d);
			d->next = H;
			return d;
		}
	}
	
	while (head->next != 0){
		head = head->next;
	}
	if(head->r == tail->l){
		head->next = tail;
		return H;
	}
	else if(head->r == tail->r){
		rotate_tile(tail);
		head->next = tail;
		return H;
	}
	else if(head->l == tail->r){
		tail->next  = head;
		return H;
	}
	else if (head->l == tail->l){
		rotate_tile(tail);
		tail->next  = head;
		return H;
	}	
}

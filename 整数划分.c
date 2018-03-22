#include <stdio.h>
#include <stdlib.h>
int number;

typedef struct num_trace
{
	int num;
	struct num_trace*next;
}NUM;

NUM *head=NULL;
NUM *tail=NULL;

void division(int num,int first_num);
void Create_num(int num);
void scan(NUM* start);
void print(NUM* start);
void delete_num();

int main(int argc, char const *argv[])
{
	scanf("%d",&number);
	division(number,number-1);
	return 0;
}
void division(int num, int first_num){
	int i;
	if(num==1||first_num<=0)
		return;
	Create_num(first_num);
	scan(head);
	int left_num;

	left_num=num-first_num;

	if(first_num*2>=num&&first_num!=1){
		Create_num(left_num);
		scan(head);
	}

	if(first_num==1){
		for(i=1;i<=num-1;i++)
			Create_num(1);
		scan(head);
		for(i=1;i<=num-1;i++)
			delete_num();
			return;
	}
	if(left_num-1<=first_num){
		division(left_num,left_num-1);
	}
	else{
		division(left_num,first_num);
	}
	delete_num();
	division(num,first_num-1);
}
void Create_num(int num){
	NUM *p=(NUM*)malloc(sizeof(NUM));
	p->num=num;
	p->next=NULL;
	if(head==NULL)
		head=p;
	else
		tail->next=p;
	tail=p;
}
void scan(NUM* start){
	int sum=0;
	NUM* p = start;
	while(p->next!=NULL){
		sum+=p->num;
		p=p->next;
	}
	sum+=p->num;
	if(sum==number)
		print(start);
}
void print(NUM *start){
	NUM* p=start;
	printf("%d = ", number);
	while(p->next!=NULL){
		printf("%d+", p->num);
		p=p->next;
	}
	printf("%d\n", p->num);
	delete_num();
}
void delete_num(){
	NUM *p = head;
	NUM *q;
	if(head==NULL)
		return;
	if(p->next!=NULL)
		q=p->next;
	else{
		free(p);
		head=NULL;
		tail=NULL;
		return;
	}
	while(q->next!=NULL){
		p=p->next;
		q=q->next;
	}
	free(q);
	p->next = NULL;
	tail=p;
}

#include <stdio.h>
#include <stdlib.h>
int number;   //输入的数字 

typedef struct num_trace
{
	int num;
	struct num_trace*next;  //存储划分数字的链表
}NUM;

NUM *head=NULL;  //链表头
NUM *tail=NULL;  //链表尾

void division(int num,int first_num);   //整数划分函数
void Create_num(int num);			   //创建链表
void scan();				  		  //检查链表函数
void print();				  		 //打印函数
void delete_num();					//删除一个链表节点

int main(int argc, char const *argv[])
{
	printf("Please Enter A Number such as 6\n");
	scanf("%d",&number);
	division(number,number-1);  //进入划分
	system("pause");
	return 0;
}
void division(int num, int first_num){
	int i;
	if(num==1||first_num<=0)  //无法划分返回
		return;
	Create_num(first_num);  //将num的first_num输进链表
	scan();                //检查是否需要输出
	int left_num;		   

	left_num=num-first_num;  //定义剩余数字

	if(first_num*2>=num&&first_num!=1){  //检查首数字是否未超出一半不重复
		Create_num(left_num);  //将余下数字输进链表
		scan();				   //检查是否需要输出
	}

	if(first_num==1){			//这种情况只包含将num划分成全是1即3->1+1+1
		for(i=1;i<=num-1;i++)
			Create_num(1);
		scan();
		for(i=1;i<=num-1;i++)  //将这次输入链表的1全部删除
			delete_num();
			return;
	}									//首数字不变递归实现以该首数字的所有划分
	if(left_num-1<=first_num){   		
		division(left_num,left_num-1);	//后面数字 = 余下数字-1
	}									//判断如何划分余下数字，后面数字不能比首数字大
	else{								//后面数字大即以首数字来划分余下数字
		division(left_num,first_num);	//后面数字小即以后面数字划分余下数字
	}
	delete_num();						//划分完删除尾节点
	division(num,first_num-1);			//将首数字-1进行递归
}
void Create_num(int num){				//创建一个储存数字的链表
	NUM *p=(NUM*)malloc(sizeof(NUM));
	p->num=num;
	p->next=NULL;
	if(head==NULL)
		head=p;
	else
		tail->next=p;
	tail=p;
}
void scan(){						//扫描链表，判断链表中数字和是否为要划分的数字
	int sum=0;
	NUM* p = head;
	while(p->next!=NULL){
		sum+=p->num;
		p=p->next;
	}
	sum+=p->num;
	if(sum==number)
		print();
}
void print(){						//扫描链表结束，若是正确的划分将其输出
	NUM* p=head;
	printf("%d = ", number);
	while(p->next!=NULL){
		printf("%d+", p->num);
		p=p->next;
	}
	printf("%d\n", p->num);
	delete_num();
}
void delete_num(){				//删除尾部的节点
	NUM *p = head;
	NUM *q;
	if(head==NULL)				//判断是否成功创建了链表
		return;
	if(p->next!=NULL)			//判断是否只有一个节点
		q=p->next;
	else{						//是单个节点就将此节点删除释放空间
		free(p);
		head=NULL;				//初始化链表头尾为空
		tail=NULL;
		return;
	}
	while(q->next!=NULL){		//不是单个节点，就将最后一个节点删除
		p=p->next;
		q=q->next;
	}
	free(q);
	p->next = NULL;				//删除尾节点，将前一个节点设置为最后一个节点
	tail=p;
}

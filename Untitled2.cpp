#include<iostream>
#include<conio.h>
#include<malloc.h>

using namespace std;

typedef struct elmt *alamatelmt;
typedef struct elmt{
	int isi;
	alamatelmt next;
	}Tstack;
typedef Tstack *stack;

void buatStack(stack *S){
	(*S) = NULL;
}

void push(stack *S, int IB){
	Tstack *NB;
	NB = (Tstack *) malloc(sizeof(Tstack));
	NB->isi = IB;
	NB->next = NULL;
	if((*S) == NULL){
		(*S) = NB;
	}
	else{
		NB->next=(*S);
		(*S)=NB;
	}
}

void pop(stack *S, int &X){
	Tstack *p;
	X = (*S)->isi;
	p = (*S);
	if((*S)!=NULL){
		(*S)=(*S)->next;
	}
	free(p);
}

void cetak(stack S){
	Tstack *p;
	p=S;
	if(S!=NULL){
	while(p!=NULL){
		cout<<p->isi<<" ";
		p=p->next;
	}
	}
	else cout<<"Stack Kosong";
}
int main(){
	int bil;
	stack ST;
	buatStack(&ST);
	push(&ST, 26);
	push(&ST, 12);
	push(&ST, 21);
	cout<<"Isi Stack mula-mula : "<<endl;
	cetak(ST);cout<<endl;
	for(int i=0;i<3;i++){
	pop(&ST, bil);
	cout<<"yang diambil : "<<bil<<endl;
	cout<<"Sisanya : ";
	cetak(ST); cout<<endl;
	}
	cout<<"Isi stack sekarang : ";
	cetak(ST);
	getch();
	return(0);
}

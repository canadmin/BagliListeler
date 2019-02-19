#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node{
	int data;
	struct Node *next;
};


void basaEkle(struct Node** head_ref,int new_data){// 
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));// yeni d���m a�t�k
	new_node->data=new_data;// yeni d���m�n datas�n� verdik
	new_node->next=(*head_ref);// yeni d���m�n nextini ilk d���me ba�lad�k
	(*head_ref)=new_node;	// yeni d���m� ilk d���m olarak atad�k
}


void sonaEkle(struct Node** head_ref,int new_data){
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	struct Node *last=*head_ref;// last ad�nda bir pointer a�t�k ve ilk d���me e�itledik
	new_node->data=new_data;// yeni d���m�n datas�n� verdik 
	new_node->next=NULL;// yeni d���m�n nextini NULL yapt�k ki son d���m olucak
	
	if(*head_ref==NULL){// e�er listede hi� eleman yok ise 
		*head_ref=new_node;// ilk eleman� yeni a�t���m�z d���m yap
		return;//c�k
	}
	while(last->next!=NULL){// e�er last �n nexti NULL de�ilse �evir
		last=last->next;// last'� last'�n nextine e�itle bak 
	}// last'�n nexti e�er NULL ise d�ng�den ��k
	last->next=new_node;// son d���m� last'a e�itledik son d���m�n nextini yeni d���m� ver ��nk� yeni d���m art�k son d���m oldu 
	return;// metottan ��k 	
}


void sil(struct Node** head_ref,int key){
	struct Node* temp=*head_ref,*prev;// burada gecici bir d���m ve bir �nceki olan prev d���m�n� ald�k temp'e head atad�k
	if(temp!=NULL && temp->data==key){// e�er kafa d���m� silinicek de�eri ta��yorsa
		*head_ref=temp->next;// ilk d���m olarak gecicinin sonras�ndaki d���m� yap yani ilk d���m burada siliniyorsa 
		free(temp); // sonra ilk d���m� serbest b�rak 
		return;
	}
	while(temp!=NULL && temp->data!=key){// e�er temp bos de�il ve datas� keye e�it de�il ise
		prev=temp;// tempi prev e ata 
		temp=temp->next;// tempin nextine bak
	}// d�ng�den ��k�ld���nda ya temp bos yada anahtar bulundu 
	
	if(temp==NULL){
		return ;// bu durum da temp bos c�km�s olur 
	}// bu kosulda ise anahtar bulunmustur
	prev->next=temp->next;// burada ise elimizde 1 2 3 var 2 silinicek 1-> x(2)x ->3 ba�lar ve kendini ba�lant�dan ��kar�r
	free(temp);// ve bellekten yok edilir
	
	
}


void arayaEkle(struct Node** head_ref,int prev_data,int new_data){// burada ilk d���m yan�na eklenecek d���m�n datas� ve yeni data geliyor
	struct Node *arama=*head_ref;// arama diye pointer a��p ilk d���me e�itledim
	
	while(arama->data!=NULL){// e�er arama datas� bos de�ilse 
			if(arama->data==prev_data){// e�er arama datas� isaret dataya e�itse d���m bulundu
				break;// donguyu k�r 
			}
			arama=arama->next;// ve bize d���m� burada veriyor 
	}
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;// yeni d���m�n datas�n� gir
	new_node->next=arama->next;// yeni d���m�n nextini aranan d���m�n nextine ver 
	arama->next=new_node;// aranan d���m�n nextini ise yeni d���m� ver i�lem bitsin 
	
	
}


void yazdir(struct Node *node){// bas de�i�kenimizi att�k
	while(node!=NULL){// ard�ndan bos olup olmad�klar�na bakt�k
		printf("%d ",node->data);// yazd�rd�k 
		node=node->next;// sonrakine bakt�k
	}
}




int main(){
	
	struct Node* head=NULL;
	sonaEkle(&head,1);
	basaEkle(&head,7);
	arayaEkle(&head,7,3);// istedi�imm d���m�n yan�na yeni d���m eklemek
	sonaEkle(&head,22);
	sonaEkle(&head,11);
	sil(&head,22);
	yazdir(head);
	/*int i=0;
	int j=0;
				int b;
				
				basaEkle(&head,11);
				yazdir(head);*/
/*
	for(i=0 ; i<10;i++){
		printf("yapmak istediginiz islemi secin");
		printf("1 sondan ekleme yapar ");
		printf("2 cikar");
		int a;
		scanf("%d",&a);
		if(a==1){
			printf("listeye girmek istediginiz elaman say�s�n� giriniz");
			scanf("%d",&b);
			for(j=0;j<b;j++){
				int s;
				scanf("%d",&s);
				sonaEkle(&head,s);
			}
			
		}else if(a==2){
			break;
		}
		
	}*/
//	yazdir(head);
	return 0;
	
}


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node{
	int data;
	struct Node *next;
};


void basaEkle(struct Node** head_ref,int new_data){// 
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));// yeni düðüm açtýk
	new_node->data=new_data;// yeni düðümün datasýný verdik
	new_node->next=(*head_ref);// yeni düðümün nextini ilk düðüme baðladýk
	(*head_ref)=new_node;	// yeni düðümü ilk düðüm olarak atadýk
}


void sonaEkle(struct Node** head_ref,int new_data){
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	struct Node *last=*head_ref;// last adýnda bir pointer açtýk ve ilk düðüme eþitledik
	new_node->data=new_data;// yeni düðümün datasýný verdik 
	new_node->next=NULL;// yeni düðümün nextini NULL yaptýk ki son düðüm olucak
	
	if(*head_ref==NULL){// eðer listede hiç eleman yok ise 
		*head_ref=new_node;// ilk elemaný yeni açtýðýmýz düðüm yap
		return;//cýk
	}
	while(last->next!=NULL){// eðer last ýn nexti NULL deðilse çevir
		last=last->next;// last'ý last'ýn nextine eþitle bak 
	}// last'ýn nexti eðer NULL ise döngüden çýk
	last->next=new_node;// son düðümü last'a eþitledik son düðümün nextini yeni düðümü ver çünkü yeni düðüm artýk son düðüm oldu 
	return;// metottan çýk 	
}


void sil(struct Node** head_ref,int key){
	struct Node* temp=*head_ref,*prev;// burada gecici bir düðüm ve bir önceki olan prev düðümünü aldýk temp'e head atadýk
	if(temp!=NULL && temp->data==key){// eðer kafa düðümü silinicek deðeri taþýyorsa
		*head_ref=temp->next;// ilk düðüm olarak gecicinin sonrasýndaki düðümü yap yani ilk düðüm burada siliniyorsa 
		free(temp); // sonra ilk düðümü serbest býrak 
		return;
	}
	while(temp!=NULL && temp->data!=key){// eðer temp bos deðil ve datasý keye eþit deðil ise
		prev=temp;// tempi prev e ata 
		temp=temp->next;// tempin nextine bak
	}// döngüden çýkýldýðýnda ya temp bos yada anahtar bulundu 
	
	if(temp==NULL){
		return ;// bu durum da temp bos cýkmýs olur 
	}// bu kosulda ise anahtar bulunmustur
	prev->next=temp->next;// burada ise elimizde 1 2 3 var 2 silinicek 1-> x(2)x ->3 baðlar ve kendini baðlantýdan çýkarýr
	free(temp);// ve bellekten yok edilir
	
	
}


void arayaEkle(struct Node** head_ref,int prev_data,int new_data){// burada ilk düðüm yanýna eklenecek düðümün datasý ve yeni data geliyor
	struct Node *arama=*head_ref;// arama diye pointer açýp ilk düðüme eþitledim
	
	while(arama->data!=NULL){// eðer arama datasý bos deðilse 
			if(arama->data==prev_data){// eðer arama datasý isaret dataya eþitse düðüm bulundu
				break;// donguyu kýr 
			}
			arama=arama->next;// ve bize düðümü burada veriyor 
	}
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;// yeni düðümün datasýný gir
	new_node->next=arama->next;// yeni düðümün nextini aranan düðümün nextine ver 
	arama->next=new_node;// aranan düðümün nextini ise yeni düðümü ver iþlem bitsin 
	
	
}


void yazdir(struct Node *node){// bas deðiþkenimizi attýk
	while(node!=NULL){// ardýndan bos olup olmadýklarýna baktýk
		printf("%d ",node->data);// yazdýrdýk 
		node=node->next;// sonrakine baktýk
	}
}




int main(){
	
	struct Node* head=NULL;
	sonaEkle(&head,1);
	basaEkle(&head,7);
	arayaEkle(&head,7,3);// istediðimm düðümün yanýna yeni düðüm eklemek
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
			printf("listeye girmek istediginiz elaman sayýsýný giriniz");
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


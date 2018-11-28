#include <stdio.h>
#include <stdlib.h>
typedef struct List{
	int numara;
	struct List *next;
}BList;

BList *ilk=NULL,*son=NULL;


int main() {
	int sayi;
	BList *bilgi;
	char secim;
	while(1==1){
		getch(); 
		puts("Ekleme:E\nSilme:S\nListeleme:L\nCikis:C\nkarakterlerine basiniz::");
		secim=getch();
			
		switch(secim){
			case 'E':
				bilgi=(BList *)malloc(sizeof(BList));
				printf("Eklenecek eleman:::");
				scanf("%d",&bilgi->numara);
				ekle(bilgi);
				break;
			case 'L':
				listele();
				break;
			case 'S':
				printf("silinecek degeri giriniz::");
				scanf("%d",&sayi);
				silme(sayi);
				break;
			case 'C':
				return 0;
				break;
			default :
				printf("Hatali giris yaptiniz...");
				break;
		}
	}
	return 0;
}
void ekle(BList *gelenBilgi){
	if(ilk==NULL){
		ilk=gelenBilgi;
		son=ilk;
		son->next=NULL;
	}
	else{
		son->next=gelenBilgi;
		son=gelenBilgi;
		son->next=NULL;
	}
}
void listele(){
	printf("LÝSTELEME\n");
	BList *temp;
	temp=ilk;
	if(temp!=NULL){
		printf("\n%d",temp->numara);
		temp=temp->next;
	}
	
}
void silme(int num){
	BList *silinecek,*onceki;
	silinecek=ilk;
	while(silinecek){
		if(silinecek->numara==num){
			break;
		}
		onceki=silinecek;
		silinecek=silinecek->next;
	}
	if(silinecek!=NULL){
		if(silinecek==ilk){
			if(silinecek==son){
				ilk==NULL;
				son==NULL;
			}
			else{
				ilk=ilk->next;
			}
		}
	}
	else{
		onceki->next=silinecek->next;
		if(silinecek==son){
			son=onceki;
		}
	}
	printf("%d silindi",silinecek->numara);
	free(silinecek->numara);
}


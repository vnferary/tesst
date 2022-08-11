#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define MAXSV 100
#define MAXSTR 1024

typedef char strc[MAXSTR];



typedef struct sinhvien{
	int stt;
	strc ten;
	strc lop;
} sinhvien_t;


void printMenu(){
	printf("\n");
	printf("1. Nhap danh sach sinh vien\n");
	printf("2. In danh sach sinh vien\n");
	printf("3. Tim kiem sinh vien theo ten\n");
	printf("4. Loc cac sinh vien theo lop\n");
	printf("5. Sap xep danh sach sinh vien theo ten\n");
	printf("6. Sap xep danh sach sinh vien theo ho\n");
	printf("7. Chuan hoa sinh vien theo ten\n");
	printf("8. Luu danh sach lop ra file lop.txt\n");
	printf("9. Luu danh sach sinh vien cua 1 lop ra file sinhvienlop.txt\n");
	printf("10. Ket Thuc\n");

}

void fixName1(strc name){
	name[strlen(name) - 1] = 0;
}

int NhapSinhVien(sinhvien_t sinhviens[]){
	char key = 0;
	int i = 0;
	do{
		__fpurge(stdin);
		printf("\n Sinh vien thu %d",i+1);
		printf("\n Nhap ten: ");
		fflush(stdin);
		sinhviens[i].stt = i+1;
		fgets(sinhviens[i].ten, MAXSTR, stdin);
		fixName1(sinhviens[i].ten);
		printf(" Nhap lop: ");
		fgets(sinhviens[i].lop, MAXSTR, stdin);
		fixName1(sinhviens[i].lop);
		i++;
		printf("\ty: Tiep tuc\n\tn: Thoat\n\t=>");
		scanf("%c",&key);
	}
	while(key == 'y');
	
	return i;
}
void In(sinhvien_t * sv,int soLuong){
	printf("\n%-2s %-15s %-10s","STT", "TEN", "LOP");
	for(int i = 0 ;i < soLuong; i++){
		printf("\n %d  %-15s %-10s",i+1, sv[i].ten, sv[i].lop);
	}
	printf("\n=============================\n");
}
void timKiem(sinhvien_t sv[],int soLuong){
	char ten[32];
	printf("\n Nhap ten can tim: ");
	fgets(ten, 32, stdin);
	fixName1(ten);
	for(int i =0;i < soLuong ; i++){
		if ( strstr(sv[i].ten,ten) > 0 ){
			printf("\n%3d \t  %-10s %-10s",i+1, sv[i].ten, sv[i].lop);
		}
	}
	printf("\n=============================\n");
}

void locTheoLop(sinhvien_t * sv,int soLuong){
	char lop[32];
	printf("\n Nhap lop can loc: ");
	fgets(lop, 32, stdin);
	fixName1(lop);
	printf("\n%-10s %-10s %-10s","STT", "TEN", "LOP");
	for(int i = 0; i < soLuong ; i++){
		if(strcmp(lop, sv[i].lop)==0){
			printf("\n%3d \t  %-10s %-10s",i+1, sv[i].ten, sv[i].lop);
		}
	}
	printf("\n=============================\n");
}
void tachTen(char fullname[], char name[]){
	int  j = 0;
	for( j = strlen(fullname) - 1; j>=0;j--){
		if(fullname[j] ==' '){
			
			break;
		}
	}
	strcpy(name, fullname+j+1);
}


void sapXepTheoTen(sinhvien_t * sv, int n){	
	for(int i =0; i<n-1;i++){		
		for(int j =i+1; j<n;j++){
			strc ten1, ten2;
			tachTen(sv[i].ten , ten1);	
			tachTen(sv[j].ten,ten2);
			int check = strcmp(ten1 , ten2);
			if( check>0 ){
				sinhvien_t temp = sv[i];
				sv[i] = sv[j];
				sv[j] = temp;
			}
			else if(check==0){
				int check2 = strcmp(sv[i].ten , sv[j].ten);
				if(check2>0){
					sinhvien_t temp = sv[i];
					sv[i] = sv[j];
					sv[j] = temp;	
				}
					
			}
		}
	}
	printf("\n%-2s %-10s %-10s","STT", "TEN", "LOP");
	for(int i=0;i<n;i++){
		printf("\n%3d \t  %-10s %-10s",i+1, sv[i].ten, sv[i].lop);
	}
	printf("\n=============================\n");
}
void sapXepTheoHo(sinhvien_t* sv, int n){
	for(int i = 0; i < n-1 ; i++){		
		for(int j = i+1 ; j < n ; j++){
			int check = strcmp(sv[i].ten, sv[j].ten);
			if(check >0 ){
				sinhvien_t temp = sv[i];
				sv[i] = sv[j];
				sv[j] = temp;
			}
		}
	}
	printf("\n%-2s %-10s %-10s","STT", "NAME", "LOP");
	for(int i=0;i<n;i++){
		printf("\n%3d \t  %-10s %-10s",i+1, sv[i].ten, sv[i].lop);
	}
	printf("\n=============================\n");
}
void chuanHoaTen(strc ten){
	int len = strlen(ten);
		if(ten[0] !=32){
			if(ten[0]>96 && ten[0]<123){
				ten[0] -=32;
			}
		}
	for(int j=1; j<len; j++){
		if(ten[j]==32){
			if(ten[j+1]>96 && ten[j+1]<123){
				ten[j+1]-=32;
			}
		}
		
	}
		
}
void chuanHoa(sinhvien_t* sv, int n){
	printf("\n%-2s %-10s %-10s","STT", "TEN", "LOP");
	for(int i =0; i< n ; i++){
		chuanHoaTen(sv[i].ten);
		printf("\n%3d \t  %-10s %-10s",i+1, sv[i].ten, sv[i].lop);
	}
	printf("\n=============================\n");
}
int checkLopExist(char lop[], strc lops[],int lenght  ){
	for (int i =0 ;i < lenght ; i ++){
		if (strcmp (lop, lops[i]) == 0 )
			return 1;
	}
	return 0;
}

void ghiFile(sinhvien_t* sv, int n, strc fileSV){
	FILE * f;

	strc lops[100];
	int indexLop = 0;

	f = fopen(fileSV, "w");
	for(int i =0; i<n;i++){
		if ( !checkLopExist(sv[i].lop,lops,indexLop) ){
			fprintf(f, "%d %10s\n", indexLop+1, sv[i].lop);
			strcpy(lops[indexLop],sv[i].lop);
			indexLop ++;
		}
	}
	fclose(f);
}

void ghiLop(sinhvien_t* sv, int n, strc fileLop){
	
	strc lop;
	printf("\n Nhap ten lop:");
	fgets(lop, MAXSTR, stdin);
	fixName1(lop);
	FILE * f;
	f = fopen(fileLop, "w");

	for(int i = 0; i < n ;i++){
		if( strcmp(lop, sv[i].lop) == 0 ){
			fprintf(f, "%d %10s%10s\n", i+1, sv[i].ten, sv[i].lop);
		}
	}
	fclose(f);
}

int main(){
	char fileLop[] = "lop.txt";
	char fileSvLop[] = "SinhVienLop.txt";
	sinhvien_t sinhviens[MAXSV];
	int soLuong = 0;
	int key=0;

	while (key != 10){
		printMenu();
		printf("Chon: ");
		scanf("%d",&key);
		__fpurge(stdin);
		switch(key){
			case 1: 
				soLuong = NhapSinhVien(sinhviens);
				break;
			case 2: 
				In(sinhviens, soLuong);
				break;
			case 3: 
				timKiem(sinhviens, soLuong);
				break;
			case 4: 	
				locTheoLop(sinhviens, soLuong);
				break;
			case 5:	
				sapXepTheoTen(sinhviens, soLuong);
				break;
			case 6: 
				 sapXepTheoHo(sinhviens, soLuong);
				break;
			case 7: 
				 chuanHoa(sinhviens, soLuong);
				break;
			case 8: 
				 ghiFile(sinhviens, soLuong, fileLop);
				break;	
			case 9: 
				 ghiLop(sinhviens, soLuong, fileSvLop);
				break;
			case 10: 
				printf("\n Thoat! \n\n");
				return 0;
				break;
	 	}
	

	}
	
	return 1;

}

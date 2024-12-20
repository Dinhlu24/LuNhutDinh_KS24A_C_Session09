#include <stdio.h>

int main(){
	int a[100]={0};
	int size = sizeof(a)/sizeof(int);
	int choice=0,currentLength,tmp=0,value=0;
	while(choice != 6){
		printf("MENU\n");
		printf("1. Nhap vao mang\n");
		printf("2. Hien thi mang\n");
		printf("3. Them phan tu\n");
		printf("4. Sua phan tu\n");
		printf("5. Xoa phan tu\n");
		printf("6. Thoat\n");
		printf("Lua chon cua ban: ");	scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Nhap vao so phan tu ma ban muon them vao: ");	scanf("%d",&currentLength);
				if(currentLength < 0 || currentLength > size){
					printf("So phan tu ban muon nhap vao khong hop le");
				}
				else{
					for(int i=0;i<currentLength;i++){
						printf("Moi nhap vao phan tu thu %d: ",i+1);
						scanf("%d",a + i);
					}
					printf("Cac phan tu da duoc nhap xong");
				}
				break;
			case 2:
				printf("Day la mang cua ban: ");
				for(int i=0;i<currentLength;i++){
					if(a[i] == '\0')	printf("  ");
					else	printf("%d ",a[i]);
				}
				break;
			case 3:
				{
					int addIndex=0,value=0;
					printf("Moi ban lua chon vi tri ban muon them vao: ");	scanf("%d", &addIndex);
					if(addIndex < 0 || addIndex > size){
						printf("Vi tri ban nhap vao khong ton tai !!!");
					}
					else{
						printf("Moi ban nhap vao gia tri ban muon them vao: ");	scanf("%d",&value);
						if(addIndex >= currentLength){
							a[currentLength]=value;
							currentLength++;
						}
						else{
							currentLength++;
							for(int i=addIndex-1;i<currentLength;i++){
								tmp = a[i];
								a[i] = value;
								value = tmp;
							}
						}
					}
				}
				break;
			case 4:
				{
					int changeIndex;
					printf("Chon vi tri ma ban muon sua: ");	scanf("%d",&changeIndex);
					if(changeIndex < 0 || changeIndex > currentLength){
						printf("Vi tri ban nhap khong ton tai !!!");
					}
					else{
						printf("Moi ban nhap vao gia tri ban muon sua: ");	scanf("%d",&value);
						a[changeIndex-1]=value;
					}
				}
				break;
			case 5:
				{
					int deleteIndex;
					printf("Chon vi tri ma ban muon xoa: ");	scanf("%d",&deleteIndex);
					if(deleteIndex < 0 || deleteIndex > currentLength){
						printf("Vi tri ban nhap khong ton tai !!!");
					}
					else{
						currentLength--;
						for(int i =deleteIndex-1;i<currentLength;i++){
							a[i] = a[i + 1];
						}
					}
				}
				break;
			case 6:
				printf("Chuong trinh ket thuc");
				break;
			default:
				printf("Gia tri ban nhap vao khong hop le");
		}
		printf("\n");
	}
}

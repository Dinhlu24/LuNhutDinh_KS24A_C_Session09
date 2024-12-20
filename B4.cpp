#include <stdio.h>
#define maxSize 100 //Kich thuoc toi da cua mang
int main(){
	int arr[maxSize]={0};
	int choice=0,currentSize=0;
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
			case 1://Nhap vao mang
				{
					currentSize=0; // Khoi tao lai do dai cua mang sau moi lan chon case 1
					while(currentSize <= 0 || currentSize > maxSize){
						if(currentSize != 0){
							printf("Do dai %d khong phai la do dai hop le vui long nhap lai\n",currentSize);
						}
						printf("Nhap vao so phan tu ma ban muon them vao (1 -> 100): ");	scanf("%d",&currentSize);
					}
					printf("So phan tu %d hop le\n",currentSize);
					
					for(int i=0;i<currentSize;i++){
						printf("Nhap vao gia tri Array[%d]: ",i+1);	scanf("%d",&arr[i]);
					}
					printf("Mang da duoc nhap xong");
				}
				break;
			case 2:// Hien thi mang
				{
					if(currentSize == 0){
						printf("Mang cua ban dang trong vui long nhap cac gia tri vao mang truoc khi hien thi");
					}
					else{
						printf("Day la mang cua ban:\n");
						for(int i=0;i<currentSize;i++){
							printf("%d ",arr[i]);
						}
					}
				}
				break;
			case 3:// Them phan tu
				{
					int addIndex=0,addValue=0;//Vi tri can them, gia tri duoc them vao
					if(currentSize == 0){
						printf("Mang cua ban dang trong vui long nhap cac phan tu vao mang truoc khi them vao");
					}
					else if(currentSize == 100){
						printf("Mang cua ban da day vui long xoa bot cac phan tu truoc khi them vao");
					}
					else{
						printf("Moi nhap vao vi tri ban muon them vao: ");	scanf("%d",&addIndex);
						printf("Moi nhap vao gia tri ban muon them vao: ");	scanf("%d",&addValue);
						currentSize++;
						
						if(addIndex < 0){
							addIndex = 1;
						}
						else if(addIndex > currentSize){
							addIndex = currentSize;
						}
						for(int i=currentSize-2;i>=addIndex-1;i--){
							arr[i+1]=arr[i];
						}
						arr[addIndex-1]=addValue;
						printf("Da them phan tu moi xong");
					}
				}
				break;
			case 4: // Sua phan tu
				{
					if(currentSize == 0){
						printf("Mang cua ban dang trong vui long nhap cac phan tu vao mang truoc khi sua doi");
					}
					else{
						int fixIndex=0,fixValue=0;
						printf("Moi nhap vao vi tri phan tu can sua: ");	scanf("%d",&fixIndex);
						printf("Moi nhap vao gia tri muon sua: ");	scanf("%d",&fixValue);
						arr[fixIndex-1]=fixValue;
						printf("Da sua doi xong");
					}
				}
				break;
			case 5://Xoa phan tu
				{
					if(currentSize == 0){
						printf("Mang cua ban dang trong vui long nhap cac phan tu vao mang truoc khi xoa");
					}
					else{
						int deleteIndex=0;
						printf("Moi nhap vao vi tri phan tu ban muon xoa: ");	scanf("%d",&deleteIndex);
						while(deleteIndex <= 0 || deleteIndex > currentSize){
							printf("Vi tri %d khong ton tai vui long nhap lai: ",deleteIndex);
							scanf("%d",&deleteIndex);
						}
						printf("Vi tri %d hop le\n",deleteIndex);
						currentSize--;
						for(int i=deleteIndex - 1;i<currentSize;i++){
							arr[i]=arr[i+1];
						}
						printf("Da xoa xong");
					}
				}
				break;
			case 6://Thoat
				{
					printf("Chuong trinh ket thuc");
				}
				break;
			default:
				printf("Lua chon ban nhap vao khong co trong menu vui long nhap lai (1 -> 6)");
		}
		printf("\n\n");
	}
	return 0;
}

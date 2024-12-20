#include <stdio.h>
#define maxSize 100
int main(){
	int matrix[maxSize][maxSize]={{0}};
	int choice=0,currentSize=0;
	while(choice != 8){
		printf("MENU\n");
		printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
		printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
		printf("3. In gia tri cac phan tu la le va tinh tong\n");
		printf("4. In ra cac phan tu nam tren duong bien va tinh tich\n");
		printf("5. In ra cac phan tu nam tren duong cheo chinh\n");
		printf("6. In ra cac phan tu nam tren duong cheo phu\n");
		printf("7. In ra dong co tong gia tri cac phan tu la lon nhat\n");
		printf("8. Thoat\n");
		printf("Lua chon cua ban: ");	scanf("%d",&choice);
		switch(choice){
			case 1:// Nhap kich co & gia tri cac phan tu
				{
					currentSize=0;
					while(currentSize <= 2 || currentSize > maxSize){
						if(currentSize <= 2 || currentSize > maxSize){
							printf("So phan tu ban nhap vao khong hop le vui long nhap lai\n");
						}
						printf("Moi nhap kich co cua ma tran (2 -> 100): ");	scanf("%d",&currentSize);
					}
					
					for(int i=0;i<currentSize;i++){
						for(int j=0;j<currentSize;j++){
							printf("Nhap gia tri Matrix[%d][%d]: ",i+1,j+1);
							scanf("%d",&matrix[i][j]);
						}
					}
					printf("Cac phan tu da duoc nhap xong");
				}
				break;
			case 2:// In ra ma tran
				{
					if(currentSize != 0){
						printf("Day la ma tran cua ban:\n");
						for(int i=0;i<currentSize;i++){
							for(int j=0;j<currentSize;j++){
								printf("%d  ",matrix[i][j]);
							}
							printf("\n");
						}
					}
				}
				break;
			case 3:// In ra cac phan tu le & tinh tong
				{
					if(currentSize != 0){
						int sum=0;
						printf("Day la cac phan tu le: ");
						for(int i=0;i<currentSize;i++){
							for(int j=0;j<currentSize;j++){
								if(matrix[i][j] % 2 != 0){
									printf("%d ",matrix[i][j]);
									sum+=matrix[i][j];
								}
							}
						}
						printf("\nDay la tong cua cac so do: %d",sum);
					}
				}
				break;
			case 4:// In cac phan tu tren duong bien & tinh tich
				{
					if(currentSize != 0){
						long long product=1;
						printf("Day la cac phan tu nam tren duong bien:\n");
						for(int i=0;i<currentSize;i++){
							for(int j=0;j<currentSize;j++){
								if(i == 0 || j == 0 || i == currentSize-1 || j == currentSize-1){
									printf("%d ",matrix[i][j]);
									product *= matrix[i][j];
								}
								else	printf("  ");
							}
							printf("\n");
						}
						printf("\nDay la tich cac phan tu nam tren duong bien: %lld",product);
					}
				}
				break;
			case 5://In ra duong cheo chinh
				{
					if(currentSize != 0){
						printf("Day la cac phan tu nam tren duong cheo chinh:\n");
						for(int i=0;i<currentSize;i++){
							for(int j=0;j<currentSize;j++){
								if(i == j){
									printf("%d",matrix[i][j]);
								}
								else{
									printf("  ");
								}
							}
							printf("\n");
						}
					}
				}
				break;
			case 6://In ra duong cheo phu
				{
					if(currentSize != 0){
						printf("Day la cac phan tu nam tren duong cheo phu:\n");
						for(int i=0;i<currentSize;i++){
							for(int j=0;j<currentSize;j++){
								if(i == 2 - j){
									printf("%d",matrix[i][j]);
								}
								else{
									printf("  ");
								}
							}
							printf("\n");
						}
					}
				}
				break;
			case 7:
				{
					if(currentSize != 0){
						int rowsum[100]={0},max=-1,maxRowIndex=0;
						for(int i=0;i<currentSize;i++){
							for(int j=0;j<currentSize;j++){
								rowsum[i]+=matrix[i][j];
							}
							if(max < rowsum[i]){
								max = rowsum[i];
								maxRowIndex = i;
							}
						}
						
						printf("Dong co gia tri lon nhat la: ");
						for(int j=0;j<currentSize;j++){
							printf("%d ",matrix[maxRowIndex][j]);
						}
						printf("\nGia tri cua dong day la: %d",max);
					}
				}
				break;
			case 8:
				{
					printf("Chuong trinh ket thuc");
				}
				break;
			default:
				printf("Lua chon cua ban khong hop le vui long nhap lai (1 -> 8)");
		}
		if(currentSize == 0 && choice != 8){
						printf("Mang cua ban dang trong vui long nhap mang !!!");
			}
		printf("\n\n");
	}
}

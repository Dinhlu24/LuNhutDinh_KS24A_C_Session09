#include <stdio.h>

int main(){
	int matrix[100][100]={0},n=0,m=0;
	int choice=0,sum=0;
	long long multiplication = 1;
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
			case 1:
				{
					printf("Moi nhap vao kich co cua hang(1 -> 100): ");	scanf("%d",&n);
					printf("Moi nhap vao kich co cua cot(1 -> 100): ");	scanf("%d", &m);
					if(m < 1 || m > 100 || n < 1 || n > 100){
						printf("Du lieu ban nhap vao khong hop le, vui long nhap lai!!!");
					}
					else{
						for(int i=0;i<n;i++){
							for(int j=0;j<m;j++){
								printf("matrix[%d][%d]: ",i+1,j+1);
								scanf("%d",&matrix[i][j]);
							}
						}
						printf("Hoan thanh viec nhap du lieu");
					}
				}
				break;
			case 2:
				{
					printf("Day la ma tran cua ban:\n");
					for(int i=0;i<n;i++){
						for(int j=0;j<m;j++){
						printf("%d  ",matrix[i][j]);
						}
					printf("\n");
					}
				}
				break;
			case 3:
				{
					printf("Day la cac phan tu la so le: ");
					for(int i=0;i<n;i++){
						for(int j=0;j<m;j++){
							if(matrix[i][j] % 2 != 0){
								printf("%d ",matrix[i][j]);
								sum += matrix[i][j];
							}
						}
					}
					printf("\nDay la tong cua cac phan tu la so le: %d",sum);
				}
				break;
			case 4:
				{
					printf("Day la cac phan tu nam tren duong bien:\n");
					for(int i=0;i<n;i++){
						for(int j=0;j<m;j++){
							if(i == 0 || j == 0 || i == n - 1 || j == n - 1){
								printf("%d  ",matrix[i][j]);
								multiplication *= matrix[i][j];
							}
							else	printf("   ");
						}
						printf("\n");
					}
					printf("Tich cua cac phan tu nam tren duong bien: %lld",multiplication);
				}
				break;
			case 5:
				{
					printf("Day la cac phan tu nam tren duong cheo chinh:\n");
					for(int i=0;i<n;i++){
						for(int j=0;j<m;j++){
							if(i == j)	printf("%d  ",matrix[i][j]);
							else	printf("   ");
						}
						printf("\n");
					}
				}
				break;
			case 6:
				{
					printf("Day la cac phan tu nam tren duong cheo phu:\n");
					for(int i=0;i<n;i++){
						for(int j=0;j<m;j++){
							if(i == 3-j-1)	printf("%d  ",matrix[i][j]);
							else	printf("   ");
						}
						printf("\n");
					}
				}
				break;
			case 7:
				{
					int tongmang[n]={0};
					int max=0,maxlineIndex=0;
					for(int i=0;i<n;i++){
						max = tongmang[0];
						for(int j=0;j<m;j++){
							tongmang[i]+=matrix[i][j];
						}
						if(max <= tongmang[i]){
							max = tongmang[i];
							maxlineIndex = i;
						}
					}
					printf("Dong co tong gia tri cac phan tu lon nhat la:\n");
					for(int j=0;j<m;j++){
						printf("%d ",matrix[maxlineIndex][j]);
					}
					printf("\nTong cua dong nay la: %d",max);
				}
		}
		printf("\n");
		sum=0,multiplication=1;
	}
}

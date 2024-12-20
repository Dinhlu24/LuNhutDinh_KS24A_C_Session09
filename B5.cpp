#include <stdio.h>
#define maxSize 100 //Kich thuoc toi da cua mang

int isPrime(int n){
	if(n < 2)	return 0;
	for(int i=2;i*i<=n;i++){
		if(n % i == 0)	return 0;
	}
	return 1;
}

int main(){
	int arr[maxSize]={0};
	int choice=0,currentSize=0;
	while(choice != 8){
		printf("MENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra cac gia tri cac phan tu dang quan ly\n");
        printf("3. In ra cac gia tri cac phan tu chan va tinh tong\n");
        printf("4. In ra gia tri lon nha va nho nhat trong mang\n");
        printf("5. In ra cac phan tu la so nguyen to trong mang va tinh tong\n");
        printf("6. Nhap vao mot so thong ke trong mang co bao nhieu phan tu do\n");
        printf("7. Them mot phan tu vao vi tri chi dinh\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");	scanf("%d",&choice);
        switch(choice){
        	case 1:// nhap mang
        		{
        			currentSize=0; // Khoi tao lai do dai cua mang sau moi lan chon case 1
					while(currentSize <= 0 || currentSize > maxSize){
						if(currentSize != 0){
							printf("So phan tu %d khong phai la so phan tu hop le vui long nhap lai\n",currentSize);
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
			case 2:// hien thi mang
        		{
        			if(currentSize == 0){
						printf("Mang cua ban dang trong vui long nhap cac gia tri vao mang truoc khi hien thi");
					}
					else{
						printf("Cac gia tri cac phan tu dang quan ly la:\n");
						for(int i=0;i<currentSize;i++){
							printf("%d ",arr[i]);
						}
					}
				}
				break;
			case 3:// in phan tu chan va tinh tong
        		{
        			if(currentSize == 0){
						printf("Mang cua ban dang trong vui long nhap cac gia tri vao mang truoc khi thuc hien");
					}
					else{
						int sum=0;
						printf("Tat ca cac so chan trong mang: ");
						for(int i=0;i<currentSize;i++){
							if(arr[i] % 2 == 0){
								printf("%d ",arr[i]);
								sum+=arr[i];
							}
						}
						printf("\nDay la tong cac so chan day: %d",sum);
					}
				}
				break;
			case 4://In ra gia tri lon nhat & nho nhat
        		{
        			if(currentSize == 0){
						printf("Mang cua ban dang trong vui long nhap cac gia tri vao mang truoc khi thuc hien");
					}
					else{
						int max=arr[0],min=arr[0];
						for(int i=0;i<currentSize;i++){
							if(max < arr[i]){
								max=arr[i];
							}
							if(min > arr[i]){
								min = arr[i];
							}
						}
						printf("Phan tu co gia tri lon nhat la: %d\n",max);
						printf("Phan tu co gia tri nho nhat la: %d",min);
					}
				}
				break;
			case 5:// In ra so nguyen to va tinh tong
        		{	
					if(currentSize == 0){
						printf("Mang cua ban dang trong vui long nhap cac gia tri vao mang truoc khi thuc hien");
					}
					else{
						int sum=0;
						printf("Day la cac so nguyen to trong mang: ");
						for(int i=0;i<currentSize;i++){
							if(isPrime(arr[i])){
								printf("%d ",arr[i]);
								sum += arr[i];
							}
						}
						printf("\nDay la tong cac so nguyen to day: %d",sum);
					}
				}
				break;
			case 6://Thong ke so phan tu
        		{
        			if(currentSize == 0){
						printf("Mang cua ban dang trong vui long nhap cac gia tri vao mang truoc khi thuc hien");
					}
					else{
						int checkValue=0,count=0;
						printf("Moi ban nhap vao gia tri can thong ke: ");	scanf("%d",&checkValue);
						for(int i=0;i<currentSize;i++){
							if(checkValue == arr[i]){
								count++;
							}
						}
						if(count == 0){
							printf("Gia tri ban nhap vao khong ton tai trong mang nay");
						}
						else{
							printf("Co tat ca %d phan tu mang gia tri %d",count,checkValue);
						}
					}
				}
				break;
			case 7:// Them mot phan tu vao vi tri chi dinh
        		{
        			int addIndex=0,addValue=0;
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
			case 8:
        		{
        			printf("Chuong trinh ket thuc !!!");
				}
				break;
			default:
				printf("Gia tri ban nhap vao khong hop le vui long nhap lai (1 -> 8)");
		}
		printf("\n\n");
	}
	return 0;
}

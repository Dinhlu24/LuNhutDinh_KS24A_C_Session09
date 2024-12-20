#include <stdio.h>
#define maxSize 100 //Kich thuoc toi da cua mang
int main(){
	int arr[maxSize]={0};
	int currentLength=0;
	printf("Moi ban nhap vao so phan tu ban muon nhap (1 -> 100): ");	scanf("%d",&currentLength);
	//Nhap vao so phan tu mang co cho den khi gia tri nam trong khoang (1 -> 100)
	while(currentLength <= 0||currentLength > maxSize){
		printf("Du lieu ban nhap vao khong hop le vui long nhap lai (1 -> 100): ");	scanf("%d", &currentLength);
	}
	
	//Nhap gia tri vao trong mang
	for(int i=0;i<currentLength;i++){
		printf("Nhap gia tri Array[%d]: ",i+1);
		scanf("%d",&arr[i]);
	}
	
	int deleteIndex=0;
	printf("Moi ban nhap vao vi tri ban can xoa: ");	scanf("%d",&deleteIndex);
	while(deleteIndex <= 0 || deleteIndex > currentLength){
		printf("Gia vi tri %d khong ton tai vui long nhap lai: ",deleteIndex);	scanf("%d",&deleteIndex);
	}
	
	currentLength--;
	for(int i=deleteIndex-1;i<currentLength;i++){
		arr[i]=arr[i+1];
	}
	printf("Gia tri da duoc xoa xong\n");
	printf("Mang cua ban sau khi xoa phan tu vi tri %d:\n",deleteIndex);
	for(int i=0;i<currentLength;i++){
		printf("%d ",arr[i]);
	}
}

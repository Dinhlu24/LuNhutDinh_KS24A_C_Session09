#include <stdio.h>
#define maxSize 100 //Kich thuoc toi da cua mang
int main(){
	int arr[maxSize];
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
	
	int addIndex=0,addValue=0,tmp=0; // Vi tri va gia tri phan tu them vao mang, bien tmp de luu giu gia tri addIndex xuat ra man hinh
	
	if(currentLength == maxSize){ //Kiem tra xem mang da day chua
		printf("Phan tu trong mang da day khong the them vao nua !!!");
	}
	else{
		printf("Moi ban nhap vao vi tri ban muon them: ");	scanf("%d",&addIndex);
		printf("Moi ban nhap vao gia tri ban muon them tai vi tri do: ");	scanf("%d",&addValue);
		currentLength++;
		tmp=addIndex;
		if(addIndex < 0){
			addIndex = 1;
		}
		else if(addIndex > currentLength){
			addIndex = currentLength;
		}
		for(int i=currentLength-2;i>=addIndex-1;i--){
			arr[i+1]=arr[i];
		}
		arr[addIndex-1] = addValue;
		
		printf("Mang sau khi duoc ban them gia tri %d tai vi tri %d la:\n",addValue,tmp);
		for(int i=0;i<currentLength;i++){
			printf("%d ",arr[i]);
		}
	}
}

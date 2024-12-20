#include <stdio.h>

int main(){
	int a[100]={0};
	int currentLength;
	printf("Moi nhap vao so phan tu muon nhap: ");	scanf("%d",&currentLength);
	for(int i=0;i<currentLength;i++){
		printf("Moi nhap vao phan tu thu %d: ",i+1);
		scanf("%d",a + i);
	}
	
	int deleteIndex;
	printf("Moi ban nhap vao vi tri phan tu ban muon xoa: ");	scanf("%d",&deleteIndex);
	if(deleteIndex > 0 && deleteIndex <= 100){
		currentLength--;
		for(int i=deleteIndex-1;i<currentLength;i++){
			int tmp=a[i+1];
			a[i]=tmp;
		}
		printf("Mang moi sau khi da xoa di phan tu vi tri thu %d: ",deleteIndex);
		for(int i=0;i<currentLength;i++){
			printf("%d ",a[i]);
		}
	}
}

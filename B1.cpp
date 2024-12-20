#include <stdio.h>

int main(){
	int a[100]={0};
	int size = sizeof(a)/sizeof(int),tmp=0;
	int currentLength;	printf("Moi ban nhap vao so phan tu muon nhap: ");	scanf("%d", &currentLength);
	if(currentLength < 0 || currentLength > size){
		printf("So phan tu ban nhap vao khong hop le");
		return 0;
	}
	else{
		for(int i=0;i<currentLength;i++){
			printf("Moi nhap vao phan tu thu %d: ",i+1);
			scanf("%d",a + i);
		}
		int addIndex,value;
		printf("Moi ban nhap vao vi tri muon them vao mang: ");	scanf("%d",&addIndex);
		
		if(addIndex < 0 || addIndex > size){
			printf("Vi tri ban nhap vao khong hop le");
		}
		else{
		printf("Moi ban nhap vao gia tri muon them vao mang: ");	scanf("%d",&value);	
			if(addIndex >= currentLength){
				a[currentLength] = value;
				currentLength++;
			}
			else{
				currentLength++;
				for(int i=addIndex-1;i<currentLength;i++){
					tmp=a[i];
					a[i] = value;
					value = tmp;
				}
			}
			
			printf("Mang sau khi them gia tri moi vao vi tri %d la: ",addIndex);
			for(int i = 0;i<currentLength;i++){
				if(a[i] == '\0')	printf("  ");
				else	printf("%d ",a[i]);
			}
		}
	}
}

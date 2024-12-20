#include <stdio.h>

int main(){
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("Day la mang truoc khi sua: ");
	for(int i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	int n,giatri;
	printf("\nMoi nhap vao vi tri can sua: ");scanf("%d", &n);
	printf("Moi nhap vao gia tri can sua cua mang do: ");	scanf("%d", &giatri);
	a[n-1]=giatri;
	printf("Day la mang cua ban sau khi sua: ");
	for(int i=0;i<10;i++){
		printf("%d ",a[i]);
	}
}

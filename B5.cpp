#include <stdio.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int a[100] = {0};
    int n = 0, currentLength, sum = 0, max, min, tmp;
    while (n != 8) {
    	printf("MENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra cac gia tri cac phan tu dang quan ly\n");
        printf("3. In ra cac gia tri cac phan tu chan va tinh tong\n");
        printf("4. In ra gia tri lon nha va nho nhat trong mang\n");
        printf("5. In ra cac phan tu la so nguyen to trong mang va tinh tong\n");
        printf("6. Nhap vao mot so thong ke trong mang co bao nhieu phan tu do\n");
        printf("7. Them mot phan tu vao vi tri chi dinh\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                {
                    printf("Phan tu can nhap: ");
                    scanf("%d", &currentLength);
                    if (currentLength < 0 || currentLength > 100) 
                        printf("Phan tu ban nhap vao khong ton tai");
                    else {
                        for (int i = 0; i < currentLength; i++) {
                            printf("Moi nhap vao gia tri phan tu %d: ", i + 1);
                            scanf("%d", a + i);
                        }
                    }
                }
                break;
            case 2:
                {
                    printf("Hien thi gia tri cac phan tu: \n");
                    for (int i = 0; i < currentLength; i++) {
                        printf("%d ", a[i]);
                    }
                    printf("\n");
                }
                break; 
            case 3:
                printf("Day la cac phan tu chan trong mang: \n");
                for (int i = 0; i < currentLength; i++) {
                    if (a[i] % 2 == 0) {
                        sum += a[i];
                        printf("+> Phan tu vi tri thu %d gia tri: %d\n", i + 1, a[i]);
                    }
                }
                printf("Tong cua cac gia tri chan nay la: %d\n", sum);
                break;
            case 4:
                max = a[0], min = a[0];
                for (int i = 0; i < currentLength; i++) {
                    if (max <= a[i]) max = a[i];
                    if (min >= a[i]) min = a[i];
                }
                printf("Gia tri lon nhat trong mang la: %d\n", max);
                printf("Gia tri nho nhat trong mang la: %d\n", min);
                break;
            case 5:
                {
                    printf("Day la cac gia tri so nguyen to trong mang: \n");
                    int countPrime = 0;
                    for (int i = 0; i < currentLength; i++) {
                        if (isPrime(a[i])) {
                            printf("+> Day la phan tu vi tri %d co gia tri: %d\n", i + 1, a[i]);
                            sum += a[i];
                            countPrime++;
                        }
                    }
                    if (countPrime) {
                        printf("Day la tong cua cac so nguyen to: %d\n", sum);
                    } else {
                        printf("Mang nay khong chua so nguyen to nao ca\n");
                    }
                }
                break;
            case 6:
            	{
            	int num=0,count=0;
                printf("Moi ban nhap vao mot so: ");	scanf("%d", &num);
                for(int i = 0;i<currentLength;i++){
                	if(num == a[i])	count++;
				}
				printf("Trong mang co tat ca %d phan tu %d",count,num);
                break;
				}
            case 7:
                {
					int addIndex=0,value=0;
					printf("Moi ban lua chon vi tri ban muon them vao: ");	scanf("%d", &addIndex);
					if(addIndex < 0 || addIndex > 100){
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
            case 8:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
        }
        printf("\n");
        sum=0;
    }
    return 0;
}


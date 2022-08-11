#include <linux/module.h>
#include <linux/init.h>

int Tong(int arr[100], int n, int m);
int Am(int arr[100], int n, int m);
int Duong(int arr[100], int n, int m);
int MAXDCC(int arr[100], int n, int m);
int MINDCC(int arr[100], int n, int m);
int MAXDCP(int arr[100], int n, int m);
int MINDCP(int arr[100], int n, int m);
int TongLe(int arr[100], int m, int n);
int TongChan(int arr[100], int m, int n);
void InMang(int arr[100], int n, int m);

static int bai3_init(void) 
{
	printk(KERN_INFO "\nHello from module Bai 3 - Lab 1\n");
	int n = 3;
	int m = 3;
	int arr[9] = {1,5,-2,5,7,3,1,2,-4};
	InMang(arr, n, m);
	printk("\nTong = %d\n", Tong(arr, n, m));
	printk("\nSo phan tu am = %d\n", Am(arr, n, m));
	printk("\nSo phan tu duong = %d\n", Duong(arr, n, m));
	printk("\nGTLN tren duong cheo chinh = %d\n", MAXDCC(arr, n, m));
	printk("\nGTNN tren duong cheo chinh = %d\n", MINDCC(arr, n, m));
	printk("\nGTLN tren duong cheo phu = %d\n", MAXDCP(arr, n, m));
	printk("\nGTNN tren duong cheo phu = %d\n", MINDCP(arr, n, m));
	printk("\nTong chan = %d\n", TongChan(arr, n, m));
	printk("\nTong le = %d\n", TongLe(arr, n, m));
	printk("\n");

	return 0;
}

void InMang(int arr[100], int n, int m)
{
	int z = 0;
	int i = 0;
	int j = 0;
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++){
			printk("%d ", arr[z]);
			z++;
		}
		printk("\n");
	}
}

int Tong(int arr[100], int n, int m)
{
	int i=0;
	int sum = 0;
	for(i=0;i<n*m;i++) {
		sum += arr[i];
	}
	return sum;
}

int Am(int arr[100], int n, int m)
{
	int i=0;
	int dem = 0;
	for(i=0;i<n*m;i++) {
		if(arr[i] < 0) dem++; 
	}
	return dem;
}

int Duong(int arr[100], int n, int m)
{
	int i=0;
	int dem = 0;
	for(i=0;i<n*m;i++) {
		if(arr[i] > 0) dem++; 
	}
	return dem;
}
int MAXDCC(int arr[100], int n, int m)
{
	int max = arr[0];
	int i = 0;
	for(i=1;i<n*m;i++) {
		if(i==0||i==4||i==8) {
			if(arr[i] > max) max = arr[i];
		}
	}
	return max;
}

int MINDCC(int arr[100], int n, int m)
{
	int min = arr[0];
	int i = 0;
	for(i=0;i<n*m;i++) {
		if(i==0||i==4||i==8) {
			if(arr[i] < min) min = arr[i];
		}
	}
	return min;
}

int MAXDCP(int arr[100], int n, int m)
{
	int max = arr[2];
	int i = 0;
	for(i=0;i<n*m;i++) {
		if(i==2||i==4||i==6) {
			if(arr[i] > max) max = arr[i];
		}
	}
	return max;
}

int MINDCP(int arr[100], int n, int m)
{
	int min = arr[2];
	int i = 0;
	for(i=0;i<n*m;i++) {
		if(i==2||i==4||i==6) {
			if(arr[i] < min) min = arr[i];
		}
	}
	return min;
}

int TongChan(int arr[100], int m, int n)
{
	int i = 0;
	int sum = 0;
	for(i=0;i<n*m;i++) {
		if(arr[i] % 2 == 0) sum += arr[i];
	}
	return sum;
}

int TongLe(int arr[100], int m, int n)
{
	int i = 0;
	int sub = 0;
	for(i=0;i<n;i++) {
		if(arr[i] % 2 == 1) sub+=arr[i];
	}
	return sub;
}

static void bai3_exit(void)
{
	printk(KERN_INFO "\nBye from module Bai 3 - Lab 1\n");
}

module_init(bai3_init);
module_exit(bai3_exit);
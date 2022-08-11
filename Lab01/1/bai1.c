#include <linux/module.h>
#include <linux/init.h>

int TongChuoiSo(int arr[100], int n);
int UCLN(int a, int b);

static int bai1_init(void) 
{
	printk(KERN_INFO "\nHello from module Bai 1 - Lab 1\n");

	int arr[5] = {1, 2, 3, 4, 5};
	int n = 5;
	int a = 4;
	int b = 8;
	printk("\nTong cac phan tu cua chuoi so: %d\n", TongChuoiSo(arr, n));
	printk("\nUCLN (%d, %d)=%d\n", a, b, UCLN(a, b));
	printk("\n");
	return 0;
}

int TongChuoiSo(int arr[100], int n)
{
	int i = 0;
	int sum = 0;
	for(i = 0; i < n; i++) {
		sum += arr[i];
	}
	printk("\n");
	return sum;
}

int UCLN(int a, int b)
{
	while(a*b != 0) {
		if(a>b) {
			a = a%b;
		}
		else {
			b = b%a;
		}
	}
	return a+b;
}

static void bai1_exit(void)
{
	printk(KERN_INFO "\nBye from module Bai 1 - Lab 1\n");
}

module_init(bai1_init);
module_exit(bai1_exit);


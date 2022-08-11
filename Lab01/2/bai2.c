#include <linux/module.h>
#include <linux/init.h>

int GTLN(int arr[100], int n);
int GTNN(int arr[100], int n);
int TrungBinhCong(int arr[100], int n);

static int bai2_init(void) 
{
	printk(KERN_INFO "\nHello from module Bai 2 - Lab 1\n");

	int n = 7;
	int arr[7] = {12, 2, 5, 4, 5, -1, -8};
	int tbc = 0;
	int sum = 0;
	
	printk("\nGTLN = %d\n", GTLN(arr, n));
	printk("\nGTNN = %d\n", GTNN(arr, n));
	
	sum = TrungBinhCong(arr, n);
	tbc = sum/7;
	printk("\nTBC = %d\n", tbc);
	printk("\n");
	return 0;
}

int GTLN(int arr[100], int n)
{
	int i = 0;
	int j = 0;
	int max = 0;
	for(i = 0; i < n; i++) {
		if(arr[i] > max) {
			max = arr[i];
		}
	}
	printk("\n");
	return max;
}

int GTNN(int arr[100], int n)
{
	int i = 0;
	int j = 0;
	int min = 0;
	for(i = 0;i<n;i++) {
		if(arr[i] < min) min = arr[i];
	}
	printk("\n");
	return min;
}

int TrungBinhCong(int arr[100], int n)
{
	int i = 0;
	int sum = 0;
	for(i = 0; i < n; i++) {
		sum += arr[i];
	}
	printk("\n");
	return sum;
}

static void bai2_exit(void)
{
	printk(KERN_INFO "\nBye from module Bai 2 - Lab 1\n");
}

module_init(bai2_init);
module_exit(bai2_exit);
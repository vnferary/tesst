#include <linux/module.h>
#include <linux/init.h>


void Tong(int arr1[4], int arr2[4], int arr3[4], int n, int m);
void Hieu(int arr_1[50], int arr_2[50], int arr_3[50], int n, int m);
void Tich(int arr_1[50], int arr_2[50], int arr_3[50], int n, int m);
void InMaTran(int arr[100], int n, int m);
void InVecTo(int arr[100], int n);
int TichVoHuong(int arr_1[50], int arr_2[50], int n);
int ChinhHop(int k, int n);
int GiaiThua(int a);

static int bai31_init(void)
{
	printk(KERN_INFO "\nHello from module Lab 03 - Bai 1\n");

	int n1 = 4;
	int n2 = 4;

	int n3 = 2;
	int n4 = 2;
	int arr_1[4] = {1, 5, 2, 6};
	int arr_2[4] = {1, 0, 4, 5};
	
	int arr_sum[4] = {0, 0, 0, 0};
	int arr_sub[4] = {0, 0, 0, 0};
	int arr_mul[4] = {0, 0, 0, 0};

	printk("\nVecto 1: \n");
	InVecTo(arr_1, n1);
	printk("\nVecto 2: \n");
	InVecTo(arr_2, n2);
	printk("\nTich vo huong cua 2 vecto: %d\n", TichVoHuong(arr_1, arr_2, n1));
	

	printk("\nMa tran 1: \n");
	InMaTran(arr_1, n3, n4);

	printk("\nMa tran 2: \n");
	InMaTran(arr_2, n3, n4);

	printk("\nTong 2 ma tran: ");
	Tong(arr_1, arr_2, arr_sum, n3, n4);
	
	printk("\nHieu 2 ma tran: \n");
	Hieu(arr_1, arr_2, arr_sub, n3, n4);

	printk("\nTich 2 ma tran: \n");
	Tich(arr_1, arr_2, arr_mul, n3, n4);

	int k = 3;
	int n = 6;

	printk("\nChinh hop chap %d cua %d: %d\n", k, n, ChinhHop(k, n));


	printk("\n");
	return 0;
}

void InMaTran(int arr[100], int n, int m)
{
	int z = 0;
	int k = 0;
	int l = 0;
	for(k=0;k<n;k++) {
		for(l=0;l<m;l++){
			printk("%d ", arr[z]);
			z++;
		}
		printk("\n");
	}
}

void InVecTo(int arr[100], int n)
{
	int i = 0;
	for(i=0;i<n;i++) {
		printk("%d ", arr[i]);
	}
	printk("\n");
}

int TichVoHuong(int arr_1[50], int arr_2[50], int n)
{
	int i = 0;
	int sum = 0;
	for(i = 0; i < n; i++) {
		sum += arr_1[i]*arr_2[i];
	}
	return sum;
}

void Tong(int arr1[50], int arr2[50], int arr3[50], int n, int m)
{
	int i = 0;
	for(i = 0; i < n*m; i++) {
		arr3[i] = arr1[i]+arr2[i];
	}
	InMaTran(arr3, n, m);
}

void Hieu(int arr_1[50], int arr_2[50], int arr_3[50], int n, int m)
{
	int i = 0;
	for(i = 0; i < n*m; i++) {
		arr_3[i] = arr_1[i]-arr_2[i];
	}
	InMaTran(arr_3, n, m);
}

void Tich(int arr_1[50], int arr_2[50], int arr_3[50], int n, int m)
{
	int i = 0;
	for(i = 0; i < n*m; i++) {
		arr_3[i] = arr_1[i]*arr_2[i];
	}
	InMaTran(arr_3, n, m);
}

int GiaiThua(int a)
{
	int s = 1;
	int i;
	for(i = 1; i <= a; i++) {
		s*=i;
	}
	return s;
}
int ChinhHop(int k, int n)
{
	return GiaiThua(n)/GiaiThua(n-k);
}

static void bai31_exit(void)
{
	printk(KERN_INFO "\nBye from module Lab 03 Bai 1\n");
}

module_init(bai31_init);
module_exit(bai31_exit);
#include <linux/module.h>
#include <linux/init.h>

void DecToBinary(int n);
int BinaryToDec(int n);
int pow(int x, int n);
void DecToHex(int n);
void DecToOct(int n);
int HexToDec(char hex[17]);
char OctToHex(long long octal);
int OctToDec(long long oct);

static int bai21_init(void) 
{
	printk(KERN_INFO "\nHello from module Bai 1 - Lab 2\n");

// 10->2
	int n1 = 85;
	printk("\n%d tu he 10 sang he 2: \n", n1);
	DecToBinary(n1);
// 2->10
	int n2 = 110;
	printk("\n%d tu he 2 sang he 10: %d\n", n2, BinaryToDec(n2));

// 10->16
	int n3 = 42422;
	printk("\n%d tu he 10 sang he 16: \n", n3);
	DecToHex(n3);

// 2->8
	int n4 = 10011011;
	int dec = BinaryToDec(n4);
	printk("\n%d tu he 2 sang he 8: \n", n4);
	DecToOct(dec);

// 16->2
	char n5[] = "7DE";
	int dec2 = HexToDec(n5);
	printk("\n%s tu he 16 sang he 2: \n", n5);
	DecToBinary(dec2);

// 8->16
	long long n6 = 125715;
	// 8->10
	int dec3 = OctToDec(n6);
	printk("\n%ld tu he 8 sang he 16: \n", n6);
	// 10->16
	DecToHex(dec3);

// 16->8
	char n7[] = "7DE";
	// 16->10
	int dec4 = HexToDec(n7);
	// 10->8
	printk("\n%d tu he 16 sang he 8: \n");
	DecToOct(dec4);

	printk("\n");
	return 0;
}

// 8->10(8^)
int OctToDec(long long oct)
{
	int i = 0;
	int decNumber = 0;
	while (oct > 0)
	{
		decNumber = decNumber + pow(8, i)*(oct%10);
		oct = oct/10;
		i++;
	}
	return decNumber;
}

// 10->2
void DecToBinary(int n)
{
	int arr[100];
	int i = 0;
	int j = 0;
	while(n > 0) {
		arr[i] = n%2;
		n = n/2;
		i++;
	}
	for(j = i-1; j >= 0; j--)
	{
		printk("%d", arr[j]);
	}
	printk("\n");
}

// 2->10
int BinaryToDec(int n)
{
	int i = 0;
	int decNumber = 0;
	while(n>0) {
		decNumber = decNumber + pow(2, i)*(n%10);
		n = n/10;
		i++;
	}
	return decNumber;
}

// 16->10
int HexToDec(char hex[17])
{
	int i=0;
	int len = strlen(hex)-1;
	int val;
	long long decimal=0;

	for(i=0;hex[i]!='\0';i++)
	{
		if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i] - 65 + 10;
        }

        decimal += val * pow(16, len);
        len--;
	}

	return decimal;
}

// 10->16
void DecToHex(int n)
{
	int arr[100];
	int i = 0;
	int j = 0;
	while(n>0) {
		arr[i] = n%16;
		n = n/16;
		i++;
	}
	for(j=i-1;j>=0;j--) {
		printk("%x", arr[j]);
	}
}
// 10->8
void DecToOct(int n)
{
	int arr[100];
	int i = 0;
	int j = 0;
	while(n>0)
	{
		arr[i] = n%8;
		n = n/8;
		i++;
	}
	for(j = i-1; j >= 0; j--)
	{
		printk("%d", arr[j]);
	}
}


int pow(int x, int n)
{
	int i = 0;
	int bp = 1;
	for(i = 0;i < n;i++) {
		bp *= x;
	}
	return bp;
}

static void bai21_exit(void)
{
	printk(KERN_INFO "\nBye from module Bai 1 - Lab 2\n");
}

module_init(bai21_init);
module_exit(bai21_exit);


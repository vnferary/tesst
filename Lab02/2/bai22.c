#include <linux/module.h>
#include <linux/init.h>

int SoKyTu(char s[50]);
void DaoNguoc(char str[], int length);
void DaoNguoc2(char str[]);
void ChuanHoa(char str[], int length);
void NoiChuoi(char str1[], char str2[]);

static int bai22_init(void) 
{
	printk(KERN_INFO "\nHello from module Bai 2 - Lab 2\n");

	char str1[] = "Driver Programming\0";
	char str2[11] = "Hello World";
	char str3[] = " dRiVer  pRoGRAmming  ";
	char str4[100] = "Hello";
	char str5[] = " World";
	printk("\nSo ky tu trong chuoi '%s' la: %d\n", str1, SoKyTu(str1));

	// Dao nguoc xau voi xau cai dat theo do dai
	int length = 11;
	DaoNguoc(str2, 11);

	// Dao nguoc xau voi xau cai theo ky tu ket thuc
	DaoNguoc2(str1);

	// Chuan hoa xau
	int length2 = strlen(str3);
	printk("\nChuoi '%s' sau khi chuan hoa la: \n", str3);
	ChuanHoa(str3, length2);
	
	// Noi hai chuoi
	printk("\nNoi chuoi '%s' va '%s' thanh: \n", str4, str5);
	NoiChuoi(str4, str5);
	return 0;
}

void NoiChuoi(char str1[], char str2[])
{

	int j = 0;
	int i = strlen(str1);
	for(j = 0; str2[j] != '\0';j++) {
		str1[i] = str2[j];
		i++;
	}
	str1[i] = '\0';
	printk("\n");
	printk("%s", str1);
	printk("\n");
}

int SoKyTu(char str[])
{
	int count = 0;
	while (str[count] != '\0')
	{
		count ++;
	}
	return count;
}

// Dao nguoc xau khi cai dat xau theo do dai
void DaoNguoc(char str[], int length)
{
	char strInvert[length];
	int i = 0;
	printk("\nIn chuoi theo chieu dao nguoc: \n");
	for(i = length-1; i>=0; i--) {
		printk("%c", str[i]);
	}
	printk("\n");
}

// Dao nguoc xau khi cai dat theo ky tu ket thuc
void DaoNguoc2(char str[])
{
	int length = 0;
	while (str[length] != '\0')
	{
		length ++;
	}

	char strInvert[length];
	int i = 0;
	printk("\nIn chuoi theo chieu dao nguoc 2: \n");
	for(i = length-1; i>=0; i--) {
		printk("%c", str[i]);
	}
	printk("\n");
}

void ChuanHoa(char str[], int length)
{
	int first = 0;
	int last = length - 1;
	int i;

	// Xoa khoang trang o dau chuoi
	while(first < last && str[first] == ' ') {
		first++;
	}

	// Xoa khoang trang o cuoi chuoi
	while (last > first && str[last] == ' ')
	{
		last--;
	}

	// Viet hoa chu cai dau
	if(str[first] >= 'a' && str[first] <= 'z') {
		str[first] -= 32;
	}
	for(i = first+1; i <= last; i++) {
		if(str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}

		// Bo khoang trang thua o giua xau
		if(str[i] == ' ' && str[i+1] == ' ') {
			strcpy(&str[i], &str[i+1]);
			i--;
		}
		if(str[i] == ' ' && str[i+1] >= 'a' && str[i+1] <= 'z') {
			str[i+1] -= 32;
		}
	
	}
	for(i = first; i < last; i++) {
		printk("%c", str[i]);
	}
	printk("\n");
}
static void bai22_exit(void)
{
	printk(KERN_INFO "\nBye from module Lab 02 - Bai 2\n");
}

module_init(bai22_init);
module_exit(bai22_exit);
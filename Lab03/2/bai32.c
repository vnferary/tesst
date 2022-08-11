#include <linux/module.h>
#include <linux/init.h>
#include <linux/string.h>

static int bai32_init(void)
{
	printk(KERN_INFO "\nHello from module Lab 03 - Bai 2\n");

	char message[] = "Driver Programming";
	int length = strlen(message);
	int key = 5;

	printk("\nXau ban dau: %s\n", message);

// 	Ma hoa
	int i=0;
    for(i = 0;message[i] != '\0';i++){
		int ch = message[i];
		if(ch >= 97 && ch <= 122) {
			ch = ch + key;
			if(ch > 122) {
				ch = ch - 122 + 97 - 1;
			}
			message[i] = ch;
		}
		else if(ch >= 65 && ch <= 90) {
			ch = ch + key;
			if(ch > 90) {
				ch = ch - 90 + 65 - 1;
			}
			message[i] = ch;
		}
	}
	printk("\nMa hoa: %s\n", message);
	
// 	Giai ma
	int j = 0;
    for(j = 0;message[j] != '\0';j++){
		int ch = message[j];
		if(ch >= 97 && ch <= 122) {
			ch = ch - key;
			if(ch < 97) {
				ch = ch + 122 - 97 + 1;
			}
			message[j] = ch;
		}
		else if(ch >= 65 && ch <= 90) {
			ch = ch - key;
			if(ch < 65) {
				ch = ch + 90 - 65 + 1;
			}
			message[j] = ch;
		}
	}
	printk("Giai ma: %s\n", message);

	return 0;
}


static void bai32_exit(void)
{
	printk(KERN_INFO "\nBye from module Lab 03 Bai 2\n");
}

module_init(bai32_init);
module_exit(bai32_exit);
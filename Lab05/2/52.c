#include <linux/module.h>
#include <linux/init.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/cdev.h>
#include<linux/slab.h>
#include<linux/uaccess.h>
#include<linux/time.h>
#include <linux/timekeeping.h>
#include<linux/jiffies.h>

//#include <linux/ktime.h>

#define DRIVER_AUTHOR "Lab 05"
#define DRIVER_DESC   "Wall time and system uptime"
#define VERSION "3.0"
#define MEM_SIZE 1024

struct vchar_drv{
	dev_t dev_num;
	struct class *dev_class;
	struct device *dev;
}vchar_drv;

static struct cdev *example_cdev;
unsigned open_cnt = 0;
unsigned long js, je;

char *kernel_buffer;
long result[10];
unsigned long js,jf;

static int lab52_open(struct inode *inode, struct file *filp);
static int lab52_release(struct inode *inode, struct file *filp);
static ssize_t lab52_read(struct file *filp, char __user *user_buf, size_t len, loff_t * off);
static ssize_t lab52_write(struct file *filp, const char *user_buf, size_t len, loff_t * off);

static struct file_operations fops =
{
	.owner          = THIS_MODULE,
	.read           = lab52_read,
	.write          = lab52_write,
	.open           = lab52_open,
	.release        = lab52_release,
};
 
static int lab52_open(struct inode *inode, struct file *filp)
{
	printk("Mo file %u lan\n", open_cnt);
	return 0;
}

static int lab52_release(struct inode *inode, struct file *filp)
{
	printk("Dong file %u lan\n", open_cnt);
	return 0;
}
 
static ssize_t lab52_read(struct file *filp, char __user *user_buf, size_t len, loff_t *off)
{
    struct timespec64 ts; //system timeup
	struct timeval tv; //wall time
	ktime_get_real_ts64(&ts);

	result[1]=ts.tv_sec; // s
	result[2]=ts.tv_nsec; //ns

	jf = jiffies; //lay so tick hien tai
	jiffies_to_timeval(jf-js,&tv);

	result[3]=tv.tv_sec;

	pr_info("%ld %ld %ld", result[1],result[2], result[3]);
	copy_to_user(user_buf, result, sizeof(long)*10);
	return MEM_SIZE;
}
static ssize_t lab52_write(struct file *filp, const char __user *user_buf, size_t len, loff_t *off)
{
	return len;
}


static int __init char_driver_init(void)
{
	/* cap phat dong device number */
    int ret = 0;
    vchar_drv.dev_num = 0;

	ret = alloc_chrdev_region(&vchar_drv.dev_num, 0, 1, "Lab 52");
    if(ret < 0) {
        printk("Can't allocate character driver\n");
		goto failed_register_devnum;
    }
	printk("Insert character driver successfully. major(%d), minor(%d)\n", MAJOR(vchar_drv.dev_num), MINOR(vchar_drv.dev_num));

	/* tao device file /dev/lab52 */
	vchar_drv.dev_class = class_create(THIS_MODULE, "Lab05");
    if(IS_ERR(vchar_drv.dev_class)) {
		printk("Can't create class\n");
		goto failed_create_class;
	}

	device_create(vchar_drv.dev_class, NULL, vchar_drv.dev_num, NULL,"lab52");
    if(IS_ERR(vchar_drv.dev)) {
		printk("Can't create device file\n");
		goto failed_create_device;
	}

	/* tao kernel buffer */
	kernel_buffer   = kmalloc(MEM_SIZE , GFP_KERNEL);

	/* lien ket cac ham entry point cua driver voi device file */
	example_cdev = cdev_alloc();
	cdev_init(example_cdev, &fops);
	cdev_add(example_cdev, vchar_drv.dev_num, 1);
	js = jiffies;
	return 0;

failed_create_device:
	class_destroy(vchar_drv.dev_class);
failed_create_class:
	unregister_chrdev_region(vchar_drv.dev_num, 1);
failed_register_devnum:
	return ret;
}

void __exit char_driver_exit(void)
{
	cdev_del(example_cdev);
	kfree(kernel_buffer);
	device_destroy(vchar_drv.dev_class,vchar_drv.dev_num);
	class_destroy(vchar_drv.dev_class);
	unregister_chrdev_region(vchar_drv.dev_num, 1);
	printk("Remove character driver successfully.\n");
}

module_init(char_driver_init);
module_exit(char_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_VERSION("2.4");
MODULE_SUPPORTED_DEVICE("testdevice");


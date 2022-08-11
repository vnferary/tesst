#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/uaccess.h>

#define DRIVER_AUTHOR "Hoang Van Thai"
#define DRIVER_DESC "Device driver dong"
#define MEM_SIZE 1024

dev_t dev_number = 0;
static struct class *device_class;
static struct cdev *lab41_cdev;
uint8_t *kernel_buffer;
unsigned open_cnt = 0;

static int vchar_driver_open(struct inode *inode, struct file *flip);
static int vchar_driver_release(struct inode *inode, struct file *filp);
static ssize_t vchar_driver_read(struct file *filp, char __user *user_buf, size_t len, loff_t *off);
static ssize_t vchar_driver_write(struct file *filp, const char __user *user_buf, size_t len, loff_t *off);

static struct file_operations fops = 
{
    .owner      = THIS_MODULE,
    .read       = vchar_driver_read,
    .write      = vchar_driver_write,
    .open       = vchar_driver_open,
    .release    = vchar_driver_release,
};

static int vchar_driver_open(struct inode *inode, struct file *flip)
{
    open_cnt++;
    printk("Handle opened event %u times\n", open_cnt);
	return 0;
}

static int vchar_driver_release(struct inode *inode, struct file *filp)
{
    printk("Handle closed event %u times\n", open_cnt);
    return 0;
}
 
static ssize_t vchar_driver_read(struct file *filp, char __user *user_buf, size_t len, loff_t *off)
{
	copy_to_user(user_buf, kernel_buffer, MEM_SIZE);
	printk("Handle read event %u times\n", open_cnt);
	return MEM_SIZE;
}
static ssize_t vchar_driver_write(struct file *filp, const char __user *user_buf, size_t len, loff_t *off)
{
	copy_from_user(kernel_buffer, user_buf, len);
	printk("Handle write event %u times\n", open_cnt);
	return len;
}

// Khoi tao driver
static int __init char_driver_init(void)
{
    // Cap phat tinh device number
    alloc_chrdev_region(&dev_number, 0, 1, "Lab4.1_Hoang Van Thai");
    printk("Insert character driver successfully. major(%d), minor(%d)\n", MAJOR(dev_number), MINOR(dev_number));

    device_class = class_create(THIS_MODULE, "Lab04");
    device_create(device_class, NULL, dev_number, NULL,"lab41");

    kernel_buffer = kmalloc(MEM_SIZE , GFP_KERNEL);

    lab41_cdev = cdev_alloc();//cap phat bo nho cho bien cau truc cdev
	cdev_init(lab41_cdev, &fops); //khoi tao cho bien cau truc cdev
	cdev_add(lab41_cdev, dev_number, 1); //dang ky cau truc cdev voi kernel

    return 0;
}
static void __exit char_driver_exit(void) 
{
    cdev_del(lab41_cdev);
	kfree(kernel_buffer);
	device_destroy(device_class,dev_number);
	class_destroy(device_class);
	unregister_chrdev_region(dev_number, 1);
	printk("Remove character driver successfully.\n");
}

module_init(char_driver_init);
module_exit(char_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_VERSION("3.0");
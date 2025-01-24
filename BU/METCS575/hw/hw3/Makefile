obj-m += hello.o

KDIR := /usr/src/linux-headers-$(shell uname -r)

default:
	$(MAKE) -Wall -C $(KDIR) M=$(PWD) modules

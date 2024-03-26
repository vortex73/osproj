obj-m += process_tree.o
ccflags-remove-y += -mrecord-mcount -fconserve-stack

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean


#!/bin/bash

make
sudo insmod hello.ko
sudo dmesg | tail
sudo rmmod hello
sudo dmesg > dmesg -`date +%d%m%Y`.log
sudo tail dmesg -`date +%d%m%Y`.log

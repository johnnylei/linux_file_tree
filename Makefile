#!/bin/bash
CURRENT_APTH=${shell pwd}
file_tree:file_ergodic.c
	gcc file_ergodic.c -o file_tree
	sudo rm /usr/bin/file_tree
	sudo ln -s $(CURRENT_APTH)/file_tree /usr/bin/file_tree


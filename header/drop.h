#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
#define o_size	123392
#define path_len	1024

int write(int ori_size, char *tar_path, char *ori_buf);
int extract(int ori_size, char *target);
int check(int ori_size, char *ori_buf, char *target);

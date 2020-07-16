#include "../header/drop.h"
using namespace std;

int write(int ori_size, char *tar_path, char *ori_buf)
{
	int tar_size = 0;
	ifstream tar_file(tar_path, ios::in | ios::binary);
	tar_file.seekg(0, ios::end);
	tar_size = int(tar_file.tellg());
	tar_file.seekg(0, ios::beg);
	char *tar_buf;
	tar_buf = new char[tar_size];

	tar_file.read(tar_buf, tar_size);
	tar_file.close();
	ofstream outputfile(tar_path, ios::in | ios::binary);

	outputfile.write(ori_buf, ori_size);
	outputfile.write(tar_buf, tar_size);
	outputfile.close();
	cout << "!!Success" << endl;
	cout << "1. 해당 파일 실행시 원본 파일이 D:\\child.exe로 드랍되어 실행됩니다." << endl;
	cout << "2. 파일명을 자유롭게 바꿔서 사용해주세요." << endl;

	return 0;
}

int extract(int ori_size, char *target)
{
	ifstream tar_file(target, ios::in | ios::binary);
	tar_file.seekg(o_size);
	int drop_size = ori_size - o_size;
	char *tar_buf;
	tar_buf = new char[drop_size];

	tar_file.read(tar_buf, drop_size);
	tar_file.close();
	ofstream outfile("D:\\child.exe", ios::out | ios::binary);
	outfile.write(tar_buf, drop_size);
	outfile.close();
	ShellExecute(NULL, "open", "D:\\child.exe", NULL, NULL, SW_SHOW);

	return 0;
}

int check(int ori_size, char *ori_buf, char *target)
{
	int checker = 0;
	char tar_path[path_len];
	if (ori_size > o_size) { //ex
		extract(ori_size, target);
	}
	else {
		cout << "=======DROP=======" << endl;
		cout << "Input File Path(Target) : ";
		cin >> tar_path;
		write(ori_size, tar_path, ori_buf);
	}
	return 0;
}

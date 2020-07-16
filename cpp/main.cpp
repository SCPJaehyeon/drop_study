#include "../header/drop.h"
using namespace std;

int main(int argc, char *argv[])
{
	int ori_size;
	char *target = argv[0];
	ifstream ori_file(argv[0], ios::in | ios::binary);

	ori_file.seekg(0, ios::end);
	ori_size = int(ori_file.tellg());
	ori_file.seekg(0, ios::beg);
	cout << "해당 exe 크기는 " << ori_size << " bytes 입니다." << endl;

	char *ori_buf = new char[ori_size];

	ori_file.read(ori_buf, ori_size);
	ori_file.close();

	check(ori_size, ori_buf, target);

	return 0;
}

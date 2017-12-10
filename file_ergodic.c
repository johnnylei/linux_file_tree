#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>


void ergodic_dir(char * dir_name, char * prefix) {
	DIR * dir = opendir(dir_name);
	if (NULL == dir) {
		printf("%s this is not dir\n", dir_name);
		exit(1);
	}

	while (1) {
		struct dirent * _dir = readdir(dir);
		if (NULL == _dir) {
			break;
		}

		if (strcmp(_dir->d_name, "..") == 0 || strcmp(_dir->d_name, ".") == 0) {
			continue;
		}

		printf("%s%s/%s\n", prefix, dir_name, _dir->d_name);
		if(DT_DIR == _dir->d_type) {
			char _dir_name[1024];
			sprintf(_dir_name, "%s/%s", dir_name, _dir->d_name);
			char _prefix[1024];
			sprintf(_prefix, "%s%s", "| ", prefix);
			ergodic_dir(_dir_name, _prefix);
		}
	}

	closedir(dir);
}

int main(int argc, char * argv[]) {
	char dir_name[512];
	if (argc < 2) {
		getcwd(dir_name, 512);	
	} else {
		strcpy(dir_name, argv[1]);
	}

	ergodic_dir(dir_name, "|-");
	return 0;
}

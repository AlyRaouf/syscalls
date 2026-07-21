#include <stdio.h>
#include <unistd.h>

int main()
{

	char buf[1024];
	char *cwd = getcwd(buf, 1024);
	printf("%s\n", cwd);
	return 0;

}

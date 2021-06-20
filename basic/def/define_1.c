#include<stdio.h>
#define DEBUG_PRINTF printf("FILE %s line %d:\n"\
	"x=%d,y=%d,z=%d",\
	__FILE__,__LINE__,\
	x,y,z)
int main(int argc, char *argv[])
{
	int x=1,y=1,z=1;
	x*=2;
	y+=x;
	z=x*y;
	DEBUG_PRINTF;
	return 0;
}

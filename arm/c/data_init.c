#include <string.h>

extern char data_start[];
extern char data_size[];
extern char data_load_start[];

void copy_data(void)
{
	for(int i = 0; i < (size_t)data_size; i++)
	{
		data_start[i] = data_load_start[i];
	}
}

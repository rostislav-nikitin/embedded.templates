#include <stddef.h>
#include <errno.h>

void *stack_ptr;
int *__errno(void)
{
	return NULL;
}

void __libc_init_array(void)
{
}

void initialise_monitor_handles(void)
{
}

void _lseek(int offset, int whence)
{
}

void _read(char *buffer, size_t size)
{
}

void _write(char *buffer, size_t size)
{
}

void _close()
{
}

void _exit(int exit_code)
{
}

int puts(const char *)
{
	return 0;
}

void *_sbrk(int incr)
{
	extern char end asm("end");
	static char *heap_end;
	char *prev_heap_end;

	if(heap_end == 0)
		heap_end = &end;

	prev_heap_end = heap_end;
	if((void *)(heap_end + incr) > stack_ptr)
	{
		errno = ENOMEM;
		return (void *) - 1;
	}

	heap_end += incr;

	return (void *)prev_heap_end;
}

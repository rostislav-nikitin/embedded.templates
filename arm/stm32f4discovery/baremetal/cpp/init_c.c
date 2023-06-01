extern void __init_cpp(void);
extern void __libc_init_array(void);
void initialise_monitor_handles(void);
extern void main(void);

void Reset_Handler(void)
{
        __init_cpp();
        __libc_init_array();
#ifdef SEMIH	
	initialise_monitor_handles();
#endif
        main();
        while(1);
}


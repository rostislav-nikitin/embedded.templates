void __init_cpp(void);
void __libc_init_array(void);
void main(void);

void Reset_Handler(void)
{
        __init_cpp();
        __libc_init_array();
        main();
        while(1);
}


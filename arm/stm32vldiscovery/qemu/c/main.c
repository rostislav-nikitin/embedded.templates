volatile unsigned char * const UART0_TX = (unsigned char *) 0x101f1000;

int x = 48;

void print(char const *string)
{
	x++;
	while(*string != '\0')
	{
		*UART0_TX = *string;
		string++;
	}
	*UART0_TX = x;
	*UART0_TX = '\n';

}

int main(void)
{
	print("Hello world!\n");
	return 0;	
}

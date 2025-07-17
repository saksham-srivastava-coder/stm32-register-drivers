
void UART_init(unsigned short uart, unsigned long BR);

unsigned long UART_BRR(unsigned short uart, unsigned long BR);

char UART_RX(unsigned short uart);

void UART_TX(unsigned short uart, char c);

void UART_ISR(unsigned short uart, unsigned short bridge, unsigned short * signal, unsigned short * counter, char str[]);

void UART_SEND(unsigned short uart, char str[]);

void  str_empty(char str[]);

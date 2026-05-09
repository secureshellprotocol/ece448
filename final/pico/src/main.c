#include <stdio.h>
#include "pico/stdlib.h"

int main(void)
{
    stdio_init_all();

    for(;;)
    {
        printf("This is my power project\n");
        sleep_ms(1000);
    }
}

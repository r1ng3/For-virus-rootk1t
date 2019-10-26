#include <stdio.h>

/* 
    (RUS)
        Регистр CR0 контролирует поведение процессора.

        Популярным методом отключения защиты памяти в ядре является
        изменение регистра CR0.

        В регистр CR0 был включен бит защиты от записи (Write Protect)
        Если вы пишите руткит уровня ядра, то этот не большой код вам поможет
        отключить эту защиту.

    (ENG)
        The CR0 register controls the behavior of the processor.

        A popular method for disabling memory protection in the kernel is
        register change CR0.

        Write Protect Bit Enabled in CR0
        If you write a kernel level rootkit, then this small code will help you.
        disable this protection.
*/

int main()
{
    __asm // Stop CR0
    {
        push eax
        mov eax, CR0
        and eax, 0FFFEFFFFh
        mov CR0, eax
        pop eax
    }

    // Your code 

    __asm // Start CR0
    {
        push eax  
        mov eax, CR0
        or eax, NOT 0FFFEFFFFh
        mov CR0, eax
        pop eax
    }
    
    return 0;
}

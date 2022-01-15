
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

int main(int argc, char** argv){


    printf("hello\n");

    printf(abc());

    return 0;

}

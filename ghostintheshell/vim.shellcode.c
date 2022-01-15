const char shellcode[] =
	"\x31\xc0"                // xor %eax, %eax      a = 0
	"\x31\xc9"                // xor %ecx, %ecx      c = 0 (*argv[])
	"\x99"                    // cdq                 d = 0 (*envp[])

	"\x50"                    // push %eax           (push the null-terminated
	"\x68\x2f\x76\x69\x6d"    // push $0x6d69762f     string "/usr/bin/vim")
	"\x68\x2f\x62\x69\x6e"    // push $0x6e69622f
	"\x68\x2f\x75\x73\x72"    // push $0x7273752f

	"\x89\xe3"                // mov %esp, %ebx      b = &filename

	"\xb0\x0b"                // mov $0x0b, %al      a = 11 (execve)
	"\xcd\x80";               // int $0x80           syscall

int main() {
	((void (*)()) shellcode)();

	return 0;
}

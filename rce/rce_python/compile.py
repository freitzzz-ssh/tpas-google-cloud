import subprocess
import sys
import tempfile
from Cython.Compiler import Main, CmdLine, Options

in_file_name = sys.argv[1]
source = open(in_file_name).read()
out_file_name = in_file_name.replace('.py', '')

temp_py_file = tempfile.NamedTemporaryFile(suffix='.py', delete=False)
temp_py_file.write(source.encode())
temp_py_file.flush()

Main.Options.embed = 'main'
res = Main.compile_single(temp_py_file.name, Main.CompilationOptions(), '')

gcc_cmd = 'gcc -fPIC -O2 -static %s -I/usr/include/python3.9 -L/usr/lib/python3.9 -lpython3.9 -o %s -I/usr/include/python3.9 -I/usr/include/x86_64-linux-gnu/python3.9 -lm -lutil -ldl -lz -lexpat -lpthread -lc' % (res.c_file, out_file_name)

print(gcc_cmd)
assert 0 == subprocess.check_call(gcc_cmd.split(' '))

from __future__ import print_function
import sys

template_file = open('template.txt','r', encoding='utf-8')
if len(sys.argv) < 2:
    print ("how to use: ", sys.argv[0], 'name')
    exit()
name = sys.argv[1]
template = template_file.read()

out_file = open(name + '.cpp', 'w', encoding='cp949')
out_data = template.format(name)
print(out_data)

out_file.write(out_data)
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 28 15:53:05 2020

@author: caoting
"""

#%% Json demo
try:
    raise NameError('HiThere')
except NameError:
    print('An Exception Flew by!')
    
    
#%% os module

import os
dir = os.getcwd()
print(dir)

#%% date
from datetime import date
now = date.today()
print(now.strftime("%m-%d-%y. %d %b %Y is a %A on the %d day of %B"))

#%% anothe time
birthday = date(1990,5,27)
now = date.today()
age = now - birthday
print(age)
print(age.days)

#%% testwrap 模块讷讷狗狗格式化文本段落，以适应给定的屏幕宽度
import textwrap
doc = """The wrap() mehtod is like fill() except that it returns
a list of strings instead of one big string with newlins to separate
the wrapped lines."""
print(textwrap.fill(doc,width=40))

#%% multi threads
import threading,zipfile

class AsyncZip(threading.Thread):
    def __init__(self,infile,outfile):
        threading.Thread.__init__(self)
        self.infile=infile
        self.outfile=outfile
    
    def run(self):
        f = zipfile.ZipFile(self.outfile,'w',zipfile.ZIP_DEFLATED)
        f.write(self.infile)
        f.close()
        print("Finished background zip of:",self.infile)

background = AsyncZip('mydata.txt','myarchive.zip')
background.start()
print('The main program continues to run in foreground')
background.join()
print('Main program waited until background was done')

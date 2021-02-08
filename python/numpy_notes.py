#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 29 11:37:22 2020

@author: caoting
"""
#%% simple plot
import numpy as np
from matplotlib import pyplot as plt

x = np.arange(1,11)
y = x*2+5
plt.title("Matplotlib demo")
plt.xlabel("x axis caption")
plt.ylabel("y axis caption")
plt.plot(x,y)
plt.show()

#%% os uid pwd
import os
user = os.getlogin()

import pwd
userpwd = pwd.getpwuid(os.getuid())

for id in pwd.getpwall():
    print(id(0))
    
#%% matlabplot, subplot
import numpy as np
from matplotlib import pyplot as plt

x = np.arange(0,3*np.pi,0.2)
y_sin = np.sin(x)
y_cos = np.cos(x)


plt.subplot(2,1,1)
plt.title("sin func")
plt.plot(x,y_sin,"*r")

plt.subplot(2,1,2)
plt.title("cos func")
plt.xlabel("x axis")
plt.ylabel("y axis")
plt.plot(x,y_cos,"+b")

plt.show()

#%% bar
from matplotlib import pyplot as plt
x = [5,8,10]
y=12,16,6
x2=[6,9,11]
y2=[6,15,7]
plt.bar(x,y,align='center')
plt.bar(x2,y2,color='g',align='center')
plt.title('Bar Graph')
plt.xlabel('X axis')
plt.ylabel('Y axis')
plt.show()

#%% histogram
import numpy as np
a = np.array([22,87,5,43,56,73,55,54,11,20,51,5,79,31,27])
hist,bins=np.histogram(a,bins=[0,20,40,60,80,100])
print(hist)
print(bins)

plt.hist(a,bins=[0,20,40,60,80,100])
plt.title('histogram')
plt.show()

#%% arrays
import numpy as np
a = np.array([[1.0,2.0],[3.0,4.0]])
b = np.array([[5.0,6.0],[7.0,8.0]])
sum = a + b
difference = a - b
product = a * b
quotient = a / b
print("Sum=",sum)
print("difference=",difference)
print("product=",product)
print("quotient=",quotient)
print("Dot=",a.dot(b))

#%% MD Array
a = np.array([[11,12,13,14,15],
              [16,17,18,19,20],
              [21,22,23,24,25],
              [26,27,28,29,30],
              [31,32,33,34,35]])
print(a[0,1:4])
print(a[1:4,0])
print(a[::2,::2])
print(a[:,1])

#%% boolean masking
import matplotlib.pyplot as plt
a = np.linspace(0,2*np.pi,50)
b = np.sin(a)
plt.plot(a,b)
mask = b>=0
plt.plot(a[mask],b[mask],'bo')
mask = (b>=0) & (a<=np.pi/2)
plt.plot(a[mask],b[mask],'go')
plot.show()

#%%
d = {'person':2,'cat':4,'spider':8}
for animal,legs in d.items():
    print('A %s has %d legs'%(animal,legs))

#%%
animals = {'cat','dog','fish'}
for idx,animal in enumerate(animals):
    print('#%d: %s'%(idx+1,animal))

#%%
from math import sqrt
nums = {int(sqrt(x)) for x in range(30)}
print(nums)

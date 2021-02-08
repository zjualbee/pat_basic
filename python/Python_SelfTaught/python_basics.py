#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 26 11:09:49 2020

@author: caoting
""" 

#%% 分割cell
#CTRL + enter执行当前cell
#shift + enter运行当前cell并将光标移到下一个cell


#%%est while circle
qs = ["what is your name?",
      "what is your fav. color?",
      "what is your question?"]
n=0
while True:
    print("Type q to quit")
    a = input(qs[n])
    if a == "q":
        break
    n = (n+1)%3
    

#%%test lists
lis=["The walking dog","entoruage","the sppranos","the vampire diaries"]
i=0
for de in lis:
    print(i)
    print(de)
    i+=1



#%% test file read and write
my_list = list()
with open("test.py","r") as f:
    my_list.append(f.read())

print(my_list)


#%% write csv file
import csv
with open("st.csv","w") as f:
    w = csv.writer(f,delimiter=",")
    for i in range(1,20):
        rowlist=[]
        for j in range(0,i):   
            rowlist.append(j)
        w.writerow(rowlist)


#%% read csv file
import csv
with open("st.csv","r") as f:
    r=csv.reader(f,delimiter=",")
    for row in r:
        print(" ".join(row))


#%% functions deom cubed
def cubenum():
    a = input("Enter a number:")
    a = int(a)
    return a**3

cubenum()
#%% class demo
class Orange:
    def __init__(self,w,c):
        self.weight=w
        self.color=c
        self.mold=0
        print("Created!")
    def rot(self,days,temp):
        self.mold = days*temp
        
or1 = Orange(10,"dark color")
print(or1.weight)
print(or1.color)
print(or1.mold)
or1.rot(10,20)
print(or1.mold)


#%% calculate rectangle area

class Rectangle():
    def __init__(self,w,l):
        self.width=w
        self.length=l
        
    def area(self):
        return self.width*self.length
    
    def change_size(self,w,l):
        self.width=w
        self.length=l

r1 = Rectangle(10,20)
print(r1.area())
r1.change_size(20,30)
print(r1.area())


#%% calculate circle area
import math
class Circle():
    def __init__(self,r):
        self.radius=r
    
    def area(self):
        return math.pi*self.radius*self.radius

r1 = Circle(2)
print(r1.area())


#%% 继承demo
class Shape():
    def __init__(self,w,l):
        self.width=w
        self.len=l
        
    def print_shape(self):
        print("{} by {}".format(self.width,self.len))

class Square(Shape):
    def print_shape(self):
        print("I am {} by {}".format(self.width,self.len))
    def area(self):
        return self.width*self.len

a_s = Square(10,20)
a_s.print_shape()
print(a_s.area())


#%% composition
class Horse():
    def __init__(self,name,breed,owner):
        self.name=name
        self.breed=breed
        self.owner=owner

class Rider():
    def __init__(self,name):
        self.name=name

mick = Rider("Michael Jackson")
stan = Horse("Stanley","bulldog",mick)
print(stan.owner.name)


#%% 继承，多态，抽象，封装
class Shape():
    def what_am_i(self):
        print("I am a shape")
        
class Rectangle(Shape):
    def __init__(self,w,l):
        self.width=w
        self.len=l
    def calculate_perimeter(self):
        return (self.width+self.len)*2
    
class Square(Shape):
    square_list=[]
    def __init__(self,s):
        self.s=s
        self.square_list.append((self.s))
    def calculate_perimeter(self):
        return self.s*4
    def change_size(self,s):
        self.s=s
    def __repr__(self):
        return "{} by {} by {} by {}".format(self.s,self.s,self.s,self.s)
    
squ1=Square(20)
print(squ1)


#%% compare comp
def comp(ob1,ob2):
        return ob1 is ob2

class Person():
    def __init__(self,name):
        self.name=name

ct = Person("ct")
xgh = Person("Xgh")

print(comp(ct,xgh))
print(comp(ct,ct))


#%% 正则表达式，定义检索模式的字符串序列
import re
l = "aoo how are you"
matches = re.findall("oo*",l,re.IGNORECASE)
print(matches)


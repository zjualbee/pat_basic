#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 28 09:29:46 2020

@author: caoting
"""

class Stack:
    def __init__(self):
        self.items=[]
    def push(self,item):
        self.items.append(item)
    def pop(self):
        return self.items.pop()
    def is_empty(self):
        return self.items==[]
    def size(self):
        return len(self.items)
    def peek(self):
        return self.items[self.size()-1]
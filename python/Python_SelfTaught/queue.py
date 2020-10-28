#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 28 09:34:34 2020

@author: caoting
"""
import time
import random
class Queue:
    def __init__(self):
        self.items=[]
    def is_empty(self):
        return self.items==[]
    def enqueue(self,item):
        self.items.insert(0,item)
    def dequeue(self):
        return self.items.pop()
    def size(self):
        return len(self.items)

    def simulate_line(self,till_show,max_time):
        pq = Queue()
        tix_sold=[]
        used_time=[]
        for i in range(10):
            pq.enqueue("person"+str(i))
        t_end=time.time()+till_show
        now=time.time()
        while now<t_end and not pq.is_empty():
            now = time.time()
            r = random.randint(0,max_time)
            time.sleep(r)
            person= pq.dequeue()
            tix_sold.append([person,r])
        return tix_sold

queue=Queue()
sold = queue.simulate_line(5,1)
print(sold)

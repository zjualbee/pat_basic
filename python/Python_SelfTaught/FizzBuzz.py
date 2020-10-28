#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 28 09:53:27 2020

@author: caoting
"""

#FizzBuzz Algorithm, 3的倍数 Fizz,5的倍数Buzz, 3 and 5的倍数，FizzBuzz

def FizzBuzz(num1,num2):
    for i in range(num1,num2):
        curs = ""
        if i%3==0:
            curs+="Fizz"
        if i%5==0:
            curs+="Buzz"
        if len(curs)==0:
            print(i)
        else:
            print(curs)


            
        
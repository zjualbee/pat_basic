#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Oct 28 10:11:54 2020

@author: caoting
"""

#%% plindrome algorithm回文字符
import stack
def plindrome(word):
    word = word.lower()
    st = stack.Stack()
    for c in word:
        st.push(c)
    for i in range(st.size()):
        if word[i]!=st.pop():
            return False
    return True


#%% 变位词
def anagram(w1,w2):
    w1 = w1.lower()
    w2 = w2.lower()
    return sorted(w1)==sorted(w2)


#%% 统计字母个数
def count_characters(string):
    count_dict={}
    for c in string:
        if c in count_dict:
            count_dict[c]+=1
        else:
            count_dict[c]=1
    return count_dict
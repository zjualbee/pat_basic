#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 27 14:36:50 2020

@author: caoting
"""
# hangman.py 猜词游戏
# words.py 使用pickle永久性存储数据

import pickle

filename = 'words.pk'
data = ['cat', 'dog', 'perro', 'gato', 'horse', 'elephant', 'mono', 'candy','tools','python']
with open(filename, 'wb') as f:
    pickle.dump(data, f)

# 使用random.choice函数在序列中随机选择
import random

def hangman(word):  # 传入一个参数(word)
    # 错误数量
    wrong = 0 
    # 要画的步骤 
    stages = ["",
        "______       ",
        "|      |       ",
        "|      |    ",
        "|      0    ",
        "|     /|\   ",
        "|     / \   ",
        "|           ",
    ]
    # 将词转换为一个列表
    rletters = list(word)
    # 生成一个下划线的待猜列表
    board = ["_"] * len(word)
    # 未赢
    win = False
    print('Welcome to Hangman')
    
    # 如果画还没画完
    while wrong < len(stages) - 1:
        print('\n')    
        # 猜一个字母
        msg = 'Guess a letter: '
        char = input(msg)
        # 如果字母在列表中
        if char in rletters:
            # 将列表中的字母剔除('$')，并在待猜列表中添加字母
            cind = rletters.index(char)
            board[cind] = char
            rletters[cind] = '$'
        # 如果字母不在列表中
        else:
            # 错误+1
            wrong += 1
        # 显示待猜列表
        print('word: ' + (" ".join(board)))
        # 打印图画
        e = wrong + 1
        print('\n'.join(stages[0:e]))
        # 如果待猜列表中以及没有下划线了，赢了
        if '_' not in board:
            print('You win!')
            print(' '.join(board))
            win = True
            break
    # 如果输了
    if not win:
        print('You lose! It was {}'.format(word))


def random_word(filename='words.pk'):
    with open(filename, 'rb') as f:
        data = pickle.load(f)
        return random.choice(data)


if __name__ == '__main__':
    while True:
        hangman(random_word())
        flag = input('Do you want to continue?(Y/N) ')    
        if flag.lower() not in ['y', 'yes']:
            break
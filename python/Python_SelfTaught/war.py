#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 27 16:41:17 2020

@author: caoting
"""

from random import shuffle

class Card:
    suits = ["spades","hearts","diamonds","clubs"]
    values = [None,None,"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"]
    
    def __init__(self,v,s):
        self.value=v
        self.suit=s
    
    def __lt__(self,c2):
        if self.value<c2.value:
            return True
        if self.value == c2.value:
            if self.suit<c2.suit:
                return True
            else:
                return False
        return False
    def __gt__(self,c2):
        if self.value>c2.value:
            return True
        if self.value == c2.value:
            if self.suit>c2.suit:
                return True
            else:
                return False
        return False
    def __repr__(self):
        return self.values[self.value] + " of " + self.suits[self.suit]
    
class Deck:
    def __init__(self):
        self.cards=[]
        for i in range(2,15):
            for j in range(0,4):
                self.cards.append(Card(i,j))
        shuffle(self.cards)
        
    def rm_card(self):
        if len(self.cards) == 0:
            return
        return self.cards.pop()
    
class Player:
    def __init__(self,name):
        self.wins = 0
        self.name = name
        self.card = None
        
class Game:
    def __init__(self):
        name1 = input("p1 name: ")
        name2 = input("p2 name: ")
        self.deck = Deck()
        self.p1=Player(name1)
        self.p2=Player(name2)
        self.cnt=0
    def wins(self,winner):
        w = "{} wind this round".format(winner)
        print(w)
    def draw(self,p1n,p1c,p2n,p2c):
        d = "{}:{}, {}:{}".format(p1n,p1c,p2n,p2c)
        print(d)
    def winner(self,p1,p2):
        if p1.wins>p2.wins:
            return p1.name
        elif p1.wins<p2.wins:
            return p2.name
        else:
            return "It was a tie!"
    def play_game(self):
        cards = self.deck.cards
        print("beginning War!")
        while len(cards)>=2:
            m="q to quit. Any "+"key to play:"
            response = input(m)
            if response == 'q':
                break
            self.cnt+=1
            p1c = self.deck.rm_card()
            p2c = self.deck.rm_card()
            p1n = self.p1.name
            p2n = self.p2.name
            winner = None
            if p1c>p2c:
                self.p1.wins+=1
                rw = self.p1.name
            else:
                self.p2.wins+=1
                rw = self.p2.name
            print("Round {}, {}:{}={}:{}".format\
                  (self.cnt,p1n,p2n,self.p1.wins,self.p2.wins))
            self.wins(rw)
            self.draw(p1n,p1c,p2n,p2c)
        win=self.winner(self.p1,self.p2)
        print("War is over. {} wins".format(win))

game = Game()
game.play_game()
                
        
        
        
        
        
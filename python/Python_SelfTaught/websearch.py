#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Oct 27 19:26:43 2020

@author: caoting
"""
#parser
import urllib.request
from bs4 import BeautifulSoup
class Scraper:
    def __init__(self,site):
        self.site=site
    def scrape(self):
        r = urllib.request.urlopen(self.site)
        html = r.read()
        parser = "html.parser"
        sp = BeautifulSoup(html,parser)
        for tag in sp.find_all("a"):
            print(tag)
            url = tag.get("href")
            print(url)
            if url is None:
                continue
            if "html" in url:
                print("\n"+url)
                
news = "http://news.baidu.com"
Scraper(news).scrape()

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Dec  7 11:55:55 2020

@author: caoting
"""

 
"""
key experiments steps about the handling of the Blast Furnace Surface:

1.image preprocessing: gray, 增强对比度，从而进行关键帧的提取
2.object detection: fire and furnace
3.3D reconstruction: 信息补全及插值等

"""
#本部分主要进行part2
#%% 读取关键帧图像，进行图像清晰化处理，前人使用极化特征



#%% 进行火焰和炉壁的目标检测，确认料面范围（mask)，采用经典目标检测算法进行初期实验，如CNN/RNN etc
#Yi et al.采用Canny算子和morphological操作



#%% 料面信息补全算法，主要是火焰部分，如果有料面缺失部分同时进行补全



#%% 深度信息提取，根据清晰度等特征及机械探尺拟合参数换算



#%% 全料面三维重建，基于二维图像的三维重建算法研究



#%% 显示图形库，显示优化及渲染
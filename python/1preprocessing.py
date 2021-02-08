#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Nov 27 15:39:18 2020

@author: caoting
"""
 
"""
key experiments steps about the handling of the Blast Furnace Surface:

1.image preprocessing: gray, 增强对比度，从而进行关键帧的提取
2.object detection: fire and furnace
3.3D reconstruction: 信息补全及插值等

"""
 
#%% 读取视频图像，并对每一帧图像进行处理（灰度、对比度增强，纹理粗计算），提取出关键帧
# 前人采用光流法和图像特征进行筛选
# 1. 转为灰度图
# 2. 对比度增强
import cv2
source = "resources/stable3.mp4"
cap = cv2.VideoCapture(source)# 获取一个视频打开cap 1 file name
isOpened = cap.isOpened# 判断是否打开‘
print(isOpened)
fps = cap.get(cv2.CAP_PROP_FPS)#帧率
width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))#w h
height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
totalFrameNum = int(cap.get(cv2.CAP_PROP_FRAME_COUNT)) #count
print(fps,width,height,totalFrameNum)
video = cv2.VideoWriter('resources/stable3gray.mp4', cv2.VideoWriter_fourcc('m', 'p', '4', 'v'), fps, (width,height)) #创建视频流对象
i = 0
while(isOpened):
    i = i+1
    (flag,frame) = cap.read()# 读取每一张 flag:是否读取成功 frame：图片内容
    if flag == True:
        if i%2==0:   
            gray = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)       
            video.write(gray)
            fileName = 'image'+str(i)+'.jpg'
            cv2.imwrite(fileName,frame,[cv2.IMWRITE_JPEG_QUALITY,100])
            print(fileName)
    else:
        break
print('end!')
cap.release()
cv2.destroyAllWindows()

#%%  灰度直方图绘制
import cv2
import numpy as np
import matplotlib.pyplot as plt

source = 'resources/stable3/image180.jpg'
def calcGrayHist(image):
    rows,cols = image.shape[:2]
    grayHist = np.zeros([256],np.uint64)
    for r in range(rows):
        for c in range(cols):
            grayHist[image[r][c]]+=1
    x_range=range(256)
    grayHist[255]=0
    plt.plot(x_range,grayHist,'r',linewidth=2,c='black')
    y_maxValue=np.max(grayHist)
    plt.axis([0,255,0,y_maxValue])
    plt.ylabel('gray level')
    plt.xlabel('number or pixels')
    plt.show()

def NpGrayHist(img):
    histogram,bins=np.histogram(img,bins=256,range=[0,256])
    #print(histogram)
    histogram[255]=0   #当特殊值均被赋值给255时，会导致255点出的像素值异常偏多
    plt.plot(histogram,color='g')
    plt.axis([0,256,0,np.max(histogram)])
    plt.show()

def NpCDF(img):
    histogram,bins=np.histogram(img,bins=256,range=[0,256])
    cdf=np.zeros([256],np.uint64)
    for i in range(256):
        if i==0:
            cdf[i]=histogram[0]
        else:
            cdf[i]=histogram[i]+cdf[i-1]
    plt.plot(cdf,color='r')
    plt.axis([0,256,0,np.max(cdf)])
    plt.show()
        
    
#%% 对比度增强，线性变换,通过cv2的函数实现
if __name__ == '__main__':
    #读入图像
    src = cv2.imread(source,0)
    img_bright=cv2.convertScaleAbs(src,alpha=1.3,beta=0)
    NpGrayHist(src)
    NpGrayHist(img_bright)
    NpCDF(src)
    NpCDF(img_bright)
    cv2.imshow("src",src)
    cv2.imshow("img_bright",img_bright)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
#%% 对比度增强，通过np实现        
if __name__ == '__main__':
    #读入图像
    src = cv2.imread(source, cv2.IMREAD_GRAYSCALE)
    a=1.5
    b=0
    y=np.float(a)*src+b
    y[y>255]=255
    y=np.round(y)
    img_bright=y.astype(np.uint8)
    cv2.imshow('img',src)
    cv2.imshow('dst',img_bright)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
#%% 对比度增强，直方图正规化
if __name__ == '__main__':
    src = cv2.imread(source, cv2.IMREAD_GRAYSCALE)
    img_norm=cv2.normalize(src, dst=None,alpha=350,beta=10,norm_type=cv2.NORM_MINMAX)
    cv2.imshow('src',src)
    cv2.imshow('dst',img_norm)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

#%% 对比度增强，伽马变换
if __name__ == '__main__':
    src = cv2.imread(source, cv2.IMREAD_GRAYSCALE)
    img_norm=src/255.0
    img_gamma=np.power(img_norm,0.5)*255.0
    img_gamma=img_gamma.astype(np.uint8)
    NpGrayHist(src)
    NpGrayHist(img_gamma)
    cv2.imshow('src',src)
    cv2.imshow('dst',img_gamma)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

#%% 对比度增强，全局直方图均衡化
if __name__ == '__main__':
    src = cv2.imread(source, cv2.IMREAD_GRAYSCALE)
    img_equaliz=cv2.equalizeHist(src)
    NpGrayHist(src)
    NpGrayHist(img_equaliz)
    cv2.imshow('src',src)
    cv2.imshow('dst',img_equaliz)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
#%% 限制对比度自适应直方图均衡化
if __name__ == '__main__':
    src = cv2.imread(source, cv2.IMREAD_GRAYSCALE)
    clahe = cv2.createCLAHE(2,(8,8))
    dst=clahe.apply(src)
    NpGrayHist(src)
    NpGrayHist(dst)
    cv2.imwrite('resources/image180_clahe.jpg',dst)
    cv2.imshow('img',np.hstack((src,dst)))
    cv2.waitKey(0)
    cv2.destroyAllWindows()


#%% 二值分割   https://blog.csdn.net/qq_40962368/article/details/80917250
img = cv2.imread('resources/image180_clahe.jpg',0)
ret, th = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY)
cv2.imwrite('resources/image180_clahe_threshold.jpg',th)
cv2.imshow('binary',th)
cv2.waitKey(0)
cv2.destroyAllWindows()

#%%图片融合
import cv2
import numpy as np
img1 = cv2.imread('resources/image180_clahe.jpg',1)
img2 = cv2.imread('resources/image180_clahe_threshold.jpg',1)
height,width = img1.shape[:2]

#ROI
roiH = int(height)
roiW = int(width)
img1ROI = img1[0:roiH,0:roiW]
img2ROI = img2[0:roiH,0:roiW]
dst = np.zeros((roiH,roiW,3),np.uint8)
dst = cv2.addWeighted(img1ROI,0.9,img2ROI,0.1,0)
cv2.imshow('dst',dst)
cv2.imshow('img1',img1)
cv2.waitKey(0)
cv2.destroyAllWindows()

#%% 自适应阈值分割,检测到火焰区域，可以设置为mask然后进行插值补全
# https://blog.csdn.net/qq_40962368/article/details/80917250
import cv2 as cv 
import matplotlib.pyplot as plt

img = cv.imread('resources/stable3/image180.jpg',0)

# 固定阈值
ret, th1 = cv.threshold(img, 127, 255, cv.THRESH_BINARY)
# 自适应阈值
th2 = cv.adaptiveThreshold(
    img, 255, cv.ADAPTIVE_THRESH_MEAN_C, cv.THRESH_BINARY, 15, 4)
th3 = cv.adaptiveThreshold(
    img, 255, cv.ADAPTIVE_THRESH_GAUSSIAN_C, cv.THRESH_BINARY, 15, 8)

titles = ['Original', 'Global(v = 127)', 'Adaptive Mean', 'Adaptive Gaussian']
images = [img, th1, th2, th3]

for i in range(4):
    plt.subplot(2, 2, i + 1), plt.imshow(images[i], 'gray')
    plt.title(titles[i], fontsize=8)
    plt.xticks([]), plt.yticks([])
plt.show()

#%%频域中的同态滤波，进行图像增强
import os
import cv2
from PIL import Image
import numpy as np


def homomorphic_filter(src, d0=10, r1=0.5, rh=2, c=4, h=2.0, l=0.5):
    gray = src.copy()
    if len(src.shape) > 2:
        gray = cv2.cvtColor(src, cv2.COLOR_BGR2GRAY)
    gray = np.float64(gray) 
    rows, cols = gray.shape
    gray_fft = np.fft.fft2(gray)
    gray_fftshift = np.fft.fftshift(gray_fft)
    dst_fftshift = np.zeros_like(gray_fftshift)
    M, N = np.meshgrid(np.arange(-cols // 2, cols // 2), np.arange(-rows//2, rows//2))
    D = np.sqrt(M ** 2 + N ** 2)
    Z = (rh - r1) * (1 - np.exp(-c * (D ** 2 / d0 ** 2))) + r1
    dst_fftshift = Z * gray_fftshift
    dst_fftshift = (h - l) * dst_fftshift + l
    dst_ifftshift = np.fft.ifftshift(dst_fftshift)
    dst_ifft = np.fft.ifft2(dst_ifftshift)
    dst = np.real(dst_ifft)
    dst = np.uint8(np.clip(dst, 0, 255))
    return dst

path = "resources/image180.jpg"
if os.path.isfile(path):
    print("path {} is existence;".format(path))
    img = Image.open(path)
    Img = img.convert('L')
    img = np.array(img)
    print(img, img.shape)
img_new = homomorphic_filter(img)
print("new img shape is {}".format(img_new.shape))
cv2.imwrite("resources/homomorphic.jpg", img_new)
cv2.imshow('homomorphic',img_new)
cv2.waitKey(0)
cv2.destroyAllWindows()


#%% 使用帧间差分法判断相邻两帧之间差异
path1="resources/image120.jpg"
path2="resources/image180.jpg"
img1=cv2.imread(path1,0)
img2=cv2.imread(path2,0)
imgd=img1-img2;
cv2.imshow('img',np.hstack((img1,imgd)))
cv2.waitKey(0)
cv2.destroyAllWindows()
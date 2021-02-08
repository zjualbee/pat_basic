#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Nov 26 17:49:05 2020

@author: caoting
"""

#%%
import tensorflow as tf
data1 = tf.constant(2,dtype=tf.int32)   #定义常量
data2 = tf.Variable(10,name='var')     #定义变量
print(data1)
print(data2)

#%%
import tensorflow as tf
data1 = tf.constant(6)
data2 = tf.Variable(2)
dataAdd = tf.add(data1,data2)
dataCopy = tf.assign(data2, dataAdd)  # 把dataAdd的值赋给data2
dataMul = tf.multiply(data1,data2)
dataSub = tf.subtract(data1,data2)
dataDiv = tf.divide(data1,data2)
init = tf.global_variables_initializer()  #变量初始化

with tf.Session() as sess:
    sess.run(init)
    print(sess.run(dataAdd))
    print(sess.run(dataMul))
    print(sess.run(dataSub))
    print(sess.run(dataDiv))
    print("sess.run(dataCopy) = ",sess.run(dataCopy))   # 8
    print("dataCopy.eval() = ", dataCopy.eval())        # 8+6 -> 14
print('end')

"""
#运算结果
8
12
4
3.0
sess.run(dataCopy) =  8
dataCopy.eval() =  14
end
"""
#%%
import tensorflow as tf
data1 = tf.placeholder(tf.float32) # 占位符
data2 = tf.placeholder(tf.float32)
dataAdd = tf.add(data1, data2)
with tf.Session() as sess:
    print(sess.run(dataAdd,feed_dict={data1:12,data2:3}))
    # feed_dict = { 参数1：6，参数2：2}，字典格式
print('end!')
"""
#运算结果
8.0
end
"""
#%%
#矩阵运算  M行*N列
import tensorflow as tf
data1 = tf.constant([[6,6]]) #一行两列
data2 = tf.constant([[2],
                     [2]])   #两行一列
data3 = tf.constant([[3,3]]) #一行两列
data4 = tf.constant([[1,2],
                    [3,4],
                    [5,6]])  #三行两列
print(data4.shape)  #打印矩阵的维度

#打印矩阵中的具体值
with tf.Session() as sess:
    print(sess.run(data4))  #打印整体内容
    print(sess.run(data4[0])) #打印某一行
    print(sess.run(data4[:,0])) #打印某一列
    print(sess.run(data4[0, 0]))  # 打印第一行第一列
"""    
运行结果
(3, 2)
[[1 2]
 [3 4]
 [5 6]]
[1 2]
[1 3 5]
1
"""
#%%
import tensorflow as tf
data1 = tf.constant([[6,6]]) #一行两列
data2 = tf.constant([[2],
                     [2]])   #两行一列
data3 = tf.constant([[3,3]]) #一行两列
data4 = tf.constant([[1,2],
                    [3,4],
                    [5,6]])  #三行两列
matMul = tf.matmul(data1,data2)   #矩阵乘法
matMul2 = tf.multiply(data1,data2)  #
matAdd = tf.add(data1,data3)      #矩阵加法
with tf.Session() as sess:
    print(sess.run(matMul))
    print(sess.run(matMul2))
    print(sess.run(matAdd))
    print(sess.run([matMul,matMul2]))  #同时打印多个值
"""
运行结果：
[[24]]
[[12 12]
 [12 12]]
[[9 9]]
[array([[24]]), array([[12, 12],
       [12, 12]])]
"""
#%%
import tensorflow as tf
mat1 = tf.zeros([2,3],dtype= tf.int16) #定义一个2*3的空矩阵
mat2 = tf.ones([3,2]) #定义一个3*2的全1矩阵
mat3 = tf.fill([2,3],15)  #定义一个填充矩阵
mat4 = tf.zeros_like(mat1) #打印一个同维度的0矩阵
mat5 = tf.linspace(0.0,2.0,11)  #把0-2之间的数据分成相等的10份
mat6 = tf.random_uniform([2,3],-1,2) #生成一个2*3的随机矩阵，范围在-1-2之间
with tf.Session() as sess:
    print(sess.run(mat1))
    print(sess.run(mat2))
    print(sess.run(mat3))
    print(sess.run(mat4))
    print(sess.run(mat5))
    print(sess.run(mat6))
    
#%%
import numpy as np
data1 = np.array([1,2,3,4,5])
data2 = np.array([[1,2],
                 [3,4]])
print(data1)
print(data1.shape)
print(data2)
print(data2.shape)
print(np.zeros([2,3]),'\n',np.ones([2,3]))
#改查
data2[1,0] = 5
print(data2)
print(data2[1,1])

#%%
import numpy as np
import matplotlib.pyplot as plt

x = np.array([1,2,3,4,5,6,7,8])
y = np.random.randint(5,size = 8)
plt.plot(x,y,'g',lw = 5)  # 折线
plt.bar(x,y,0.5,alpha=1,color='b')  # 饼状
plt.show()

#%%调用API实现图像缩放
import cv2
img = cv2.imread('resources/son.jpg',1)
cv2.imshow('original',img)
imgInfo = img.shape
print(imgInfo)
height = imgInfo[0]
width = imgInfo[1]
mode = imgInfo[2]
# 1 放大 缩小 2 等比例 非 2:3
dstHeight = int(height*0.2)
dstWidth = int(width*0.2)
#最近临域插值 双线性插值 像素关系重采样 立方插值
dst = cv2.resize(img,(dstWidth,dstHeight))   #调用API
cv2.imshow('image',dst)
dstInfo = dst.shape
print(dstInfo)
cv2.waitKey(0)
cv2.destroyAllWindows()
"""
输出结果为：
(512, 512, 3)
(256, 256, 3)
"""
#%% 源码实现图像缩放
import cv2
import numpy as np
img = cv2.imread('resources/son.jpg',1)
imgInfo = img.shape
height = imgInfo[0]
width = imgInfo[1]
dstHeight = int(height/2)
dstWidth = int(width/2)
dstImage = np.zeros((dstHeight,dstWidth,3),np.uint8) #0-255
for i in range(dstHeight):#行
    for j in range(dstWidth):#列
        iNew = int(i*(height/dstHeight))
        jNew = int(j*(width/dstWidth))
        dstImage[i,j] = img[iNew,jNew]
cv2.imshow('dst',dstImage)
cv2.waitKey(0)
cv2.destroyAllWindows()

#%%图像剪切
import cv2
img = cv2.imread('resources/son.jpg',1)
imgInfo = img.shape
dst = img[100:500,100:300]  #[行，列]
cv2.imshow('image',dst)
cv2.waitKey(0)
cv2.destroyAllWindows() 

#%% 解决了opencv窗口无法关闭的问题
import cv2
import numpy as np
img = cv2.imread('resources/son.jpg',1)
cv2.imshow('src',img)
imgInfo = img.shape
dst1 = np.zeros(img.shape,np.uint8)
dst2 = np.zeros(img.shape,np.uint8)
height = imgInfo[0]
width = imgInfo[1]
#行列不能同时移位，要分开进行
# 行移位
for i in range(height-200):
    for j in range(width):
        dst1[i+200, j] = img[i, j]
#列移位
for i in range(height):
    for j in range(width-100):
        dst2[i,j+100]=dst1[i,j]
cv2.imshow('image',dst2)
cv2.waitKey(0)
cv2.destroyAllWindows()  

#%%调用API实现图像移位（cv2.warpAffine）
import cv2
import numpy as np
img = cv2.imread('resources/son.jpg',1)
cv2.imshow('src',img)
height, width = img.shape[:2]
matShift = np.float32([[1,0,100],[0,1,200]]) # 2*3矩阵
dst = cv2.warpAffine(img,matShift,(width,height)) #1 原图像 2 移位矩阵 3 行列信息
cv2.imshow('dst',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()

# [1,0,100],[0,1,200] 2*2 2*1
# [[1,0],[0,1]]  2*2  A
# [[100],[200]] 2*1   B
# xy C
# A*C+B = [[1*x+0*y],[0*x+1*y]]+[[100],[200]]
#(0,0)->(100,200)
# (X,Y)= (x+100,y+200)

#%% 仿射变换 旋转
import cv2
img=cv2.imread("resources/son.jpg")
height,width=img.shape[:2]
M=cv2.getRotationMatrix2D((width/2,height/2),30,0.8)
rotate=cv2.warpAffine(img,M,(width,height))
cv2.imshow("original",img)
cv2.imshow("rotation",rotate)
cv2.waitKey(0)
cv2.destroyAllWindows()
    
#%% 放射变换 3点改变
import cv2
import numpy as np
img = cv2.imread("resources/son.jpg")
rows,cols,ch=img.shape
p1=np.float32([[0,0],[cols-1,0],[0,rows-1]])
p2=np.float32([[0,rows*0.33],[cols*0.85,rows*0.25],[cols*0.15,rows*0.7]])
M=cv2.getAffineTransform(p1,p2)
dst=cv2.warpAffine(img,M,(cols,rows))
cv2.imshow("original",img)
cv2.imshow("result",dst)
cv2.waitKey(0)
cv2.destroyAllWindows()

#%%透视变换
import cv2
import numpy as np
img=cv2.imread('resources/son.jpg')
rows,cols=img.shape[:2]
print(rows,cols)
pts1 = np.float32([[150,50],[400,50],[60,450],[310,450]])
pts2 = np.float32([[50,50],[rows-50,50],[50,cols-50],[rows-50,cols-50]])
M=cv2.getPerspectiveTransform(pts1,pts2)
dst=cv2.warpPerspective(img,M,(cols,rows))
cv2.imshow("img",img)
cv2.imshow("dst",dst)
cv2.waitKey(0)
cv2.destroyAllWindows()
    
#%%实现灰度处理
import cv2
img = cv2.imread('resources/son.jpg',1)
#dst = cv2.cvtColor(img,cv2.COLOR_RGB2GRAY)
height,width=img.shape[:2]
dst = np.zeros((height,width,3),np.uint8)
dstreverse = np.zeros((height,width,3),np.uint8)
for i in range(height):
    for j in range(width):
        (b,g,r)=img[i,j]
        gray=(int(b)+int(g)+int(r))/3
        dst[i,j]=int(gray)
        dstreverse[i,j]=(255-b,255-g,255-r)
cv2.imshow('rgb',img)
cv2.imshow('gray',dst)
cv2.imshow('grayreverse',dstreverse)
cv2.waitKey(0)
cv2.destroyAllWindows()
#%%马赛克效果
import cv2
import numpy as np
img = cv2.imread('resources/son.jpg',1)
info = img.shape
height = info[0]
width = info[1]
for m in range(100,300):
    for n in range(100,200):
        # pixel -> 10*10
        if m%10 == 0 and n%10 == 0:
            for i in range(0,10):
                for j in range(0,10):
                    (b,g,r) = img[m,n]
                    img[i+m,j+n] = (b,g,r)
cv2.imshow('dst',img)
cv2.waitKey(0)
cv2.destroyAllWindows()

#%%毛玻璃效果
import cv2
import numpy as np
import random
img = cv2.imread('resources/son.jpg',1)
info = img.shape
height = info[0]
width = info[1]
dst = np.zeros(img.shape,np.uint8)
#cv2.imshow('dst',dst)
mm = 8
for m in range(height-mm):
    for n in range(width-mm):
        index = int(random.random()*8)
        (b,g,r) = img[m+index,n+index]
        dst[m,n] = (b,g,r)
cv2.imshow('dst',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()

#%%图片融合
import cv2
import numpy as np
img1 = cv2.imread('resources/son.jpg',1)
img2 = cv2.imread('resources/lena.jpg',1)
height,width = img1.shape[:2]

#ROI
roiH = int(height)
roiW = int(width)
img1ROI = img1[0:roiH,0:roiW]
img2ROI = img2[0:roiH,0:roiW]
dst = np.zeros((roiH,roiW,3),np.uint8)
dst = cv2.addWeighted(img1ROI,0.8,img2ROI,0.2,0)
cv2.imshow('dst',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()

#%% Canny边缘检测
import cv2
import numpy as np
import random
img = cv2.imread('resources/son.jpg',1)
info = img.shape
height = info[0]
width = info[1]
cv2.imshow('img',img)
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
imgG = cv2.GaussianBlur(gray,(3,3),0)
dst = cv2.Canny(gray,100,100)
cv2.imshow('gray',gray)
cv2.imshow('imgG',imgG)
cv2.imshow('dst',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()
#%% Sobel算子边缘检测
import cv2
import numpy as np
import random
import math
img = cv2.imread('resources/son.jpg',1)
info = img.shape
height = info[0]
width = info[1]
cv2.imshow('img',img)
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
dst = np.zeros((height,width,1),np.uint8)
for i in range(height-2):
    for j in range(width-2):
        gx =(gray[i-1,j+1]-gray[i-1,j-1])+2*(gray[i,j+1]-gray[i,j-1])+(gray[i+1,j+1]-gray[i+1,j-1])
        gy = (gray[i+1,j-1]-gray[i-1,j-1])+2*(gray[i+1,j]-gray[i-1,j])+(gray[i+1,j+1]-gray[i-1,j+1])
        grad = math.sqrt(gy*gy + gx*gx)
        if grad>800:
            dst[i,j] = 255
        else:
            dst[i,j] = 0
cv2.imshow('dst',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()

#%% 浮雕效果
import cv2
import numpy as np
img = cv2.imread('resources/lena.jpg',1)
info = img.shape
height = info[0]
width = info[1]
cv2.imshow('img',img)
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
dst = np.zeros((height,width,1),np.uint8)
for i in range(height):
    for j in range(width-1):
        grayP0 = int(gray[i,j])
        grayP1 = int(gray[i,j+1])
        newP = grayP0 - grayP1 +150
        if newP>255:
            newP = 255
        if newP<0:
            newP =0
        dst[i,j] = newP
cv2.imshow('dst',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()
#%%color
import cv2
import numpy as np
img = cv2.imread('resources/lena.jpg',1)
info = img.shape
height = info[0]
width = info[1]
cv2.imshow('img',img)
dst = np.zeros(img.shape,np.uint8)
#蓝色效果
for i in range(height):
    for j in range(width):
        (b,g,r) = img[i,j]
        b = b*1.8
        g = g*1.5
        if b>255:
            b = 255
        if g>255:
            g = 255
        dst[i,j] = (b,g,r)
cv2.imshow('dst',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()
#%% 油画特效
import cv2
import numpy as np
img = cv2.imread('resources/lena.jpg',1)
info = img.shape
height = info[0]
width = info[1]
cv2.imshow('img',img)
dst = np.zeros((height,width,3),np.uint8)
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
for i in range(4,height-4):
    for j in range(4,width-4):
        array1 = np.zeros(8,np.uint8)
        for m in range(-4,4):
            for n in range(-4,4):
                p1 = int(gray[i+m,j+n]/32)
                array1[p1] = array1[p1] + 1
        currentMax = array1[0]
        l = 0
        for k in range(0,8):
            if currentMax<array1[k]:
                l = k
        #简化 均值
        for m in range(-4,4):
            for n in range(-4,4):
                if gray[i+m,j+n] >= (l*32)  and gray[i+m,j+n]<= (l+1)*32:
                    (b,g,r) = img[i+m,j+n]
        dst[i,j] = (b,g,r)
cv2.imshow('dst',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()

#%% line draw
import cv2
import numpy as np
dst = np.zeros((500,500,3),np.uint8)
#line 参数：图片，起始点，终点，颜色,线条宽度
#绘制三角形
cv2.line(dst,(100,100),(300,300),(0,0,255))
cv2.line(dst,(100,100),(100,300),(0,255,255),5)
cv2.line(dst,(100,300),(300,300),(255,255,255),5,cv2.LINE_AA)
cv2.imshow('dst',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()

#%% rectangle, circle, ellipse, polylines
import cv2
import numpy as np
dst = np.zeros((600,600,3),np.uint8)
#绘制矩形  rectangle参数：图片，左上角，右下角，颜色,是否填充
cv2.rectangle(dst,(50,100),(200,300),(255,0,0),1)
#绘制圆形 circle参数：图片，圆心，半径，颜色,是否填充
cv2.circle(dst,(250,250),(50),(0,255,0),2)
#绘制椭圆 ellipse参数：图片，椭圆圆心，（长轴，短轴），偏转角度，起始角度，终止角度，颜色,是否填充
cv2.ellipse(dst,(300,300),(60,40),45,0,360,(0,0,255),5)
#绘制任意多边形
points = np.array([[150,50],[100,100],[200,270],[450,550],[350,350]],np.int32)
print(points.shape)
points = points.reshape((-1,1,2))
print(points.shape)
cv2.polylines(dst,[points],True,(0,255,255))
cv2.imshow('dst',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()

#%%文字图片识别
import cv2
import numpy as np
img = cv2.imread('resources/lena.jpg',1)
font = cv2.FONT_HERSHEY_COMPLEX
cv2.rectangle(img,(200,100),(500,400),(0,255,0),3)
cv2.putText(img,'this is flower',(100,300),font,1,(200,100,255),2,cv2.LINE_AA)
cv2.imshow('dsst',img)
cv2.waitKey(0)
cv2.destroyAllWindows()

#%%灰度图像直方图处理
import cv2
import numpy as np
import matplotlib.pyplot as plt
img = cv2.imread('resources/lena.jpg',1)
height,width=img.shape[:2]
gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
count = np.zeros(256,np.float)
for i in range(0,height):
    for j in range(0,width):
        index=int(gray[i,j])
        count[index]=count[index]+1
for i in range(0,255):
    count[i] = count[i]/(height+width)
x=np.linspace(0,255,256)
y=count
plt.bar(x,y,0.9,alpha=1,color='b')
plt.show()

#%%彩色图像直方图处理
import cv2
import numpy as np
def ImageHist(image,type):
    color=(255,255,255)
    windowName='Gray'
    if type==31:
        color=(255,0,0)
        windowName='B Hist'
    elif type==32:
        color=(0,255,0)
        windowName='G Hist'
    elif type==33:
        color=(0,0,255)
        windowName='R Hist'
    hist = cv2.calcHist([image],[0],None,[256],[0,255])
    minV,maxV,minL,maxL=cv2.minMaxLoc(hist)
    histImg=np.zeros([256,256,3],np.uint8)
    for h in range(256):
        intenNormal = int(hist[h]*256/maxV)
        cv2.line(histImg,(h,256),(h,256-intenNormal),color)
    cv2.imshow(windowName,histImg)
    return histImg
img=cv2.imread('resources/lena.jpg',1)
channels=cv2.split(img)
for i in range(0,3):
    ImageHist(channels[i], 31+i)
cv2.waitKey(0)
cv2.destroyAllWindows()
#%%直方图均衡化
import numpy as np
import cv2
img = cv2.imread('resources/lena.jpg',1)
cv2.imshow('src',img)
(b,g,r) = cv2.split(img)#通道分解
bH = cv2.equalizeHist(b)
gH = cv2.equalizeHist(g)
rH = cv2.equalizeHist(r)
result = cv2.merge((bH,gH,rH))#通道合成
cv2.imshow('dst',result)
cv2.waitKey(0)
cv2.destroyAllWindows()
#%%亮度增强
import cv2
import numpy as np
img = cv2.imread('resources/lena.jpg',1)
imgInfo = img.shape
height = imgInfo[0]
width = imgInfo[1]
cv2.imshow('src',img)
dst = np.zeros((height,width,3),np.uint8)
for i in range(0,height):
    for j in range(0,width):
        (b,g,r) = img[i,j]
        bb = int(b)+40
        gg = int(g)+40
        rr = int(r)+40
        if bb>255:
            bb = 255
        if gg>255:
            gg = 255
        if rr>255:
            rr = 255
        dst[i,j] = (bb,gg,rr)
cv2.imshow('dst',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()
#%%双边滤波
import cv2
img = cv2.imread('resources/son.jpg',1)
cv2.imshow('src',img)
dst = cv2.bilateralFilter(img,15,35,35)
cv2.imshow('dst',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()
#%%视频分解图像
# 视频分解图片
# 1 load 2 info 3 parse 4 imshow imwrite
import cv2
cap = cv2.VideoCapture("resources/test.mp4")# 获取一个视频打开cap 1 file name
isOpened = cap.isOpened# 判断是否打开‘
print(isOpened)
fps = cap.get(cv2.CAP_PROP_FPS)#帧率
width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))#w h
height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))
print(fps,width,height)
i = 0
while(isOpened):
    if i == 10:
        break
    else:
        i = i+1
    (flag,frame) = cap.read()# 读取每一张 flag:是否读取成功 frame：图片内容
    fileName = 'image'+str(i)+'.jpg'
    print(fileName)
    if flag == True:
        cv2.imwrite(fileName,frame,[cv2.IMWRITE_JPEG_QUALITY,100])
print('end!')

#%%图片合成视频
import cv2
img = cv2.imread('image1.jpg')
imgInfo = img.shape
size = (imgInfo[1],imgInfo[0])
print(size)
fourcc = cv2.VideoWriter_fourcc(*"mp4v")
videoWrite = cv2.VideoWriter('2.mp4',fourcc,5,size)# 写入对象 1 file name
# 2 编码器 3 帧率 4 size
for i in range(1,11):
    fileName = 'image'+str(i)+'.jpg'
    img = cv2.imread(fileName)
    videoWrite.write(img)# 写入方法 1 jpg data
print('end!')

#%% Haar+Adaboost人脸识别
# 1.引入xml文件  2.引入图片  3.灰度处理  4.检测特征（人脸，眼睛） 5.绘制方框（眼睛，脸）
import  cv2
import  numpy as np
# 1.引入xml文件
face_xml = cv2.CascadeClassifier('/anaconda3/envs/tensorflow/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml')
eye_xml = cv2.CascadeClassifier('/anaconda3/envs/tensorflow/share/OpenCV/haarcascades/haarcascade_eye.xml')
#2.引入图片
img = cv2.imread('resources/son.jpg')
cv2.imshow('src',img)
#3.灰度处理
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
#4.检测特征（人脸，眼睛）
#参数1：图片数据 参数2：比例缩放系数 参数3：人脸大小
faces = face_xml.detectMultiScale(gray,1.5,5)
print('face= ',len(faces))
#5.绘制方框（眼睛，脸）
for (x,y,w,h) in faces:
    cv2.rectangle(img,(x,y),(x+w,y+h),(255,0,0),2)
    roi_face = gray[y:y+h,x:x+w]
    roi_color = img[y:y+h,x:x+w]
    # 眼睛识别
    eyes = eye_xml.detectMultiScale(roi_face)
    print('eye = ',len(eyes))
    for (e_x,e_y,e_w,e_h) in eyes:
        cv2.rectangle(roi_color,(e_x,e_y),(e_x+e_w,e_y+e_h),(0,255,0),2)
cv2.imshow('dst',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
#%% face detection based on camera
import cv2
import sys
from PIL import Image
 
def CatchUsbVideo(window_name, camera_idx):
    cv2.namedWindow(window_name)
    
    #视频来源，可以来自一段已存好的视频，也可以直接来自USB摄像头
    cap = cv2.VideoCapture(camera_idx)                
    
    #告诉OpenCV使用人脸识别分类器
    classfier = cv2.CascadeClassifier("/anaconda3/envs/tensorflow/share/OpenCV/haarcascades/haarcascade_lefteye_2splits.xml")
    
    #识别出人脸后要画的边框的颜色，RGB格式
    color = (0, 255, 0)
        
    while cap.isOpened():
        ok, frame = cap.read() #读取一帧数据
        if not ok:            
            break  
 
        #将当前帧转换成灰度图像
        grey = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)                 
        
        #人脸检测，1.2和2分别为图片缩放比例和需要检测的有效点数
        faceRects = classfier.detectMultiScale(grey, scaleFactor = 1.2, minNeighbors = 3, minSize = (32, 32))
        if len(faceRects) > 0:            #大于0则检测到人脸                                   
            for faceRect in faceRects:  #单独框出每一张人脸
                x, y, w, h = faceRect        
                cv2.rectangle(frame, (x - 10, y - 10), (x + w + 10, y + h + 10), color, 2)
                        
        #显示图像
        cv2.imshow(window_name, frame)        
        c = cv2.waitKey(10)
        if c & 0xFF == ord('q'):
            break        
    
    #释放摄像头并销毁所有窗口
    cap.release()
    cv2.destroyAllWindows() 
    
if __name__ == '__main__':
    if len(sys.argv) != 1:
        print("Usage:%s camera_id\r\n" % (sys.argv[0]))
    else:
        CatchUsbVideo("识别人脸区域", 0)











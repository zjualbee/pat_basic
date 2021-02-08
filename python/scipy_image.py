#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Nov 11 17:01:30 2020

@author: caoting
"""

#%% img
from PIL import Image
from scipy.ndimage import filters
from matplotlib import pyplot as plt
import numpy as np

im = np.array(Image.open(u'resources/son.JPG').convert('L'))
im2 = filters.gaussian_filter(im,3)
im3 = filters.gaussian_filter(im,5)

plt.subplot(1,3,1)
plt.axis('off')
plt.imshow(im,cmap='gray')
plt.title('original')

plt.subplot(1,3,2)
plt.axis('off')
plt.imshow(im2,cmap='gray')
plt.title('gaussian(kernel 3)')

plt.subplot(1,3,3)
plt.axis('off')
plt.imshow(im3,cmap='gray')
plt.title('gaussian(kernel 5)')

#%% blur color images
from PIL import Image
from scipy.ndimage import filters
from matplotlib import pyplot as plt
import numpy as np

im = np.array(Image.open(u'resources/son.JPG'))
im2 = np.zeros(im.shape)
im3 = np.zeros(im.shape)
for i in range(3):
    im2[:,:,i] = filters.gaussian_filter(im[:,:,i],3)
    im3[:,:,i] = filters.gaussian_filter(im[:,:,i],5)

im2 = np.uint(im2)
im3 = np.uint(im3)

plt.subplot(1,3,1)
plt.axis('off')
plt.imshow(im)
plt.title('original')

plt.subplot(1,3,2)
plt.axis('off')
plt.imshow(im2)
plt.title('gaussian(kernel 3)')

plt.subplot(1,3,3)
plt.axis('off')
plt.imshow(im3)
plt.title('gaussian(kernel 5)')

#%% sobel filter
im = np.array(Image.open(u'resources/son.JPG').convert('L'))

imx = np.zeros(im.shape)
filters.sobel(im,1,imx)

imy = np.zeros(im.shape)
filters.sobel(im,0,imy)

magnitude = np.sqrt(imx**2+imy**2)


plt.subplot(1,4,1)
plt.axis('off')
plt.imshow(im,cmap='gray')
plt.title('original')

plt.subplot(1,4,2)
plt.axis('off')
plt.imshow(imx,cmap='gray')
plt.title('x')

plt.subplot(1,4,3)
plt.axis('off')
plt.imshow(imy,cmap='gray')
plt.title('y')

plt.subplot(1,4,4)
plt.axis('off')
plt.imshow(magnitude,cmap='gray')
plt.title('x**2+y**2')

#%% gaussian blur
for sigma in [2,5,10,20]: # standard deviation

    im = np.array(Image.open(u'resources/son.JPG').convert('L'))

    imx = np.zeros(im.shape)
    filters.gaussian_filter(im,(sigma,sigma),(0,1),imx)

    imy = np.zeros(im.shape)

    filters.gaussian_filter(im,(sigma,sigma),(1,0),imy)
    magnitude = np.sqrt(imx**2+imy**2)

    plt.figure()
    plt.subplot(1,5,1)
    plt.axis('off')
    plt.imshow(im,cmap='gray')
    plt.title('original')

    plt.subplot(1,5,2)
    plt.axis('off')
    plt.imshow(imx,cmap='gray')
    plt.title('x (%d)'%sigma)

    plt.subplot(1,5,3)
    plt.axis('off')
    plt.imshow(imy,cmap='gray')
    plt.title('y (%d)'%sigma)

    plt.subplot(1,5,4)
    plt.axis('off')
    plt.imshow(magnitude,cmap='gray')
    plt.title('x**2+y**2 (%d)'%sigma)
    
    plt.subplot(1,5,5)
    plt.axis('off')
    plt.imshow(255.0-magnitude,cmap='gray')
    plt.title('magnitude')

    plt.show()
    
#%% morphology
from scipy.ndimage import morphology, measurements
im = np.array(Image.open(u'resources/son.JPG').convert('L'))
im = 1*(im<128)

labels,nbr_object = measurements.label(im)
print('Number of object:',nbr_object)

im_open = morphology.binary_opening(im,np.ones((9,5)),iterations=2)#binary open???

labels_open,nbr_object_open = measurements.label(im_open)
print('Number of object:',nbr_object_open)

im_close = morphology.binary_closing(im,np.ones((9,5)),iterations=2)

labels_close,nbr_object_close = measurements.label(im_close)
print('Number of object:',nbr_object_close)

plt.subplot(1,3,1)
plt.axis('off')
plt.imshow(labels)
plt.title('raw binary')

plt.subplot(1,3,2)
plt.axis('off')
plt.imshow(labels_open)
plt.title('binary open')

plt.subplot(1,3,3)
plt.axis('off')
plt.imshow(labels_close)
plt.title('binary close')

plt.show()

#%% pandas
import numpy as np
import pandas as pd

data1=pd.DataFrame(pd.read_excel('resources/name.xlsx'))


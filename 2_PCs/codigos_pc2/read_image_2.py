import numpy as np
import cv2
from matplotlib import pyplot as plt

img = cv2.imread('messi.jpg',cv2.IMREAD_COLOR)
b,g,r = cv2.split(img)
im2 = cv2.merge([r,g,b])
plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
plt.xticks([]), plt.yticks([]) 
plt.show()

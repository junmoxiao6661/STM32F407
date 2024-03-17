# Hello World Example
#
# Welcome to the OpenMV IDE! Click on the green run arrow button below to run the script!

import sensor, image, time

sensor.reset() # 初始化摄像头
sensor.set_pixformat(sensor.RGB565) # 格式为 RGB565.
sensor.set_framesize(sensor.QQVGA)
sensor.skip_frames(10) # 跳过10帧，使新设置生效
while(True):
    img = sensor.snapshot()         # Take a picture and return the image.
    img.draw_line((20, 30, 40, 50))
    img.draw_line((80, 50, 100, 100), color=(255,0,0))
    img.draw_rectangle((20, 30, 41, 51), color=(255,0,0))
    img.draw_circle(50, 50, 30)
    img.draw_cross(90,60,size=10)
    img.draw_string(10,10, "hello world",color=(0,255,0))

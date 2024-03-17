
import sensor, image, time

threshold = [(87, 75, 14, -13, -101, 121)]                 #暗黄色的阈值

sensor.reset()                                          #初始化传感器
sensor.set_pixformat(sensor.RGB565)                     #传感器色彩
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 2000 )                        #开机跳过一些时间
sensor.set_auto_whitebal(False)                         #关闭白平衡

clock = time.clock()                                    #获取时钟

while(True):
    clock.tick()
    img = sensor.snapshot()                             #拍照
    blob = img.find_blobs(threshold, area_threshold=300, margin=10)
    #寻找对应阈值的色块，阈值小于300像素的色块过滤掉，合并相邻像素在10个像素内的色块
    print(blob)
    if blob:                                            #如果找到了目标颜色
        FH = bytearray([0xb3,0xb4])

        for b in blob:
        #迭代找到的目标颜色区域
            img.draw_cross(b.cx(), b.cy())                  #画十字 cx,cy
#            blob.cx() 返回色块的外框的中心x坐标（int），也可以通过blob[5]来获取。
#            blob.cy() 返回色块的外框的中心y坐标（int），也可以通过blob[6]来获取。
            img.draw_edges(b.min_corners(), color=(0,255,0))#画框

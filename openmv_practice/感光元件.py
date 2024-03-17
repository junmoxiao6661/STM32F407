import sensor
import time
sensor.reset() # 初始化
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(10)
# sensor.set_vflip(True)
clock = time.clock()
while(True):
    clock.tick()
    img=sensor.snapshot()
    # print(clock.fps())
    print(img.size())

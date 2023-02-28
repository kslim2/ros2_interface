#!usr/bin/env python3 

import rclpy 
from rclpy.node import Node 
from sensor_msgs.msg import Image 
from cv_bridge import CvBridge 
import cv2 
import numpy as np 
from learn_interface.msg import ObjectPosition

lower_red = np.array([0, 90, 128])
upper_red = np.array([180, 255, 255])

class ImageSubscriber(Node):

    def __init__(self, name):
        super().__init__(name)
        self.sub = self.create_subscription(Image, "image_raw", 
            self.listener_callback, 10)
        self.pub = self.create_publisher(ObjectPosition, "object_position", 10)
        self.cv_bridge = CvBridge()

        self.objectX = 0
        self.objectY = 0

    def listener_callback(self, data):
        self.get_logger().info("Receiving video frame")
        image = self.cv_bridge.imgmsg_to_cv2(data, "bgr8")
        position = ObjectPosition()
        self.object_detect(image)
        position.x, position.y = int(self.objectX), int(self.objectY)
        self.pub.publish(position)

    def object_detect(self, image):      
        hsv_img = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)        # 图像从BGR颜色模型转换为HSV模型
        mask_red = cv2.inRange(hsv_img, lower_red, upper_red)   # 图像二值化
        contours, hierarchy = cv2.findContours(
            mask_red, cv2.RETR_LIST, cv2.CHAIN_APPROX_NONE)     # 图像中轮廓检测
        for cnt in contours:                                    # 去除一些轮廓面积太小的噪声
            if cnt.shape[0] < 150:
                continue

            (x, y, w, h) = cv2.boundingRect(cnt)                # 得到苹果所在轮廓的左上角xy像素坐标及轮廓范围的宽和高

            cv2.drawContours(image, [cnt], -1, (0, 255, 0), 2)  # 将苹果的轮廓勾勒出来
            cv2.circle(image, (int(x+w/2), int(y+h/2)), 5,      # 将苹果的图像中心点画出来
                       (0, 255, 0), -1)   

            self.objectX = int(x+w/2)
            self.objectY = int(y+h/2)

        cv2.imshow("object", image)                             # 使用OpenCV显示处理后的图像效果
        cv2.waitKey(50)

def main(args=None):
    rclpy.init(args=args)
    node = ImageSubscriber("topic_webcam_sub")

    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
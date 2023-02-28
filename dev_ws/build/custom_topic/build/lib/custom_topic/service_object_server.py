#!usr/bin/env python3 

import rclpy 
from rclpy.node import Node
from std_msgs.msg import String 
from learn_interface.msg import ObjectPosition 

class SubscriberNode(Node):

    def __init__(self, name):
        super().__init__(name)
        self.sub = self.create_subscription(ObjectPosition, 
            "object_position", self.listener_callback, 10)
        
    def listener_callback(self, msg):                                         # 创建回调函数，执行收到话题消息后对数据的处理
        self.get_logger().info('Target Position: "(%d, %d)"' % (msg.x, msg.y))

def main(args=None):
    rclpy.init(args=args)
    node = SubscriberNode("interface_position_sub")
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
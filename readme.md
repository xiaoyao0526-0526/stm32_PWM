# 硬件方面
- stm32f103zet6
- 步进电机：28BYJ_48
- 舵机：SG90

# 软件方面
- stm32 Cube Mx
- Keli 5
##  pwm_28BYJ_48
- IN1 -> PA5
- IN2 -> PA7
- IN3 -> PB15
- IN4 -> PA12


![28BYJ-48链接示意图](/image/pwm_28BYJ_48.jpg "28BYJ-48链接示意图")
## pwm_SG90
- PWM信号线 -> PE9


![SG90线的解释](/image/SG90.png "SG90SG90线的解释")

图片来源: [ST中文论坛文章](https://shequ.stmicroelectronics.cn/thread-636354-1-1.html)

![SG90链接示意图](/image/pwm_SG90.jpg "SG90链接示意图")
# [自己的项目链接](https://github.com/xiaoyao0526-0526/stm32_PWM)
# 参考的链接
- B站乐在程上: [[STM32]超简单的开发方法-实例篇（步进电机控制）](https://www.bilibili.com/video/BV1oN411o7zj/?spm_id_from=333.337.search-card.all.click&vd_source=49dc982c99a453d8b92cdf9df498199d)
（值得注意的是要勾选上这个）
![勾这个](https://img-blog.csdnimg.cn/18c8fb26132146cbbb64c2b85b7e15af.png)

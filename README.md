# rm_version-study
视觉组的任务

1.1 使用imread(“文件名”)，读取一张彩色图片。了解CV处理单个像素的方法，然后将每个像素的rgb
值同时改为(r+g+b)/3，即将3个通道的值统一为相同值，改为3个通道的平均值。然后显示图片，
观察图片显示的特点，可多测试几张图像。

1.2 在练习1的基础上，在处理每个像素的时候加个一个条件。声明一个uchar变量uchar threshold
=100，如果 average>threshold 则average=255，否则为0。然后再把average值赋值给像素的3
个通道，并通过 imshow 函数观察结果，然后修改threshold 值，观察输出结果。

1.3 读取一张图片，存入 mat型变量 srcMat，然后声明两个mat型数据，命名为deepMat和
shallowMat。分别用深复制和浅复制把 srcMat的内容赋值给两个mat。然后用练习2中的方法修改
srcMat的值。观察deepMat和 shallowMat的变化。

1.4 通道分离，利用图像在色彩上的一些特点，可以在图像处理中进行一些巧妙的处理。通过opencv
将下图的rgb 三个通道分离，并观察每个通道的图像。

1.5 摄像头调用。
要求：完整的逻辑关系。
提示：判断是否打开摄像头；判断是否读取图片输出 FPS；输出图片

1.6 基本绘图功能
要求：（1）画圆 (2）画线段、矩形框

1.7. 实现 Gamma 矫正并思考它可以用在什么场景，题目使用图片如下

2.1 HSV 通道的二值化
利用不同的物体在 HSV 色彩空间上的不同色域，实现目标像素的提取。主要利用 inRange 函数

2.2 对上图先进行二值化，然后分别进行腐蚀、膨胀、开运算和闭运算。
2.3 对上图先进行二值化，然后进行连通域标记，并绘制出每个连通域的 外接四边形（Bounding
Box），并使用 cout << 将硬币的个数输出至状态栏
2.4 根据上一题所学知识，对下列图片进行自动计数。
2.5 读取摄像头图像，并对摄像头图像进行中值滤波、均值滤波、高斯滤波
2.6 实现 Canny 算子（注意原理，以及（建议）了解一下对canny算子的进一步改进方法）
3 请对以下原图进行处理，得到检测对应检测结果， 同时，将以下 ROI 区域使用单独新的窗口
显示出来同时思考，怎么在得到当前算法的基础上进行优化。

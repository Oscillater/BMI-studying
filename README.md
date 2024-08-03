Document my journey of learning about brain-computer interfaces.

## Week 1

### Theoretical knowledge 

- Basic idea about IP / TCP / UDP
- How computers display images
- Basic idea in BMI

### Hands-on Practice

#### Task 1: TCP / IP "Hello World"

- Use C++ and TCP protocol to send a packet containing a string locally and receive and display the string.

#### Task 2: Read and Draw

- Use Qt to read data from an array and draw lines based on the data.

### Advance Task

#### Read and Draw Forward

- Draw 8 lines
- Know time to draw a graph & image refresh rate & Moving line (Some docs I find below)
- [QT中Qwt、QChart、QCustomPlot使用与性能对比-CSDN博客](https://blog.csdn.net/xieliru/article/details/134831552)
  - [Plot a Graph with Real Time Data | Qt Forum](https://forum.qt.io/topic/28708/plot-a-graph-with-real-time-data/13)
  - [Qwt User's Guide: Qwt - Qt Widgets for Technical Applications (sourceforge.io)](https://qwt.sourceforge.io/)
  - [Qt Plotting Widget QCustomPlot - Realtime Data Demo](https://www.qcustomplot.com/index.php/demos/realtimedatademo)

## Week 2

### Theoretical knowledge 

- Process
- How memory pools/ FIFOs are shared and interlocked
- Increase the effective frame rate and reduce CPU usage

### Hands-on Practice

#### Task 1: Moving Line

- Try to draw a refresh line, the refresh rate is controlled at about 30 Hz

<video controls>
  <source src="./week2/Moving_Line.mp4" type="video/mp4">
  Your browser does not support the video tag.
</video>

#### Task 2: Two threads

- Two threads, one constantly reading and writing files, and the other constantly drawing, can have a TCP/IP signal with each other

####  Task 3 : Many Lines

- Increase the number of lines drawn.

# TODO: 

- Improve performance: Use the QCustomPlot class, as well as OpenGL and other performance-enhancing plug-ins.
- Change the UI : make it more user-friendly.
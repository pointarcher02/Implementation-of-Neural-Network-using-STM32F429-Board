#Objective

The main objective of the present work is to design and implement a light type of neural
network for the STM32F429 microcontroller board. It involves the effective development
of a neural network model, which will work under resource-constraint typical problems
for an embedded system, e.g., limited memory and computation power.

#Dataset

We have used the BUPA Liver disorder dataset , which is a lightweight dataset with
fewer features. The BUPA liver disorder dataset, commonly referred to as the BUPA
dataset, is a well-known dataset used in the field of medical machine learning to study
liver disorders. The number of features are 6 while the number of labels are 2 (which is
liver disorder or not) while the number of samples are 345.

#Analysis

We further analyze the results and get to know that for one particular set of
input X_train[0], we are getting output as 0.707610 from the C program while for
another set of input X_train[1] we get output as 0.136 while the labels for both of them
are different. Here we observe that for threshold= 0.5 we are getting different labels.
Therefore when output is above 0.5 it is denoting 0 label while for below 0.5 it is
denoting label 1.

![image](https://github.com/pointarcher02/Implementation-of-Neural-Network-using-STM32F429-Board/assets/120496303/3824d50b-ab1d-49b4-8351-e71c8a8d8faa)


##STM32 Board implementation

Step 1: We initially load the keil micro vision software and paste our C code in the C
file.

Step 2: We define the GPIO LED functions where we use these LED configurations in
order to turn on one LED when the output value calculated is greater than 0.5 and turn
on another LED when the output is below 0.5.
We have defined a variable named scope which is initially initialized to 0 in the
global scope while in order to view it on the watch window.
We assign the value of scope to 2 when we turn on the first LED while the value of 4
when we turn on the second LED.

![image](https://github.com/pointarcher02/Implementation-of-Neural-Network-using-STM32F429-Board/assets/120496303/f0435e6d-f64d-4f5e-b0b4-2d3eebfb6587)

Step 3: We first translated and builded the program to notice that there were 0 errors
and 0 warnings in the code compiled.

![image](https://github.com/pointarcher02/Implementation-of-Neural-Network-using-STM32F429-Board/assets/120496303/4292a6e5-94be-49eb-b2b5-dd5fa3036fa2)

Step 4: Now we load the STM32F429 Board and set the mode to STLink debugger, in
order to implement the logic on the board while also to see the value of the scope
getting changed.

![image](https://github.com/pointarcher02/Implementation-of-Neural-Network-using-STM32F429-Board/assets/120496303/bb356969-e1f2-493b-b8a3-882e4becd092)

When we start the debug session we notice that the value of scope which was
initially 0 gets updated to 2 and our LED blinks on the STM board.
The picture below shows the LED has been turned which indicates that scope is 2
and the output is greater than 0.5.

![image](https://github.com/pointarcher02/Implementation-of-Neural-Network-using-STM32F429-Board/assets/120496303/7dcf747b-782e-439e-8eea-c1d66628c7f7)

While similarly turns on the different LED and scope becomes 4 for output less
than 0.5.
Therefore our Neural Network has been successfully implemented on the
STM32429 board as desired by the problem statement.


#Conclusion
The neural network deployed on the STM32F429 board effectively processed the
biochemical data to predict liver disorders, showing that even low-power
microcontrollers can host intelligent algorithms capable of performing meaningful
real-time analytics. The project highlighted several key advantages of edge computing
in medical applications, including reduced latency, decreased dependency on
continuous internet connectivity, and enhanced data security by localizing data
processing.

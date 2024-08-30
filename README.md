# ProyectMJD3
Proyect for competition WRO 2024 Future Engineers

2.	Introduction
   
We are MJD3, we are young people passionate about robotics and what it entails for the future, our goal as a group is to discover new methodologies in order to solve different problems related to this in the WRO Future Engineers competition.

3. Who we are:

María José Guirola          -    Group Leader, Software and Hardware Developer.

Diego Marcelo Rivera        -                 Software Developer.

Diego Alejandro Rodríguez   -                In charge of the engineering journal.

Diego Alejandro Cartagena   -              Team Coach.


5.	Proyect Status:
   
Our group engaged the steps of the project with deliberate planning, including reviewing previous competitions. We collected detailed information from each competition, analyzing what skills and knowledge were assessed and what our achievements and learnings were. This informed our group's understanding of the known challenges we would experience in our current competition, as it aligned with which strategies/approaches we would build upon. Once we compiled all the information, we methodically reviewed the competency documentation, laying the groundwork to have everything understood in advance. Especially the rules, technical specifications and evaluation criteria. This positioned our team to have a firmer backing to make decisions, particularly with respect to components selection. We conducted a rigorous evaluation of our components available to us on the market, considering feasibility, price and compatibility tests on such components with our project. From this, we selected the best components that suited our needs and budget. Once we identified the best components we had to initiate our design process. Our group utilized a digital design capability to establish a model of the electronic circuit, with one of the best advantages of digital design was being able to visualize, anticipate and adapt possible challenges before developing our flying robot in physical reality. The development began physically our robot with the chassis. During the build we worked through many design changes with respect to the steering system due to space, strength, and speed of making the change; and later issues with regards to, voltage and current, false connection, frying Arduinos etc. By working through adjustments, many times constructive change through trying to improve the form and integration of our components to our power supply. Simultaneously we started with programming modules. We worked on our code with limited hardware, the electronic design tool, and while we helped achieve some stability.

The construction of our chassis was an unprecedented endeavor that we faced with diligence and determination. From the very beginning, we ensured that the wheels would slip not at all as the vehicle moved - this was critical to the vehicle's stability and steering performance. We did a number of tests on this subject, used a variety of materials and joined pieces in different ways, each trial led to a very efficient traction system. We also worked hard to ensure that the action system worked both precise and accurately; hence the vehicle's ability to perform complex movements was both forceful and defensible. We could not have developed a level of control and precision without a million tests. Yet the iterations laid the groundwork for a world of confidence to approach project challenges with creativity moving forward.

4.1. Enery Supply Distribution:

We find out that our components occupied the following amperage and voltage:

NAME--------AMOUNT-------AMPERAGE-----TOTAl AMPERAGE--------VOLTAGE

Dc Motor------1---------------900mA------------900mA------------------------5V

Servomotor----1-----------------350mA-----------350mA-------------------5V

MPU6050------1------------------4mA-------------4mA-------------------3.3V up to 5V

HC-SR04-------3------------------15mA------------60mA--------------------5V

Pixy 2.1---------1-----------------140mA-------------140mA-----------------5V

Arduino Uno---1------------------100mA-----------100mA------------------5V

LN298----------1------------------2A----------------2A----------------------5V

TOTAL	3654 mA	

The batteries we decided would meet our needs would be the 18650, these have between 3.7V and 4.2V and between 8800mAH and 9800mAH. So we decided to place our entire circuit in parallel except for the batteries since the battery holder was in series, thus giving us each battery holder a supply of 8V and 8800mAh maximum.
We used two battery holders with each battery holder distributing power to the following components:

BATTERY HOLDER A---------------------BATTERY HOLDER B

   HC-SR04----------------------------------- DC Motor
   
   MPU6050-----------------------------------LN298
   
  Arduino UNO-------------------------------Power Button
  
Sensor Shield v5.0--------------------------SG90 Servomotor

  Pixy Cam 2.1	
  
4015 Voltage Regulator.	


The 4015 voltage regulator is also used to prevent damage to the Arduino due to a higher voltage than it can withstand.

To begin, we must know what materials we have decided to use, and they are the following:

Material List-------------------Amount

HC-SR04--------------------------1

MPU6050-------------------------1

Arduino UNO---------------------1

Sensor Shield---------------------1

Pixy Cam 2.1----------------------1

DC Motor-------------------------1

LN298-----------------------------1

Power Button---------------------1

SG90 Servo Motor----------------1

4015 Voltage Regulator----------1

18650 Batteries-------------------4

Plastic rims------------------------4

Gears------------------------------2

Metal Axles------------------------2

Switch------------------------------2

Chasis with  3D printing -----------1

Rubber Bands----------------------4

Male-Female Jumpers--------------1

Female-Female Jumpers------------23

Male-Male Jumpers----------------13

Battery Holder-----------------------2

In general we use the rubber bands to generate “grip” on the tires, since without this they slide on the track. The servo motor is to give direction to the car, the servo is anchored with a 3.5cm bolt to a piece printed with PLA that has connected the tires, thus performing the rotation of the tires. The motor has in its axis a gear of 1cm diameter, and the gear of the wheels axis measures 3cm allowing its rotation in reverse direction.

4.2.1.   Open Challenge

In this challenge we made use of the MPU6050 and the HC-SR04.
The flow diagram is attached:

4.2.2. Obstacle Challenge


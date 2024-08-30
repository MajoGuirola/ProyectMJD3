# ProyectMJD3
Proyect for competition WRO 2024 Future Engineers

1.	Introduction
   
We are MJD3, we are young people passionate about robotics and what it entails for the future, our goal as a group is to discover new methodologies in order to solve different problems related to this in the WRO Future Engineers competition.

2. Who we are:

María José Guirola          -    Group Leader, Software and Hardware Developer.

Diego Marcelo Rivera        -                 Software Developer.

Diego Alejandro Rodríguez   -                In charge of the engineering journal.

Diego Alejandro Cartagena   -              Team Coach.


3.	Proyect Status:

Our group engaged the steps of the project with deliberate planning, including reviewing previous competitions. We collected detailed information from each competition, analyzing what skills and knowledge were assessed and what our achievements and learnings were. This informed our group's understanding of the known challenges we would experience in our current competition, as it aligned with which strategies/approaches we would build upon. Once we compiled all the information, we methodically reviewed the competency documentation, laying the groundwork to have everything understood in advance. Especially the rules, technical specifications and evaluation criteria. This positioned our team to have a firmer backing to make decisions, particularly with respect to components selection. We conducted a rigorous evaluation of our components available to us on the market, considering feasibility, price and compatibility tests on such components with our project. From this, we selected the best components that suited our needs and budget. Once we identified the best components we had to initiate our design process. Our group utilized a digital design capability to establish a model of the electronic circuit, with one of the best advantages of digital design was being able to visualize, anticipate and adapt possible challenges before developing our flying robot in physical reality. The development began physically our robot with the chassis. During the build we worked through many design changes with respect to the steering system due to space, strength, and speed of making the change; and later issues with regards to, voltage and current, false connection, frying Arduinos etc. By working through adjustments, many times constructive change through trying to improve the form and integration of our components to our power supply. Simultaneously we started with programming modules. We worked on our code with limited hardware, the electronic design tool, and while we helped achieve some stability.

The construction of our chassis was an unprecedented endeavor that we faced with diligence and determination. From the very beginning, we ensured that the wheels would slip not at all as the vehicle moved - this was critical to the vehicle's stability and steering performance. We did a number of tests on this subject, used a variety of materials and joined pieces in different ways, each trial led to a very efficient traction system. We also worked hard to ensure that the action system worked both precise and accurately; hence the vehicle's ability to perform complex movements was both forceful and defensible. We could not have developed a level of control and precision without a million tests. Yet the iterations laid the groundwork for a world of confidence to approach project challenges with creativity moving forward.

4.1. Enery Supply Distribution:

We find out that our components occupied the following amperage and voltage:

![Captura de pantalla 2024-08-30 014126](https://github.com/user-attachments/assets/ad2aafde-81b8-4563-809a-2da347385790)

The batteries we decided would meet our needs would be the 18650, these have between 3.7V and 4.2V and between 8800mAH and 9800mAH. So we decided to place our entire circuit in parallel except for the batteries since the battery holder was in series, thus giving us each battery holder a supply of 8V and 8800mAh maximum.
We used two battery holders with each battery holder distributing power to the following components:

![Captura de pantalla 2024-08-30 014020](https://github.com/user-attachments/assets/06ce46da-a4e2-4c6d-b010-13bf664e6c03) 

The 4015 voltage regulator is also used to prevent damage to the Arduino due to a higher voltage than it can withstand.

To begin, we must know what materials we have decided to use, and they are the following:

![Captura de pantalla 2024-08-30 013600](https://github.com/user-attachments/assets/e8408c10-bd52-4527-adab-700ac866823c)

In general we use the rubber bands to generate “grip” on the tires, since without this they slide on the track. The servo motor is to give direction to the car, the servo is anchored with a 3.5cm bolt to a piece printed with PLA that has connected the tires, thus performing the rotation of the tires. The motor has in its axis a gear of 3cm diameter, and the gear of the wheels axis measures 3cm allowing its rotation in reverse direction.

![OIP](https://github.com/user-attachments/assets/c1f1bbc2-9089-4ce9-bd6b-141e616ac50a)

4.2.1.   Open Challenge


Our car uses three distance sensors to decide its direction of turn depending on the value shown by these sensors, so it either makes a turn or not. If none of the sensors shows that it is more than 100 cm away, the car continues straight. If one of the sensors shows that it is too close to a wall, it turns away from the nearest wall to avoid hitting it. If a sensor shows more than 100 cm away from a wall, we decide that the car turns towards the side of the space; that is, if the space is on the left side, it turns left, and the same with the right side. Each time it turns, one is added to a variable that counts the turns. This variable is divided to calculate the turns the car has made. When the turns reach 3, the car stops.

![¿Cuál es tu idea principal](https://github.com/user-attachments/assets/dd7be74f-94aa-486a-be79-e1b90ecafb7a)

4.2.2. Obstacle Challenge


The Arduino first detects which object has been detected, whether green or red. When it has that value, it classifies it into 3 positions: if it is in the center, on the left, or on the right. If it is the green rectangle that has to turn left and the rectangle is on the right, the car will advance. If the green rectangle is in its center, it will maneuver to avoid it and return to its position. If the rectangle is on its left side or is very close, the car will go back or start to turn to the left side or it will also go back until the object is centered to do the maneuver to avoid it. The distance sensor reads if there is no wall to its left or right and turns to the side where there is no wall and adds it to the turn variable. At the end of the 3 turns, it will start to look for the parking space. When it detects the parking space, it will look for the best way to enter.

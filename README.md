# HW12
 
 I liked working with the potentiometer and button in class because of their tactility so I decided to use them for the password machine. I decided to have the sequence be

 1) turn potentiometer all the way to the left
 2) press button
 3) turn potentiometer all the way to the right
 4) press button 

 I used a red LED as a default "locked" indicator and a green to indicate a success. First I set up the Arduino and individually tested to make sure all the different components were functioning (and also did tweezer surgery on the breadboard when a wire broke). Once I had done that I borrowed from the in-class code to set up the password parameters. At first I was trying to set up the code so that there were four inputs steps (potentiometer left, button, potentiometer right, button) but then I realized that actually I could do if/else: if the potentiometer value was 0 when the button was clicked, that indicates that the steps have been followed correctly. 

![Circuit diagram](./circuit.png)
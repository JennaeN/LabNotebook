LAB 4 - C -"AN LCD DEVICE DRIVER"
_________________________________________________________________________

GRADING

Item                                                                                         	Grade                              	         Points 	Out of 	Date 	Due

Prelab   On-Time:------------------------------- 0 ---- Check Minus ---- Check ---- Check Plus            	 	5 		              BOC L25

Required Functionality 	On-Time------------- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days 		          35 		              COB L26

B Functionality 	On-Time --------------------- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days           		10              		COB L26

A Functionality 	On-Time --------------------- Late: 1Day ---- 2Days ---- 3Days ---- 4+Days           		10               		COB L26

Use of Git / Github 	On-Time:----------------- 0 ---- Check Minus ---- Check ---- Check Plus          		10		              BOC L27

Lab Notebook 	On-Time:------------------------ 0 ---- Check Minus ---- Check ---- Check Plus -----
                                                                          Late: 1Day ---- 2Days ---- 3Days ---- 4+Days  	  	       30            		COB L27
                                                                          
Total                                                                                                                                                 			100 	
_________________________________________________________________________

OBJECTIVE/PURPOPOSE: In this lab, you'll use C to write a device driver for the LCD you used in Lab 3. You'll be expected to write clean, maintainable, modular code that is committed regularly to Git.

The Basic Idea
    Ever wonder how you plug a mouse into your computer and it "just works"? That's due in large part to software called a device driver. Device drivers are low-level software that interface directly with hardware. In this lab, you'll write a device driver for the LCD in the Geek box.
    Unlike Lab 3, you will not be given any code. The code from Lab 3 will prove useful - but you'll have to port it to C!

Required Functionality
    Create an LCD device driver using the C programming language.
    Scroll the message "ECE382 is my favorite class!" across the top line of the LCD. Scroll a message of your choice across the bottom line.
    You will want to interface with this LCD again (in Lab 5). I expect you to create a reusable LCD library! Design a good API in advance - you want this library to be easy to work with in the future.
    You must place your code under version control on git and push your repo to Github.

B Functionality
    Create an additional library to deal with buttons. Allow the user to select between three different bottom line messages depending on which button they press.
    B Functionality Program operation:

    Screen 1
        Top Line: Message?
        Bottom Line: Press123
    Screen 2
        Top Line (scrolling): ECE382 is my favorite class!
        Bottom Line (scrolling): Chosen message

A Functionality
    Create an additional library for calibrating your clock to different frequencies.
    You think your libraries for working with buttons, clock calibration, and the LCD could prove useful to other programmers. You've decided to release them on Github as open source.ou'll need a separate git repository for each of your libraries. You'll need to create a README for each covering their API and usage.
    You must show me each repo successfully hosted on Github to receive credit.
 
    Design the API for your LCD library.
    Consider how you'll port different assembly language constructs in the Lab 3 template code to C.
    Consider how you'll create software delays in C.
    
_________________________________________________________________________

How I'll port different assembly language constructs in the Lab 3 template code to C:
*bis is |= (sets bits)
*bic is &=~ (clears bits)
->In this way, checking to see if a button has been pushed can be converted into C. Other functions may be converted in a similary way.

How I'll create software delays in C: Software delays can be implemented by using __delay_cycles(num_of_cycles). This will delay by the specified number of clock cycles.
I can use this method in place of my LCD Delay methods.

<<<<<<< HEAD
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

PRELIMINARY DESIGN

How I'll port different assembly language constructs in the Lab 3 template code to C:
*bis is |= (sets bits)
*bic is &=~ (clears bits)
->In this way, checking to see if a button has been pushed can be converted into C. Other functions may be converted in a similary way.

How I'll create software delays in C: Software delays can be implemented by using __delay_cycles(num_of_cycles). This will delay by the specified number of clock cycles.
I can use this method in place of my LCD Delay methods.

Overall, I will reference my code from Lab03, and code that is on the website shifting from assembly to 
C language.

_________________________________________________________________________

TESTING AND RESULTS

I began testing once I had transferred all useful code from Lab03 into C language. 
The first problem I encountered was initializing my screen. To fix this, I ensured that my 
wires were wired correctly, and then made sure that I did not have unnccessary code.
Error was found in the LCD_write_4 portion of my code. To fix this problem, I deleted my first 
line of code which initialized sendByte. Since sendByte is sent in, it should not be set to any
other value.

The next step was writing a character to the screen. 

Once I could write a character, I wrote a string. Initially my code would not write both strings. 
At this point, I created cursorToLineOne and cursorToLineTwo. After making these functions, the 
string would appear on each line.

Many errors were encountered during scrolling functionality. 
Originally, my string was just blocks. I changed my code to use writeDataByte, and tried using many
different counters to make it work properly. Eventually, I had a jumpy string appearing. 
In the end, I used two pointers - one for the current character and one for the beginning character of
the string. Both of these referenced the beginning of the string once they reached the end of the string.

_________________________________________________________________________

RESULTS/ CONCLUSION

In this lab, I learned how to convert from assembly language to a high level language. High
level languages make programming easier to read, and condense the code. Also, using multiple
files to implement one program makes the program more understandable. 

Scrolling functionality was the most difficult portion of this lab. To make my program scroll, 
I needed to use pointers. One pointer would point at the current character being printed to the screen,
while the other pointer pointed at the beginning character of the string. By using these pointers and 
referencing them to the beginning of the string of text, I was able to implement scrolling functionality.

In future labs, I will commit more often and with more descriptive statements. Every once in a while
problems are ran into while commiting. 

_________________________________________________________________________

DOCUMENTATION

In this lab I received help from C2C Ryan Hub. C2C Hub helped me with the buttons and scrolling
functionality.

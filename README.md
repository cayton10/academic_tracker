# Academic Tracker Using C++

This project was a requirement for my intro to programming course in Fall of '19. I've learned a lot since then, so I'm coming back from time to time to refactor some of the code base and optimize the application. I haven't been lucky enough to find a job this summer, so I'll work on this until I find something better to do. :)

## Issues:

#### Infinite Loop on Menu

When I originally submitted the program in December of '19 I had some minimal user quali in place. If users entered ints outside the accepted choice range, an appropriate message would display and the user could try again. However, I was unfamiliar with this little guy:
```C++
cin.fail()
```
Which I uncovered during my time learning data structures. So when unqualified information like a string is entered, we're no longer entering infinite loops. 

#### User Qualification on Course Entry

Something I need to update is qualification on user entry. 
I.E.:
<ul>
    <li>* Limit course alpha to 4 char</li>
    <li>* ~No letters allowed in course number~</li>
    <li>* I'm sure I can find something else to keep busy.</li>
    <li>* ~Case insensitivity~</li>
</ul>
##### 5.21.2020

Fixed case insensitive qualifying input for mutliple functions.
Functions updated:
<ul>
    <li>* Add Courses (alpha designation)</li>
    <li>* Search By Alpha (alpha designation (obviously))</li>
    <li>* Search By Grade (Letter grade)</li>
</ul>


#### 5.22.2020

Updated writing location for ofstream. Navigates to "Grades" directory and writes file of user's choosing. Added: 
```C++
//Prepend string with directory
    userFile.insert(0, "Grades/");
```
to prepend user input filename with the directory I created to store files. Also added this functionality to the 'load file' function. 


Qualified user input for courseNum of course struct member. Pulled a check_number function from the interwebs and incorporated into the Add Course function. If a user enters any characters other than numbers, the program sarcastically calls the user a genius and prompts to re-enter the course number. 

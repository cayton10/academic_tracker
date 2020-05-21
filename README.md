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
    * Limit course alpha to 4 char
    * No letters allowed in course number
    * I'm sure I can find something else to keep busy. 
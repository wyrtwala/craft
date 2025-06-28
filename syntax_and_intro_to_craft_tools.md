basic craft syntax

comments are placed inside two sets of double colons ***::comment::*** and may be single line or multiple line.  

anything inside ***parentheses()*** is considered a single unit.  

functions names are placed inside square braces **[]**.  
  + if written before **[run]** and outside of any other function declaration,it is taken to be a declaration, anywhere else is an implementation
  + every function recieves two and only two variables 
  + every function returns one and only one value

**[paste]** *:filepath* *:protocol*(local default, craft, git, ssh, wget)   
  + file is included in it's entirity at command location  
  + file is copied only until encountering **[run]**

**[run]**  
  + starts process at current line  

**[stack]** _:name_ _:array count_  
  + create stack variable  
  + all are 64 bit with no type and initiate as 0 bits  
  + stack arrays cannot be resized  

**[heap]** *:name* *:beginning array count*  
  + create heap variable
  + all heap variables are arrays, if no array count declared default is 1
  + all variables are 64 bit with no type and initiate as 0 bits

**[select]** *:variable* *:offset* (starting at zero)

**[craft]** *:variable/value* *:translation*

**[move]** *:variable* *:value*

**[if]** *:condition* *:action*

**[jump]** *:mark* *:condition*

**[mark]** *:name* :??

**[add]** *:variable/value* *:variable/value*

**[sub]** *:variable/value* *:variable/value*

**[mul]** *:variable/value* *:variable/value*

**[div]** *:variable/value* *:variable/value*

**[mod]** *:variable/value* *:variable/value*

**[=/!=/</<=/>/>=]** *:variable/value* *:variable/value*  
+ returns `/0{64}/` on false, `/0{63}1{1}/` on true

**[free]** *:variable* *:after how many lines will the variable be freed*

**[point]** *:variable* *:offset* 
  + dereference variable at given offset

**[address]** *:variable* *:offset*
  + returns variable address at given offset (for arrays)

**[resize]** *:variable* *:newsize*

**[regex]** *:variable/value* *:regex to compare*

**square braces[]** themselves can be placed around any value that contains spaces to force it to be considered a single entity

you can see an example [here](https://github.com/wyrtwala/craft/edit/main/example.anvl)

-------------------------------------------------------------------------------------------------------------------------------  
  
# Premise  
  
-------------------------------------------------------------------------------------------------------------------------------  
  
```
A computer can do only five things:                 Recieve Data; Store Data; Compare Data; Transform Data; Send Data.  
A kernel side program can do only five things:      Recieve Data; Store Data; Compare Data; Transform Data; Send Data.  
A user side program can do only five things:        Recieve Data; Store Data; Compare Data; Transform Data; Send Data.  
  
  
A computer can recieve data in only one way:                      Ports.  
A computer can send data in only one way:                         Ports.  
A computer can only Store Data internally in three places:        Storage Devices; Memory Devices; CPU.  

  
A program has only two sets of Data:                              Compiled Data; Runtime Data.
A program sorts data into two types:                              Stack; Heap.
```
   
-------------------------------------------------------------------------------------------------------------------------------  
  
# Argument   
  
-------------------------------------------------------------------------------------------------------------------------------  
    
   
## I. Send & Recieve Data:    
  
### A. Send & Recieve Data:  
```
port:recieve port count buffer
port:send    buffer count port
```
### C. Open & Close Ports:  
```
port:open:file          filepath
port:open:socket:server protocol address port
port:open:socket:client protocol address port
port:open:device        device
port:close              port
```
## II. Store Data:    
  
### A. Hardcoded program data:  
```
data:unit   name unit_size signed_integer
data:string name unit_size string_of_integers
```
(Note: unit sizes are taken in bytes and can be set to 1/2/4/8)  
  
### B. Runtime Data:  
  
#### 1. Units:  
```
symbol:global:unit name size signed_integer
symbol:local:unit  name size signed_integer
```
(Note: any size 8 unit may be used as a pointer)  
  
#### 2. Mapped Memory:  
  
##### a. Small Maps:  
```
map:open        pionter size
map:close       address size
map:resize      address size
```
##### b. Page Aligned Maps:  
```
map:page:new    pointer count
map:page:close  address count
map:page:resize address count
``` 
#### 3. CPU Registers:  
  
##### a. Flexible Registers:  
```
$1
$2
$3
$4
$5
$6
```
##### b. Rigid Registers:  
```
#1
#2
#3
#4
#5
#6
```
## III. Compare Data:  

```  
cmp    section section
bound  section section
 ```

## IV. Transform Data:  
  
Data can be changed in two ways:  
  1. From 1 to 0.  
  2. From 0 to 1.  
We though, will use several abstractions to make it so that making millions of those changes doesn't take 17,000.000,000 lines of code to write.  
  
A data storage may be set to a specific value with:  
```
set section size value
```
(Note: a section may be a memory addess, a symbol name or a register)  
(Note: each section, other than registers, may take a size other than 8 bytes, and is formatted as address:size)  
(Note: a value may be a specific value, a memory address, a symbol or a register)  
  
Data be changed in place with arithmetic commands:    
```
add section section
sub section section
mul section section
div section section
mod section section
inc section
dec section
neg section
xor section section/value
eor section section/value
and section section/value
not section
shr section section/value
shl section section/value
```
  
## V. Execute Data:  

Computers execute instructions linearly: one after another in sequence.   
So in order to have flexibility in the way our code runs we add in what   
is commonly called "control-flow", which has several flavors.  
  
### A. Marks
  
Special units can be created that, instead of a human set value, contain their own memory address:
```
symbol:global:mark name passed_values...
symbol:local:mark  name passed_values...
```
First six passed values are passed in registers; anything after that is passed as a size 8 stack value.  
  
### B. Jumps & Detours

From anywhere you can move to somewhere else in the code by jumping to a mark:
```
jump address
```
Or detour with:  
```
execute name 
```
Every detour must have the return command to come back to the original route:  
```
return:with value
```
After a detour a section may be set to the returned value with:  
```
return:into section
```
Jumps may not use passed values and do not return.  
  
### C. Conditional Jumps & Detours  
  
You may at some point want to change the course of your code depending information  
you don't have before runtime; in that case you may use conditional jumps and detours.  

```
cmp section section
jump:smaller     address
jump:greater     address
jump:equal       address
jump:not:smaller address
jump:not:greater address
jump:not:equal   address
cmp section section
execute:smaller     address passed_values...
execute:greater     address passed_values...
execute:equal       address passed_values...
execute:not:smaller address passed_values...
execute:not:greater address passed_values...
execute:not:equal   address passed_values...
```
  
Basics done, if you're still interested go to [The Craft Dictionary](https://github.com/wyrtwala/craft/blob/main/src/dictionary.txt)  
  
  

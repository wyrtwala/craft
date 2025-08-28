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
  - Any time your computer reads from a hard-drive, writes to your screen,
     accepts information from the internet, etc.; that information is read
     or written through ports.
```
port:recieve port   buffer
port:send    buffer port
```
### C. Open & Close Ports:  
  - Your program can open a port by asking the kernel to give it a port to
    some device or resource, which will be a number that your program and
    the kernel use to let each other know which device or resource is being
    written to or read from.
```
port:open:file          filepath
port:open:socket:server protocol address port accept_count
port:open:socket:client protocol address port
port:open:device        device
port:close              port
```
## II. Store Data:    
  
### A. Hardcoded data:  
  - All data is accessed by using an address: either a port address or a
    memory address.
  - Many times addresses are given names to make accessing them easier.
  - When the computer starts to execute your program it actually puts the
    program itself in memory, on the heap side. If you want you can write
    data into your program's code itself that can be accessed when it is
    run.  
    We will call this data: Hardcoded Data.
```
hc:unit   name signed_integer
hc:string name list_of_signed_integers
```
  - Note: It is not possible to change the length of hc:string, only read
    or write to it.
  
### B. Runtime Data:  
  - Some data is not known before executing your program; this includes any
    data recieved from ports.   
    We will call this data: Runtime Data.
    
#### 1. Units:  
  - These can be split up into Global and Local units. Global units can be
    accessed from anywhere, but Local units can only be accessed within the
    subroutine (we will talk about these later) where they are placed.
  - Note: hc:unit and hc:string are both global.
```
rtu:global name signed_integer
rtu:local  name signed_integer
```
  - There is a special type of unit called a mark. A mark contains it's own
    address instead of some other value. They are used to navigate the code
    itself. We will talk about these later, but for now, this is how to make
    them:
```
mark:global name
mark:local  name
mark:anonymous
```
  - Note: Global and Local marks work just like other Global and Local runtime
    units.
  
#### 2. Mapped Memory:  
 - Some times you will need more than just a single unit at runtime, for
   example: reading an entire file, or downloading a photograph from the
   internet. In cases like these where you need more space you can ask the
   kernel for extra memory. The kernel will give you (if it is available) the
   memory size you asked for and also the address where the memory is located.  
   We will call this process Memory Mapping.

##### a. Small Maps:  
  - You can open very specifically sized maps with:
```
map:new         unit size
map:close       address size
map:resize      address size
```
##### b. Page Aligned Maps:  
  - Or you can open memory along page lines (if your interested this is actually
    a very interesting thing to look further into) you can use:
```
map:page:new    unit count
map:page:close  address count
map:page:resize address count
```
  - Note: When you ask for a new map you must give a unit name because unit's
    value will be set to the address for the mapped memory.
    
#### 3. CPU Registers:  
  - The CPU is what transforms data in a computer. It has registers which is
    what it uses to grab data to be transformed. So if you want to transform
    data you can put that data inside of a register. There are two kinds of
    registers that we will specify here. There are more registers, but these
    are the ones we will give easy access to.
    
##### a. Flexible Registers:  
  - These registers are the ones that will be passed to subroutines (again,
    we will be seeing these soon).
```
$1
$2
$3
$4
$5
$6
```
##### b. Rigid Registers:  
  - Ridig Registers are ones that the computer saves to the stack (also
    something we will look at in just a moment) before calling a subroutine
    and then sets back after the subroutine returns.
```
#1
#2
#3
#4
#5
#6
```
  - Note: because of how these registers work, we usually use the Flexible
    Registers inside of subroutines and Rigid Registers everywhere else.

#### 4. The Stack:
  - Runtime Units, Mapped Memory and the Program itself are held inside the
    heap; but every program has another, darker side: the Stack.
  - The Stack sits literaly at the oposite end of the program and works differently
    than the heap. The memory on the Heap is accessed by address; memory on
    the Stack is accessed by distance. Specifically, distance from what is
    called the Stack Pointer.
  - Values may be placed on the Stack or removed from it, but you can only place them
    on the top of the stack, not in the middle, not at the bottom. You can only remove
    the value at the top of the stack as well. We will see a bit more about the stack
    when we look at subroutines.
```
stack:place   value
stack:remove  value
stack:access  count
```
  - Note: count referse to how far down the stack the value you want was set.

## III. Compare Data:  
  - Often in order to make decisions about what route to take through your code
    you need to compare data. This can be done in two ways.
  - cmp compares two values and bound will check a value with two other values to
    see if it is in between them.
```  
cmp    value value
bound  value value:value
 ```

## IV. Transform Data:  
  
  - Data can be changed in two ways:  
    1. From 1 to 0.  
    2. From 0 to 1.  
  - We though, will use several abstractions to make it so that making
    millions of those changes doesn't take 17,000.000,000,000 lines of
    code to write.  
  
  - You can set a data in the Heap or a Register to a specific value using:  
```
set address/register value
```  
  - Note: from here on out we will call the combination Heap/Register: sections
  
  - Sections may be transformed in place: 
```
add sections
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

  - Computers execute instructions linearly: one after another in sequence.   
    So in order to have flexibility in the way our code runs we add in what   
    is commonly called "control-flow" (yes, we are finally going to talk
    about subroutines).  
  
### A. Jumps

  - From anywhere in your code you can move to any Global Mark by jumping:
```
jump address
```
  - You can also jump based on a cmp:
```
cmp section section
jump:smaller     address
jump:greater     address
jump:equal       address
jump:not:smaller address
jump:not:greater address
jump:not:equal   address
```
### B. Subroutines:
  - Sometimes you have a task that needs to be completed many times in
    the same program. This can be done with Subroutines. These are a set
    of commands strung together under a common name.
  - Jumps just jump to a new place in your program, but subroutines jump
    do a bunch of stuff and then come back to where they started.
  - When you execute a subroutine the Rigid Registers get all get placed
    on the Stack automatically and taken off again when you return to your
    original place. That is why we use the Flexible Registers to pass values
    to the subroutine.
  - There are only 6 Flexible Registers though, so if you need to pass more
    values, they are placed on the stack to be used when needed.
  - Also the stack changes when you execute a subroutine. You will only be able
    to access the values specifically placed on the stack for use by the subroutine
    everything else will be out of reach until you return from the subroutine.

```
subroutine:mark   name number_of_passed_values
subroutine:return returned_value
execute           subroutine_name passed_values
returninto        section
>>>               subroutine_name passed_values 
```
  - Note: subroutine:mark is literally just a Global Mark where we also make
    note of how many passed values the subroutine will need. You could legitimately
    just use a mark:global if you wanted to remember how many values to pass.
  - Note: returninto placed the returned value from the last subroutine into a section.
  - Note: >> is a special syntax that makes it easy to string subroutines together by
    placing the return value from the last subroutine directly into the first Flexible
    Register and calling the next subroutine with its values from $2 on.

  - Subroutines can also be executed conditionally with cmp:
```
cmp section section
execute:smaller     address passed_values...
execute:greater     address passed_values...
execute:equal       address passed_values...
execute:not:smaller address passed_values...
execute:not:greater address passed_values...
execute:not:equal   address passed_values...
```

### C. Loops:
  - Loops (repeating commands) are made by combining marks and jumps.
    Many times it is easier to use mark:anonymous. To jump to mark:anonymous
    use:
```
anon:next
anon:last
```
  - Note: these are used as the address in jmp.

## VI. Extras:
  - Just a few little things for those who think they know what they're doing.
    
### A. System Calls:
  - Talk directly to the kernel.
```
sys:call  syscall_number args... //in order of course
```

### B. Execute Foreign Code:
```
external:execute filepath
```













-------------------------------------------------------------------------------------------------------------------------------

# I. Premise

-------------------------------------------------------------------------------------------------------------------------------

```
A computer can do only five things:                 Recieve Data; Store Data; Compare Data; Transform Data; Send Data.  
A kernel side program can do only five things:      Recieve Data; Store Data; Compare Data; Transform Data; Send Data.  
A user side program can do only five things:        Recieve Data; Store Data; Compare Data; Transform Data; Send Data.  
  
  
A computer can recieve data in only one way:                      Ports.  
A computer can send data in only one way:                         Ports.  
A computer can only Store Data internally in three places:        Storage Devices; Memory Devices; CPU Registers.  

  
A program has only two sets of Data:                              Compiled Data; Runtime Data.   
A computer transforms data with only one unit:                    CPU.
```
  
-------------------------------------------------------------------------------------------------------------------------------

# II. Argument  

-------------------------------------------------------------------------------------------------------------------------------
  
 
## A. Data  

#### 1. Send and Recieve Data

-------------------------------------------------------------------------------------------------------------------------------

```
Data may be recieved with the command:  
>> port:recieve port count buffer  
And sent with:
>> port:send    buffer count port  
(Note: ">>" only signals that the line is code and does not form part of the code itself.)  

  
A Port may be obtained with:  
>> port:open:file          filepath  
>> port:open:socket:server protocol address port  
>> port:open:socket:client protocol address port  
>> port:open:device        device  
Any port may be closed with:  
>> port:close              port  


Examples:
>> data:recieve 0 64 reg:1
```

#### 2. Store Data
-------------------------------------------------------------------------------------------------------------------------------

```
Pre compile data may be stored as:
>> data:unit name unit_size signed_integer  
>> data:string name unit_size string_of_integers
(Note: unit sizes are taken in bytes and can be set to 1/2/4/8)  

Runtime data is stored in three ways:
    Units:
>> symbol:global:unit name size signed_integer
>> symbol:local:unit  name size signed_integer
(Note: any size 8 unit may be used as a pointer)
    Mapped Memory:
Memory may be obtained (and removed) for a pointer with:
>> map:open        pionter size  
>> map:close       address size  
>> map:resize      address size  
You also have the option of:
>> map:page:new    pointer count  
>> map:page:close  address count  
>> map:page:resize address count  
    And CPU Registers:  
>> reg:1  
>> reg:2  
>> reg:3  
>> reg:4  
>> reg:5  
>> reg:6  
There are also special registers:
>> reg:a  
>> reg:b
>> reg:c
>> reg:x  
>> reg:y  
>> reg:z
(Note: registers must be set. We will see how to do that later)
```

#### 4. Compare Data

-------------------------------------------------------------------------------------------------------------------------------

```
### TODO
xor
or
and
not
cmp
test
bound

```

#### 4. Transform Data

-------------------------------------------------------------------------------------------------------------------------------

```
Data can be changed in two ways:
  From 1 to 0.
  From 0 to 1.
We though, will use several abstractions to make it so that making millions of those changes doesn't take 17,000.000,000 lines of code to write.


A data storage may be set to a specific value with:
>> set address size value
(Note: an address may be a memory addess, a symbol name or a register)
(Note: a value may be a specific value, a memory address, a symbol or a register) 

A D.S. may be changed in place with arithmetic commands:
>> add address:size value:size
>> sub address:size value:size
>> mul address:size value:size
>> div address:size value:size
>> mod address:size value:size
And with:
>> add:into addres:size value:size value:size
>> sub:into addres:size value:size value:size
>> mul:into addres:size value:size value:size
>> div:into addres:size value:size value:size
>> mod:into addres:size value:size value:size
(Note: these act on two values and put the result into adress)
(Note: size may be omitted when 8)

There are also the commands:
>> inc address/value:size
>> dec address/value:size
>> neg address/value:size
>> xoraddress/value:size address/value:size
>> eoraddress/value:size address/value:size
>> andaddress/value:size address/value:size
>> not address/value:size
>> shr address/value:size address/value:size
>> shl address/value:size address/value:size
And:
>> inc:into addres:size address/value:size
>> dec:into addres:size address/value:size
>> neg:into addres:size address/value:size
>> xor:into addres:size address/value:size address/value:size
>> eor:into addres:size address/value:size address/value:size
>> and:into addres:size address/value:size address/value:size
>> not:into addres:size address/value:size
>> shr:into addres:size address/value:size address/value:size
>> shl:into addres:size address/value:size address/value:size
```


#### 5. Execute Data

-------------------------------------------------------------------------------------------------------------------------------

subroutines
execute memory
exec 
system
system call




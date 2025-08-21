-------------------------------------------------------------------------------------------------------------------------------

# Premise

-------------------------------------------------------------------------------------------------------------------------------
```
A computer can do only three things:                   Recieve Data; Transform Data; Send Data.  
A kernel side program can do only three things:        Recieve Data; Transform Data; Send Data.  
A user side program can do only three thing:           Recieve Data; Transform Data; Send Data.  
  
  
A computer can recieve data in only one way:           Ports.  
A computer can send data in only one way:              Ports.  
A computer can only transform Data in two places:      Memory; Registers.  

  
A program has only two sets of Data:                   Hardcoded Data; Runtime Data.  
A program stores data in only two places:              Stack Data; Heap Data.  
A computer transforms data with only one unit:         CPU.
```
  
-------------------------------------------------------------------------------------------------------------------------------

# Argument  

-------------------------------------------------------------------------------------------------------------------------------
  
```
  
### Data

Data may be recieved with the command:  
>> port:recieve port count buffer
To send data use:
>> port:send buffer count port
(Note: port may be for file/network/device and is described in more detail below)
(Note: ">>" only signals that the line is code and does not form part of the code itself.)

Port may be obtained with:
>> port:open:file          file
>> port:open:socket:server protocol address port
>> port:open:socket:client protocol address port
>> port:open:device        device 
(Note: any of the above commands may be used with :close: instead of open.)

example for stdin
>> data:recieve 0 64

Only hardcoded data may be stored on database with:
>> data:unit name signed_integer
>> data:string name string of integers

Runtime data is stored in two ways:
>> symbol:unit name size singed_integer
(symbols are programmer made names for numbers)
>> symbol:pointer name
(pointers must point to some place in memory

Memory may be obtained (and removed) for a pointer with:
>> map:open       pointer size
>> map:close      pointer size
>> map:resize     pointer size
You also have the option of:
>> map:page:new   pointer count
>> map:page:close pointer count

Data may also be held in cpu registers:
>> reg:a
>> reg:b
>> reg:1
>> reg:2
>> reg:3
>> reg:4
>> reg:5
>> reg:6
>> reg:7
>> reg:8

### Transformations

```




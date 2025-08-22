-------------------------------------------------------------------------------------------------------------------------------

# Premise

-------------------------------------------------------------------------------------------------------------------------------

```
A computer can do only four things:                               Recieve Data; Store Data; Transform Data; Send Data.  
A kernel side program can do only four things:                    Recieve Data; Store Data; Transform Data; Send Data.  
A user side program can do only four things:                      Recieve Data; Store Data; Transform Data; Send Data.  
  
  
A computer can recieve data in only one way:                      Ports.  
A computer can send data in only one way:                         Ports.  
A computer can only Store Data internally in three places:        Storage Devices; Memory Devices; CPU Registers.  

  
A program has only two sets of Data:                              Compiled Data; Runtime Data.   
A computer transforms data with only one unit:                    CPU.
```
  
-------------------------------------------------------------------------------------------------------------------------------

# Argument  

-------------------------------------------------------------------------------------------------------------------------------
  
 
## Data  

#### Send and Recieve Data

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

#### Store Data
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

#### Transform Data

-------------------------------------------------------------------------------------------------------------------------------





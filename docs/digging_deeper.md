## I. Regersters:

### A. Accessing Partial Registers:
  - Registers contain 8 bytes/64 bits of data. Cool, but sometimes we only
    want to use 4 bytes or 2 bytes, for example: when you read from a port
    it only gives you 4 bytes at a time. What do we do then?
    Well there is a way to access smaller portions of our registers:
```
$1:8
$1:4
$1:2
$1:1
```
  - The first number is the register to access and the second number tells
    the program how many bytes to grab from the register.

### B. Casting Registers
  - If you need to fill in a register that you only set to a 4 byte or smaller
    value, you can use:
```
reg:fill register original_size
````
  - For the opposite:
```
reg:rend register new size
```

### C. Registers for Numbers with Decimal Points:
  - Computers don't have any idea what numeric precision or decimal points are,
    and therefore are horrible at calculations involving them. For this reason
    I consider them a bad idea in general in programming, but for the sake of
    completeness I will put a way to access the registeres that are specially
    made for dealing with this type of numbers.
```
xmm:0
xmm:1
xmm:2
xmm:3
xmm:4
xmm:5
xmm:6
xmm:7
xmm:8
xmm:9
xmm:10
xmm:11
xmm:12
xmm:13
xmm:14
xmm:15
```

II. Formatting
  - Formatting usually referse to manipulating the way data shows up on your
    screen or other port. For example, do you want to print the letter a,
    the decimal number 97, the hexadecimal number 64 or binary 1100001? Which
    to your computer are all exactly the same thing.
  - So we have a function that turns a value into the kind of ascii format you
    want to print.
```
print:format value format port
```
  - Note: format can be ascii, decimal, hex, oct or binary

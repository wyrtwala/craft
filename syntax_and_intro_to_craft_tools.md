# basic craft syntax

comments are placed inside two sets of double colons $\color{#B0B0B0}{::comment::}$ and may be single line or multiple line.  

anything inside $\color{#B0B0B0}{parentheses()}$ is considered a single unit.  

functions names are placed inside square braces $\color{#87CEEB}{[]}$.  
  + if written before $\color{#87CEEB}{[run]}$ and outside of any other function declaration,it is taken to be a declaration, anywhere else is an implementation
  + every function recieves two and only two variables 
  + every function returns one and only one value

$\color{#87CEEB}{[paste]}$ $\color{#E2CA76}{:filepath}$ $\color{#EBA487}{:protocol}$ $\color{#B0B0B0}{(local, craft, git, ssh, wget)}$  
  + file is included in it's entirity at command location  
  + file is copied only until encountering $\color{#87CEEB}{[run]}$


$\color{#87CEEB}{[mark]}$ $\color{#E2CA76}{:name}$ $\color{#EBA487}{:count}$ $\color{#B0B0B0}{(maximum-times-mark-can-be-reached/0=infinite)}$

$\color{#87CEEB}{[mark]}$ $\color{#E2CA76}{[run]}$ $\color{EBA487}{0}$
  + starts process at current line  

$\color{#87CEEB}{[stack]}$ $\color{#E2CA76}{:name}$ $\color{#EBA487}{:array-count}$  
  + create stack variable  
  + all are 64 bit with no type and initiate as 0 bits  
  + stack arrays cannot be resized  

$\color{#87CEEB}{[heap]}$ $\color{#E2CA76}{:name}$ $\color{#EBA487}{:initial-array-count}$  
  + create heap variable
  + all heap variables are arrays, if no array count declared default is 1
  + all variables are 64 bit with no type and initiate as 0 bits

$\color{#87CEEB}{[follow]}$ $\color{#E2CA76}{:variable}$ $\color{#EBA487}{:offset}$ $\color{#B0B0B0}{(starting at zero)}$

$\color{#87CEEB}{[craft]}$ $\color{#E2CA76}{:variable/value}$ $\color{#EBA487}{:translation}$
  + \>(oct, dec, hex, ascii, utf8)
  + (oct, dec, hex, ascii, utf8)>

$\color{#87CEEB}{[move]}$ $\color{#E2CA76}{:variable}$ $\color{#EBA487}{:value}$

$\color{#87CEEB}{[if]}$ $\color{#E2CA76}{:condition}$ $\color{#EBA487}{:action}$

$\color{#87CEEB}{[jump]}$ $\color{#E2CA76}{:mark}$ $\color{#EBA487}{:condition}$

$\color{#87CEEB}{[add]}$ $\color{#E2CA76}{:variable/value}$ $\color{#EBA487}{:variable/value}$

$\color{#87CEEB}{[sub]}$ $\color{#E2CA76}{:variable/value}$ $\color{#EBA487}{:variable/value}$

$\color{#87CEEB}{[mul]}$ $\color{#E2CA76}{:variable/value}$ $\color{#EBA487}{:variable/value}$

$\color{#87CEEB}{[div]}$ $\color{#E2CA76}{:variable/value}$ $\color{#EBA487}{:variable/value}$

$\color{#87CEEB}{[mod]}$ $\color{#E2CA76}{:variable/value}$ $\color{#EBA487}{:variable/value}$

$\color{#87CEEB}{[=/!=/</<=/>/>=]}$ $\color{#E2CA76}{:variable/value}$ $\color{#EBA487}{:variable/value}$  
+ returns `/0{64}/` on false, `/0{63}1{1}/` on true

$\color{#87CEEB}{[free]}$ $\color{#E2CA76}{:variable}$ $\color{#EBA487}{:after-how-many-lines-will-the-variable-be-freed}$

$\color{#87CEEB}{[point]}$ $\color{#E2CA76}{:variable}$ $\color{#EBA487}{:offset}$ 
  + dereference variable at given offset

$\color{#87CEEB}{[address]}$ $\color{#E2CA76}{:variable}$ $\color{#EBA487}{:offset}$
  + returns variable address at given offset (for arrays)

$\color{#87CEEB}{[resize]}$ $\color{#E2CA76}{:variable}$ $\color{#EBA487}{:newsize}$

$\color{#87CEEB}{[regex]}$ $\color{#E2CA76}{:variable/value}$ $\color{#EBA487}{:regex-to-compare}$

$\color{#87CEEB}{[system-call]}$ $\color{#E2CA76}{:system-call}$ $\color{#EBA487}{:[argument-string]}$

$\color{#87CEEB}{[read]}$ $\color{#E2CA76}{:variable}$ $\color{#EBA487}{:where-from}$

$\color{#87CEEB}{[write]}$ $\color{#E2CA76}{:variable}$ $\color{#EBA487}{:where-to}$

$\color{#87CEEB}{[return]}$ $\color{#E2CA76}{:variable/value}$ $\color{#EBA487}{:(return-to-mark/0)}$

$\color{#87CEEB}{[error]}$ $\color{#E2CA76}{:description/value}$ $\color{#EBA487}{:(panic\log)}$



$\color{#87CEEB}{square braces[]}$ themselves can be placed around any value that contains spaces to consider it a single entity


you can see an example [here](https://github.com/wyrtwala/craft/edit/main/example.anvl)

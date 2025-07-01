::standard craft library, shipped with craft::  
$\color{#87CEEB}{[paste]}$ $\color{#E2CA76}{tools}$ $\color{#EBA487}{craft}$  


::all variables initialize automatically as all zeros::  
$\color{#87CEEB}{[stack]}$ $\color{#E2CA76}{[stack-single-value]}$ $\color{#EBA487}{1}$  
$\color{#87CEEB}{[stack]}$ $\color{#E2CA76}{[stack-array]}$ $\color{#EBA487}{100}$  
$\color{#87CEEB}{[heap]}$ $\color{#E2CA76}{[heap-single-value]}$ $\color{#EBA487}{1}$  
$\color{#87CEEB}{[heap]}$ $\color{#E2CA76}{[heap-array]}$ $\color{#EBA487}{1000}$   
  
  
$\color{#87CEEB}{[free]}$ $\color{#E2CA76}{[heap-array]}$ $\color{#EBA487}{0}$


::initialize::  
$\color{#87CEEB}{[move]}$ $\color{#E2CA76}{[stack-single-value]}$ $\color{#EBA487}{(}$  $\color{#87CEEB}{[craft]}$ $\color{#E2CA76}{9999}$ $\color{#EBA487}{dec>}$ $\color{#EBA487}{)}$  
  
::or::  
$\color{#87CEEB}{[move]}$ $\color{#E2CA76}{[stack-single-value]}$ $\color{#EBA487}{(}$   
$\color{#87CEEB}{[craft]}$ $\color{#E2CA76}{9999}$ $\color{#EBA487}{dec>}$  
$\color{#EBA487}{)}$  
::newlines are not taken into account, nor is any white space between the command and the parentheses.  
so the indentation is completely up to you::

::declare a function::  
$\color{#87CEEB}{[test-function]}$ $\color{#E2CA76}{[argument-one]}$ $\color{#EBA487}{arg2}$  
$\color{#87CEEB}{[move]}$ $\color{#E2CA76}{[stack-single-value]}$ $\color{#EBA487}{[argument-one]}$  
  
$\color{#87CEEB}{[move]}$ $\color{#E2CA76}{(}$
$\color{#87CEEB}{[follow]}$ $\color{#E2CA76}{[heap-array]}$ $\color{#EBA487}{7}$
$\color{#EBA487}{)}$  
$\color{#EBA487}{(}$
$\color{#87CEEB}{[craft]}$ $\color{#E2CA76}{9999}$ $\color{#EBA487}{dec>}$
$\color{#EBA487}{)}$
  
$\color{#87CEEB}{[add]}$ $\color{#E2CA76}{[stack-single-value]}$ $\color{#EBA487}{(}$  
$\color{#87CEEB}{[follow]}$ $\color{#E2CA76}{[heap-array]}$ $\color{#EBA487}{7}$  
$\color{#EBA487}{)}$  
  
$\color{#87CEEB}{[write]}$ $\color{#E2CA76}{arg2}$ $\color{#EBA487}{stdout}$  
$\color{#87CEEB}{[return]}$ $\color{#E2CA76}{[stack single value]}$ $\color{#EBA487}{:0}$  
$\color{#87CEEB}{[test function]}$  


 












$\color{#87CEEB}{[mark]}$ $\color{#33DB98}{[run]}$ $\color{#EBA487}{0}$  



$\color{#87CEEB}{[stack]}$ $\color{#E2CA76}{counter}$ $\color{#EBA487}{0}$  
$\color{#87CEEB}{[mark]}$ $\color{#E2CA76}{[example-if]}$ $\color{#EBA487}{0}$  
$\color{#87CEEB}{[write]}$ $\color{#E2CA76}{counter}$ $\color{#EBA487}{stdout}$  
$\color{#87CEEB}{[jump]}$ $\color{#E2CA76}{(}$  
$\color{#87CEEB}{<}$ $\color{#E2CA76}{counter}$ $\color{#EBA487}{(}$  
$\color{#87CEEB}{[craft]}$ $\color{#E2CA76}{0}$ $\color{#EBA487}{dec>}$  
$\color{#EBA487}{)}$ $\color{#E2CA76}{)}$ $\color{#EBA487}{[example-if]}$  










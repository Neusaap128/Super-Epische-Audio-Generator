- - -

Sampling Rate counter example

$f_s$ = 44.000Khz
$T_s$ = 1/f = 22.72µs = 22727.27ns

Prescaler bus = /1
Prescaler timer = /1 

Timer Clock $f_{clk}$ = 170Mhz
Timer period $T_{clk}$ = 5.88ns

clockstrikes = $\frac{T_s}{T_{clk}} = \frac{f_{clk}}{T_s}$ = 3864



--- Will's notes ---

CLK settings
200MHZ
APB1 pre /4
APB2 pre /2
=> timer 1 clock = 100MHz

calculation
100MHz => periode van 10ns
elke 500ms
500ms / 10ns = 50 000 000
50 000 000 => count value

48MHz => 21ns
na 5sec
5000 / 21ns = 238 095 238

Prescaler (ni nodig as u waarde in die variable past)
in 1 seconde 100 000 000 pulses
in 1 seconde      10 000 pulses    ( / 10000 ) = prescaler

autoreload aanzette hangt af van applicatie
couter mode => down
prescaler 0
counter period  = 50000 - 1 (0 is ook een waarde)
(zorgen dat in een 32bit register past)

turn NVIC on in timer menu en system core tab

SYS timebase source timer 1

code
HAL_TIM_Base_Start_IT (vergeet IT ni !!!)

if (htim->Instance == TIM2) {
     //Plaats uw code hier
}
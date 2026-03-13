---
header-includes: |
  \usepackage{float}
  \makeatletter
  \def\fps@figure{H}
  \makeatother
  \usepackage[section]{placeins}
---

# Simulation 3

James Ryan, ECE448 Power Electronics, Spring 2026

# q1 - halfwave rectifier

![Halfwave rectifier with no envelope
detector](media/halfwave_nosmooth/circuit_and_peaks.png)

![Current output for Halfwave rect. w no envelope 
detector](media/halfwave_nosmooth/currents.png)


$\text{Conversion Efficiency}=\frac{P_{DC}}{P_{AC}}$, where $P_{DC}=I_{dc}^2 
\cdot R_L$ and $P_{AC} = I_{rms}^2 \cdot R_L$

![DC Conversion Efficiency Calculation](media/halfwave_nosmooth/dceff.jpeg)

![Halfwave rectifier with an envelope
detector](media/halfwave_smooth/circuit_and_output.png)

# q2 - fullwave rectifier

## Silicon diodes

Even though it wasn't explicitly necessary, I had some issues getting the sim
right with a non-isolated input, so I included an isolating transformer.

![Fullwave rectifier with no envelope
detector](media/fullwave_nosmooth/circuit_and_output.png)

![Fullwave rectifier with an envelope
detector](media/fullwave_smooth/circuit_and_output.png)

## Schottky diodes

The primary advantage of schottky diodes comes from their low forward voltage
and fast switch speed. Because we are at a high peak voltage and relatively low
frequency, I don't anticipate that much difference between the two.

![Fullwave rectifier with an envelope
detector](media/fullwave_schottky_smooth/circuit_and_output.png)

It should be noted that Schottky diodes tend to have worse reverse blocking
capabilities than typical silicon diodes. According to the 1N5817 datasheet,
these devices can block up to 14 volts (rms). So I think these would explode in
real life.

Changing the source voltage to be a little lower, around 1V, and the
frequency to be much larger, around 100kHz, we may see some more change

![Prime Schottky environment: low amplitude, high frequency
signal. Left is the silicon diode testbench, right is schottky result. Note the
much faster rise from our schottky 
setup!](media/fullwave_schottky_smooth/schottky_comparison.png)

For the current analysis, I got rid of the isolation transformer since it caused
weird results (e.g. every even harmonic disappeared?)

![Fullwave schottky FFT of current](media/fullwave_schottky_smooth/fft.png)

From LTSpice's log: $THD=43.687625%$

# q3 - voltage doubler

![Transient curve for our voltage doubler test bench. From time `0->250ms` we
are operating as a typical rectifier, but from time `250->500ms`, 
the `miswitch` closes and we operate as a voltage 
doubler.](media/voltage_doubler/circuit_and_output.png)

# ec

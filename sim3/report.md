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

# ec - full-bridge line-frequency controlled rectifier

A line-frequency controlled rectifier follows a typical full or half-bridge
structure, but instead of using diodes to passively block any negative current,
we use thyristors.

![Full-bridge Line-Frequency controlled rectifier
circuit](media/lcc_demo/circuit.png)

This configuration is similar to our full-bridge rectifier, but with one
difference: we trigger our thyristors to permit current flow at a specific phase
angle relative to our AC waveform; this trigger point is defined by `alpha`.

At a high level, this lets us vary our output DC voltage, given a constant DC
current load, and we can produce an output waveform which varies from the
expected full bridge output (where the negative cycles flip polarity) to an
inverted output (where the positive cycles flip polarity). This can let us
achieve a bucked (and/or inverted) DC output, relative to the input waveform.

Considering we have a constant DC current output, after we trigger a thyristor,
it will continue to conduct. Once we send the alternate trigger, we form a lower
impedance path for the other set of thyristors, allowing them to take over
conducting, and the former set will turn off.

On our schematic, we define `alpha` as a phase offset, determining the phase
angle to send the trigger relative to the input source. Thyristors `U1` and `U4`
trigger together (rectifying the positive cycle); 
`U2` and `U3` trigger half a period after them (rectifying the negative cycle).
`alpha` ranges from 0 to 180 degrees; setting `alpha` beyond 90 will provide a
negative average voltage (ie, we are sourcing energy, not delivering it). Below
are some phases of interest.

Its important to note some harmonics as a result of the thyristor switching we
do. This is to be expected with the large discontinuities we see on the output
(adjusting our rise and fall times on the triggers can remedy this somewhat)

![`alpha` is 0. Passive rectifier emulation](media/lcc_demo/alpha_0.png)

![`alpha` is 20](media/lcc_demo/alpha_20.png)

![`alpha` is 60](media/lcc_demo/alpha_60.png)

![`alpha` is 90](media/lcc_demo/alpha_90.png)

![`alpha` is 120. note the negative average voltage](media/lcc_demo/alpha_120.png)

![`alpha` is almost 180](media/lcc_demo/alpha_179.png)

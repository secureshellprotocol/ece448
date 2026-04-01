---
header-includes: |
  \usepackage{float}
  \makeatletter
  \def\fps@figure{H}
  \makeatother
  \usepackage[section]{placeins}
---

# Simulation 4

James Ryan, ECE448 Power Electronics, Spring 2026

# q1 - async buck converter

## a

$D = \frac{t_{on}}{t_{on}+t_{off}} = \frac{7}{10}$

Let $T = 4.4 \micro s$, so $t_{on} = 0.7 \cdot 4.4 \micro s = 3.08 \micro s$,
and $t_{off} = T - t_{on} = 1.32 \micro s$.

We assume our switching device has a slew rate of $100ns$, a typical rise / fall
figure for the LM555 timer.

![media/async_buck/transients_full.png]
(Buck Converter working to steady state at our specified duty cycle, $D$)

![media/async_buck/transients_waves.png]
(Close-up on our waveforms)

Note that our voltage ripple maintains about a $10mV$ peak to peak swing, it's
steady enough to be considered a roughly $14.57 V$ DC output.

## b

Changing `R2`, our load resistor, from $5 \Omega$ to $20 \Omega$ caused our DC
center to raise to around $14.838 V$ at the output, and our current to drop and
be centered around $0.73 A$.

![media/async_buck/transients_waves_20ohm.png]
(Close-up on our waveforms, with a raised load)

Theres a greater power load which is demanded by the larger resistor. Our duty
cycle is partly determining our power efficiency, and with the larger
resistance, we start demanding less current. So, to maintain the ratio, our
output DC rises, which we observe here. This idea is sort of reflected in the
switch utilization chart, where we can expect some $\frac{P_o}{P_T}$ given the
$D$.

# q2 - async buck boost converter

## a

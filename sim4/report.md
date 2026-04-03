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

Let $T = 4.4 \mu s$, so $t_{on} = 0.7 \cdot 4.4 \mu s = 3.08 \mu s$,
and $t_{off} = T - t_{on} = 1.32 \mu s$.

We assume our switching device has a slew rate of $100ns$, a typical rise / fall
figure for the LM555 timer.

![Buck Converter working to steady state at our specified duty cycle, $D$](media/async_buck/transients_full.png)

![Close-up on our waveforms](media/async_buck/transients_waves.png)

Note that our voltage ripple maintains about a $10mV$ peak to peak swing, it's
steady enough to be considered a roughly $14.57 V$ DC output.

## b

Changing `R2`, our load resistor, from $5 \Omega$ to $20 \Omega$ caused our DC
center to raise to around $14.838 V$ at the output, and our current to drop and
be centered around $0.73 A$.

![Close-up on our waveforms, with a raised load](media/async_buck/transients_waves_20ohm.png)

Theres a greater power load which is demanded by the larger resistor. Our duty
cycle is partly determining our power efficiency, and with the larger
resistance, we start demanding less current. So, to maintain the ratio, our
output DC rises, which we observe here. This idea is sort of reflected in the
switch utilization chart, where we can expect some $\frac{P_o}{P_T}$ given the
$D$.

# q2 - async buck boost converter

## a

$D = \frac{t_{on}}{t_{on}+t_{off}} = \frac{4}{10}$

Let $T = 8 \mu s$, so $t_{on} = 0.4 \cdot 8 \mu s = 3.2 \mu s$,
and $t_{off} = T - t_{on} = 4.8 \mu s$.

We assume our switching device has a slew rate of $100ns$, a typical rise / fall
figure for the LM555 timer.

![Buck-Boost Converter working to steady state at our specified duty cycle, $D$](
media/async_buckboost/transients_full.png)

![Close-up on our waveforms](
media/async_buckboost/transients_waves.png)

Note the reference inversion! The bottom node, our positive output terminal, is
allowed to float and shift as the circuit reaches steady state. So, in sim, we
hold the 'top' of the resistor at a fixed ground to get an interpretable output.

![The textbook covers this, our $V_d$ input has an inverted polarity relative to
our output $V_o$. The technical reason is due to the current direction, where
our load (in this example) always sees the current come from the
bottom-up.](media/async_buckboost/reference_shenanigans_reason.png)

![This is reflected in the sim, where our constant input's level will shift
around as our output reaches steady state (eg, our 'input' node at steady state
rises to actually be the input level PLUS its bucked output level. This has some
interesting implications for our previous stage, if it weren't a constant ideal
voltage source)](media/async_buckboost/reference_shenanigans.png)

## b

It's bucking, since our duty cycle, $D$ is $\lt 50%$. 

At lower voltages, this is impacted by the voltage drop across the diode `D1`,
however, we can demonstrate this behavior by boosting our input DC voltage to be
significantly larger than this loss; we set $V_{in} = 30V$ and observe a
$V_{out} = 20V$.

According to the [datasheet]()

$\frac{D}{1-D} = \frac{.4}{1-.4} = \frac{2}{3}$, so $30V \cdot \frac{2}{3} = 
20V$

![Bucking behavior, where $D = 0.4$. Note that the "input" is referenced between
the input to the buck circuit, and our output node, so our real input node gets
pushed around as the circuit reaches steady state. That behavior is observable
in the previous part](media/async_buckboost/bucking.png)

In the same regard, pushing $D \gt 0.5$ gets us our boosting behavior. Adjusting
the duty cycle $D = 0.6$:

$\frac{.6}{1-.6} = \frac{3}{2}$, $30V \cdot \frac{3}{2} = 45V$

![Boosting behavior](media/async_buckboost/boosting.png)

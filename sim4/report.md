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

This is because the higher output resistance demands less current from the
buck converter, so the output voltage levels raise. This is seen on the switch
utilization chart, where our duty cycle primarily impacts our efficiency.
Usually, in applications where we want to keep the output voltage at a steady
level, we implement some kind of feedback to adjust $D$ as our load demands
change.

![Switch utilization chart, demonstrating the duty-cycle's relationship with
power delivery for a converter](media/async_buck/switchutil.png){width=40%}

# q2 - async buck boost converter

## a

$D = \frac{t_{on}}{t_{on}+t_{off}} = \frac{4}{10}$

Let $T = 8 \mu s$, so $t_{on} = 0.4 \cdot 8 \mu s = 3.2 \mu s$,
and $t_{off} = T - t_{on} = 4.8 \mu s$.

We assume our switching device has a slew rate of $100ns$, a typical rise / fall
figure for the LM555 timer.

![Buck-Boost Converter working to steady state at our specified duty cycle, $D$. 
In order: Our switching from the modulator, our bridge voltage, our inductor
current, and our output (pink) versus the input (gold). The sloping weirdness
is due to reference weirdness, where all magnitudes are measured with reference
to the output's negative pole](
media/async_buckboost/transients_full.png)

![Close-up on our waveforms, same order as previous figure.](
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

It's bucking, since our duty cycle, $D$ is $< 50\%$. 

At lower voltages, this is impacted by the voltage drop across the diode `D1`,
however, we can demonstrate this behavior by boosting our input DC voltage to be
significantly larger than this loss; we set $V_{in} = 30V$ and observe a
$V_{out} = 20V$.

$\frac{D}{1-D} = \frac{.4}{1-.4} = \frac{2}{3}$, so $30V \cdot \frac{2}{3} = 
20V$

![Bucking behavior, where $D = 0.4$. Note that the "input" is referenced between
the input to the buck circuit, and our output node, so our real input node gets
pushed around as the circuit reaches steady state. That behavior is observable
in the previous part](media/async_buckboost/bucking.png)

In the same regard, pushing $D > 0.5$ gets us our boosting behavior. Adjusting
the duty cycle $D = 0.6$:

$\frac{.6}{1-.6} = \frac{3}{2}$, $30V \cdot \frac{3}{2} = 45V$

![Boosting behavior, red is input (30V), output is green (45V)](media/async_buckboost/boosting.png)

# q3 -- Variable buck boost

Considering our $\frac{V_{out}}{V_{in}}$ equation in terms of $D$, we can
rearrange to get an expression of $D$ considering our current input and target
output voltage.

\begin{align*}
&\frac{V_{out}}{V_{in}} = \frac{D}{1-D} \\
\Longrightarrow &\frac{V_{in}}{V_{out}} = \frac{1-D}{D}\\
&= \frac{1}{D} - 1 \\
\Longrightarrow &\frac{1}{D} = \frac{V_{in}}{V_{out}} + 1 \\
\Longrightarrow &D = \frac{1}{\frac{V_{in}}{V_{out}} + 1} \\
\end{align*}

This can be implemented in LTSpice as just a couple of parameters.

![Testing 10V(pink)->15V(green) Boosting; works!](media/async_buckboost/variable_10V.png)

![Testing 20V(pink)->15V(green) Bucking; works!](media/async_buckboost/variable_20V.png)

![Swept random inputs bound between 10V to 20V, works! Each pink line is an input
voltage, and we can see that our output is fairly noisy at the start, but all
green lines converge to 15V after 15ms.](
media/async_buckboost/variable_sweeps.png)


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

Even though it wasn't explicitly necessary, I had some issues getting the sim
right with a non-isolated input, so I included an isolating transformer.



# q3 - voltage doubler



# ec

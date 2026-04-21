# Induction Hot Plate Proposal
Final Project for ECE448 - Power Electronics.

Fred Kim, James Ryan. Prof. Cavallaro. Spring 2026.

# Background

## Introduction

In an induction stovetop, our main goal is to induce heat into another piece of 
metal using some kind of coil. Conceptually, the goal is to harness an AC power 
source to induce a magnetic field around our coil. This alternating 
magnetic field then generates current in metal which is in proximity to it, 
which in turn induces a circulating current in that metal. These currents are 
called eddy currents. Metal is imperfect, so this current encounters 
resistance as it circulates, and as we learned in circuit analysis, this 
generates energy, which in our case becomes thermal heat. So, our main goal 
is to create a circuit which can generate a lot of circulating currents, in 
order to produce a lot of eddies in a neighboring piece of metal.

## Technical details


IGBTs combine MOSFETs and BJTs, and are capable of switching at 10s-100s of KHz
while supporting high-current workloads, which make it suitable for this 

# Proposed Solution

[Tutorial for a bolt heater](https://inductionheatertutorial.com/)

[Induction Coil Design considerations](https://www.mdpi.com/2076-3417/14/17/7996)

BOM TBD

[Induction heater
whitepaper](https://toshiba.semicon-storage.com/content/dam/toshiba-ss-v3/master/en/semiconductor/design-development/innovationcentre/whitepapers/TCM0542_GT20N135SRA.pdf0)

"the primary coil is typically made of copper and consists of many copper 
strands, known as a litz wire, that helps to reduce AC resistance."
(skin effect)

[Litz wire](https://ieeexplore.ieee.org/document/8340533)

Go to figure 2: Cm is PF correction, Lr and Cr. This is a SEPR circuit
(single ended parallel resonance converter)

[Paper on power loss reduction in a SEPR circuit](https://www.temjournal.com/documents/vol3no3/Study%20of%20Power%20Loss%20Reduction%20in%20SEPR%20Converters%20for%20Induction%20Heating%20through%20Implementation%20of%20SiC%20Based%20Semiconductor%20Switches.pdf)

[Coil HOW-TO](https://www.instructables.com/DIY-Induction-Heater-Circuit-With-Flat-Spiral-Coil/)

[Coil Selection](https://www.ebay.com/itm/376954271107)

[IGBT selection](https://toshiba.semicon-storage.com/us/semiconductor/product/igbts-iegts/igbts/detail.GT20N135SRA.html)

Spec goals TBD -- How do we figure this out?


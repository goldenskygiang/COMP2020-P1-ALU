# Project 1 - ALU Design Documentation

## Overview

This is a 32-bit ALU which can perform basic operations on 32-bit signed integers. Supported operations include addition/subtraction, shift left/right logical/arithmetic, logic operations AND/OR/XOR/NOR, comparison between 2 numbers and one number with 0.

![Overview ALU design](imgs/whole_ALU.png)

## ALU Op splitter
![ALU Opcode splitter](imgs/ALU_opcode.png)

The 4-bit Op is splitted into multiple outputs to serve different purposes.

**Notation**:
- Op[$x:y$]: continuous bit segment from position $x$ to position $y$ (inclusive);
- Op[$x_1, x_2, ..., x_n$]: the output consists of bits Op[$x_1$], Op[$x_2$], ..., Op[$x_n$] to be placed respectively, as a group.

The output will have its own new indexes for each bit, independent of how it was calculated.

**Outputs**:
- Op[1:3]: select master MUX output.
- Op[0,3]: custom Opcode for the LRShift32 circuit.
- Op[2]: Cin value for the Add32 circuit.
- Op[1,3]: to be put through an AND gate to calculate EV to determine whether to output V of the whole ALU.
- Op[0]: subfunction bit to differentiate among function groups (to be explaned in later parts).

## 32-bit adder/subtracter circuit (Add32)
> a) 1-bit full adder

> b) 4-bit adder

> c) 16-bit adder

> d) 32-bit adder

![Add32 circuit](imgs/Add32.png)

## 32-bit shifter (LRShift32)

## Logic operations

## Comparison operations
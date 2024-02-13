# Files of lab 3 of course IS1200 at KTH 
https://www.kth.se/student/kurser/kurs/IS1200?l=en
I/O Programming

## Assignment 1: Polling switches
In this assignment, you will write code that (repeatedly) examines the values of one or more input
bits. This is called polling, and is the simplest way to check input from a switch or push-button. You
will also write code to send output-data to LEDs.

## Assignment 2: Timer
In this assignment, you will use a timer device. Timers are controlled directly by a very accurate
pulse-generator (called a crystal oscillator). Because of this, timers can can be used for very precise
measurements of time. The resolution of these measurements depends on the pulse-frequency and is
usually well into the sub-microsecond range. 

## Assignment 3: Interrupts
In the previous assignments, you have used polling of input-data and polling of a timer event-flag.
The downside of polling is that it keeps the processor busy, checking input and/or event flags.
With interrupts, the processor can perform any kind of useful computation instead. When input data
changes, or when the timer event-flag goes on, ordinary computation is temporarily suspended; the
processor starts executing an interrupt-service routine (ISR) instead.
However, the fact that ordinary program execution can be interrupted at any time makes it hard to
debug problems related to interrupt programming. We will therefore limit this assignment to one
source of interrupts: the timer event-flag.

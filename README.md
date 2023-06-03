# Philosophers Project



## Introduction

Welcome to the Philosophers project! This project aims to simulate the dining philosophers problem, which is an interesting synchronization problem in computer science. The project provides a solution that demonstrates the problem and showcases various synchronization techniques to avoid deadlocks and resource contention.


## Installation

To get started with the project, follow these steps:

1. Clone the repository:

```shell
git clone https://github.com/emohamedd/philosophers.git

```shell
cd philosophers

```shell
make
 
```shell
./philosophers [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]

# Usage 
Replace the arguments in square brackets with your desired values. Here's a brief explanation of each argument:

number_of_philosophers: The total number of philosophers in the simulation.
time_to_die: The time in milliseconds after which a philosopher dies if they haven't started eating.
time_to_eat: The time in milliseconds that a philosopher takes to finish eating.
time_to_sleep: The time in milliseconds that a philosopher spends sleeping between meals.
number_of_times_each_philosopher_must_eat: The number of times each philosopher must eat before the simulation ends.
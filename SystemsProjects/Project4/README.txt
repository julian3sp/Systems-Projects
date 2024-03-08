Julian Espinal, 2/30/2024

Description:
This program simulates a coffee shop where the user inputs the command line arguments deciding
seed: An integer for the random number seed

total_min: The total “time” to run the simulation

arrive_prob: The probability of a customer arriving (float between 0 and 1)

order_prob: The probability of a customer finishing their order (float between 0 and 1)

queues: The number of queues to simulate

outputFile: The name of the output file

Each customer has 4 values associated with them: ID, arrival time, order start time and completed time. 
random intervals, customers will enter the store and join the queue.
As time goes on, customers will reach the front of the queue and make their purchase before
leaving the queue.

Whenever a customer enters a queue or is served, it is printed to the terminal

At the end of the simulation, the number of people left in each queue 
and the number of customer each queues cashier served is printed to the terminal

Compile/Running Program Instructions: (typed into terminal)
Compile: Type 'make all' into the terminal
Running: './run_simulation <seed> <total_min> <arrival_prob> <order_prob> <num_queues> <outputFile>'


References: 
-none

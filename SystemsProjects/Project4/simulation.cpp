#include "customer.h"
#include "shopQueue.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::make_shared;
using std::make_unique;
using std::shared_ptr;
using std::string;
using std::unique_ptr;

int main(int argc, char *argv[]) {
  // Check if the correct number of command-line arguments is provided
  if (argc < 7) {
    cout << "Error: Wrong number of arguments!" << endl;
    cout << "Usage: ./run_simulation <seed> <total_min> <arrival_prob> "
            "<order_prob> <num_queues> <outputFile>"
         << endl;
    // Exit the program
    return 1;
  }

  // Parse command-line arguments
  int seed = stoi(argv[1]);
  int total_min = stoi(argv[2]);
  float arrival_prob = stof(argv[3]);
  float order_prob = stof(argv[4]);
  int num_queues = stoi(argv[5]);
  string outputFile = argv[6];
  srand(seed);

  // Welcome message
  cout << "Welcome to Gompei Coffee Shop!" << endl;
  cout << "-- # of Checkout Queues: " << num_queues << " --" << endl;

  // Create an array/vector of ShopQueue objects
  vector<ShopQueue> queues(num_queues);

  // Initialize variables for simulation
  int currentTime = 0;
  int timeNeeded = 0;
  int completedTime = 0;
  int queuePlacement = 0;
  // Create a variable to keep track of the shortest queue
  ShopQueue shortestQueue = queues.front();

  // Create a vector to store completed customers
  vector<shared_ptr<Customer>> completed;

  // Add initial customer to the first queue
  queues[0].addNewCustomer(currentTime, timeNeeded, completedTime, queuePlacement);
  cout << "New customer at t = " << currentTime << "." << endl;
  queuePlacement++;

  // Main simulation loop
  while (currentTime < total_min) {
    // Find the shortest queue among all queues
    ShopQueue *shortestQueue = &queues.front();
    for (ShopQueue &currentQueue : queues) {
      if (currentQueue.getLength() < shortestQueue->getLength()) {
        shortestQueue = &currentQueue;
      }
    }

    // Generate a random number to decide if a new customer arrives
    auto random = (float)rand() / RAND_MAX;
    if (random < arrival_prob) {
      shortestQueue->addNewCustomer(currentTime, 0, 0, queuePlacement);
      cout << "New customer at t = " << currentTime << endl;
      queuePlacement++;
    }

    // Iterate through all queues and process customers
    for (ShopQueue &currentQueue : queues) {
      if (!currentQueue.isEmpty()) {
        auto random = (float)rand() / RAND_MAX;
        if ((random < order_prob)) {
          shared_ptr<Customer> frontCustomer = currentQueue.peekFrontCustomer();

          if (completed.empty() || frontCustomer->arrivalTime == 0) {
            // Process the customer and update relevant information
            frontCustomer->startTime = frontCustomer->arrivalTime;
            frontCustomer->completedTime = currentTime;
            currentQueue.setServeTime(currentTime);
            completed.push_back(frontCustomer);
            cout << "Customer #" << frontCustomer->ID
                 << " was served from t = " << frontCustomer->startTime
                 << " to " << frontCustomer->completedTime << "." << endl;
            currentQueue.removeFrontCustomer();
          } else {
            // Process the customer and update relevant information
            if (currentQueue.getServeTime() < frontCustomer->arrivalTime) {
              frontCustomer->startTime = frontCustomer->arrivalTime;
            } else {
              frontCustomer->startTime = currentQueue.getServeTime();
            }
            frontCustomer->completedTime = currentTime;
            currentQueue.setServeTime(currentTime);
            completed.push_back(frontCustomer);
            cout << "Customer #" << frontCustomer->ID
                 << " was served from t = " << frontCustomer->startTime
                 << " to " << frontCustomer->completedTime << "." << endl;
            currentQueue.removeFrontCustomer();
          }
        }
      }
    }
    currentTime++;
  }

  // Output the results to the outFile
  ofstream outFile;
  outFile.open(outputFile);
  if (outFile.fail()) {
    cout << "Error: Failed to open the output file!" << endl;
    return 1;
  }

  // Write the results of the simulation to the output file
  outFile << std::setw(8) << "ID" << std::setw(8) << "Arrive" << setw(8)
          << "Start" << setw(8) << "Leave" << endl;
  for (auto &x : completed) {
    if (x != nullptr) {
      outFile << setw(8) << x->ID << setw(8) << x->arrivalTime << setw(8)
              << x->startTime << setw(8) << x->completedTime << endl;
    }
  }

  // Output the remaining customers in each queue
  for (int i = 0; i < num_queues; i++) {
    cout << "After " << total_min << " minutes, " << queues[i].getLength()
         << " customers remain in queue #" << i << "." << endl;
  }

  // Output the number of customers served by each cashier
  for (int i = 0; i < num_queues; i++) {
    if (queues[i].getCustomersServed() != 0) {
      cout << "Cashier " << i << " served " << queues[i].getCustomersServed()
           << " customers." << endl;
    }
  }

  // Return 0 to indicate successful execution
  return 0;
}
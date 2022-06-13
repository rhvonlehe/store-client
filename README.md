# store-client - part of the Stream Labs coding challenge

The Store 'client' uses the Store library.  The goal is to for the client to instantiate a user-supplied number of 'customers', each one running in its own thread.
Alternately, multiple 'client' processes can be started independently on the command line.  Each customer then buys random products following a sequence of API calls with random delays between purchases.

Instructions for use:

Prerequisites: Must have CMake 3.12 or newer, Windows 10/11, MSVC2019 or later

1. git clone git@github.com:rhvonlehe/store-client.git
2. git submodule update --init --recursive
3. mkdir build
4. cd build
5. cmake -G <generator-of-choice> -S ../
6. ./client.exe <num_of_customers>
  


Notes:

Although multi-process access to the store was designed from the start to work, it has not been fully tested due to time constraints.  Synchronizing the start of multiple processes might also be tricky.

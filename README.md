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
6. ./client.exe <num_customers> <num_purchases>    
  
  

Notes:

* Although multi-process access to the store was designed from the start to work, it has not been fully tested due to time constraints.  Synchronizing the start of multiple processes was going to be a little trickier and I wanted to wrap this up.
* The 2 params to the client.exe are the number of customers (threads in this case) and the number of items they attempt to purchase.  The purchases are dumb in this case and they will attempt to purchase without examining the qty available.  

  
  
Answers to questions:
Q: How long did it take?  
A: A weekend with several breaks (attended grad party, birthday party, etc)

Q: What about the assignment was unclear?
A: Not perfectly clear if threads or processes would be used by the store client - I made it safe for both.  Also, the level of attention to detail needed is subjective - e.g. do I need to do proper error checking or exception handling for all possible cases.  I did some, but could certainly do more if this wasn't a timed exercise.
  
Q: Was the level of difficulty appropriate?
  
A: I'd say yes, given this is for a senior level position.  I took longer than my own estimate, but I was unfamiliar with nlohmann-json.

Q: Explain technical decisions
  
A: I'll list the ones I'm most aware of below.
  
* I decided to use an OS (Windows) mutex because I wasn't clear whether than was the goal (vs a C++ thread mutex).  The mutex protects simultaneous access to a file, thus keeping its integrity.  For reads in the API the mutex is released as soon as the json model is created.  For the purchase case, the mutex is held through a read/update cycle.
* As requested the store library repo is a submodule of my application (store-client repo).  Also, nlohmann-json is pulled in as a dependency using CMake's FetchContent feature.
* I used the pimpl idiom in my Store class. It became less necessary as my design evolved, but I kept there anyway.  I could probably have eliminated it with a little work.
* The assets/store.json file is moved into the build folder along with the client executable and the store.dll shared library via CMake's configure_file().  To reset the file, simply ask CMake to configure your project again.
* I took advantage of the json library's ability to convert between custom types and json easily with my Product class.  
* I made it a point to keep all json library use from becoming part of the store library's interface.  It is all encapsulated in the implementation only.  
* Aspects of C++ that I used: RAII, threads, chrono, containers like vector and map, smart pointers (unique_ptr), random.  Limited use of exceptions with local catch.

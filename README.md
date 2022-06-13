# store-client - part of the Stream Labs coding challenge

The Store 'client' uses the Store library.  The goal is to for the client to instantiate a user-supplied number of 'customers', each one running in its own thread.
Alternately, multiple 'client' processes can be started independently on the command line.  Each customer then buys random products following a sequence of API calls with random delays between purchases.

Instructions for use:







Notes:

Although multi-process access to the store was designed from the start to work, it has not been fully tested due to time constraints.  Synchronizing the start of multiple processes might also be tricky.

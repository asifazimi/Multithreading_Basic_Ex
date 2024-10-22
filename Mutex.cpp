int counter = 0;

std::mutex m;
m.lock(); // acquire mutex
++counter;
m.unlock(); // release mutex
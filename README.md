# Digital Circuit Simulation Fixes
## Tech Stack Utilised
| Desciption | Version|
| ----------- | ----------- |
| Microsoft Visual Studio Community 2019 | 16.11.26|
| C++ Language Standard | std:c++latest |
## Methodology
The initial check for runtime bottleneck was done by adding the following duration timers on all the methods in the main function. This was also used as a benchmark timing for the subsequent optimization exercises.
```
#include <chrono>
// Get the start time
auto start = std::chrono::high_resolution_clock::now();

// Run the code you want to time
auto simulation = Simulation::FromFile(input);

// Get the end time
auto end = std::chrono::high_resolution_clock::now();

// Calculate the duration
auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
std::cout << "Function: Simulation::Method Name " << "Time taken: " << duration << " milliseconds" << std::endl;
```

The test file used was 5devadas13.in as it was already mentioned this takes a long time to produce an output. It was found that the 2 longest execution was from the methods Simulation::Run and boost::property_tree::write_json.
The 2 methods were targeted for optimization and the resulting improvement achieved was greater than 90%.

## Changes Done
| Commit| Description|
| ----------- | ----------- |
| [b1f720](https://github.com/daddySpartan/firstwatch/tree/b1f720e847dbbf5a84a095f3d4bbfd1d0bc6764b) | initialise local include paths|
| [5a7e3b](https://github.com/daddySpartan/firstwatch/commit/5a7e3b362c167eaa9a5994aae4e7bb4804653d10) | optimize simulation by changing existing priority queue algorithm to binary heap method|
| [7ebbc8](https://github.com/daddySpartan/firstwatch/commit/7ebbc8759253e12540c16d854f09296bf88680f6) | optimize simulation by changing json output format removing whitespaces and propertytree library|
| [ce281f](https://github.com/daddySpartan/firstwatch/commit/ce281f3846f5c66bf06aefb44e09a48bdeedd655) | minor code cleanup including command line fixes|
| [0bebd9](https://github.com/daddySpartan/firstwatch/commit/0bebd92083e01305cb2e6d82640ae8b805eb4347) | added output string filter to keep escape characters intact in case required by visualizer| 

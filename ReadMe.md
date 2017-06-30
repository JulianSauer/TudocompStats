# Tudocomp Stats
This is a fork of a submodul from the Technical University of DOrtmund COMPression Framework (tudocomp). It measures the time and needed memory during execution of a program. The result is printed in JSON format and can be visualized using the [tudocomp charter](http://tudocomp.org/charter/). You can check out their [website](http://tudocomp.org/documentation/index.html#runtime-statistics) for the official documentation.

![tudocomp charter](http://tudocomp.org/documentation/media/charter_diagram.png)

## Usage
After downloading and compiling the library you can start by for example adding a root phase that measures the whole application. Within it additional nested phases can be added later to measure single tasks more precisely.
```C++
tdc::StatPhase root("Root");
// Your code
root.to_json().str(std::cout);
```

If you want to use the [tudocomp charter](http://tudocomp.org/charter/) a few additional parameters have to be set. Since the charter tool is for measuring algorithms some of the parameters might not be useful for different use cases.
### Example for charter
```C++
auto algorithm_stats = root.to_json();

    tdc::json::Object meta;
    meta.set("title", "TITLE");
    meta.set("startTime", "STARTTIME");

    meta.set("config", "NONE");
    meta.set("input", "FILENAME");;
    meta.set("inputSize", "INPUTSIZE);
    meta.set("output", "NONE");
    meta.set("outputSize", "OUTPUTSIZE");
    meta.set("rate", "NONE");

    tdc::json::Object stats;
    stats.set("meta", meta);
    stats.set("data", algorithm_stats);

    std::cout << "data for http://tudocomp.org/charter" << std::endl;
    stats.str(std::cout);
    std::cout << std::endl;
```
### Example for using sub phases
```C++
tdc::StatPhase root("Root");
tdc::StatPhase sub_phase_add("Sub phase 1");
// Phase 1
sub_phase_add.split("Sub phase 2");
// Phase 2
sub_phase_add.split("Sub phase 3");
// Phase 3
root.to_json().str(std::cout);
```

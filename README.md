## Distributed Column Aggregator
A template for a distributed, horizontally scalable column aggregation system, enabling basic statistical operations on user-defined and C++ built-in numeric types. It leverages Docker to set up a multi-machine calculation cluster using a "client-server" architecture, with one central unit ("hub") and multiple calculation nodes operating in parallel through asynchronous RPC technology. The user interface logic is exported to Python to facilitate a convenient workflow within the interpreter, as well as to enable simple platform integration testing and benchmarking using the pytest library.

### Dependencies

- Loki by Andrei Alexandrescu: https://loki-lib.sourceforge.net/
- rpclib by Tamás Szelei: https://github.com/rpclib/rpclib
- boost-1.71.0
- clang++ 10
- pytest
- docker

### Running the application

#### Build the docker image from the project repo:

```docker build . -t minidb_1.0```

#### Setup the app in docker containers

```docker compose -f ./docker_setup/1_hub_2_nodes.yml up -d```

#### Kick-off the interperter

```docker exec -it hub bash -c "python3 -i engine/initDB.py"```

#### Enable view from nodes in the separate terminal windows:

```
docker logs -f node1
docker logs -f node2
```
## Usage:
```
a = DoubleColumn() 
a.LoadData("data4.csv")
a.Print()
result = a.Sum()
result = a.Count()
result = a.MomentI()
result = a.MomentII()
result = a.Stddev()
```

### Benchmarks

```docker exec -it hub bash -c "pytest" ```

Or just use convenient script starting containers from scratch:

```scripts/run_benchmarks_2_nodes.sh```

#### Running Unit Tests

``` docker exec -it hub bash -c "cd engine/build/ && ctest -V"```

or just with script: 

```scripts/run_ctest.sh```

#### Static analysis:
```
clang-tidy -p ./src/ ./src/ParameterController/ParameterControllerHub.cpp -checks=* -header-filter=.* --
```

#### Formatter:
Just run:
```./formatter```

To edit configuration:
```vim .clang-format```

### Future Work
This section outlines potential features and ideas that could be added to enhance the project in the future:
- **GPU Processing**: Extend the system to leverage GPU processing for higher parallelization and significant performance improvement.
- **Numeric Data Types**: Expand support for a wider range of numeric data types, including arbitrary precision types for full compliance with modern DBMS systems.
- **Mathematical Operations and Operators**: Implement operators and mathematical operations on columns the enhance data analysis capabilities.

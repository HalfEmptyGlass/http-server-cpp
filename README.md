# http-server-cpp
An HTTP server created using only raw C++

Configure cmake
```
# Debug
cmake -S . -B ./builds/build-debug -DCMAKE_BUILD_TYPE=Debug

# OR for release
cmake -S . -B ./builds/build-release -DCMAKE_BUILD_TYPE=Release
```

Compile build
```
# Debug
cmake --build ./builds/build-debug

# Release
cmake --build ./builds/build-release
```

Run app
```
# Debug
./builds/build-debug/httpservercpp

# Release
./builds/build-release/httpservercpp
```





# CSCE2110\_Campus\_Resource\_Reservation\_System

## Building



## Requirements

- g++ with C++17 support

- CMake 3.x or newer — optional



## Build with CMake

```

cmake -S . -B build

cmake --build build

```



## Build without CMake

For machines where CMake is unavailable:

```

mkdir -p build

g++ -std=c++17 -Iinclude -Wall -Wextra -o build/CampusResourceReservationSystem src/\*.cpp
```



## Running

Run from the repository root

`data/resources.txt` by relative path.

```

./build/CampusResourceReservationSystem

```


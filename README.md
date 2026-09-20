# CSCE2110\_Campus\_Resource\_Reservation\_System

\## Building



\### Requirements

\- g++ with C++17 support (verified on g++ 11.4.0, UNT CSE cell machines)

\- CMake 3.x or newer — optional, see manual build below



\### Build with CMake

```

cmake -S . -B build

cmake --build build

```



\### Build without CMake

For machines where CMake is unavailable (e.g. the UNT CSE cell machines):

```

mkdir -p build

g++ -std=c++17 -Iinclude -Wall -Wextra -o build/CampusResourceReservationSystem src/\*.cpp

```



\### Running

Run from the repository root, \*\*not\*\* from `build/` — the program loads

`data/resources.txt` by relative path.

```

./build/CampusResourceReservationSystem

```


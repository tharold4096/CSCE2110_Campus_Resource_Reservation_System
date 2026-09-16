
cmake_minimum_required(VERSION 3.10)

project(CampusResourceReservationSystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(CampusResourceReservationSystem
    src/main.cpp
    src/Reservation.cpp
    src/ReservationManager.cpp
    src/WaitingList.cpp
)


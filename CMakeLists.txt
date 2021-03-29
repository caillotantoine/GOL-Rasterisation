cmake_minimum_required(VERSION 2.8)
project( GOLRasterisation )

find_package(OpenCV 4 REQUIRED)
find_package (Eigen3 3.3 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}
                    ${OpenCV_INCLUDE_DIRS}
                    ${Eigen3_INCLUDE_DIRS}
)

add_executable( GOLRasterisation main.cpp pgm_out.cpp segments.cpp)
target_link_libraries( GOLRasterisation ${OpenCV_LIBRARIES} ${Eigen3_LIBRARIES} )
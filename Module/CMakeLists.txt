# NavigationModule 相关文件
add_library(NavigationModule NavigationModule.cpp)
target_include_directories(NavigationModule PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(CampusNavigation NavigationModule)

# OperationalModule 相关文件
add_library(OperationalModule OperationalModule.cpp)
target_include_directories(OperationalModule PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(CampusNavigation OperationalModule)

# StorageModule 相关文件
add_library(StorageModule StorageModule.cpp)
target_include_directories(StorageModule PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(CampusNavigation StorageModule)

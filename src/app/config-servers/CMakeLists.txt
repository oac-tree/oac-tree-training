
add_executable(config-servers)
add_executable(sequencer-training::config-servers ALIAS config-servers) # alias for build-tree usage

target_compile_features(config-servers PRIVATE cxx_std_11)

target_include_directories(config-servers
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_sources(config-servers
  PRIVATE
    factory.cpp
    main.cpp
)

add_subdirectory(signal-generator)

find_package(sup-config REQUIRED)
find_package(sup-utils REQUIRED)

target_link_libraries(config-servers
  PRIVATE
    sequencer-training
    sup-config::sup-config
    sup-utils::sup-cli
)

# -- Installation --

install(TARGETS config-servers EXPORT sequencer-training-targets LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
set_target_properties(config-servers PROPERTIES EXPORT_NAME config-servers)

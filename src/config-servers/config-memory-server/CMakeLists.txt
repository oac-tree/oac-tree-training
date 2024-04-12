add_executable(config-memory-server)
add_executable(sequencer-training::config-memory-server ALIAS config-memory-server) # alias for build-tree usage

target_compile_features(config-memory-server PRIVATE cxx_std_11)

target_include_directories(config-memory-server
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_sources(config-memory-server
  PRIVATE
    config-handler.cpp
    main.cpp
)

find_package(sup-dto REQUIRED)
find_package(sup-protocol REQUIRED)
find_package(sup-epics REQUIRED)
find_package(sup-config REQUIRED)
target_link_libraries(config-memory-server
  PRIVATE
    sup-config::sup-config-test
    sup-config::sup-config
    sup-epics::sup-epics
    sup-protocol::sup-protocol
    sup-dto::sup-dto
)

# -- Installation --

install(TARGETS config-memory-server EXPORT sequencer-training-targets LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
set_target_properties(config-memory-server PROPERTIES EXPORT_NAME config-memory-server)

add_executable(signal-generator-config)
add_executable(sequencer-training::signal-generator-config ALIAS signal-generator-config) # alias for build-tree usage

target_compile_features(signal-generator-config PRIVATE cxx_std_11)

target_include_directories(signal-generator-config
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_sources(signal-generator-config
  PRIVATE
    config-handler.cpp
    main.cpp
)

find_package(sup-dto REQUIRED)
find_package(sup-protocol REQUIRED)
find_package(sup-epics REQUIRED)
find_package(sup-config REQUIRED)
target_link_libraries(signal-generator-config
  PRIVATE
    sup-config::sup-config-test
    sup-config::sup-config
    sup-epics::sup-epics
    sup-protocol::sup-protocol
    sup-dto::sup-dto
)

# -- Installation --

install(TARGETS signal-generator-config EXPORT sequencer-training-targets LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
set_target_properties(signal-generator-config PROPERTIES EXPORT_NAME signal-generator-config)

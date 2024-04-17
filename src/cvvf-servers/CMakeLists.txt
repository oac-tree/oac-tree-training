
add_executable(cvvf-servers)
add_executable(sequencer-training::cvvf-servers ALIAS cvvf-servers) # alias for build-tree usage

target_compile_features(cvvf-servers PRIVATE cxx_std_11)

target_include_directories(cvvf-servers
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_sources(cvvf-servers
  PRIVATE
    factory.cpp
    i_server_stack.cpp
    utils.cpp
    main.cpp
)

add_subdirectory(signal-generator)

find_package(sup-dto REQUIRED)
find_package(sup-protocol REQUIRED)
find_package(sup-epics REQUIRED)
find_package(sup-config REQUIRED)
find_package(sup-utils REQUIRED)

target_link_libraries(cvvf-servers
  PRIVATE
    sup-config::sup-cvvf
    sup-epics::sup-epics
    sup-protocol::sup-protocol
    sup-dto::sup-dto
    sup-utils::sup-cli
)

# -- Installation --

install(TARGETS cvvf-servers EXPORT sequencer-training-targets LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
set_target_properties(cvvf-servers PROPERTIES EXPORT_NAME cvvf-servers)

add_library(sequencer-training SHARED "")
add_library(sequencer-training::sequencer-training ALIAS sequencer-training) # alias for build-tree usage

target_compile_features(sequencer-training PRIVATE cxx_std_11)

set_target_properties(sequencer-training PROPERTIES
  EXPORT_NAME sequencer-training
  SOVERSION ${LIBSOVERSION}
  VERSION ${LIBVERSION}
)

target_include_directories(sequencer-training PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/../..>
)

find_package(sup-dto REQUIRED)
find_package(sup-protocol REQUIRED)
find_package(sup-epics REQUIRED)
find_package(sup-config REQUIRED)

target_link_libraries(sequencer-training
  PRIVATE
    sup-config::sup-config
    sup-config::sup-cvvf
    sup-epics::sup-epics
    sup-protocol::sup-protocol
    sup-dto::sup-dto
)

target_sources(sequencer-training
  PRIVATE
    factory.cpp
    i_server_stack.cpp
    utils.cpp
)

add_subdirectory(signal-generator)

# -- Installation --
install(TARGETS sequencer-training EXPORT sequencer-training-targets LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES
  factory.h
  i_server_stack.h
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/sequencer/training
)

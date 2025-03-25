add_library(oac-tree-training SHARED "")
add_library(oac-tree-training::oac-tree-training ALIAS oac-tree-training) # alias for build-tree usage

set_target_properties(oac-tree-training PROPERTIES
  EXPORT_NAME oac-tree-training
  SOVERSION ${LIBSOVERSION}
  VERSION ${LIBVERSION}
)

target_include_directories(oac-tree-training PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/../..>
)

find_package(sup-dto REQUIRED)
find_package(sup-protocol REQUIRED)
find_package(sup-epics REQUIRED)
find_package(sup-config REQUIRED)

target_link_libraries(oac-tree-training
  PRIVATE
    sup-config::sup-config
    sup-config::sup-cvvf
    sup-epics::sup-epics
    sup-protocol::sup-protocol
    sup-dto::sup-dto
)

target_sources(oac-tree-training
  PRIVATE
    factory.cpp
    i_server_stack.cpp
    utils.cpp
)

add_subdirectory(signal-generator)

# -- Installation --
install(TARGETS oac-tree-training EXPORT oac-tree-training-targets LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES
  factory.h
  i_server_stack.h
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/oac-tree/training
)


add_executable(cvvf-servers)
add_executable(oac-tree-training::cvvf-servers ALIAS cvvf-servers) # alias for build-tree usage

target_include_directories(cvvf-servers
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_sources(cvvf-servers
  PRIVATE
    main.cpp
)

find_package(sup-utils REQUIRED)

target_link_libraries(cvvf-servers
  PRIVATE
    oac-tree-training
    sup-utils::sup-cli
)

# -- Installation --

install(TARGETS cvvf-servers EXPORT oac-tree-training-targets LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
set_target_properties(cvvf-servers PROPERTIES EXPORT_NAME cvvf-servers)

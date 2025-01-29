
add_executable(config-servers)
add_executable(oac-tree-training::config-servers ALIAS config-servers) # alias for build-tree usage

target_include_directories(config-servers
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_sources(config-servers
  PRIVATE
    main.cpp
)

find_package(sup-utils REQUIRED)

target_link_libraries(config-servers
  PRIVATE
    oac-tree-training
    sup-utils::sup-cli
)

# -- Installation --

install(TARGETS config-servers EXPORT oac-tree-training-targets LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
set_target_properties(config-servers PROPERTIES EXPORT_NAME config-servers)

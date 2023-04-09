set(library_name TestLib)

include_directories(
  ${PROJECT_SOURCE_DIR}/source/inc
  ${CMAKE_CURRENT_BINARY_DIR})

ROOT_GENERATE_DICTIONARY(
  ${library_name}_dict
  testobject.h
  MODULE ${library_name}
  LINKDEF inc/LinkDef.hh
)

SET(root_dict
  ${library_name}_dict.cxx)
SET(root_dict_libs
  ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}${library_name}_rdict.pcm
  ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_SHARED_LIBRARY_PREFIX}${library_name}.rootmap)

file(GLOB sources ${PROJECT_SOURCE_DIR}/source/src/*.cxx)
file(GLOB headers ${PROJECT_SOURCE_DIR}/source/inc/*.h)

set(LIB_ROOT_DEPS ROOT::Core ROOT::Physics)
add_library(${library_name} ${sources} ${root_dict} ${headers})
target_link_libraries(${library_name} ${LIB_ROOT_DEPS})
set_target_properties(${library_name} PROPERTIES INTERFACE_LINK_LIBRARIES "${LIB_ROOT_DEPS}")
target_include_directories(${library_name} INTERFACE $<INSTALL_INTERFACE:inc/${base_name}>)

install(DIRECTORY inc/ DESTINATION include)
install(TARGETS ${library_name} EXPORT TestTargets DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${root_dict_libs} DESTINATION ${CMAKE_INSTALL_LIBDIR})

add_executable(write_test src/write_test.cpp)
set(EXEC_ROOT_DEPS ROOT::Core ROOT::Tree ROOT::Physics)
target_link_libraries(write_test ${EXEC_ROOT_DEPS} ${library_name})
install(TARGETS write_test)

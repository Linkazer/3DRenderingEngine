# CMakeList.txt : projet CMake pour 3DRenderingEngine, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.10)

# Activez Rechargement à chaud pour les compilateurs MSVC si cela est pris en charge.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("3DRenderingEngine")

# Ajoutez une source à l'exécutable de ce projet.
add_executable (3DRenderingEngine
        "source/3DRenderingEngine.cpp"
        "source/glad.c"  )

target_include_directories(3DRenderingEngine PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/includes"
)

target_include_directories(3DRenderingEngine PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/external/OpenGL/includes"
)

target_link_directories(3DRenderingEngine PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/external/OpenGL/lib"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 3DRenderingEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.

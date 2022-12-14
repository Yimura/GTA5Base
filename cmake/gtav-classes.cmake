include(FetchContent)

set(LIB_NAME "gtav_classes")
message("Setting up GTAV-Classes")

FetchContent_Declare(
    ${LIB_NAME}
    GIT_REPOSITORY https://github.com/Yimura/GTAV-Classes.git
    GIT_TAG        47b53c9a10ff7b67ff33954fb78efd7ccbb57379
    GIT_PROGRESS TRUE
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
)
if(NOT gtav_classes_POPULATED)
    FetchContent_Populate(gtav_classes)

    file(GLOB_RECURSE SRC_GTAV_CLASSES "${gtav_classes_SOURCE_DIR}/*.hpp")

    # Show GTAV-Classes project
    add_library(${LIB_NAME} "${SRC_GTAV_CLASSES}")

    source_group(TREE "${gtav_classes_SOURCE_DIR}" PREFIX "GTAV-Classes" FILES "${SRC_GTAV_CLASSES}")
endif()
set_property(TARGET ${LIB_NAME} PROPERTY CXX_STANDARD 23)
set_target_properties(${LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)
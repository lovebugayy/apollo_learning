set(MODULE_MATH math)

aux_source_directory(. MATH_LIST)

add_library(MODULE_MATH ${MATH_LIST})
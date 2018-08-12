#! /bin/bash
#
# Uses sed and cpp to get nng.h into a form cffi can swallow.
# removes #includes,
echo "// THIS FILE WAS AUTOMATICALLY GENERATED BY $0" > nng_api.h
function process_header() {
    sed '/^#include/d' $1 | cpp | sed 's/^#.*$//g' | sed '/^$/d'
}
process_header nng/src/nng.h >> nng_api.h

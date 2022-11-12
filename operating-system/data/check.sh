#!/usr/bin/bash

cd "$(cd "$(dirname "${BASH_SOURCE[0]}" )" > /dev/null 2>&1 && pwd)"

function check_file() {
    local filename="$(basename "$1")"
    local filename_serial="serial-$filename"
    local filename_pthread="pthread-$filename"
    local filename_tbb="tbb-$filename"

    if [[ ! -f "$filename_serial" ]]; then
        echo -e "\nFile '$filename_serial' does not exist"
        return 1
    fi

    if [[ ! -f "$filename_pthread" ]]; then
        echo -e "\nFile '$filename_pthread' does not exist"
        return 1
    fi

    if [[ ! -f "$filename_tbb" ]]; then
        echo -e "\nFile '$filename_tbb' does not exist"
        return 1
    fi

    if ! cmp "$filename_serial" "$filename_pthread" > /dev/null; then
        echo -e "\nFiles '$filename_serial' and '$filename_pthread' don't match"
        return 1
    fi

    if ! cmp "$filename_serial" "$filename_tbb" > /dev/null; then
        echo -e "\nFiles '$filename_serial' and '$filename_tbb' don't match"
        return 1
    fi

    printf .
    return 0;
}

find . -type f -iname "[0-9]*.png" | sort | while read FILE; do
    if ! check_file "$FILE"; then
        exit 1
    fi
done

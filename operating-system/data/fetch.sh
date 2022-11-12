#!/usr/bin/bash

cd "$(cd "$(dirname "${BASH_SOURCE[0]}" )" > /dev/null 2>&1 && pwd)"

function fetch_file() {
    local frame_local="$1"
    local frame_bbb=$(echo "$1+5580" | bc)

    wget --quiet "https://media.xiph.org/BBB/BBB-360-png/big_buck_bunny_0${frame_bbb}.png" \
        -O "$(printf "%04d.png" "$frame_local")"
    printf .
}

export -f fetch_file
seq 0 400 | tr '\n' '\0' | xargs -0 -P16 -I{} bash -c 'fetch_file "$@"' _ {}
echo

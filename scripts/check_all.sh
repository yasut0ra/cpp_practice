#!/usr/bin/env bash

set -euo pipefail

tmp_dir="$(mktemp -d)"
trap 'rm -rf "$tmp_dir"' EXIT

count=0

while IFS= read -r file; do
    output_path="$tmp_dir/${file//\//_}"
    g++ -std=c++17 -O2 -Wall -Wextra -pedantic "$file" -o "$output_path"
    count=$((count + 1))
done < <(find . -name '*.cpp' | sort)

printf 'compiled %d files\n' "$count"

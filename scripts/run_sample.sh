#!/usr/bin/env bash

set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "$script_dir/sample_utils.sh"

cd "$repo_root"

if [[ $# -ne 1 ]]; then
    printf 'usage: %s path/to/sample.cpp\n' "$0" >&2
    exit 1
fi

file="${1#./}"
if [[ ! -f "$file" || "$file" != *.cpp ]]; then
    printf 'C++ sample not found: %s\n' "$file" >&2
    exit 1
fi

tmp_dir="$(mktemp -d)"
trap 'rm -rf "$tmp_dir"' EXIT

input_path="$tmp_dir/input.txt"
expected_path="$tmp_dir/expected.txt"
actual_path="$tmp_dir/actual.txt"
output_path="$tmp_dir/sample"

extract_example "ミニ入力例" "$file" > "$input_path"
extract_example "ミニ出力例" "$file" > "$expected_path"

if [[ ! -s "$input_path" || ! -s "$expected_path" ]]; then
    printf 'missing mini example: %s\n' "$file" >&2
    exit 1
fi

g++ -std=c++17 -O2 -Wall -Wextra -pedantic "$file" -o "$output_path"
"$output_path" < "$input_path" > "$actual_path"

printf '%s\n' '--- input ---'
cat "$input_path"
printf '%s\n' '--- output ---'
cat "$actual_path"

if ! diff -u "$expected_path" "$actual_path"; then
    printf 'mini example failed: %s\n' "$file" >&2
    exit 1
fi

printf '%s\n' '--- matched the mini output example ---'

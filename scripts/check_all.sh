#!/usr/bin/env bash

set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "$script_dir/sample_utils.sh"

cd "$repo_root"

tmp_dir="$(mktemp -d)"
trap 'rm -rf "$tmp_dir"' EXIT

count=0

while IFS= read -r file; do
    output_path="$tmp_dir/${file//\//_}"
    input_path="$tmp_dir/input.txt"
    expected_path="$tmp_dir/expected.txt"
    actual_path="$tmp_dir/actual.txt"

    extract_example "ミニ入力例" "$file" > "$input_path"
    extract_example "ミニ出力例" "$file" > "$expected_path"

    if [[ ! -s "$input_path" || ! -s "$expected_path" ]]; then
        printf 'missing mini example: %s\n' "$file" >&2
        exit 1
    fi

    g++ -std=c++17 -O2 -Wall -Wextra -pedantic "$file" -o "$output_path"
    "$output_path" < "$input_path" > "$actual_path"

    if ! diff -u "$expected_path" "$actual_path"; then
        printf 'mini example failed: %s\n' "$file" >&2
        exit 1
    fi

    count=$((count + 1))
done < <(list_sources)

printf 'compiled and checked %d files\n' "$count"

#!/usr/bin/env bash

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"

list_sources() {
    find basics templates algorithms math competitive -type f -name '*.cpp' | sort
}

extract_example() {
    local label="$1"
    local file="$2"

    awk -v label="$label" '
        $0 ~ "^[[:space:]]*" label ":[[:space:]]*$" {
            capturing = 1
            next
        }
        capturing && /^[[:space:]]*$/ {
            exit
        }
        capturing && /^[[:space:]]*\*\// {
            exit
        }
        capturing {
            sub(/^[[:space:]]+/, "")
            print
        }
    ' "$file"
}

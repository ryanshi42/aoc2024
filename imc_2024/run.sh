#!/bin/bash

for file in tasks/merchandise/data/*.in; do
    file="${file%.*}"
    python3 M.py < "$file.in" > res.txt
    diff res.txt "$file.out"
done



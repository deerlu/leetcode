#!/bin/bash
# Calculate the frequency of each word in words.txt
# by descending frequency

cat words.txt | tr -cs "[a-z][A-Z]" "\n" | sort | uniq -c | sort -k 1 -n -r | awk '{print $2,$1}'
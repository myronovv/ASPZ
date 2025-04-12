#!/bin/bash

echo "testing ulimit ..."

ulimit -aH
ulimit -aS

echo "Max file size: $(ulimit -f) blocks"
echo "Max process count: $(ulimit -u)"
echo "Max open files: $(ulimit -n)"
echo "Max stack size: $(ulimit -s) kbytes"
echo "Max virtual memory: $(ulimit -v) kbytes"
echo "Max locked-in-memory size: $(ulimit -l) kbytes"
echo "Max resident set size: $(ulimit -m) kbytes"
echo "Max CPU time: $(ulimit -t) seconds"
echo "Max pending signals: $(ulimit -i)"
echo "Max nice priority: $(ulimit -e)"
echo "Max real-time priority: $(ulimit -r)"
echo "Max core file size: $(ulimit -c) blocks"

echo -e "\nEnd"

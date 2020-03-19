#!/bin/bash

echo "step 1 testing"
echo " "
echo " "
echo " "
for file in file1.txt file2.txt file3.txt file4.txt; do
  echo "step1 $file"
  time ./step1 $file
  echo " "
done
echo " "
echo " "
echo " "

echo "step 2 testing"
echo " "
echo " "
echo " "
for file in file1.txt file2.txt file3.txt file4.txt; do
  for buffer in 100 1000 10000 100000; do
    echo "step2 $file $buffer"
    time ./step2 $file $buffer
    echo " "
  done
done
echo " "
echo " "
echo " "

echo "step 3 testing"
echo " "
echo " "
echo " "
for file in file1.txt file2.txt file3.txt file4.txt; do
  for buffer in 100 1000 10000 100000; do
    echo "step3 $file $buffer"
    time ./step3 $file $buffer
    echo " "
  done
done
echo " "
echo " "
echo " "

echo "step 4 testing"
echo " "
echo " "
echo " "
for file in file1.txt file2.txt file3.txt file4.txt; do
  for buffer in 100 1000 10000 100000; do
    for thread in 2 8 32 64; do
      echo "step4 $file $buffer $thread"
      time ./step4 $file $buffer $thread
      echo " "
    done
  done
done

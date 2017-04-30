<?php

define("TEST_INPUT_FILE", "testInput.txt");
define("TEST_OUTPUT_FILE", "testOutput.txt");

define("INPUT_FILE", "submitInput.txt");
define("SUBMIT_FILE", "submitOutput.txt");

define("SLICES_PER_PIZZA", 8);

include "functions.inc"; 

$file = fopen(INPUT_FILE,"r");
$outputFile = fopen(SUBMIT_FILE, "w");

$line =  fgets($file);
$cases = getNumberOfCases($line);
$index = 1;
while(!feof($file)) {
  $line =  fgets($file);
  if(is_blank_line($line)) break;
  $numberOfPeople = getNumberOfPeople($line);

  $line =  fgets($file);
  if(is_blank_line($line)) break;
  $minimumOrderPizza = getMinimumOrderPizza($line);

  write2file($outputFile , $index, $minimumOrderPizza);
  // printResult($index, $minimumOrderPizza);
  $index++;
}


fclose($file);
fclose($outputFile);

?>
<?php

define("TEST_INPUT_FILE", "testInput.txt");
define("TEST_OUTPUT_FILE", "testOutput.txt");

define("INPUT_FILE", "submitInput.txt");
define("SUBMIT_FILE", "submitOutput.txt");

include "functions.inc"; 

$file = fopen(TEST_INPUT_FILE,"r");
$outputFile = fopen(TEST_OUTPUT_FILE, "w");

// TODO
while(!feof($file)) {
  echo fgets($file);
}


fclose($file);
fclose($outputFile);
?>
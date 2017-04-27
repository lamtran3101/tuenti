<?php

define("TEST_INPUT_FILE", "testInput.txt");
define("TEST_OUTPUT_FILE", "output");

define("SUBMIT_INPUT_FILE", "submitInput.txt");
define("SUBMIT_FILE", "submitOutput");

include "functions.inc";

$input = fopen(SUBMIT_INPUT_FILE, "r");
$output = fopen(SUBMIT_FILE, "w");

$line = fgets($input);
$cases = getNumberOfCases($line);
$case_index = 0;

while (!feof($input)) {
    $line = fgets($input);
    if(isBlankLine($line)) break;
    $case_index++;

    $lengths = getListLength($line);
    $sides = $lengths[0];
    array_shift($lengths);
    
    $minimumPerimeter = getMinimumPerimeter($lengths, $sides);

    $text = "Case #".$case_index.": ".$minimumPerimeter."\n";
    fwrite($output, $text);
}

fclose($input);
fclose($output);
?>


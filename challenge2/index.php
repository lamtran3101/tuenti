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

    $numberofRolls = getNumberOfRolls($line);
    $line = fgets($input);
    $rolls = getAllRolls($line);
    $scores = getScores($numberofRolls, $rolls); 

    $text = "Case #".$case_index.": ".implode(" ", $scores)."\n";
    fwrite($output, $text);
}

fclose($input);
fclose($output);
?>


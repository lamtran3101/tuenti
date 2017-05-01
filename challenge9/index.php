<?php


define("TEST_FILE", "test");
define("TEST_INPUT_FILE", "testInput.txt");
define("TEST_OUTPUT_FILE", "output");

define("SUBMIT_INPUT_FILE", "submitInput.txt");
define("SUBMIT_FILE", "submitOutput");

include "functions.inc";

$input = fopen(TEST_INPUT_FILE, "r");
$output = fopen(TEST_OUTPUT_FILE, "w");

$line = fgets($input);
$cases = getNumberOfCases($line);
$case_index = 0;

while (!feof($input)) {
    $line = fgets($input);
    if(isBlankLine($line)) break;
    $case_index++;
    if($case_index == 88) echo $line;
    $params = getParamters($line);
    
    
    $maximumSections = getMaximumSections($params);

    $text = "Case #".$case_index.": ".$maximumSections."\n";
    fwrite($output, $text);
}

fclose($input);
fclose($output);
?>


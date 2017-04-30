<?php
define("TEST_FILE", "test");
define("TEST_INPUT_FILE", "testInput.txt");
define("TEST_OUTPUT_FILE", "output");

define("SUBMIT_INPUT_FILE", "submitInput.txt");
define("SUBMIT_FILE", "submitOutput");

include "functions.inc";

$input = fopen(TEST_FILE, "r");
$output = fopen(TEST_OUTPUT_FILE, "w");

$line = fgets($input);
$cases = getNumberOfCases($line);
$case_index = 0;

while (!feof($input)) {
    $line = fgets($input);
    if(isBlankLine($line)) break;
    $case_index++;

    $numberInHexa = getNumberInHexa($line);

    $text = "Case #".$case_index.": ".$numberInHexa."\n";
    fwrite($output, $text);
}

fclose($input);
fclose($output);
?>


<?php

if(!class_exists("IntlChar")) {
	die('Require IntlChar class');
} 

define("TEST_FILE", "test");
define("TEST_INPUT_FILE", "testInput.txt");
define("TEST_OUTPUT_FILE", "output");

define("SUBMIT_INPUT_FILE", "submitInput.txt");
define("SUBMIT_FILE", "submitOutput");

include "functions.inc";

//$input = fopen(TEST_INPUT_FILE, "r");
$output = fopen(SUBMIT_FILE, "w");

$input = file_get_contents( SUBMIT_INPUT_FILE);
 
$input = mb_convert_encoding($input, 'UTF-8', 'UTF-16LE');
$lines = parseLines( $input );

$cases = getNumberOfCases($lines[0]);
$case_index = 0;
array_shift($lines);
foreach ($lines as $line) {
    $case_index++;
    if($case_index > $cases) break;
    echo $case_index."\n";
    $numberInHexa = getNumberInHexa($line);
    $text = "Case #".$case_index.": ".$numberInHexa."\n";
    fwrite($output, $text);
}

fclose($output);
?>


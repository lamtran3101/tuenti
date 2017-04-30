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
    echo "Case: ".$case_index."\n";

    $numbers = getNumbersFromLine($line);
    $floors = $numbers[0];
    $shortestRoutes = $numbers[1];
    $map = initMap($floors);
    $listNeighbors = initListNeighbors($floors);

    while ($shortestRoutes != 0) {
    	$line = fgets($input);
        
    	$route = getRoutes($line);
    	initMapRoute($map, $route);
    	$shortestRoutes--;
    }
    updateListNeighbors($listNeighbors, $map);

    $minimumYears = fintMinimumYears($map, $floors, $listNeighbors, $case_index);
    $text = "Case #".$case_index.": ".$minimumYears."\n";
    fwrite($output, $text);
}

fclose($input);
fclose($output);
?>


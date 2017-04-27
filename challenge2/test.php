<?php

define("SUBMIT_FILE", "submitOutput");
define("TEST_FILE_OUTPUT", "testOutput");

$input = fopen(SUBMIT_FILE, "r");
$output = fopen(TEST_FILE_OUTPUT, "w");

include "functions.inc";

$case_index = 0;

while (!feof($input)) {
    $line = fgets($input);
    if(isBlankLine($line)) break;
    $case_index++;

    $scores = _parse_numbers($line);
    $result = _check_case($scores);

    $text = "Case #".$case_index.": ".$result."\n";
    fwrite($output, $text);
}

fclose($input);
fclose($output);

function _check_case($scores) {
	$sum = 0;
	$size = sizeof($scores);
	if(!_checkFullFrames($size)) {
		return "number of frames is not correct";
	}
	
	for ($index=0; $index < $size; $index++) { 
		$score = $scores[$index];
		if($index != 0) {
			$score = $scores[$index] - $scores[$index -1];
		}
		if(!_check_score_each_frame($score)) {
			return "score of frames ".$index." is not correct";
		}
	}

	return "PASS";
}

function _check_score_each_frame($score) {
	return ($score <= 30);
}

function _checkFullFrames($size) {
	return ($size == 10);
}

function _parse_numbers($line) {
	$substr = trim(substr($line, strpos($line, ":") + 1));
	return getNumbersFromLine($substr);
}

?>
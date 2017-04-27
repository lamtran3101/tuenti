<?php

function isBlankLine($line) {
	if($line == "\n" OR $line == "") return true;
	return false;
}

function getNumberOfCases($line) {
	$number = intval($line);
	return $number;
}

function getMaximumPoint($line) {
	$number = intval($line);
	return $number;
}

function getMinimumCard($maximumPoint) {
	$bin = decbin($maximumPoint);
	return strlen($bin);
}
?>
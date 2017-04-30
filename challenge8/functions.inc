<?php

function isBlankLine($line) {
	if($line == "\n" OR $line == "") return true;
	return false;
}

function getNumberOfCases($line) {
	$number = intval($line);
	return $number;
}

function getNumberInHexa($line) {
	$line = trim($line);
	$number = mb_detect_encoding($line);
	$number = mb_convert_encoding($line, "ASCII", "UTF-8");
	// $length = strlen($line);
	// for ($i=0; $i < $length; $i++) { 
	// 	$c = $line[$i];
	// 	$r = (int)$c;
	// 	$number .= $c."-";
	// }
	return $number;
}
?>
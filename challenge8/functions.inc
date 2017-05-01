<?php

function isBlankLine($line) {
	if($line == "\n" OR $line == "") return true;
	return false;
}

function getNumberOfCases($line) {
	$length = mb_strlen($line);
	$number = "";
	for ($i=0; $i < $length; $i++) { 
		$c = mb_substr($line, $i, 1);
		$number .= IntlChar::digit($c);
	}
	return $number;
}

function parseLines($input) {
	$lines = explode(PHP_EOL, $input);
	// $length = mb_strlen($input);
	// mb_strpos()
	// $line = "";
	// for ($i=0; $i < $length; $i++) { 
	// 	$c = mb_substr($input, $i, 1);
	// 	$type = IntlChar::charType($c);
	// 	$line .= $c;
	// 	if($type === 15) {
	// 		$lines[] = $line;
	// 		$line = "";
	// 	}
	// }
	return $lines;
}

function getNumberInHexa($line) {
	$number = "";
	// $line = mb_substr($line, 0, -1);
	$length = mb_strlen($line);

	$continue =true;
	$start = false;
	for ($i=0; $i < $length; $i++) { 
		$c = mb_substr($line, $i, 1);
		$type = IntlChar::charType($c);
		if($type === IntlChar::CHAR_CATEGORY_SPACE_SEPARATOR) {
			if($start == true) $continue = false;
			continue;
		} else {
			if($continue == false) return "N/A";
			if(!IntlChar::isdigit($c)) {
				return "N/A";
			} else {
				$start = true;
				$number .= IntlChar::getNumericValue($c);
			}
		}
	}
	return convert2hex($number);
}
function convert2hex($dec) {
   $hex = '';
    do {    
        $last = bcmod($dec, 16);
        $hex = dechex($last).$hex;
        $dec = bcdiv(bcsub($dec, $last), 16);
    } while($dec>0);
    return $hex;
}
?>
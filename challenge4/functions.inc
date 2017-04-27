<?php

function isBlankLine($line) {
	if($line == "\n" OR $line == "") return true;
	return false;
}

function getNumberOfCases($line) {
	$number = intval($line);
	return $number;
}

function getListLength($line) {
	$lengths = getNumbersFromLine($line);
	return $lengths;
}

function getMinimumPerimeter($lengths, $sides) {
	sort($lengths);
	$minimumPerimeter = 0;
	$largestSideIndex = 0;
	for ($i=0; $i < $sides - 2; $i++) { 
		if($i >= $largestSideIndex && $minimumPerimeter != 0) break;
		for ($j=$i + 1; $j < $sides - 1; $j++) { 
			if(is_triangle($lengths, $i, $j ,$j + 1)) {
				$perimeter = getPerimeter($lengths, $i, $j ,$j + 1);
				if($minimumPerimeter == 0) $minimumPerimeter = $perimeter;     
				else $minimumPerimeter = ($minimumPerimeter > $perimeter) ? $perimeter : $minimumPerimeter;
				$largestSideIndex = $j + 1;
				break;
			}
		}
	}

	if($minimumPerimeter == 0) return "IMPOSSIBLE";
	return $minimumPerimeter;
}
function is_triangle($lengths, $smallestSideIndex, $mediumSideIndex, $largestSideIndex) {
	return $lengths[$smallestSideIndex] + $lengths[$mediumSideIndex] > $lengths[$largestSideIndex];
}

function getPerimeter($lengths, $smallestSideIndex, $mediumSideIndex, $largestSideIndex) { 
	return $lengths[$smallestSideIndex] + $lengths[$mediumSideIndex] + $lengths[$largestSideIndex];
}

function getNumbersFromLine($line) {
	$numbers = array();
	$params = explode(" ", $line);
	foreach ($params as $value) {
		$numbers[] = intval($value);
	}
	return $numbers;
}

?>
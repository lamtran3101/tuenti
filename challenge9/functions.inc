<?php
define("TOP", "top");
define("TOPLEFT", "topleft");
define("TOPRIGHT", "topright");
define("LEFT", "left");
define("RIGHT", "right");
define("BOTTOM", "bottom");
define("BOTTOMLEFT", "bottomleft");
define("BOTTOMRIGHT", "bottomright");

function isBlankLine($line) {
	if($line == "\n" OR $line == "") return true;
	return false;
}

function getNumberOfCases($line) {
	$number = intval($line);
	return $number;
}

function getParamters($line) {
	$params = getNumbersFromLine($line);
	return $params;
}

function getNumbersFromLine($line) {
	$numbers = array();
	$params = explode(" ", $line);
	foreach ($params as $value) {
		$numbers[] = intval($value);
	}
	return $numbers;
}


class Point {
	var $x, $y;
	var $s, $c, $d;
	var $prevPoint;
}

function getMaximumSections($params) {
	$maximumSections = 0;
	$s = $params[0];
    $c = $params[1];
    $d = $params[2];
    $total = $s + $c +$d;
    if(checkNumberofCurves($c)) {
    	$remains_c = getCurvesRemainAfterBaseCircuit($c);
        if($remains_c == 0) {
            if($c >= 12) {
                $remains_s =  $s % 2;
            } else {
                if($s >= 2) $remains_s =  ($s + $d * 2 ) % 2;
                else {
                    $remains_s =  $s + ($d % 2);
                }
            }
            
            $maximumSections = $total - $remains_s;
        } else {
            if($remains_c >= 4) {
                if($d != 0) {
                    $remains_c = $remains_c - 4;
                    if($d >= 2 && $d % 2 == 0) $d = $d - 2;
                    else $d = $d - 1;
                } else if($s != 0) {
                    $remains_c = $remains_c - 4;
                    if($s >= 4) $s = $s - 4;
                    else $s = $s - 2;
                }
            }
            if($remains_c >= 2) {
                if($s >= 2) {
                    $remains_c = $remains_c - 2;
                    $s = $s - 2;
                    if($d%2 == 1) $d = $d - 1;
                }
            }
            if($s >= 2) $remains_s =  ($s + $d * 2 ) % 2;
            else {
                $remains_s =  $s + ($d % 2);
            }
            $maximumSections = $total - ($remains_c + $remains_s);
        }

    	
    }
	return $maximumSections;
}

function checkNumberofCurves($c) {
	return $c > 3;
}

function getCurvesRemainAfterBaseCircuit($c) {
	return ($c - 4) % 8; 
}

?>
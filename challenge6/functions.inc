<?php

function isBlankLine($line) {
	if($line == "\n" OR $line == "") return true;
	return false;
}

function getNumberOfCases($line) {
	$number = intval($line);
	return $number;
}

function getNumbersFromLine($line) {
	$numbers = array();
	$params = explode(" ", $line);
	foreach ($params as $value) {
		$numbers[] = intval($value);
	}
	return $numbers;
}

function getRoutes($line) {
	return getNumbersFromLine($line);
}

function calculateNormalYears($floor) {
	return bcdiv(bcmul($floor ,($floor - 1)),2);
}

function initMap($floors) {
	$map = array();
	$map[$floors][$floors] = calculateNormalYears($floors);
	$map[1][1] = 0;
	return $map;
}

function initListNeighbors($floors) {
	$listNeighbors = array();
	return $listNeighbors;
}

function updateListNeighbors(&$listNeighbors, &$map) {
	ksort($map);
}

function initMapRoute(&$map, $route) {
	$srcFloor = $route[0];
	$desFloor = $route[1];
	$r = $route[2];
	if(isset($map[$srcFloor][$desFloor])) {
		$map[$srcFloor][$desFloor] = min($map[$srcFloor][$desFloor], $r);
	} else {
		$map[$srcFloor][$desFloor] = $r;
	}

	$map[$srcFloor][$srcFloor] = calculateNormalYears($srcFloor);
	$map[$desFloor][$desFloor] = calculateNormalYears($desFloor);

}

function printMap($floors, $map) {
	echo "  "; 
	for ($i=1; $i <= $floors ; $i++) { 
		echo $i." "; 
	}
	echo "\n";
	for ($i=1; $i <=$floors ; $i++) { 
		echo $i." "; 
		for ($j=1; $j <=$floors ; $j++) { 
			if(isset($map[$i][$j])) {
				echo $map[$i][$j]." ";
			} else {
				echo "- ";
			}
		}
		echo "\n";
	}
}

function fintMinimumYears($map, $floors, $listNeighbors, $case) {
	$topFloor = $floors;
	$queues = array(1);
	$visited = array();
	$minYear = 0;
	$prev = array();
	// var_dump($map);
	// var_dump($listNeighbors);

	while (sizeof($queues) != 0) {
		$nextFloor = findNextBestFloor($queues, $map);
		// removeFloorFromQueue($queues, $nextFloor);
		if(isTopFloor($nextFloor, $floors)) {
			return $map[$floors][$floors];
			break;
		} 
		
		// var_dump("Next: ".$nextFloor);


		if(isset($visited[$nextFloor])) {
			// unset($map[$nextFloor]);
			continue;
		} 
		$visited[$nextFloor] = true;

		$neighbours = findAllNeighbours($map, $nextFloor);

		foreach ($neighbours as $neighbour) {
			if(isset($visited[$neighbour])) {
				continue;
			} 
			// var_dump("neighbour: ".$neighbour);
			$years2ReachThisNeighbour = getYearsTraining($map, $nextFloor, $neighbour);
				if(isset($map[$neighbour][$neighbour])) {
					$minimumYears2thisNeighbour = $map[$neighbour][$neighbour];
					if(bccomp($years2ReachThisNeighbour, $minimumYears2thisNeighbour) <= 0) {
						$map[$neighbour][$neighbour] = $years2ReachThisNeighbour;
						if(!in_array($neighbour, $queues))
							$queues[] = $neighbour;
					}
				} else {
					$map[$neighbour][$neighbour] = $years2ReachThisNeighbour;
					if(!in_array($neighbour, $queues))
					$queues[] = $neighbour;
				}
		}
		unset($map[$nextFloor]);
		
	}
	return $map[$floors][$floors];
}

function findNextFloor($map, $srcFloor) {
	$destFloor = 1;
	$next = false;
	foreach ($map as $key => $value) {
		if($next == true) {
			$destFloor =$key;
			break;
		}
		if ($key == $srcFloor) $next = true;
	}
   return  $destFloor;
}

function findAllNeighbours(&$map, $srcFloor) {
	$neighbours = array();
	foreach ($map as $neighbour => $routes) {
		if($neighbour < $srcFloor) {
			$neighbours[] = $neighbour;
		} else if($neighbour >  $srcFloor) {
			$neighbours[] = $neighbour;
			break;
		}
	}

	$routes = $map[$srcFloor];
	foreach ($routes as $destFloor => $v) {
		if(!in_array($destFloor, $neighbours)) {
			$neighbours[] = $destFloor;
		}
	}
	
	return $neighbours;
}

function removeFloorFromQueue(&$queues, $floor) {
	$key = array_search($floor, $queues);
	unset($queues[$key]);
}

// function insertIntoQueue(&$queues, $map, $floor) {
// 	if(isset($map[$floor][$floor])) {
// 			$minimumYear2thisFloor = $map[$floor][$floor];
// 	} else {
// 		$minimumYear2thisFloor = $floor * ($floor - 1) / 2;
// 	}
// 	foreach ($queues as $key => $floor) {
// 		# code...
// 	}
// }

function findNextBestFloor(&$queues, $map) {
	$minimumYear = -1;
	$nextFloor = 1;
	$removekey = 0;
	foreach ($queues as $key => $floor) {
		// var_dump("Queue: ".$floor);
		if(isset($map[$floor][$floor])) {
			$minimumYear2thisFloor = $map[$floor][$floor];
		} else {
			$minimumYear2thisFloor = calculateNormalYears($floor);
		}
		if($minimumYear == -1 OR bccomp($minimumYear, $minimumYear2thisFloor ) > 0) {
				$minimumYear = $minimumYear2thisFloor;
				$nextFloor = $floor;
				$removekey = $key;
		}
		
	}
	unset($queues[$removekey]);
	return $nextFloor;
}

function isTopFloor($floor, $floors) {
	return $floor == $floors;
}

function getYearsTraining($map, $srcFloor, $desFloor) {
	if($desFloor < $srcFloor ) {
		if(!isset($map[$desFloor][$desFloor]))
			$map[$desFloor][$desFloor] = calculateNormalYears($desFloor);
		if(bccomp($map[$srcFloor][$srcFloor], $map[$desFloor][$desFloor]) > 0) {
			return  $map[$desFloor][$desFloor];
		}
		return $map[$srcFloor][$srcFloor];
	} 

	$normal_route = bcadd($map[$srcFloor][$srcFloor],bcsub(calculateNormalYears($desFloor),calculateNormalYears($srcFloor)));

	if(isset($map[$srcFloor][$desFloor])) {
		$shortcut = bcadd($map[$srcFloor][$srcFloor] ,$map[$srcFloor][$desFloor]);
		if(bccomp($normal_route, $shortcut) > 0) {
			return  $shortcut;
		}
		return $normal_route;
	} 
	
	return $normal_route;
}

function printNeibours($list) {
	foreach ($list as $k => $l) {
		echo $k.": ".implode("," , $l)."\n";
	}
}

?>
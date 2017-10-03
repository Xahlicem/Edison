#!/bin/bash
while true
do
	./ssd1306 7 "`TZ='America/Los_Angeles' date '+%I:%M'`"
	sleep 1
	./ssd1306 7 "`TZ='America/Los_Angeles' date '+%I %M'`"
	sleep 1
done


#!/bin/bash	


filtered=$(cat "$1"  | grep -E -o '^(([^#]))*' | tr -d ' ') 

#take all the each rull and check it on each packet
#in the end we collect all of the results in variable final

for line in $filtered; do
	one=$(echo $line | cut -d "," -f1)
	

	two=$(echo $line | cut -d "," -f2)
	three=$(echo $line | cut -d "," -f3)
	four=$(echo $line | cut -d "," -f4)
	#echo $line;
	#echo $one;
	#echo $two;
	#echo $three;
	#echo $four;

	while read pack; do
		final+=`echo -e "$pack" | ./firewall.exe  "$one" 2>/dev/null | \
			./firewall.exe  "$two" 2>/dev/null | \
			 ./firewall.exe  "$three"  2>/dev/null | \
			./firewall.exe  "$four" 2>/dev/null `
		final+="\n"
		#echo "$pack";
	done </dev/stdin
done

#eventually print all
echo -ne $final | tr -d ' ' | sed '/^$/d' | sort




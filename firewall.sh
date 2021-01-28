
#!/bin/bash	


filtered=$(cat "$1"  | grep -E -o '^(([^#]))*' | tr -d ' ') 

#take all the each rull and check it on each packet
#in the end we collect all of the results in variable final

for line in $filtered; do
	one=$(sed 's/,/ /'<<<$line)
	two=$(sed 's/,/ /'<<<$one)
	three=$(sed 's/,/ /'<<<$two)
	read -a fields <<< $three
	while read pack; do
		final+=`echo -e "$pack" | ./firewall.exe  "${fields[0]}" 2>/dev/null | \
			./firewall.exe  "${fields[1]}" 2>/dev/null | \
			 ./firewall.exe  "${fields[2]}"  2>/dev/null | \
			./firewall.exe  "${fields[3]}" 2>/dev/null `
		final+="\n"
	done< "$2"
done

#eventually print all
echo -ne $final | tr -d ' ' | sed '/^$/d' | sort




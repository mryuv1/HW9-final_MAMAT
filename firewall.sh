
#!/bin/bash
rules_file="$1" 
packests="$2"


filtered=$(cat "$1"  | grep -E -o '^(([^#]))*' | tr -d ' ')  



for line in $filtered; do
	
	#rulles=$(echo "$line" | sed -e 's/,/ /');
	#echo "$line";
	one=$(sed 's/,/ /'<<<$line)
	two=$(sed 's/,/ /'<<<$one)
	three=$(sed 's/,/ /'<<<$two)

	read -a fields <<< $three
	echo "${fields[0]}"
	echo "${fields[1]}"
	echo "${fields[2]}"
	echo "${fields[3]}"

	
	while read pack; do
		echo $pack;
	done< "$2"
	#while IFS= read -r line;
	#echo $pack	
	#all=""
	#	for rull in $three;do
			
	#		all+=$(./firewall.exe "$rull" < $pack );
			#all+=$(echo -e '\n');
			#all+="\n";
	#		all+=$(echo -e '\v');
			
	##	done;	
	#echo "$all" | uniq -c
	
	#done<test3-pkts.in
done



#while IFS= read -r line;
#do
#	read -a rulles <<< "$line"
	
#	echo ${rulles[1]}

	#read -a fields <<< "$line"
	#fullpack+=echo "./firewall.exe ${fields[0]} < test2-pkts.in"
	#fullpack+=$("./firewall.exe ${fields[1]}")
	#fullpack+=$("./firewall.exe ${fields[2]}")
	#fullpack+=$("./firewall.exe ${fields[2]}")

#done<fields

